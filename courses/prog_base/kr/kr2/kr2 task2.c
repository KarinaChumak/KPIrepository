#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//WASTED
 struct plane{
 int numberOfPassengers;
 int maxNumberOfPassengers;
 int maxDistance;
 char destination[30];
 time_t lastFlight;
}Boeing={150,180,2000,"Paris",4305980435};

/*int initialize(){
   struct plane *pBoeing=&Boeing;
printf("Boeing");
printf("\nNumber of passengers: %i",pBoeing->numberOfPassengers);
printf ("\nMax number of passengers: %i",pBoeing->maxNumberOfPassengers);
printf ("\nMax distance: %i",pBoeing->maxDistance);
printf ("\nDestination: %s",pBoeing->destination);
printf ("\nLast flight: %lld",pBoeing->lastFlight);
}*/


int main(void){
//initialize();
struct plane *pBoeing=&Boeing;
printf("Boeing");
printf("\nNumber of passengers: %i",pBoeing->numberOfPassengers);
printf ("\nMax number of passengers: %i",pBoeing->maxNumberOfPassengers);
printf ("\nMax distance: %i",pBoeing->maxDistance);
printf ("\nDestination: %s",pBoeing->destination);
printf ("\nLast flight: %lld",pBoeing->lastFlight);



int newValue;
printf("\nEnter new number of passengers; ");
scanf("&i", newValue);
    strcpy(pBoeing->numberOfPassengers, newValue);
printf("\nNew number of passengers: %s");


return 0;
}

/*void changeNumberOfPassengers(plane * Boeing, const char * newValue)
{
    strcpy(pVar->numberOfPassengers, newValue);
}*/
