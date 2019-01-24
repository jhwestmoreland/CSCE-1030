#include "jhw0094HW4func.h"

int main()
{
	//structs
	Storage stuff;
	Status color;

	//intializes board
	string fakeboard[TOTAL];
	string board[ROW][COL];
	int number;
	char tile;	

	//allows for random variables
	srand(time(NULL));
		
	//basically makes the introduction and sets everything up
	printStudentInfo();
	openfile();
	printIntro();
	makeboard(fakeboard);
	transfer1d_2d(fakeboard,board);
	print(board);
	
	//will go endlessly until either computer/ players wins
	do
	{
		userprompt(number, tile, board);
		edit(number, tile, board);
		computer(board, number, tile);
		print(board);
	}while(number != -1); //this used to actually exit when player type -1, but I though exit was better later on
	
	cout<<endl;
	
	return 0;
}
