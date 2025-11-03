#include <iostream>	//For cin, cout 
#include<windows.h> // For time delay
#include<iomanip>  // For System cls
#include<conio.h>  // For getch
#include<stdlib.h>	//For rand(), setw()
#include<time.h>	//For srand
#include<math.h>	//For pow, sqrt

using namespace std;
const int box = 15;
int row = box -2, col = box/2;
char dot[box][box];
char arrow;
char enemy = char(157);
int GameOver = 1;
int eLocx = box/2;
int eLocy = (box/2);
int score = 0;
int noOfDots = (box*box - 2*box - 2*(box-2) - 2);
char dotOrNot = ' ';
double array[2][4];
int CaptureValue = 0;
int quit=1;

void menu();
void set();
void disp();
void GameOverCheck();
void EnemyMove();
void PlayAgain();

int main ()
{	
	menu();
	if(quit==0) {goto quit;}
	if (box < 5)
	{
		cout<<"Box size too small\n";
		return 0;
	}
	char arr[4] = {'^', 'V', '<', '>'};
	arrow = arr[2];
	set();
	disp();	
	
	char c;
	
	while(GameOver)
	{
		system("cls");
		disp();
		c = _getch();
		switch (c)
		{
			case 72: 					//UP
				arrow = arr[0];
				dot[row][col] = ' ';
				if (row == 1 && col == box/2)
				{
					row = box-2;
					if (dot[row][col] == '.') {score++;	Beep(750,5);}
				}
				else if (row != 1) 
				{
					row--;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				dot[row][col] = arrow;
				GameOverCheck();
				EnemyMove();
				//system("cls");
				//disp();
				break;
				
			case 80: 					//DOWN
				arrow = arr[1];
				dot[row][col] = ' ';
				if (row == box-2 && col == box/2)
				{
					row = 1;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				else if (row != box-2) 
				{
					row++;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				dot[row][col] = arrow;
				GameOverCheck();
				EnemyMove();
				//system("cls");
				//disp();
				
				break;
				
			case 75: 					//LEFT
				arrow = arr[2];
				dot[row][col] = ' ';
				if (col == 1 && row == box/2)
				{
					col = box-2;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				else if (col != 1)
				{
					col--;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				dot[row][col] = arrow;
				GameOverCheck();
				EnemyMove();
				//system("cls");
				//disp();
				
				break;
				
			case 77: 					//RIGHT
				arrow = arr[3];
				dot[row][col] = ' ';
				if (col == box-2 && row == box/2) 
				{
					col = 1;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				else if (col != box-2)
				{
					col++;
					if (dot[row][col] == '.') {score++; Beep(750,5);}
				}
				dot[row][col] = arrow;
				GameOverCheck();
				EnemyMove();
				//system("cls");
				//disp();
				
				break;
		}
		GameOverCheck();
	}
	
	system("cls");
	disp();
		
	if (score == noOfDots) {cout<<setw(30)<<"You WIN !!\n"; Beep(900,750);}
	else {cout<<setw(40)<<"Enemy caugth you, YOU LOOSE !!\n"; Beep(2000,500);}
	cout<<setw(32)<<"PLAY AGAIN? (Y/N)";
	while(quit!=3)
	{
		char decision=_getch();
		if(decision=='y'||decision=='Y') {system("cls"); PlayAgain();}
		if(decision=='n'||decision=='N') {goto quit;}
	}
	return 0;
	quit:;
}

void set()
{
	for (int i=0;i<box;i++)
	{
		for (int j=0;j<box;j++)
		{
			if (j==0) dot[i][j] = (char)219;
			else if (i==0) dot[i][j] = (char)219;
			else if (j==box-1) dot[i][j] = (char)219;
			else if (i==box-1) dot[i][j] = (char)219;
			else 
	    	dot[i][j]='.';
	  	}
	}
	dot[box/2][0] = ' ';
	dot[box/2][box-1] = ' ';
	dot[0][box/2] = ' ';
	dot[box-1][box/2] = ' ';
	dot[row][col] = arrow;
	dot[eLocx][eLocy] = enemy;
	//dot[eLocx1][eLocy1] = enemy;
}

void disp()
{
	char c = char(219);
	cout<<setw(17)<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<endl;
	cout<<setw(32)<<"Pacman by Hassaan\n";
	cout<<setw(17)<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<endl<<endl;
	cout<<"Your Score: "<<score<<setw(38)<<"Dots remaining: "<<noOfDots-score<<"\n\n\n";
	
	for (int i=0;i<box;i++)
	{
		cout<<"\t\t";
		for (int j=0;j<box;j++)
	  	{
	    	cout<<dot[i][j];
	  	}
	  	cout<<endl;
	}
	cout<<endl;
}

void GameOverCheck()
{
	if (score == noOfDots || (row == eLocx && col == eLocy)) GameOver = 0;
}

void EnemyMove()
{
	//srand(time(NULL));
	int num;// = ( rand()%4 ) +1;
	//for (int i = 0;i<4;i++) array[0][i] = 0;
	
	array[1][0] = 1; // Up
	array[1][1] = 2; // Down
	array[1][2] = 3; // Left
	array[1][3] = 4; // Right
	double x1=(eLocx - 1) - row;
	double y1=(eLocy - col);
	double x2=(eLocx + 1)-row ;
	double y2=eLocy - col;
	double y3=((eLocy - 1) - col);
	double x3=(eLocx - row);
	double y4=((eLocy + 1) - col);
	double x4=(eLocx - row);
	array[0][0] = pow( pow(x1, 2) + pow(y1 , 2) , 0.5); // Up
	array[0][1] = pow( pow(x2 , 2) + pow(y2 , 2) , 0.5); // Down
	
	array[0][2] = pow( pow(y3 , 2) + pow( x3, 2) , 0.5); // Left
	array[0][3] = pow( pow( y4, 2) + pow(x4 , 2) , 0.5); // Right
	
	for (int i=0;i<3;i++)
	{
		if (array[0][i] < array[0][i+1])
		{
			double temp = array[0][i+1];
			array[0][i+1] = array[0][i];
			array[0][i] = temp;
			
			temp = array[1][i+1];
			array[1][i+1] = array[1][i];
			array[1][i] = temp;
			
		}
	}
	
	double val = array[0][3];
	if (val < CaptureValue) num = array[1][3];
	else
	{
		srand(time(NULL));
		num = ( rand()%4 ) +1;
	}
	
	switch (num)
		{
			case 1: 					//UP
				if (eLocx == 1 && eLocy == box/2) 
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocx=box-2;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				else if (eLocx != 1)
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocx--;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				break;
				
			case 2: 					//DOWN
				if (eLocx == box-2 && eLocy == box/2) 
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocx=1;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				else if (eLocx != box-2) 
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocx++;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				break;
				
			case 3: 					//LEFT
				if (eLocy == 1 && eLocx == box/2) 
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocy = box-2;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				else if (eLocy != 1)
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocy--;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				break;
				
			case 4: 					//RIGHT
				if (eLocy == box-2 && eLocx == box/2) 
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocy = 1;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				else if (eLocy != box-2)
				{
					dot[eLocx][eLocy] = dotOrNot;
					eLocy++;
					dotOrNot = dot[eLocx][eLocy];
					dot[eLocx][eLocy] = enemy;
				}
				break;
		}
	
}
void menu()
{
	menu:
	system("cls");
	cout<<"\n\n\n\n"<<setw(32)<<"PLAY*\n"<<setw(35)<<"HOW TO PLAY\n"<<setw(30)<<"EXIT";
	int j=0;
	char move;
	while(j<3)
	{
		move=_getch();
		if(j!=2&&move==80) j++;
		if(j!=0&&move==72) j--;
		if(j==0)
		{ 
			system("cls"); 
			cout<<"\n\n\n\n"<<setw(32)<<"PLAY*\n"<<setw(35)<<"HOW TO PLAY\n"<<setw(30)<<"EXIT";
			if(move==13) {system("cls"); goto play;}
		}
		if(j==1)
		{ 
			system("cls"); 
			cout<<"\n\n\n\n"<<setw(31)<<"PLAY\n"<<setw(36)<<"HOW TO PLAY*\n"<<setw(30)<<"EXIT";
			if(move==13) {system("cls"); goto instruction;}
		}
		if(j==2)
		{ 
			system("cls"); 
			cout<<"\n\n\n\n"<<setw(31)<<"PLAY\n"<<setw(35)<<"HOW TO PLAY\n"<<setw(31)<<"EXIT*";
			if(move==13) {quit=0; goto end;}
		}
	}
	play:
	cout<<"\n\n\n\n"<<setw(32)<<"EASY*\n"<<setw(32)<<"MEDIUM\n"<<setw(30)<<"HARD";
	while(j<3)
	{
		move=_getch();
		if(j!=2&&move==80) j++;
		if(j!=0&&move==72) j--;
		if(j==0)
		{ 
			system("cls"); 
			cout<<"\n\n\n\n"<<setw(32)<<"EASY*\n"<<setw(32)<<"MEDIUM\n"<<setw(30)<<"HARD";
			if(move==13){CaptureValue=3; goto end;} 
			if(move==8) goto menu;
		}
		if(j==1)
		{
			system("cls"); 
			cout<<"\n\n\n\n"<<setw(31)<<"EASY\n"<<setw(33)<<"MEDIUM*\n"<<setw(30)<<"HARD";
			if(move==13){CaptureValue=6; goto end;}
			if(move==8) goto menu;
		}
		if(j==2)
		{ 
			system("cls");
			cout<<"\n\n\n\n"<<setw(31)<<"EASY\n"<<setw(32)<<"MEDIUM\n"<<setw(31)<<"HARD*";
			if(move==13){CaptureValue=10; goto end;}
			if(move==8) goto menu;
		}
	}
	instruction:
	cout<<setw(35)<<"HOW TO PLAY"<<"\n\n\n\n";
	cout<<"\t-Use arrow keys to control your pacman.\n";
	cout<<"\t-Move around the maze and collect food.\n";
	cout<<"\t-Beware of the enemy.\n";
	cout<<"\t-Keep a safe distance from the enemy.\n";
	cout<<"\t-Use teleporters to escape the enemy\n";
	cout<<"\t-Collect all the food to win.\n";
	while(j!=3) {move=_getch(); if(move==8) goto menu;}
	end:;
}
void PlayAgain()
{
	main();
}