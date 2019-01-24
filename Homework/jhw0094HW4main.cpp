#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
using namespace std;

const int ROW = 8;
const int COL = 15;
const int TOTAL = ROW * COL;

enum Status {EMPTY = ' ', CROSS = '-', VERTICAL = '|', LOCKED = 'X'};

string fakeboard[TOTAL];
string board[ROW][COL];

void printStudentInfo();
void printIntro();
void openfile();
void makeboard(string fakeboard[]);
void userprompt(int& number, char& tile);
void edit(int &number, char tile, string board[][COL]);
void transfer1d_2d(string fakeboard[], string board[][COL]);
void transfer2d_1d(string fakeboard[], string board[][COL]);
void print(string board[][COL]);
void computer(string board[][COL], int& number);
void storearray(string board[][COL]);

int main()
{
	srand(time(NULL));
	
	int number = 0;
	char tile;
	
	printStudentInfo();
	openfile();
	printIntro();
	makeboard(fakeboard);
	transfer1d_2d(fakeboard,board);
	print(board);
	
	do
	{
		userprompt(number, tile);
		edit(number, tile, board);
		computer(board, number);
		print(board);
	}while(number != -1);
	
	cout<<endl;
	
	return 0;
}

void printStudentInfo()
{
	cout << "     +-------------------------------------------------+" << endl;
	cout << "     |       Computer Science and Engineering          |" << endl;
	cout << "     |        CSCE 1030 - Computer Science I           |" << endl;
	cout << "     |Jared Westmoreland   jhw0094   jhw0094@my.unt.edu|" << endl;
	cout << "     +-------------------------------------------------+" << endl;
	cout << endl;

	return;
}


void printIntro()
{	
	cout << endl;
	cout << "********************The aMAZEing Labyrinth********************" << endl;
	cout << "\t\t\tRules" <<endl;
	cout << "The aMAZEing Labyrinth is a two player game in which players" << endl;
	cout << "take turns sliding tiles, marked with |, -, or +, into lanes" << endl;
	cout << "from their side of the board. The goal is to have at least one" << endl;
	cout << "lane that has a straight, connected path from one player's" << endl;
	cout << "side of the board to the opposite side. This game is as much" << endl;
	cout << "about offense as it is defense, as you will have to try to!" << endl;
	cout << "extend your path while blocking your opponent's progress." << endl;
	cout << "\t\t\tGood luck!" <<endl;
	cout << "**************************************************************" << endl << endl;

	return;
}

void openfile()
{
	ifstream labyrinth;
	ofstream continue_game;

	string user_input;
	char c;
	string yn;
	int success = 0;
	
	while(success == 0)
	{
		cout<<"Do you want to continue your last game (Y/N)?:";
		cin >> yn;
		
		cin.ignore();
		if(yn == "n" || yn == "N")
		{
			cout<<"Please enter the name of the input file: ";
			getline(cin, user_input);
			success = 1;
		}	
		else if (yn == "y" || yn == "Y")
		{
			labyrinth.open("continue.txt");
			if(!labyrinth.is_open())
			{
				cout<<"No current saved games.\n";
				exit(EXIT_FAILURE);
			}
			return;
		}
		else
		{
			cout<<"invalid input try again\n";
		}
	}
	
	labyrinth.open(user_input.c_str());
	continue_game.open("continue.txt");
	
	if(!labyrinth.is_open())
	{
		cout<<"Input file opening failed.\n";
		exit(EXIT_FAILURE);
	}
	while(labyrinth.get(c) && !labyrinth.eof())
	{
		continue_game.put(c);
	}
	
	continue_game.close();
	labyrinth.close();
	
	return;
}

