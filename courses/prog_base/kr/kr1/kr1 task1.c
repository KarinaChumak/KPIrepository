#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    printf("Enter the size: ");
scanf("%i",&N);

    int arr1[N], arr2[N],arr3[N];
for (int i=0; i<N;i++){
    arr1[i]=rand()%100-50;
    printf("%i ",arr1[i]);
}
printf("\n");
for (int i=0; i<N;i++){
    arr2[i]=rand()%132-13;
    printf("%i ",arr2[i]);}
printf("\nSums:\n");

for (int i=0;i<N;i++){
 arr3[i]=arr1[i]+arr2[i];
printf("%i ",arr3[i]);}

int min=arr3[0];
for (int i=0;i<N;i++){
  if (min>arr3[i])
    min=arr3[i];}
printf("\nThe least sum: %i ",min);

return 0;
}

