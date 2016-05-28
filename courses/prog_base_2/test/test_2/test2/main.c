#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "socket.h"
#include "server.h"
#include "client.h"
#include "moovie.h"
#include "cJSON.h"

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480




void parse(char * text,  moovie_t * moovie);
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);
    char buf[10000];
    socket_t * client = NULL;
      const char * dbFile = "designers.db";
    db_t * db = db_new(dbFile);
    list_t * designers = list_new();

    WSADATA Data;
    SOCKADDR_IN recvSockAddr;
    SOCKET recvSocket;
    int status;
    struct hostent * remoteHost;
    char * ip;
    const char * host_name = "pb-homework.appspot.com";
    char buffer[MAXBUFLEN];
    memset(buffer,0,MAXBUFLEN);
    status = WSAStartup(MAKEWORD(2, 2), &Data);
    if(status != 0)
    {
        printf("ERROR: WSAStartup unsuccessful\r\n");
        return 0;
    }
    remoteHost = gethostbyname(host_name);
    ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);

    recvSockAddr = setSocAddr(ip);


     while(1)
    {
        client = socket_accept(server);
        socket_read(client, buf, sizeof(buf));
        printf("%s",buf);
        if (strlen(buf) != 0){
        http_request_t rs;
        rs = http_request_parse(buf);
        if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/info") == 0 )
        {
            server_info(client);
        }
        if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/database") == 0 )
        {
            server_db(client,db,designers);
        }
        if (strcmp(rs.method,"GET") == 0 && strcmp(rs.uri, "/external") == 0 )
            {
                recvSocket = new_Socket();
                Connect(recvSockAddr,recvSocket);
                sendFirstRequest(recvSocket,host_name);
                Recieve(recvSocket,buffer);
                moovie_t * moovie = moovie_new();
                parse(buffer,moovie);
                printf("%s",buffer);
                char * str = moovie_toJSON(moovie);
                server_external(client,str);
            }

        }
    }
    return 0;
}

void parse(char * text,  moovie_t * moovie)
{
    char * text_part = strstr(text,"{");
	cJSON * jList = cJSON_Parse(text_part);
	if (!jList) {
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
	}
    moovie_set(moovie,cJSON_GetObjectItem(jList, "movie")->valuestring,cJSON_GetObjectItem(jList, "year")->valueint);
    cJSON_Delete(jList);
}
