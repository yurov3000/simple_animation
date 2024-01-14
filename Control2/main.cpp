#include <iostream>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include "altconio.h"


void DrawBoat(int colorFigure, int x, int y, int color){
	setfillstyle(1,color);
	setcolor(0);
	circle(x, y, 50);
	setcolor(colorFigure);
	circle(x+10, y+10, 7);
	line(x,y,x+20,y);
	line(x+20,y,x+40,y+10);
	line(x+40,y+10,x+20,y+20);
	line(x+20,y+20,x-20,y+20);
	line(x-20,y+20,x-20,y);
	line(x-20,y,x,y);
	
	line(x-20,y,x-20,y-10);
	line(x-20,y-10,x-45,y-5);
	line(x-45,y-5,x-20,y);
	
	line(x-20, y+20, x-20, y+30);
	line(x-20,y+30,x-45,y+25);
	line(x-45,y+25,x-20,y+20);
	
	
	
}

int main(int argc, char** argv) {
	srand(time(NULL));
	int key, i, n;
	for(i = 1; i <= 3; i++){ 
		gotoxy(45,(i*2)+3); 
		switch(i){ 
			case 1:{
				printf("1. Free movement of the object");
				break;
			}
			case 2:{
				printf("2. Moving an object using keyboard");
				break;
			}
			case 3:{
				printf("3. Exit...");
				break;
			}
		}
	}
	
	while(key != 13){ // 13 - Enter
		key = _getch();
		gotoxy(45,(i*2)+3);
		settextcolor(15,0);
		switch(i){
			case 1:{
				printf("1. Free movement of the object");
				break;
			}
			case 2:{
				printf("2. Moving an object using keyboard");
				break;
			}
			case 3:{
				printf("3. Exit...");
				break;
			}
		}
		if (key == 72) i--;
		if (key == 80) i++;
		if (i > 3) i=1;
		if (i < 1) i=3;
		gotoxy(45,3+i*2);
		settextcolor(12,7); 
		
		switch(i){
			case 1:{
				printf("1. Free movement of the object");
				break;
			}
			case 2:{
				printf("2. Moving an object using keyboard");
				break;
			}
			case 3:{
				printf("3. Exit...");
				break;
			}
		}
	}
	
/*==================================================================================================*/
	
	switch(i){
		case 1:{
			initwindow(800,600);
			setfillstyle(1,0);
			bar(0, 0, 600, 600); 
			int x = rand() % 800, y = rand() % 600;
			
			while(1){
			while(x-30 > 0){
				int r = rand() % 10;
				if (r <= 5){
					break;
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x -= 5;
				
			}	
			while(x+30 < 800){
				int r = rand() % 10;
				if (r <= 5){
					break;
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x += 5;
				
			}
			
			
			while(x-30 > 0 && y+30 < 600){
				int r = rand() % 10;
				if (r <= 5){
					break;
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x -= 10;
				y += 7;
			}
			
			
			while(x+30 < 800 && y+30 < 600){
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x += 10;
				y += 7;
			}
			
			while(y-30 > 0){
				int r = rand() % 10;
				if (r <= 5){
					break;
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y -= 5;
				
			}
			

			
			while(x-30 > 0 && y + 30 < 600){
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x -= 10;
				y += 7;
			}
			
			while(x-30 > 0 && y - 30 > 0){
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x -= 10;
				y -= 10;
			}
			while(x-30 > 0 && y + 30 < 600){
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y += 7;
			}
			
			while(y-30 > 0 && x + 30 < 800){
				int r = rand() % 10;
				if (r <= 5){
					break;
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y -= 5;
				x += 10;
				
			}
			
			
			while(x-30 > 0 && x + 30 < 800){
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x += 7;
			}
			
			while(y-30 > 0){
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y -= 5;
				
			}
			
			}
			closegraph();
			break;
		}
		
		
		case 2:{
			initwindow(800,600);
			setfillstyle(1,0);
			bar(0, 0, 800, 600);
			int x = 400, y = 300;
			while(1){
				DrawBoat(15, x, y, 0);
				int code = getch();
				
				if (code == 27){
					break;
				}
				
				DrawBoat(0, x, y, 0);
				
				if (code == 72) y -= 10; //движение объекта
       			if (code == 80) y += 10;
       			if (code == 75) x -= 10;
       			if (code == 77) x += 10;
				
			}
			closegraph();
			break;
		}
		
		case 3:{ 
			return 0;
			break;
		}
	}
}

