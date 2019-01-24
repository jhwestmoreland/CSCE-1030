#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
using namespace std;

//All my variables needed that have to stay constant
const int ROW = 8;
const int COL = 15;
const int TOTAL = ROW * COL;

//enums, didn't have the time to really go deep into these
enum Status {EMPTY = ' ', CROSS = '-', VERTICAL = '|', LOCKED = 'X'};
enum Color {red, blue};

//struct, didn't have the time to really go deep into these
struct Storage{
	Status tile_items;
	Color pigm;
	int num;
	char til;
};

//All the functions, so main can be tiny
void printStudentInfo();
void printIntro();
void openfile();
void makeboard(string fakeboard[]);
void userprompt(int& number, char& tile, string board[][COL]);
void edit(int& number, char& tile, string board[][COL]);
void transfer1d_2d(string fakeboard[], string board[][COL]);
void transfer2d_1d(string fakeboard[], string board[][COL]);
void print(string board[][COL]);
void computer(string board[][COL], int& number, char& tile);
void storearray(string board[][COL]);
