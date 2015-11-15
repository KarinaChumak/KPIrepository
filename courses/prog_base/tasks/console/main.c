#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
int getColor(int x, int y){

	int bg = 0,fg=0, k= 0;
fg=FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	if (y<5){ if ((x<11)||(x<71&&x>60)||(x>30&&x<41))
        bg=BACKGROUND_BLUE | BACKGROUND_RED;
        if ( (x>10&&x<31)||(x>50&&x<61))
   bg=BACKGROUND_RED | BACKGROUND_GREEN;
      if ((x>40&&x<51)||(x>70))
    bg= BACKGROUND_RED;
        }
 if (y>4&&y<10)
        {if ((x>10&&x<21)||(x>40&&x<51)||(x>70))
        bg=BACKGROUND_BLUE | BACKGROUND_RED;
        if (( x>20&&x<41)||(x>60&&x<71))
   bg=BACKGROUND_RED | BACKGROUND_GREEN;
        if ((x<11)||(x>50&&x<61))
    bg= BACKGROUND_RED;}




   if (y>9&&y<15){if ((x<31&&x>20)||(x>50&&x<61))
        bg=BACKGROUND_BLUE | BACKGROUND_RED;
        if ((x<11)||(x>30&&x<51)||(x>70))
   bg=BACKGROUND_RED | BACKGROUND_GREEN;
      if ((x>10&&x<21)||(x>60&&x<71))
    bg= BACKGROUND_RED;
        }

        if (y>14&&y<20){if ((x<11)||(x>30&&x<41)||(x>60&&x<71))
        bg=BACKGROUND_BLUE | BACKGROUND_RED;
        if ((x>10&&x<21)||(x>40&&x<61) )
   bg=BACKGROUND_RED | BACKGROUND_GREEN;
      if ((x<31&&x>20)||(x>70))
    bg= BACKGROUND_RED;
        }

        if (y>19&&y<25){if ((x>10&&x<21)||(x>40&&x<51)||(x>70))
        bg=BACKGROUND_BLUE | BACKGROUND_RED;
        if ( (x<31&&x>20)||(x>50&&x<71))
   bg=BACKGROUND_RED | BACKGROUND_GREEN;
      if ((x<11)||(x>30&&x<41))
    bg= BACKGROUND_RED;
        }


	k = FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| bg| fg;
	return k;
}
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    int i,j	;

   for (i = 0; i<25; i++){
        if ((i%2)==0)
		{for (j = 79; j>-1; j--)
		{
		    pos.X=j;
            pos.Y=i;
            printf("*");
			Sleep (1);
			SetConsoleTextAttribute(hConsole, getColor(pos.X, pos.Y));
			SetConsoleCursorPosition(hConsole, pos);
		}}
		if ((i%2)==1) {
      {for (j =0; j<80; j++)
		{
		    pos.X=j;
    pos.Y=i;
    printf("*");
			Sleep (1);
			SetConsoleTextAttribute(hConsole, getColor(pos.X, pos.Y));
			SetConsoleCursorPosition(hConsole, pos);
		}}
      }}

 getchar();
  return EXIT_SUCCESS;
}
