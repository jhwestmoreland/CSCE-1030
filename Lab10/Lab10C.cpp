/*
	Jared Westmoreland
	11/21/2018
	Experience bonus
*/
#include <iostream>
using namespace std;

struct Employee
{
	string name;
	int experience;
	double bonus;
};

int main()
{
	Employee *ptr = new Employee;
	
	cout<<"Please enter the value for the name and number of years \nof experience for the employee: ";
	cin >>ptr->name>>ptr->experience;
	
	if(ptr->experience > 10)
	{
		ptr->bonus = 5000.00;
	}
	else
	ptr->bonus = 3000.00;
	
	cout<<ptr->name<<"'s bonus is "<<ptr->bonus<<endl;
	
	ptr = NULL;
	delete ptr;
	
	return 0;
}