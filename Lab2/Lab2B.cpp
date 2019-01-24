#include <iostream>
using namespace std;

int main()
{
	float mile_km = 0;

	cout<<"How many miles did you walk today? ";
	cin >>mile_km;
	mile_km = mile_km * 1.609;
	cout<<"You walked "<< mile_km <<" kilometers today!\n";

	return 0;
}
