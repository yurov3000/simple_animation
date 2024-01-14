#include <iostream> 
#include <graphics.h> 
#include <windows.h> 
#include <conio.h>   
#include <locale.h> 
 
void Draw ( int x, int y, int color1,int color2 )                                                                
{  
    setcolor(color1); 
    setfillstyle ( 1, 0 ); 
   circle(x,y,40); 
    circle(x-45,y,5); 
    circle(x+45,y,5); 
    circle(x-20,y,5); 
    circle(x+20,y,5); 
    moveto(x,y-10); 
    lineto(x,y+10); 
    arc(x,y+10,180,0,15); 
    floodfill(x,y,color1); 
}  
void Variant1() 
{ 
    int x, y, code; 
     
    initwindow (400, 400); 
    setfillstyle(1, 0); 
    bar (0, 0, 399, 399); 
    x = 20; y = 200; 
     
 while ( 1 ) 
    { 
        Draw ( x, y, 15,3 );  
        code = getch(); 
        if ( code == 27 ) break; 
        Draw ( x, y, 0,0 ); 
            switch ( code )  
            { 
                case 52: x -=5; Draw ( x, y, 15,4 ); Draw ( x, y, 0,0 ); 
                break; 
                case 54: x +=5; Draw ( x, y, 15,4 ); Draw ( x, y, 0,0 ); 
                break; 
                case 56: y -=5; Draw ( x, y, 15,4 ); Draw ( x, y, 0,0 ); 
                break;  
                case 50: y +=5; Draw ( x, y, 15,4 ); Draw ( x, y, 0,0 ); 
                break; 
            } 
    } 
} 
 
void Variant2() 
{ 
    int x, y; 
     
    initwindow (400, 400); 
    setfillstyle(1, 0); 
    bar (0, 0, 399, 399); 
    x = 20; y = 200; 
     
    while (1) 
    { 
        while (y > 40) 
            { 
                if ( kbhit() ) 
                if ( getch() == 27 ) 
                    break; 
            Draw ( x, y, 15,4 ); 
            delay ( 20 ); 
            Draw ( x, y, 0, 0); 
            x = x + 5; 
            y = y - 5; 
   } 
     while (x > 40 ) 
            { 
                if ( kbhit() ) 
                if ( getch() == 27 ) 
                    break; 
            Draw ( x, y, 15,4 ); 
            delay ( 20 ); 
            Draw ( x, y, 0, 0); 
   x = x - 5; 
            } 
     while (x < 360 ) 
            { 
                if ( kbhit() ) 
                if ( getch() == 27 ) 
                    break; 
            Draw ( x, y, 15,4 ); 
            delay ( 20 ); 
            Draw ( x, y, 0, 0); 
   x = x + 5; 
            y = y + 5; 
   } 
  while (x > 40 ) 
            { 
                if ( kbhit() ) 
                if ( getch() == 27 ) 
                    break; 
            Draw ( x, y, 15,4 ); 
            delay ( 20 ); 
            Draw ( x, y, 0, 0); 
   x = x - 5; 
   } 
    } 
} 
 
int main() 
{ 
    setlocale(LC_ALL, "Rus");   
    int N; 
    printf("¬ыберите вариант задани€В, 1 - —вободное движение объекта, 2 - ?вижение объекта с помощью клавиатуры 3 - ¬ыход из программы "); scanf("%d", &N); 
     
if (N==2) 
{ 
    Variant1(); 
} 
  
if (N==1) 
{ 
    Variant2(); 
} 
if (N==3) 
{ 
 exit(0); 
} 
  closegraph(); 
}
