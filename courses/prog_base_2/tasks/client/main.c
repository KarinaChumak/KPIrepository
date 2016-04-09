#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <winsock2.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#pragma comment(lib, "ws2_32.lib")

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480 // How much is printed out to the screen

SOCKET createSocket();
void connectToRemoteServer(SOCKET recvSocket, SOCKADDR_IN recvSockAddr);
void sendRequest(SOCKET recvSocket, const char* host_name);

char* receiveResponse(SOCKET Socket);
void sendSecret(SOCKET recvSocket, char* host_name, char* buffer);
char* getString(SOCKET Socket, char* buffer);
int getArraySize(const char* divStr);
char * arraySorting( char* divStr, int size);
void sendPOST(SOCKET recvSocket, char* host_name, char* message);


SOCKET createSocket(){
SOCKET recvSocket;
if((recvSocket = socket(AF_INET , SOCK_STREAM , IPPROTO_TCP )) == INVALID_SOCKET)
    {
		printf("ERROR: socket unsuccessful\r\n");
             WSACleanup();
		system("pause");
		exit(EXIT_FAILURE);
	}
	 printf("Socket created.\n");
    return recvSocket;

}

void connectToRemoteServer(SOCKET recvSocket, SOCKADDR_IN recvSockAddr){
puts("Connecting to server...");
 if(connect(recvSocket,(SOCKADDR*)&recvSockAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        printf("ERROR: socket could not connect\r\n");
        closesocket(recvSocket);
        WSACleanup();
exit(EXIT_FAILURE);
    }
     puts("Connected.");
}

void sendRequest(SOCKET recvSocket, const char* host_name){
	char request[200];
    sprintf(request, "GET /var/3 HTTP/1.1\r\nHost:%s\r\n\r\n", host_name);
        printf("Sending request...\n");

        send(recvSocket, request, strlen(request), 0);
        printf("Request send.\n");
}

char* receiveResponse(SOCKET recvSocket)
{
    char response[20000];
    if(recv(recvSocket, response, 20000, 0) == SOCKET_ERROR)
    {
        puts("Receive failed");
        closesocket(recvSocket);
        WSACleanup();
        return 1;
    }
    puts("Response received!\n");
    return response;
}




void sendSecret(SOCKET recvSocket, char* host_name, char* buffer){
char secret[50];
	char request[200];
	strcpy(secret, strstr(buffer, "secret"));
	sprintf(request, "GET /var/3?%s HTTP/1.1\r\nHost:%s\r\n\r\n", secret, host_name);
	    printf("Sending secret-request...\n");
	send(recvSocket, request, strlen(request), 0);
	    printf("Secret-request send.\n");

}

char* getString(SOCKET Socket, char* buffer)
{
    char divStr[40];
    char* str;
    buffer = strstr(buffer, "Content-Length:");
    str = strtok(buffer, "\n");
    str = strtok(NULL, "\n");
    str = strtok(NULL, "\n");
    strcpy(divStr, str);
    divStr[strlen(divStr)] = '\0';
    return divStr;
}

int getArraySize(const char* divStr)
{
    int size = 0;
    char* str = divStr;
    while(*str != NULL)
    {
        if(*str == ' ')
            size++;
        *str++;
    }
    size++;
    return size;
}

char * arraySorting( char* divStr, int size)

{
    char* str, temp[10];
    int i, j;
    int position = 0;
    int arr[size],tmp;

    str = strtok(divStr, " ");
    while(str != 0)
    {
        arr[position] = atoi(str);
        position++;
        str = strtok(NULL, " ");
    }

    for(i = 0; i<size - 1; i++)
        for(j = 0; j < size -1; j++)
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }

    for(i = 0; i<position; i++)
    {
        if(i == 0)
        {
            itoa(arr[i], divStr,10);
            continue;
        }
        strcat(divStr, " ");
        itoa(arr[i], temp, 10);
        strcat(divStr, temp);
    }
    divStr[strlen(divStr)] = '\0';
    return divStr;
}





void sendPOST(SOCKET recvSocket, char* host_name, char* message){
	char data[30];
	char request[200];
	sprintf(data, "result=%s", message);
	    data[strlen(data)] = '\0';
 sprintf(request, "POST %s/var/3 HTTP/1.1\r\nContent-Length: %i\r\n\r\n%s\r\n", host_name, strlen(data), data);
	send(recvSocket, request, strlen(request), 0);
}



int main(void) {
    WSADATA Data;
    SOCKADDR_IN recvSockAddr;
    SOCKET recvSocket;
    int status;
    int numrcv = 0;
    struct hostent * remoteHost;
    char * ip;
    const char * host_name = "pb-homework.appspot.com";
    char buffer[MAXBUFLEN];
    char myArray[50];
    memset(buffer,0,MAXBUFLEN);
 // Initialize Windows Socket DLL
    status = WSAStartup(MAKEWORD(2, 2), &Data);
    if(status != 0)
    {
        printf("ERROR: WSAStartup unsuccessful\r\n");
        return 1;
    }
    // Create socket
     recvSocket = createSocket();
	// Get IP address from host name
	remoteHost = gethostbyname(host_name);
	ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
	printf("IP address is: %s.\n", ip);
    memset(&recvSockAddr, 0, sizeof(recvSockAddr)); // zero the sockaddr_in structure
    recvSockAddr.sin_port=htons(PORT); // specify the port portion of the address
    recvSockAddr.sin_family=AF_INET; // specify the address family as Internet
    recvSockAddr.sin_addr.s_addr= inet_addr(ip); // specify ip address



	// Connect

connectToRemoteServer(recvSocket, recvSockAddr);
	// Send request
sendRequest(recvSocket, host_name);
    strcpy(buffer, receiveResponse(recvSocket));
	//Send request with secret param
	sendSecret(recvSocket, host_name, buffer);

    strcpy(buffer, receiveResponse(recvSocket));

    strcpy(myArray, getString(recvSocket, buffer));

    strcpy(myArray, arraySorting(myArray, getArraySize(myArray)));

	//Send POST-request with sorted array
sendPOST(recvSocket, host_name, myArray);
puts(receiveResponse(recvSocket));
	closesocket(recvSocket);
 WSACleanup();
	getchar();
	return EXIT_SUCCESS;

}
