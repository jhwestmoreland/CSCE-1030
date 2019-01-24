#include "jhw0094HW4func.h"

/*
	My introduction card
*/
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

/*
	Game rules/ game introduction
*/
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

/*
	This opens the file the user specified and stores it into a another file
*/
void openfile()
{
	//read only
	ifstream labyrinth;
	ofstream continue_game;

	//variables needed
	string user_input;
	char c;
	string yn;
	int success = 0;
	
	//updates accordingly
	while(success == 0)
	{
		//asks user if they want to continue previos game. Loads file called continue
		cout<<"Do you want to continue your last game, if no it will override previous game (Y/N)?:";
		cin >> yn;
		
		//because it is within a loop inside a function. Needed this to help stop a endless loop
		cin.ignore();
		//if no
		if(yn == "n" || yn == "N")
		{
			//continue as usual
			cout<<"Please enter the name of the input file: ";
			getline(cin, user_input);
			success = 1;
		}	
		//if yes load game
		else if (yn == "y" || yn == "Y")
		{
			labyrinth.open("continue.txt");
			//if game does not exit exit
			if(!labyrinth.is_open())
			{
				cout<<"No current saved games.\n";
				exit(EXIT_FAILURE);
			}
			return;
		}
		//user tries to get cute by putting invalid input exit
		else
		{
			cout<<"invalid input try again\n";
		}
	}
	
	//gets user input and trys to open it
	labyrinth.open(user_input.c_str());
	continue_game.open("continue.txt");
	
	//if it cannot open exit failure
	if(!labyrinth.is_open())
	{
		cout<<"Input file opening failed.\n";
		exit(EXIT_FAILURE);
	}
	//if successful grab every character and put it into continue
	while(labyrinth.get(c) && !labyrinth.eof())
	{
		continue_game.put(c);
	}
	
	//close both files
	continue_game.close();
	labyrinth.close();
	
	return;
}

/*
	Grabs all the user prompt (-continue prompt)
	side note: I had a really hard time not having an endless loop with invalid user input if I used a loop
		   to ask the user again. I tried cin.ignore(), but it had no effect.
*/
void userprompt(int& number, char& tile, string board[][COL])
{	
	//give me input
	char con;
	cout<<"Please choose a lane: 1-7 or type -1 to quit:";
	cin >>number;
	
	//if user wants to exit
	if(number == -1) 
	{
		//allows to save progress
		cout<<"Would you like to save your current game (Y/N)? ";
		cin >>con;
		//if yes goes to function store
		if(con == 'y' || con == 'Y')
		{
			//storearray(board);
		}
		//exits no matter what
		exit(EXIT_SUCCESS);
	}
	//if number is valid
	if(number > 0 && number < 8)
	{
		//equation that keeps the display nice and clean
		number = 2*(number) - 2;
		
		//asks about tiles
		cout<<"Please choose a tile to add: -, |, or +:";
		cin >>tile;

		//if valid
		if(tile == '-' || tile == '|' || tile == '+')
		{
			//return;
		}
		//if input is not valid exit
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

/*
	grabs from continue and then puts it into a 1d array
*/
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

/*
	converts the 1d array to a 2d array
*/
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

/*
	If the user wants to store their current progress. It will store it within continue
*/
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

/*
	Prints out the entire board
	note: for some reason it would not let me put the * underneath the loop and 
	      because it was a string instead of a char. I could not detect '\n'
*/
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

/*
	This grabs the user input and puts it on the board manually
*/
void edit(int& number, char& tile, string board[][COL])
{
	int win = 0;
	
	//The array is viewed bottom to up 
	for(int i = ROW-2; i >= 0; i--)
	{
		for(int j=0; j< COL; j++)
		{
			//if COL matches user input
			if(number == j)
			{	
				//userinput has to go through his. Orginally I had a different test file and I required this.
				//I do not have time to edit this out, but it works regardless
				if(board[i][j] == "+" || board[i][j] == "-" || board[i][j] == "|" || board[i][j] == " ")
				{	
					//regoes bottom to up looking for any aviable blanks space
					for(int k= ROW-2; k >= 0; k--)
					{
						if(board[k][number] == " ")
						{
							/*
								hard coded this sorry. Couldn't think of another way to move so much
							*/
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
							//if there is an X in the way
							cout<<"A locked tile is preventing your tile from being added. Try to be more careful next turn.\n";
							return;
						}
						if(k == 0)
						{
							//when the array can not find any white spaces within the user input checks to see if you won
							for(int l=0; l< ROW-1; l++)
							{
								if(board[l][number] != " ")
								win++;
							}
							if(win == 7)
							{
								cout<<"\nCongratulations! You won!"<<endl;
								exit(EXIT_SUCCESS);
							}
							win = 0;
						}
					}
				}
				else
				{
					//backup user display message
					cout<<"A locked tile is preventing your tile from being added. Try to be more careful next turn.\n";
				}
				return;
			}
		}
	}
}

/*
	Exactly like the user but flipped 90 degrees
*/
void computer(string board[][COL], int& number, char& tile)
{
	//computer randomly generated input
	number = rand()%7;
	int tilenumber = rand()%3+1;
	int count = 0;
	
	//assigns values to char
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

	//basically view the array 90 degrees
	for(int j = 0; j< COL; j++)
	{
		for(int i = 0; i < ROW; i++)
		{
			//if it matches computer input
			if(number == i)
			{
				//looks for any white spaces
				for(int k= 0; k < COL; k++)
				{
					//if it finds an X in the way
					if(board[number][k+2] == "X" && board[number][k] != " ")
					{
						cout<<"A locked tile is preventing the computer's tile from being added. Silly computer."<<endl;
						return;
					}
					//hard coded like before because a loop really was not going to cut it I think
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
						//checks if computer won
						for(int p=0; p<13; p++)
						{
							if(board[number][p] != " " && board[number][p] != "X" && board[number][p] != "*")
							count++;
						}
						if(count == 13)
						{
							cout<<"Sorry, you lost"<<endl;
							exit(EXIT_SUCCESS);
						}
					}
				}
			}
		}
	}
	
}
