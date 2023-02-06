#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//Prototypes
bool functionOR(bool, bool, bool);
void truthTable(ofstream &output, int num);
bool functionAND(bool x, bool y, bool z);
string funMinTerm(ifstream &input, int num);
bool funMinTerm(int minterm, bool x, bool y, bool z);
void truthTable(ofstream &output, int num, bool minOrMax);
string funMaxTerm(ifstream &input, int num);
bool funMaxTerm(int num, bool x, bool y, bool z);


int main()
{

	//Step 2
	//Start by creating an output file to send all print statements to
	ofstream output;
	output.open("Bool_func_3var_CSOP_CPOS.txt");
	
	//Creating an input file to read from
	ifstream input;
	input.open("Bool_func_3var.txt");
	
	//Setting input value to num
	int num;
	input >> num;
	
	//Testing if num is in between 0 and 7
	if (num >= 0 && num <= 7)
	{
		output << "ECE 0301: Boolean Functions of 3 Variables." << endl;
		output << "Realization in Canonical Forms." << endl << endl;
		
		//Runs function minterm
		string minterm = funMinTerm(input, num);
		output << minterm << endl << endl;
		output << "Truth Table for minterm " << num << "." << endl << endl;
		truthTable(output,num, true);
		
		output << endl;
		
		//Runs function maxterm
		string maxterm = funMaxTerm(input, num);
		output << maxterm << endl << endl;
		output << "Truth table for maxterm " << num << "." << endl << endl;
		truthTable(output,num, false);
	}
	//Else statement entered if number is not between 0 and 7
	else
	{
		cout << "ERROR! Invalid minterm index.";
	}
	
	output.close();
}

string funMinTerm(ifstream &input, int num){
	
	string minterm;
	
	//Switch case that uses value of num from input file and sets it equal to its correct minterm string value
	switch (num) 
	{
		case 0:
			minterm = "m0 = x'y'z'";
			break;
		case 1:
			minterm = "m1 = x'y'z";
			break;
		case 2:
			minterm = "m2 = x'yz'";
			break;
		case 3:
			minterm = "m3 = x'yz";
			break;
		case 4:
			minterm = "m4 = xy'z'";
			break;
		case 5:
			minterm = "m5 = xy'z";
			break;
		case 6:
			minterm = "m6 = xyz'";
			break;
		case 7:
			minterm = "m7 = xyz";
			break;			
		}
		
	return minterm;
}

//This is the overloaded function
bool funMinTerm(int num, bool x, bool y, bool z){
	bool val;
	//create 3 new variables
	bool x1, y1, z1;
	
	//switch case 0-7
	switch (num)
	{
		case 0:
			x1 = !x;
			y1 = !y;
			z1 = !z;
			
			break;
		case 1:
			x1 = !x;
			y1 = !y;
			z1 = z;
			
			break;
		case 2:
			x1 = !x;
			y1 = y;
			z1 = !z;
			
			break;
		case 3:
			x1 = !x;
			y1 = y;
			z1 = z;
			
			break;
		case 4:
			x1 = x;
			y1 = !y;
			z1 = !z;
			
			break;
		case 5:
			x1 = x;
			y1 = !y;
			z1 = z;
			
			break;
		case 6:
			x1 = x;
			y1 = y;
			z1 = !z;
			
			break;
		case 7:
			x1 = x;
			y1 = y;
			z1 = z;
			
			break;
		}
	
	//Runs AND gate
	val = functionAND(x1,y1,z1);
	
	return val;
	
}

//AND function
bool functionAND(bool x, bool y, bool z){
	bool gate;
	
	if (x == true && y == true && z == true)
	{
		gate = true;
	}
	
	else
	{
		gate = false;
	}
	
	return gate;
}	
//Or function 
bool functionOR(bool x, bool y, bool z){
	
	bool gate;
	if (x == false && y == false && z == false)
	{
		gate = false;
	}
	else
	{
		gate = true;
	}
	
	return gate;
}



string funMaxTerm(ifstream &input, int num){
	
	string maxterm;
	
	//Switch case that uses value of num from input file and sets it equal to its correct maxterm string value
	switch (num) 
	{
		case 0:
			maxterm = "M0 = x + y + z";
			break;
		case 1:
			maxterm = "M1 = x + y + z'";
			break;
		case 2:
			maxterm = "M2 = x + y' + z";
			break;
		case 3:
			maxterm = "M3 = x + y' + z'";
			break;
		case 4:
			maxterm = "M4 = x' + y + z";
			break;
		case 5:
			maxterm = "M5 = x' + y + z'";
			break;
		case 6:
			maxterm = "M6 = x' + y' + z";
			break;
		case 7:
			maxterm = "M7 = x' + y' + z'";
			break;			
		}
		
	return maxterm;
}

//Overloaded maxterm functions
bool funMaxTerm(int num, bool x, bool y, bool z){
	
	bool x2, y2, z2, val;
	
	//Switch case that uses value of num from input file and sets it equal to its correct maxterm string value
	switch (num) 
	{
		case 0:
			x2 = x;
			y2 = y;
			z2 = z;
			break;
		case 1:
			x2 = x;
			y2 = y;
			z2 = !z;
			break;
		case 2:
			x2 = x;
			y2 = !y;
			z2 = z;
			break;
		case 3:
			x2 = x;
			y2 = !y;
			z2 = !z;
			break;
		case 4:
			x2 = !x;
			y2 = y;
			z2 = z;
			break;
		case 5:
			x2 = !x;
			y2 = y;
			z2 = !z;
			break;
		case 6:
			x2 = !x;
			y2 = !y;
			z2 = z;
			break;
		case 7:
			x2 = !x;
			y2 = !y;
			z2 = !z;
			break;			
		}
	
	val = functionOR(x2, y2, z2);
	
	return val;
}

//Truth table
void truthTable(ofstream &output, int num, bool minOrMax){
	output << "X\ty\tz\tf(x,y,z)" << endl;
	output << "--------------------------------" << endl;
	
	bool x, y, z, f, f2;
	
	//This for loop will set x, y, and z to 0 or 1 and will then run the correct 
	//AND or OR function depending of if the gate is true or false
	for (int i=0; i<=1; i++)
	{
		for (int j=0; j<=1; j++)
		{
			for (int k=0; k<=1; k++)
			{
				x = i;
				y = j;
				z = k;
				
				//First prints minterm truth table then goes into else in main when minOrmax value is changed
				if(minOrMax == true) 
				{
					f = functionAND(x,y,z);
					int val = funMinTerm(num, x, y, z);
					output << x << "\t" << y << "\t" << z << "\t" << val << "\t" << endl;
				} 
				else 
				{
					f2 = functionOR(x,y,z);
					int val2 = funMaxTerm(num, x, y, z);	
					output << x << "\t" << y << "\t" << z << "\t" << val2 << "\t" << endl;
				}

			}
		}
	}
				
}


