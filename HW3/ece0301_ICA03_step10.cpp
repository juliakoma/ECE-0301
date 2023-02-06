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
	double c1, c2;

	//changing values to use in switch
	if (user == "c" || user == "C"){
		choice1 = 1;

		c1 = number1;
		c2 = number2;
	}
	else if(user == "p" || user == "P"){
		choice1 = 2;

		c1 = number1;
		c2 = number2;
	}
	else {
		cout << "ERROR! Invalid selection, exiting." << endl;
		return -1;
	}
	
	double R, theta;	
	double x, y;
	
	if (choice1 == 1 || choice1 == 2)
	{
		//Step 4
		switch (choice1){
			case 1:
				//Converting first two numbers to cartesian
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
			// Converting first two numbers to polar
				cout << "You entered polar coordinates." << endl;
					
				//Error checking user numbers
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
	
	double c3, c4;
	
	//Changing user input to use in switch 
	if (user1 == "c" || user1 == "C"){
		choice2 = 1;

		c3 = number3;
		c4 = number4;
	}
	else if(user1 == "p" || user1 == "P"){
		choice2 = 2;

		c3 = number3;
		c4 = number4;
	}
	else {
		return -1;
	}

	double R1, theta1;
	double x1,y1;


	if (choice2 == 1 || choice2 == 2)
	{
		//Step 4: converting user's numbers to cartesian/polar coordinates
		switch (choice2){
			case 1:
				//Cartesian conversion
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
				//Polar conversion
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

	//Step 7
	cout << "Do the values you entered represent vectors (v) or complex numbers (c)?" << endl;
	cout << "Please enter a single character as your choice." << endl;
	
	string user3;
	cin >> user3;
	int choice3=0;

	if (user3 == "v" || user3 == "V"){
		choice3 = 1;
	}
	else if(user3 == "c" || user3 == "C"){
		choice3 = 2;
	}
	else {
		cout << "ERROR! Invalid selection, exiting." << endl;
		return -1;
	}

	switch (choice3){
		case 1:
			//Depending on if first numbers are polar or cartesian will display correct values
			if (choice1 == 1){
				cout << "Cartesian:\tv1 = (" << c1 << ", " << c2 << ")" << endl;
				cout << "Polar:\t\tv1 = (" << R << ", " << theta << ")" << endl << endl;
			
				cout << "Cartesian:\tv2 = (" << x1 << ", " << y1 << ")" << endl;
				cout << "Polar:\t\tv2 = (" << c3 << ", " << c4 << ")" << endl << endl;
			}
			else if (choice1 == 2){
				cout << "Cartesian:\tv1 = (" << x << ", " << y << ")" << endl;
				cout << "Polar:\t\tv1 = (" << c1 << ", " << c2 << ")" << endl << endl;
				
				cout << "Cartesian:\tv2 = (" << c3 << ", " << c4 << ")" << endl;
				cout << "Polar:\t\tv2 = (" << R1 << ", " << theta1 << ")" << endl << endl;
			}
				
			cout << "Which of the following vector sums or differences " << endl << "would you like to compute?" << endl;
			cout << "(1) v1 + v2" << endl << "(2) v1 - v2" << endl << "(3) v2 - v1" << endl << "(4) -v1 - v2" << endl << endl;
			
			int user3;
			cin >> user3;
			double sum1, sum2;
			double R2, theta2;
			
			//Calculating vector sum
			if (user3>=1 && user3<=4){
				switch (user3){
					case 1: 
					//Each if statement pulls correct values that user inputted based on if Cartesian numbers were inputted first or second
					if (choice1==1){
						sum1 = number1 + x1;
						sum2 = number2 + y1;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}
							
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
						}	
					else{
						sum1 = x + number3;
						sum2 = y + number4;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}
							
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
						}
					
						break;
					case 2:
					
					if (choice1 == 1){
						sum1 = number1 - x1;
						sum2 = number2 - y1;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}					
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
					}
					else{
						sum1 = x - number3;
						sum2 = y - number4;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}
							
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
						}
					}
						break;
					case 3:
					
					if (choice1 == 1){
						sum1 = x1 - number1;
						sum2 = y1 - number2;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}					
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
					}
					else{
						sum1 = number3 - x;
						sum2 = number4 - y;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}
							
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
						}
						break;
					case 4:
						
					if (choice1==1){
						sum1 = -number1 - x1;
						sum2 = -number2 - y1;
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}					
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta1 << ")" << endl;
					}
					else{
						
						sum1 = -x - number3;
						sum2 = -y - number4;
						
						R2 = sqrt((pow(sum1,2))+(pow(sum2,2)));
				
						if (sum1>=0)
						{
							theta2 = atan(sum2/sum1);
						}
						else if(sum1<0 && sum2>=0)
						{
							theta2 = atan(sum2/sum1) + M_PI;
						}
						else
						{
							theta2 = atan(sum2/sum1) - M_PI;
						}
							
						cout << "Sum, Cartesian:\tv_sum = (" << sum1 << ", " << sum2 << ")" << endl;
						cout << "Sum, Polar:\tv_sum = (" << R2 << ", " << theta2 << ")" << endl;
						}
						break;
				}
					
			else{
				cout << "ERROR! Invalid selection, exiting." << endl;
				return -1;
			}
			
			break;
		//Choice of complex numbers switch case
		case 2:
			//Again, each if statement pulls correct values from user's input
			if (choice1 == 1){
				if (c2>0){
					cout << "Cartesian:\tz1 = " << c1 << " + j " << c2 << endl;
				}
				else{
					cout << "Cartesian:\tz1 = " << c1 << " - j " << -(c2) << endl;
				}
				cout << "Polar:\t\tz1 = " << R << " exp(j " << theta << ")" << endl << endl;
				
				if (y1>0){
					cout << "Cartesian:\tz2 = " << x1 << " + j " << y1 << endl;
				}
				else{
					cout << "Cartesian:\tz2 = " << x1 << " - j " << -(y1) << endl;
				}
				cout << "Polar:\t\tz2 = " << c3 << " exp(j " << c4 << ")" << endl << endl;
			}
			else if (choice1 == 2){
				if (y>0){
				cout << "Cartesian:\tz1 = " << x << " + j " << y << endl;
				}
				else{
				cout << "Cartesian:\tz1 = " << x << " - j " << -(y) << endl;
				}
				cout << "Polar:\t\tz1 = " << c1 << " exp(j " << c2 << ")" << endl << endl;
				
				if (c4>0){
				cout << "Cartesian:\tz2 = " << c3 << " + j " << c4 << endl;
				}
				else {
				cout << "Cartesian:\tz2 = " << c3 << " - j " << -(c4) << endl;

				}
				cout << "Polar:\t\tz2 = " << R1 << " exp(j " << theta1 << ")" << endl << endl;
			}
			cout << "Which of the following sums or differences " << endl << "would you like to compute?" << endl;
			cout << "(1) z1 + z2" << endl << "(2) z1 - z2" << endl << "(3) z2 - z1" << endl << "(4) -z1 - z2" << endl << endl;
			
			int user4;
			cin >> user4;
			
			double sum1C, sum2C;
			
			//Switch case to make sure number is in between 4
			if (user4>=1 && user4<=4){
				switch (user4){
					//Calculating complex numbers sum
					case 1: 
					
					if (choice1==1){
						sum1C = number1 + x1;
						sum2C = number2 + y1;
						
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}			
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;
					}
					else{
						sum1C = x + number3;
						sum2C = y + number4;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;						
					}
						break;
					case 2:
					
					if (choice1==1){
						sum1C = number1 - x1;
						sum2C = number2 - y1;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}				
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;
					}
					else{

						sum1C = x - number3;
						sum2C = y - number4;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;						
					}
						break;
					case 3:
					
					if (choice1==1){
						sum1C = x1 - number1;
						sum2C = y1 - number2;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;
					}
					else{

						sum1C = number3 - x;
						sum2C = number4 - y;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;						
					}	
						break;
					case 4:
					
					if (choice1 == 1){
						sum1C = -number1 - x1;
						sum2C = -number2 - y1;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}
						
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;
					}
					else{

						sum1C = -x - number3;
						sum2C = -y - number4;
						R2 = sqrt((pow(sum1C,2))+(pow(sum2C,2)));
				
						if (sum1C>=0)
						{
							theta2 = atan(sum2C/sum1C);
						}
						else if(sum1C<0 && sum2C>=0)
						{
							theta2 = atan(sum2C/sum1C) + M_PI;
						}
						else
						{
							theta2 = atan(sum2C/sum1C) - M_PI;
						}
						cout << "Sum, Cartesian:\tz_sum = " << sum1C << " + j " << sum2C << endl;
						cout << "Sum, Polar:\tz_sum = " << R2 << " exp(j " << theta2 << ")" << endl;						
					}
						
						break;
				}
				
			}
		
			else{
				cout << "ERROR! Invalid selection, exiting." << endl;
				return -1;
			}
			
			break;
	}
	

	return 0;

}



