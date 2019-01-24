/* Author: Jared Westmoreland (Jaredwestmoreland@my.unt.edu)
 Date: 12/6/2018
 Instructor: Dr. Thompson
 Description: converts km to miles
here.
*/

#include <stdio.h>
#include <stdlib.h>

//defined variables
#define KM_TO_MILES 0.621371
#define value c * KM_TO_MILES


int main(int argc, char *argv[] )
{
	//two files for opening and closing
	FILE *number;
	FILE *output;
	double c;
	
	//if there is more than one variable error
	if(argv[2] != NULL)
	{
		printf("Error\n");
		exit(0);
	}
	
	//tries to open file
	number=fopen("kilometers.txt","r");
	//if fail does not exist
	if(number == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	
	//opens up file to write in
	output=fopen("output.txt","w");
	//scans kilometers and puts it into output
	while(fscanf(number,"%lf", &c) != EOF)
	{
		fprintf(output,"%lf\n", value);
	}
	
	//close both files
	fclose(number);
	fclose(output);
}