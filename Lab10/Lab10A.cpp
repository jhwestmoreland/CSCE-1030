/*
	Jared Westmoreland
	11/21/2018
	Averaging test grades
*/
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int test[3];
    double avg;
};

int main()
{
  Student array[10];
  int number;
  cout<<"How many students?";
  cin >>number;

  for(int i=0; i<number;i++)
  {
    cout<<"What is the name of student "<<i+1<<": ";
    cin >>array[i].name;
    cout<<"What is "<<array[i].name<<" 1st test score: ";
    cin >>array[i].test[0]; //for an array i might need to use gets(aef.aef)
    cout<<"What is "<<array[i].name<<" 2st test score: ";
    cin >>array[i].test[1];
    cout<<"What is "<<array[i].name<<" 3st test score: ";
    cin >>array[i].test[2];

    array[i].avg = double(array[i].test[0] +array[i].test[1] + array[i].test[2])/3;
  }
  for(int i=0; i<number; i++)
  {
      cout<<array[i].name<<"'s average test score was "<<array[i].avg<<"\n";
  }
  return 0;
}
