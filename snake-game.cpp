#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h> // for _kbhit() and _getch()
using namespace std;

bool gameOver;//global variables
const int height=25;
const int width=50;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100],Ltail;
enum eDirection{STOP=0, UP ,DOWN, LEFT ,RIGHT};
eDirection dir;


void Setup(){
	gameOver=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	srand(time(0));
	fruitx=rand()%(width-2)+1;
	fruity=rand()%(height-2)+1;
	score=0;
	Ltail=0;
}
void Draw(){
	
	system("CLS");//to clear the screen before new game
	
	for(int i=0;i<width;i++)//top row
	{
	cout<<"#";	
	}cout<<endl;
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0||j==width-1)//for left and right wall k liye;
			{
				cout<<"#";
			}
			else if(i==y&&j==x)
			{
				cout<<"O";
		    }
		    else if(i==fruity&&j==fruitx){
		    	cout<<"F";
			}
			else
			{
				bool print=false;
				for(int k=0;k<Ltail;k++)
				{
				if(i==taily[k]&&j==tailx[k])
				{
					cout<<"O";
					print=true;
					break;
				}	
				}
				if(!print)
				{
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
	
	for(int i=0;i<width;i++)//bottom row
	{
	cout<<"#";	
	}
	cout<<endl;
	cout<<"score: "<<score<<endl;
}
void Input(){
	if(_kbhit())//keyboard key press
	{
			switch(_getch())
		{
			case 'w':
				dir=UP;
				break;
				
			case 'a':
				dir=LEFT;
				break;
				
			case 's':
				dir=DOWN;
				break;
				
			case 'd':
				dir=RIGHT;
				break;
			 
			default:
				break;
		}
	}
	
}
void Logic(){
	int prevx=tailx[0];
	int prevy=taily[0];
	tailx[0]=x;
	taily[0]=y;
	int prev2x,prev2y;
	
	for(int i=1;i<Ltail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	
	switch(dir){
		case UP:
			y--;
			break;
			
		case DOWN:
			y++;
			break;
			
		case LEFT:
			x--;
			break;
			
		case RIGHT:
			x++;
			break;
			
		default:
			break;
	}
	if(x<=0||x>=width-1||y<0||y>=height)
	{
		gameOver=true;
	}
	for(int i=0;i<Ltail;i++)
	{
	  if(x==tailx[i]&&y==taily[i])
	  {
	  	gameOver=true;
	  }
	}
	if(x==fruitx&&y==fruity){
		score=score+1;
		fruitx=rand()%(width-2)+1;
	    fruity=rand()%(height-2)+1;
		Ltail++;
	}
}
int main(){
	Setup();
	while(!gameOver){
		Draw();
		Input();
		Logic();
		Sleep(100);//blinking stop karne k liye for 100 ms 
	}
	return 0;
}
