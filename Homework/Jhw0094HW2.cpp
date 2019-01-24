/*
	Author:	Jared Westmoreland
	Date:	10/03/2018
	Course: 1030.001
	Instructor: Dr. Thompson
	Description: Calculator menu
*/
#include <iostream>
using namespace std;

enum Values{SUM=1, MEAN, MIN, MAX};

int main()
{
	//enum variable
	Values user;

	//variables
	int userInput = 0;
	float userNumber = 0;
	float min = 0;
	float max = 0;
	float sum = 0;
	int i = 0;
	float mean = 0;

	//Title card
	cout<<"+---------------------------------------------------------+\n"
	    <<"|            Computer Science and Engineering             |\n"
  	    <<"|             CSCE 1030 - Computer Science I              |\n"
	    <<"| Jared Westmoreland Jhw0094 jaredwestmoreland@my.unt.edu |\n"
	    <<"+---------------------------------------------------------+"<<endl;
	cout<<endl;

	do{
		//user menu
		cout<<"+******************* M E N U ******************+\n"
		<<"|  1. Compute sum of 6 floating-point numbers  |\n"
		<<"|  2. Compute mean of 6 floating-point numbers |\n"
		<<"|  3. Compute min of 6 floating-point numbers  |\n"
		<<"|  4. Compute max of 6 floating-point numbers  |\n"
		<<"|  5. Exit                                     |\n"
		<<"+**********************************************+"<<endl;

		//gets user input
		cout<<"---->";
		cin >> userInput;

		user = static_cast<Values>(userInput);
		//checks to see if it is either sum or mean
		switch(user)
		{
			case 1:
			case 2:
				cout<<"You will now be prompted to enter 6 numbers."<<endl;
				//gets the total sum
				for(i=0; i<6;i++)
				{
					//gets and stores user input
					cout<<"Enter number "<<i+1<<": ";
					cin >>userNumber;
					//sum = userNumber + sum
					sum += userNumber;
				}
				//mean basically divides the total by the amount of numbers
				mean = sum / 6;

				//if input was sum
				if(userInput == 1)
					cout<<"The sum of the 6 numbers is: "<<sum<<endl;
				//if input was mean
				else
					cout<<"The mean of the 6 numbers is: "<<mean<<endl;
				cout<<endl;
				break;

			//checks to see if it is either min or max
			case 3:
			case 4:
				//gets the first number so it can compare something to the next set of numbers
				cout<<"You will now be prompted to enter 6 numbers."<<endl;
				cout<<"Enter number 1: ";
				cin>>userNumber;
				min = userNumber; //stores in min
				max = userNumber; //stores in max

				for(i=1; i<6;i++)
				{
					//will get the next 5 numbers to compare
					cout<<"Enter number "<<i+1<<": ";
					cin>>userNumber;
					//if userNumber is less than min update value
					if(min > userNumber)
						min = userNumber;
					//if userNumber is greater than max update value
					if(max < userNumber)
						max = userNumber;
				}
				//if input was min
				if(userInput == 3)
					cout<<"The min of the 6 numbers is: "<<min<<endl;
				//if input was max
				else
					cout<<"The max of the 6 numbers is: "<<max<<endl;
				cout<<endl;
				break;

			case 5: break;

			default:
				cout<<"Invalid selection ("<<userInput<<"). Please enter choice 1 - 5."<<endl;
		}
		//sets all values back to zero
		min = 0;
		max = 0;
		mean = 0;
		sum = 0;
	}while(userInput != 5); //if input was 5 exit

	cout<<"Thank you for using this program! Have a great day!\n"<<endl;

	return 0;
}
