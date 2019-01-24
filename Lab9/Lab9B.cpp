/*
	Jared Westmoreland
	csce 1030.001
	11/15/2018
	redirects file information to another
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//gets user input function
void get_stream(ifstream& in_s, ofstream& out_s);

int main()
{
	//fstream variables and char
	char c;
	ifstream in_s;
	ofstream out_s;
	//calls function
	get_stream(in_s,out_s);
	
	//reads file until complete and grabs all characters
	while(in_s.get(c) && !in_s.eof())
	{
		//outputs all characters into user input file
		out_s.put(c);
	}
	
	//close files
	in_s.close();
	out_s.close();
	
	return 0;
}

//user input function
void get_stream(ifstream& in_s, ofstream& out_s)
{
	//variables to store user input
	char input_file[15];
	char output_file[15];
	
	//user prompt
	cout<<"Enter the name of the input file: ";
	cin >>input_file;
	cout<<"Enter the name of the output file: ";
	cin >> output_file;
	
	//opens and creates files
	in_s.open(input_file);
	out_s.open(output_file);
	
	//checks if file exists
	if(in_s.fail())
	{
		cout<<"Unable to open input file "<<input_file<<endl;
	}
	
	return;
}