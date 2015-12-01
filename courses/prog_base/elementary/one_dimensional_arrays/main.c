#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_array( int arr1[],int n);
int sum (int arr1[], int res);



int main (){
int n, i;
    printf("Enter the size of array: n= ");
    scanf ("%d", &n);
int arr1[n];

initialize_array(arr1, n);
    for (i=0;i<n;i++)
    printf("%d,",arr1[i]);
int res=0;
 for (i=0;i<n;i++){
   if(arr1[i]<0)
    {res+=arr1[i];}
   }
printf("\nsum= %i \n",res);


int arr2[n];
change_array ( arr2,n,arr1);
    for (i=0;i<n;i++)
    printf("%i, ",arr2[i]);
    printf("\n");


positive_elements ( arr1, n);
printf("\n");


change_min_max ( arr1, n);
for (i=0;i<n;i++)
{
    printf("%i, ", arr1[i]);
}
}






void initialize_array( int arr1[],int n){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        arr1[i]=rand()%10-5;
    }
}



void change_array (int arr2[], int n,int arr1[]){
initialize_array(arr1, n);
for (int i=0;i<n;i++){
    if (arr1[i]<0){
        arr1[i]=0 ;
    }
    arr2[i]=arr1[i];
}
}





int positive_elements (int arr1[],int n){
int i;
for(i=0;i<n;i++)
{
if (arr1[i]>0) {

printf ("%d ", arr1[i]);
}}}






   int change_min_max (int arr1[], int n){
   int i;
   int min,max,min_index,max_index,tmp;
   max=arr1[0];
   for (i=0;i<n;i++){

    if(max<arr1[i]){
        max=arr1[i];
        max_index=i;
   }}

   min=arr1[0];
   for (i=0;i<n;i++){

    if(min>arr1[i])
        min=arr1[i];
        min_index=i;
   }

   tmp=arr1[min_index];
    arr1[min_index] = arr1[max_index];
   arr1[max_index] = tmp;


   }

