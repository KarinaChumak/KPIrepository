#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillRand3(int arr[], int size);
int checkRand3(int arr[], int size);
float meanValue (int arr[], int size);
int maxValue(int arr[], int size);
int meanIndex(int arr[], int size);
int maxIndex(int arr[], int size);
int maxOccurance(int arr[], int size);
int diff(int arr1[], int arr2[], int res[], int size);
void add(int arr1[], int arr2[], int res[], int size);
int lteq(int arr1[], int arr2[], int size);
void lor(int arr1[], int arr2[], int res[], int size);




int main(void){
    int size = 10;
    int arr[size];
    int arr1[size];
    int arr2[size];
    int res[size];
    int i;
     srand(time(NULL));
    fillRand3(arr, size);
    printf("\nCheckRand3= %d", checkRand3(arr, size));
    printf("\nAverage= %f", meanValue(arr, size));
    printf("\nMax = %d" , maxValue(arr, size));
    printf("\nMean_Index= %d", meanIndex(arr, size));
    printf("\nMax_Index= %d", maxIndex(arr, size));
    printf("\nMax Occurance= %d", maxOccurance(arr, size));
    printf("\nDiff: %d", diff(arr1,arr2,res, size));
    printf("\nLteq: %d", lteq(arr1,arr2, size));
   lor(arr1,arr2,res, size);

}

/* Заповнює масив випадковими цілими числами в діапазоні [0..1] (включно) */
void fillRand3(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
    arr[i]=rand()%2-0;
    printf("%d ", arr[i]);
    }
}
/* Перевіряє чи всі елементи масиву знаходяться у діапазоні [0..1] (включно). Повертає 1, якщо умова задовольняється і 0 - якщо не задовольняється */
int checkRand3(int arr[], int size){
   int i;
   for (i=0;i<size; i++){
    if (arr[i]<0||arr[i]>1)
        return 0;
   }
  return 1;
}
/* Знаходить середнє значення серед елементів масиву */
float meanValue (int arr[], int size){
 int i;
 float average;
 for(i=0; i<size; i++){
    average += (double)arr[i]/size;}
  return average;
}
/* Знаходить максимальний серед елементів масиву */
int maxValue(int arr[], int size){
  int i;
  int max=arr[0];
  for(i=0; i<size; i++){
    if(arr[i]>max)
        max=arr[i];
  }
  return max;
}
/* Знаходить індекс першого елементу, значення якого найближче до середнього значення серед елементів масиву */
int meanIndex(int arr[], int size){
  int i, Mean_Index;
 float average,dif,a;
 for(i=0; i<size; i++){
    average += (double)arr[i]/size;}
  return average;
   dif=average-arr[0];
   for (i = 0; i < size; i++){
   a = abs(average-arr[i]);}
   if(a<dif){
    dif=a;
    Mean_Index=i;
   }
   return Mean_Index;
}

/* Знаходить індекс першого максимального елемента масиву */
int maxIndex(int arr[], int size)
{    int i = 0, Max_Index = 0, max = arr[0];
for (i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
            Max_Index=i;
        }
}
return Max_Index;

}


/* Знаходить значення, яке найчастіше зустрічається у масиві. Якщо таких декілька, повертає більше з них*/
int maxOccurance(int arr[], int size){
    int i = 0, j =0, counter = 0, max_counter = 0, max_index = 0;
    for (i = 0; i < size; i++){
            counter = 0;
       for (j = 0; j < size; j++){
            if (arr[i]==arr[j]){
                counter++;
            }

      }
      if (counter > max_counter){
                max_counter = counter;
                max_index = i;
            }
      if (counter == max_counter){
        if (arr[i] > arr[max_index]){
            max_index = i;
        }
      }
    }
    return arr[max_index];
}

/* Розміри arr1, arr2 і res одинакові. Перевіряється різниця між відповідними елементами масивів arr1 і arr2. Ця різниця записується у відповідний елемент масиву res. Якщо всі різниці рівні 0 (тобто масиви arr1 і arr2 одинакові, то функція повертає 1, інакше - 0). */
int diff(int arr1[], int arr2[], int res[], int size){
         int i=0;
         for (i=0; i<size; i++){

            res[i]=arr1[i]-arr2[i];
       if (res[i]!=0) {
			return  0;}
		else return 1;
    }
}

/* Сума двох масивів arr1 та arr2*/
 void add(int arr1[], int arr2[], int res[], int size){

    int i=0;
    res[i]=0;
         for (i=0; i<size; i++){

            res[i]=arr1[i]+arr2[i];}
 }

 /* перація відношення lteq - less than or equals */
int lteq(int arr1[], int arr2[], int size){
int i=0;
for (i=0;i<size; i++){
    if (arr1[i]<=arr2[i]){
return 0;
    }
}
return 1;
}


/*Операція  lor - logical OR */
void lor(int arr1[], int arr2[], int res[], int size)
{
    int i;
	for (i = 0; i < size; i++){
		res[i] = (arr1[i] || arr2[i]) ? 1 : 0;
	}
}














