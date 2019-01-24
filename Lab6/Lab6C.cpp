/*
	Jared Westmoreland
	1030.001
	Thursay's Lab
*/
#include <iostream>
using namespace std;

int main()
{
	char arr[]={'b','f','a','z','m','g'};
	char temp;
	
	for(int i=0; i<6; i++)
	{
		for (int k = 0; k < 6-i; ++k )
		{		
				if (static_cast<int>(arr[k])>=static_cast<int>(arr[k+1])) {
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = arr[k];
      }
		}
	}
	for(int i=0; i< 6; i++)
	{
		cout<<arr[i]<<"\t";	
	}
	cout<<endl;
	
	return 0;
}