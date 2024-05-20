#include<graphics.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
using namespace std;


void won(int x, char*a, char*b)
{
	delay(2000);
	cleardevice();
	setcolor(WHITE);
    settextstyle(8, 0, 6);
    outtextxy(60,100,"Congratulations");
    
    settextstyle(8, 0, 3);
    if(x == 3)
    {
    	outtextxy(50,300,a);
    	outtextxy(150,300," is the WINNER");
	}
	else
	{
		outtextxy(50,300,b);
		outtextxy(150,300," is the WINNER");
	}
    delay(10000);
}

int start()
{
	
	setcolor(WHITE);
    settextstyle(8, 0, 4);
    outtextxy(100,100,"WELCOME TO");
    outtextxy(300,100," TIC-TAC-TOE");
    
    settextstyle(8, 0, 3);
    outtextxy(60,300,"Press Enter Key to start the game");
    outtextxy(60,400,"Press Escape Key to quit the game");
    delay(100);
    if (GetAsyncKeyState(VK_RETURN))
    {
    	return 1;
	}
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		return -1;
	}
	else 
	{
		return 0;
	}
	
}
void border()
{
	setcolor(RED);
	
	rectangle(0,0,600,100);
	rectangle(0,500,600,600);
	rectangle(0,100,100,500);
	rectangle(500,100,600,500);
	
	setfillstyle(SOLID_FILL,RED);
	
	floodfill(300,25,RED);
	floodfill(300,575,RED);
	floodfill(25,300,RED);
	floodfill(575,300,RED);
	
}

void box(float x = 0, float y = 0)
{
	setcolor(WHITE);

	rectangle(100*x+50,100*y+50,100*x+150,100*y+150);

	setfillstyle(SOLID_FILL,WHITE);
	floodfill(100*x+100,100*y+100,WHITE);

}

void cross(int y = 0,int x = 0)
{
	setcolor(GREEN);
	line(100*x + 70,100*y + 70,100*x + 140,100*y + 140);
	line(100*x + 70,100*y + 140,100*x + 140,100*y + 70);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(((210+200*x)/2),((210+200*y)/2),GREEN);
}

void Circle(int y = 0,int x = 0)
{

	setcolor(BLUE);
	circle(100+100*x,100+100*y,30);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(100+100*x,100+100*y,BLUE);
}



main()
{
	
	int turn = 0;
	initwindow(600,600);
	
	
	int**coordinates;
	
	coordinates = new int*[3];
	for(int i = 0; i < 3; i++)
	{
		coordinates[i] = new int[3];
	}
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			coordinates[i][j] = 0;
		}
	}
					
	for(;;)
	{
		cleardevice();
		int st = start();
		if(st == 1)
		{
			
		cleardevice();
		settextstyle(8, 0, 3);
		outtextxy(100,100,"Player 1 name: ");
		char*P1;
		P1 = new char[20];
		getch();
		for(int i = 0; i < 20; i++)
		{
			P1[i] = ' ';
		}
		for(int i = 0; i < 20; i++)
		{
			char c = getch();
			if(c != VK_RETURN)
			{
				P1[i] = c;
				outtextxy(300,100,P1);
			}
			else
			{
				P1[i] = '\0';
				break;
			}
		}
		
		char*P2;
		P2 = new char[20];
		for(int i = 0; i < 20; i++)
		{
			P2[i] = ' ';
		}
		outtextxy(100,300,"Player 2 name: ");
		for(int i = 0; i < 20; i++)
		{
			char c = getch();
			if(c != VK_RETURN)
			{
				P2[i] = c;
				outtextxy(300,300,P2);
			}
			else
			{
				P2[i] = '\0';
				break;
			}
		}
		
	
	while(st == 1)
	{
		cleardevice();
		border();
		int y_c = 0;
		int x_c = 0;
	
		if (GetAsyncKeyState(VK_ESCAPE))
		{
		return 0;
		}
	
	
		float x = 1;
		float y = 1;
	
		POINT p;
		HWND hWnd;
		if(GetAsyncKeyState(0x01))
		{
			GetCursorPos(&p);
			ScreenToClient(GetForegroundWindow(),&p);
			if(p.x >= 150 && p.x <= 450 && p.y >= 150 && p.y <= 450)
			{
				
				cleardevice();
				border();
				if(p.x < 381 && p.x > 360)
				{
					x_c = 3;
				}
				else
				{
					x_c = p.x/127;
				}
				if(p.y < 381 && p.y > 360)
				{
					y_c = 3;
				}
				else
				{
					y_c =	p.y / 127;
				}
			
				
				
				
				cout << x_c << " " << y_c << endl;
				if(coordinates[y_c-1][x_c-1] == 0)
				{
					coordinates[y_c-1][x_c-1] = 1;
					turn++;
				}
				
				
			}
		}
			
			int a = 1;
			int b = 1;
		
			float m = a,n = b;
			for(int i = 0; i < 3; i++)
			{
				m = a;
				for(int j = 0; j < 3; j++)
				{
					if(coordinates[i][j] == 0)
					{
						box(m,n);
					}
					else if(coordinates[i][j] == 1)
					{
		
						if(turn % 2 == 0)
						{
							Circle(i+1,j+1);
							coordinates[i][j] = 2;
						}
						else if(turn % 2 == 1)
						{
							cross(i+1,j+1);
							coordinates[i][j] = 3;
						}
					}
					else if(coordinates[i][j] == 2)
					{
						Circle(i+1,j+1);
					}
					else if(coordinates[i][j] == 3)
					{
						cross(i+1,j+1);
					}

				m+=1.05;
				}
			n+=1.05;
			}
			
			
			int w = 0;
			int z = 0;
			
			for(w; w < 3; w++)
			{
				if(coordinates[w][z] == 2 || coordinates[w][z] == 3)
			{
				if((coordinates[w][z] == coordinates[w][z+1]) && (coordinates[w][z+1] == coordinates[w][z+2]))
				{
					won(coordinates[w][z],P1,P2);
					return 0;
				}
			}
			}
			w = 0;
			z = 0;
			for(z; z < 3; z++)
			{
				if(coordinates[w][z] == 2 || coordinates[w][z] == 3)
			{
				if((coordinates[w][z] == coordinates[w+1][z]) && (coordinates[w+2][z] == coordinates[w+1][z]))
				{
					won(coordinates[w][z],P1,P2);
					return 0;
				}
			}
			}
			w = 0;
			z = 0;
			if(coordinates[w][z] == 2 || coordinates[w][z] == 3)
			{
			if((coordinates[w][z] == coordinates[w+1][z+1]) && (coordinates[w+2][z+2] == coordinates[w+1][z+1]))
			{
				won(coordinates[w][z],P1,P2);
				return 0;
			}
		}
			if(coordinates[w][z+2] == 2 || coordinates[w][z+2] == 3)
			{
			if((coordinates[w][z+2] == coordinates[w+1][z+1]) && (coordinates[w+2][z] == coordinates[w+1][z+1]))
			{
				won(coordinates[w][z+2],P1,P2);
				return 0;
			}
		}
			delay(1000);
		}
	}
}
}