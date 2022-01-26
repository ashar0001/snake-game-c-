#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
using namespace std;
const int width = 50;
const int hight = 25;
bool gameover;
int x, y, fx, fy, score;
int tailx[100], taily[100];
int nTail;
enum edirection { STOP = 0, LEFT, RIGHT,UP,DOWN };
edirection dir;
void setup()
{
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = hight / 2;
	fx = rand() % width;
	fy = rand() % hight;
	score = 0;
	
}
void draw()
{
	
	system("cls");
	cout << setw(50) << "SNAKE GAME" << endl;
	int i, j;

	for (i = 0; i < width + 1; i++)
		cout << '#';                               

	cout << endl;
	for (i = 0; i < hight; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (j == 0)
				cout << '#';
			else if (x == j && y == i)
				cout << "O";
			else if (fx == j && fy == i)
				cout << 'F';
			
			else
			{
				bool print = false;      //if condition meets no extra space.
				for (int k = 0; k < nTail; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << 'o';
						print = true;
					}
				}
				if(!print)
				cout << " ";
			}
			if (j == width - 1)
				cout << '#';
		}
		cout << endl;

	}

	for (i = 0; i < width + 1; i++)
		cout << '#';
	cout << endl;

	cout << "SCORE :" << score<<endl;
	

}
 void input()
 {
	 if (_kbhit())
	 {
		 switch (_getch())
		 {
		 case 'w':
			 dir = UP;
			 break;
		 case'a':
			 dir = LEFT;
			 break;
		 case 'd':
			 dir = RIGHT;
			 break;
		 case's':
			 dir = DOWN;
			 break;
		 case 'x':
			 gameover = true;
			 break;


		 }

	 }
 }
 void logic()
 {
	 int prevtailx = tailx[0];   //following [0]
	 int prevtaily = taily[0];  //prevtail is assigned to [0]
	 int prev2x, prev2y;
	 tailx[0] = x; //for following the head
  	 taily[0] = y;// ''  ''
	 for (int i = 1; i < nTail; i++)  //As the score increases the tail size will  also incre
	 {
		 prev2x = tailx[i];     //as loop is increasing the prev2x will increase and follow prevx
		 prev2y = taily[i];
		 tailx[i] = prevtailx;
		 taily[i] = prevtaily;
		 prevtailx = prev2x;
		 prevtaily = prev2y;

	 }

	 switch (dir)
	 {
	 case LEFT:
		 x--;
		 break;
	 case RIGHT:
		 x++;
		 break;
	 case UP:
		 y--;
		 break;
	 case DOWN:
		 y++;
		 break ;
	 default:
		 break;
	 }
	
	 if (x > width || x<0 || y > hight||y<0)
		 gameover = true;
	 for (int i = 0; i < nTail; i++)
		 if (tailx[i] == x && taily[i] == y)  //if current tail is equal to head posi then game over
			 gameover = true;
	 if (x == fx && y == fy)
	 {		 
		 score += 20;    
		 fx = rand() % width;
		 fy = rand() % hight;
		 nTail++;
	 } 
 }
 int main()
 {
	 setup();
	 while (!gameover)
	 {
		 draw();
		 input();
		 logic();
	//Sleep(1); // for slowing speed.
	 }
	 if (gameover = true)
	 {
		 cout << setw(50)<<"GAMEOVER" << endl;
		 cout <<'\n' << setw(57) << "Better Luck Next Time" << endl;
	 }
 }