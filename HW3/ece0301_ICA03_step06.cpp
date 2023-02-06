#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Step 1: starting message
	cout << "ECE 0301 - Vectors in R2 and Complex Numbers" << endl;
	cout << "Please enter two numbers, separated by a space," << endl;
	cout << "that will represent a vector or a complex number." << endl << endl;
	
	//Step 2: printing user's number to the screen with three decimal places
	double number1, number2;

	cin >> number1 >> number2;
	
	cout << "You entered " << fixed << setprecision(3) << number1 << " and " << number2 << "." << endl << endl;
	
	//Step 3: creating an error check
	//If the user enters non-numeric data, the code reads it as 0 and 0
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?" << endl;
	cout << "Please enter a single character as your choice." << endl;
	string user;
	cin >> user;
	int choice1=0;
	
	if (user == "c" || user == "C"){
		choice1 = 1;
	}
	else if(user == "p" || user == "P"){
		choice1 = 2;
	}
	else {
		cout << "ERROR! Invalid selection, exiting." << endl;
		return -1;
	}
	
	double R, theta;	
	double x, y;

	
	if (choice1 == 1 || choice1 == 2)
	{
		//Step 4: converting user's numbers to cartesian/polar coordinates
		switch (choice1){
			case 1:
				cout << "You entered Cartesian coordinates." << endl;

				R = sqrt((pow(number1,2))+(pow(number2,2)));
				
				if (number1>=0)
				{
					theta = atan(number2/number1);
				}
				else if(number1<0 && number2>=0)
				{
					theta = atan(number2/number1) + M_PI;
				}
				else
				{
					theta = atan(number2/number1) - M_PI;
				}
				
				cout << "The equivalent polar coordinates are:" << endl;
				cout << "R = " << R << ", " << "theta = " << theta << endl;
				break;
			case 2:
				cout << "You entered polar coordinates." << endl;

				if (number1>0 && number2>=-M_PI && number2<=M_PI)
				{
					x = number1*cos(number2);
					y = number1*sin(number2);
					cout << "The equivalent Cartesian coordinates are:" << endl;
					cout << "x = " << x << ", y = " << y << endl << endl;
				}
				else {
					cout << "ERROR! Invalid polar coordinates, exiting." << endl << endl;
					return -1;

				}
				
				break;
		}
	}
		else
	{
		cout << "ERROR! Invalid selection, exiting." << endl;
		return -1;

	}
		
	//Step 5: asking user for another pair of numbers and asking if they are polar or cartesian coordinates
	cout << "Please enter another pair of numbers, separated by a" << endl << "space, to represent a second vector or complex number." << endl << endl;
	

	double number3, number4;
	cin >> number3 >> number4;

	cout << "You entered " << fixed << setprecision(3) << number3 << " and " << number4 << "." << endl << endl;
	
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?" << endl << "Please enter a single character as your choice." << endl;
	string user1;
	cin >> user1;
	
	//Same error check
	int choice2=0;
	
	if (user1 == "c" || user1 == "C"){
		choice2 = 1;
	}
	else if(user1 == "p" || user1 == "P"){
		choice2 = 2;
	}
	else {
		cout << "ERROR! Invalid selection, exiting." << endl;
		return -1;
	}

	double R1, theta1;
	double x1,y1;


	if (choice2 == 1 || choice2 == 2)
	{
		//Step 4: converting user's numbers to cartesian/polar coordinates
		switch (choice2){
			case 1:
				cout << "You entered Cartesian coordinates." << endl;
				R1 = sqrt((pow(number3,2))+(pow(number4,2)));
				
				if (number3>=0)
				{
					theta1 = atan(number4/number3);
				}
				else if(number3<0 && number4>=0)
				{
					theta1 = atan(number4/number3) + M_PI;
				}
				else
				{
					theta1 = atan(number4/number3) - M_PI;
				}
				
				cout << "The equivalent polar coordinates are:" << endl;
				cout << "R = " << R1 << ", " << "theta = " << theta1 << endl;
				break;
			case 2:
				cout << "You entered polar coordinates." << endl;

				if (number3>0 && number4>=-M_PI && number4<=M_PI)
				{
					x1 = number3*cos(number4);
					y1 = number3*sin(number4);
					cout << "The equivalent Cartesian coordinates are:" << endl;
					cout << "x = " << x1 << ", y = " << y1 << endl << endl;
				}
				else {
					cout << "ERROR! Invalid polar coordinates, exiting." << endl << endl;
					return -1;

				}
				
				break;
		}
	}
	else
	{
		cout << "ERROR! Invalid selection, exiting." << endl;
		return -1;

	}

	return 0;
}




