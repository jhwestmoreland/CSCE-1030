/*
	Jared Westmoreland
	11/21/2018
	Addressing stuff
*/
#include <iostream>
using namespace std;

int main()
{
  int my_int = 10;
  int *my_iptr;
  int *my_iptr2;

  my_iptr = &my_int;

  cout<<"The value of my_int: "<<my_iptr<<endl;
  cout<<"The address of my_int: "<<&my_int<<endl;
  cout<<"The address of my_int using the pointer: "<<*my_iptr<<endl;
  cout<<"The value of my_int using the pointer: "<<my_int<<endl;

  *my_iptr = 15;

  cout<<"The value of my_int: "<<my_int<<endl;

  my_iptr = new int;
  *my_iptr = 20;

  cout<<"The value of my_int: "<<my_int<<endl;

  my_iptr2 = new int;

  my_iptr2 = my_iptr;
  cout<<"The Value my_iptr2 Dereferenced is: "<<*my_iptr2<<endl;

  my_iptr = NULL;
  my_iptr2= NULL;

  delete my_iptr;
  delete my_iptr2;

  return 0;
}
