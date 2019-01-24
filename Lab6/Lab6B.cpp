#include <iostream>
using namespace std;

int main()
{
	const int ROW_SIZE=2;
	const int COLUMN_SIZE=5;
	int matrix[ROW_SIZE][COLUMN_SIZE];
	int row_sum[ROW_SIZE];
	int column_sum[COLUMN_SIZE];
	int count=0;
	
	for(int i=0; i<ROW_SIZE; i++)
	{
		for(int h=0; h<COLUMN_SIZE; h++)
		{
			column_sum[h]=0;
		}
		row_sum[i]=0;
	}
		
	for(int i=0; i<ROW_SIZE; i++)
	{
		for(int h=0; h<COLUMN_SIZE; h++)
		{
			cout<<"Enter data for row#"<<i+1<<" and column#"<<h+1<<":";
			cin>>matrix[i][h];
			column_sum[h] += matrix[i][h];
			row_sum[i] += matrix[i][h];
		}
		
	}
	
	cout<<"You entered:"<<endl;
	for(int i=0; i<ROW_SIZE; i++)
	{
		for(int h=0; h<COLUMN_SIZE; h++)
		{
			cout<<matrix[i][h]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for(int i=0; i<COLUMN_SIZE; i++)
	{
			cout<<"The column sum is displayed as such : "<<column_sum[i]<<"\t";
			cout<<endl;
	}
	for(int i=0; i<ROW_SIZE; i++)
	{
			cout<<"The row sum is displayed as such : "<<row_sum[i]<<"\t";
			cout<<endl;
	}
	return 0;
}