void userprompt(int& number, char& tile)
{	
	char con;
	cout<<"Please choose a lane: 1-7 or type -1 to quit:";
	cin >>number;
	
	if(number == -1) 
	{
		cout<<"Would you like to save your current game (Y/N)? ";
		cin >>con;
		if(con == 'y' || con == 'Y')
		{
			storearray(board);
		}
		exit(EXIT_SUCCESS);
	}
	if(number > 0 && number < 8)
	{
		number = 2*(number) - 2;
		
		cout<<"Please choose a tile to add: -, |, or +:";
		cin >>tile;

		if(tile == '-' || tile == '|' || tile == '+')
		{
			return;
		}
		else
		{
			cout<<"Invalid input"<<endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cout<<"Invalid input"<<endl;
		exit(EXIT_FAILURE);
	}
	
		
}

void makeboard(string fakeboard[])
{
	fstream continue_game;
	continue_game.open("continue.txt");
	char c;
	int i = 0;
	
	if (!continue_game.is_open())
	{
		cout<<"Input file opening failed.\n";
		exit(EXIT_FAILURE);
	}
	while(continue_game.get(c))
	{
		fakeboard[i] = c;
		i++;
	}
	
	cout<<endl;
	continue_game.close();
	return;
}

void transfer1d_2d(string fakeboard[], string board[][COL])
{
	int i = 0;
	int j = 0;
	int counter =0;
	
	for(int i=0; i< ROW; i++)
	{
		for(int j=0; j< COL; j++)
		{
			board[i][j] = fakeboard[counter];
			counter++;
		}
	}
}

void storearray(string board[][COL])
{
	int i = 0;
	ofstream store;
	store.open("continue.txt");
	for(int i=0; i< ROW; i++)
	{
		for(int j=0; j< COL; j++)
		{
			store << board[i][j];
		}
	}
	store.close();
}

void print(string board[][COL])
{
	cout<<"   1 2 3 4 5 6 7\n";
	cout<<"  ***************\n";
	for(int i=0; i< ROW; i++)
	{
		if(i < 7)
		cout<<i+1<<" *";
		for(int j=0; j< COL; j++)
		{
			if(board[i][j] != ",")
			cout<<board[i][j];
			else
			cout<<" ";
		}
	}
	cout<<"  ***************"<<endl;
}

void edit(int &number, char tile, string board[][COL])
{
	int win = 0;
	
	for(int i = ROW-2; i >= 0; i--)
	{
		for(int j=0; j< COL; j++)
		{
			if(number == j)
			{	
				if(board[i][j] == "+" || board[i][j] == "-" || board[i][j] == "|" || board[i][j] == " ")
				{	
					for(int k= ROW-2; k >= 0; k--)
					{
						if(board[k][number] == " ")
						{
							if(board[i-6][number] != "X" && board[i-5][number] != " " && board[i-5][j] != "X" && board[i-4][number] != " " && board[i-3][number] != " " && board[i-2][number] != " " && board[i][number] != " ")
							board[i-6][number] = board[i-5][number];
							if(board[i-5][number] != "X" && board[i-4][number] != " " && board[i-4][j] != "X" && board[i-3][number] != " " && board[i-2][number] != " " && board[i][number] != " ")
							board[i-5][number] = board[i-4][number];
							if(board[i-4][number] != "X" && board[i-3][number] != " " && board[i-3][j] != "X" && board[i-2][number] != " " && board[i][number] != " ")
							board[i-4][number] = board[i-3][number];
							if(board[i-3][number] != "X" && board[i-2][number] != " " && board[i-2][j] != "X" && board[i][number] != " ")
							board[i-3][number] = board[i-2][number];
							if(board[i-2][number] != "X" && board[i-1][number] != " " && board[i-1][j] != "X")
							board[i-2][number] = board[i-1][number];
							if(board[i-1][number] != "X" && board[i][number] != " " && board[i][j] != "X")
							board[i-1][number] = board[i][number];
							board[i][number] = tile;
							return;
						}
						else if(board[k][number] == "X")
						{
							cout<<"A locked tile is preventing your tile from being added. Try to be more careful next turn.\n";
							return;
						}
						if(k == 0)
						{
							for(int l=0; l< ROW-1; l++)
							{
								if(board[l][number] != " ")
								win++;
							}
							if(win == 7)
							{
								cout<<"You win"<<endl;
								exit(EXIT_SUCCESS);
							}
							win = 0;
						}
					}
				}
				else
				{
					cout<<"A locked tile is preventing your tile from being added. Try to be more careful next turn.\n";
				}
				return;
			}
		}
	}
}

void computer(string board[][COL], int& number)
{
	number = rand()%7;
	int tilenumber = rand()%3+1;
	char tile;
	int count = 0;
	
	if(tilenumber == 1)
	{
		tile = '+';
	}
	else if(tilenumber == 2)
	{
		tile = '-';
	}
	else
	{
		tile = '|';
	}
	for(int j = 0; j< COL; j++)
	{
		for(int i = 0; i < ROW; i++)
		{
			if(number == i)
			{
				for(int k= 0; k < COL; k++)
				{
					if(board[number][k+2] == "X" && board[number][k] != " ")
					{
						cout<<"A locked tile is preventing the computer's tile from being added. Silly computer."<<endl;
						return;
					}
					if(board[number][k] == " ")
					{
						if(board[i][j+12] != "X" && board[i][j+10] != " " && board[i][j+10] != "X" && board[i][j+8] != " "  && board[i][j+6] != " " && board[i][j+4] != " " && board[i][j+2] != " "  && board[i][j] != " ")
						board[i][j+12] = board[i][j+10];
						if(board[i][j+10] != "X" && board[i][j+8] != " " && board[i][j+8] != "X"&& board[i][j+6] != " " && board[i][j+4] != " " && board[i][j+2] != " "  && board[i][j] != " ")
						board[i][j+10] = board[i][j+8];
						if(board[i][j+8] != "X" && board[i][j+6] != " " && board[i][j+6] != "X" && board[i][j+4] != " " && board[i][j+2] != " "  && board[i][j] != " ")
						board[i][j+8] = board[i][j+6];
						if(board[i][j+6] != "X" && board[i][j+4] != " " && board[i][j+4] != "X" && board[i][j+2] != " "  && board[i][j] != " ")
						board[i][j+6] = board[i][j+4];
						if(board[i][j+4] != "X" && board[i][j+2] != " " && board[i][j+2] != "X" && board[i][j] != " ")
						board[i][j+4] = board[i][j+2];
						if(board[i][j+2] != "X" && board[i][j] != " " && board[i][j] != "X")
						board[i][j+2] = board[i][j];
						board[i][j] = tile;
						return;
					}
					count = 0;
					if(k == COL-1)
					{
						for(int p=0; p<13; p++)
						{
							if(board[number][p] != " " && board[number][p] != "X" && board[number][p] != "*")
							count++;
						}
						if(count == 13)
						{
							cout<<"You Lost"<<endl;
							exit(EXIT_SUCCESS);
						}
					}
				}
			}
		}
	}
	
}
