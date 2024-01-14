#include <iostream>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include "altconio.h"

void DrawBoat(int colorFigure, int x, int y, int color){ // Рисуем лодку
	setfillstyle(1,color);
	setcolor(0);
	circle(x, y, 50);
	setcolor(colorFigure);
	line(x,y,x+20,y);
	line(x+20,y,x+30, y-10);
	line(x+30,y-10,x-30,y-10);
	line(x-30,y-10,x-20,y);
	line(x-20,y,x,y);
	line(x,y,x,y-35);
	line(x,y-35,x-20, y-35);
	line(x-20,y-35,x-20, y-15);
	line(x-20,y-15,x,y-15);
	line(x,y-15,x+20,y-15);
	line(x+20,y-15,x+20,y-35);
	line(x+20,y-35,x,y-35);
}

int main(int argc, char** argv) {
	// вырисовываем меню
	int key, i, n;
	for(i = 1; i <= 3; i++){ // формируем меню
		gotoxy(45,(i*2)+3); // формируем отступы пунктов
		switch(i){ // выводим пункты в консоль
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
	
	// делаем выбор в меню.
	while(key != 13){ // 13 - Enter
		key = _getch();
		gotoxy(45,(i*2)+3);
		settextcolor(15,0);
		switch(i){ // выводим пункты в консоль
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
		if (key == 72) i--; // вниз по меню
		if (key == 80) i++; // вверх по меню
		if (i > 3) i=1; // зациклили меню
		if (i < 1) i=3; // зациклили меню
		gotoxy(45,3+i*2); // перемещаем курсор
		settextcolor(12,7); // делаем заливку текста
		
		switch(i){ // выводим пункты в консоль
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
	
	// привязываем код на каждый пункт меню. (правка на будущее: делать состояния в разных файлах)
	switch(i){
		case 1:{ // свободное движение
			initwindow(800,600);
			setfillstyle(1,0); // стиль заливки
			bar(0, 0, 600, 600); // заливаем фон
			int x = 120, y = 100;
			
			while(1){	
			while(x+30 < 800){// движение вправо по прямой
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				x += 5;
				
			}
			
			
			while(x-30 > 0){ // движение влево-вниз по диогонали
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
			
			while(y-30 > 0){ // движение вверх по левой стороне
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y -=5;
			}
			
			while(x+30 < 800){ // движение вправо-вниз
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
			
			while(y-30 > 0){ // движение вверх по правой стороне
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y -=5;
			}
			
			while(x-30 > 0){ // движение влево-вниз по диогонали
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
			
			while(y-30 > 0){ // движение вверх по левой стороне
				if (kbhit()){
					if (getch() == 27){
						break;
					}
				}
				DrawBoat(15, x, y, 0);
				delay(20);
				DrawBoat(0, x, y, 0);
				y -=5;
			}
			}
			closegraph();
			break;
		}
		
		
		case 2:{ // движение по клавиатуре
			initwindow(800,600);
			setfillstyle(1,0); // стиль заливки
			bar(0, 0, 800, 600); // заливаем фон
			int x = 400, y = 300;
			while(1){
				DrawBoat(15, x, y, 0);
				int code = getch();
				
				if (code == 27){
					break;
				}
				
				DrawBoat(0, x, y, 0);
				
				switch(code){
					case 75: x-=5; break; // влево
					case 77: x+=5; break; // вправо
					case 72: y-=5; break; // вверх
					case 80: y+=5; break; // вниз
				}
				
				if(x+10 >= 800){
					x -= 10;
				}
				if(x-10 <= 0){
					x += 10;
				}
				if(y+10 >= 600){
					y -= 10;
				}
				if(y-10 <= 0){
					y += 10;
				}
			}
			closegraph();
			break;
		}
		
		case 3:{ // пункт выхода из программы (сделан)
			return 0;
			break;
		}
	}
}
