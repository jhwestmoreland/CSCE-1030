#include <iostream>
using namespace std;

int main()
{
		const int SIZE = 8;
		int height[SIZE];
		int above_average[SIZE];
		double average = 0;
		int index=0;
		
		for(int i=0; i<SIZE; i++)
		{
			cout<<"Enter height in inches of student #"<<i+1<<":";
			cin>>height[i];
			average = static_cast<double>(height[i]) + average;
			above_average[i] = 0;
		}
		
		average = average / static_cast<double>(SIZE);
		
		for(int i =0; i<SIZE; i++)
		{
			if(height[i] > average)
			{
				above_average[i] = height[i];
				index++;
			}
		}
		
		cout<<"You entered:"<<endl;
		for(int i=0; i<SIZE; i++)
		{
			cout<<"Height in inches of students #"<<i+1<<":"<<height[i]<<endl;
		}
		
		cout<<endl<<"The total number of students that were above average were #"<<index<<"\n";
		
		for(int i=0; i<SIZE; i++)
		{
			if(above_average[i] > average)
			cout<<"The student #"<<i<<" where above average with the height of "<<above_average[i]<<endl;
		}
		
		return 0;
}