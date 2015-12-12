#include<stdio.h>
#include<stdlib.h>
void initMatrix(int N);
int main (){
int N,sum;
printf("Enter the size: ");
scanf("%i",&N);
initMatrix(N);

}


void actMatrix(int N){
int arr[N][N];
int k=0,sum2=0;
int sum=0;
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
    arr[i][j]=k;
    k++;
}
}
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
printf("%2i ",arr[i][j]);}
puts("\n");}


for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
            if(i=j)
    sum+=arr[i][j];}
    printf("Diag sum: %i ",sum);

for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
            if((i==0)||(i==(N-1))||(j==0)||(j==N-1))
    sum2+=arr[i][j];}
printf("\nSum of side elements: %i ",sum2);

}

