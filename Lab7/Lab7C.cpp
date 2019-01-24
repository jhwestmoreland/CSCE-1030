#include <iostream>
using namespace std;

const int SIZE = 5;
void get_min(double my_array[], double& minimum);


int main()
{
	double my_array[SIZE]={1.1,-3.6,2.5,2.9,-3.4};
	double minimum = my_array[0];
	
	get_min(my_array,minimum);
	
	cout<<"Smallest value:"<<minimum<<endl;
	return 0;
}

void get_min(double my_array[], double& minimum)
{
	for(int i=1; i< SIZE; i++)
	{
		if(minimum>my_array[i])
		minimum=my_array[i];
	}
}