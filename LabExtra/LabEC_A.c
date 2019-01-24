/* Author: Jared Westmoreland (Jaredwestmoreland@my.unt.edu)
 Date: 12/6/2018
 Instructor: Dr. Thompson
 Description: computes average with pointers
here.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//variables
	double sum;
	int variable = 0;
	int count1 = 0;
	char character;
	//gives me enough space for one
	double *array = (double *)malloc(10*sizeof(double));
	
	//until break, return, or false
	while(true)
	{
		//user prompt
		printf("Please enter value or -1 to exit: ");
		scanf("%lf",array+variable);
		
		//if user input == -1 break end program
		if(*(array+variable) == -1)
		{
			free(array);
			return 0;
		}
		
		//sum all known variables
		sum += *(array+variable);
		//count iterations
		variable++;
		
		//loop all know iterations
		while(true)
		{
			printf("%lf\n", *(array+count1));
			count1++;
			//when count1 == variable break while loop
			if(count1 == variable)
				break;
		}
		//reset for next iteration
		count1 = 0;

		//average display
		printf("Update average is: %lf\n", sum/variable);

		//makes more memory
		array = (double*)realloc(array, (variable+1) * sizeof(double));
	}
}