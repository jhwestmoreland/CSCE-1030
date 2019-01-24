/*
	Jared Westmoreland
	1030.001
	Thursay's Lab
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str1[15] = "algorithms";
	char str2[14];
	int len1, len2;
	
	
	cout<<"Enter a word with 14 or fewer characters at the prompt: ";
	cin>>str2;
	
	if( strlen(str1) ==  strlen(str2))
	{
		cout<<"The C-strings are the same length."<<endl;
	}
	else
	{
		cout<<"The C-strings are not the same length and must be different words."<<endl;
		return 0;
	}
	
	if(strcmp(str1, str2) == 0)
	{
		cout<<"The two C-strings are the same."<<endl;
	}
	else
	{
		cout<<"The two C-strings are NOT the same."<<endl;
	}
	
	return 0;
}