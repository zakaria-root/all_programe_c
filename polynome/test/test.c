#include <stdio.h>
#include <conio.h>
#include <windows.h>



// Fonction qui permet de placer le curseur à la position x,y
void gotoxy(short x, short y)
{
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos={x,y};
	SetConsoleCursorPosition(hConsole,Pos);
}

int main()
{
   int x, y;

   x = 10;
   y = 10;

   gotoxy(x,y);

   printf("C program to change cursor position.");

      printf("lequatio  : %d",&x1);
   scanf("%d",&x1);
   if()
   

   
   return 0;
}