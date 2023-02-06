#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//Prototypes
bool functionOR(bool, bool, bool);
void truthTable(ofstream &output, bool gate);
bool functionAND(bool x, bool y, bool z);

int main()
{

	//Step 2
	//Start by creating an output file to send all print statements to
	ofstream output;
	output.open("Bool_func_3var_CSOP_CPOS.txt");
	
	output << "ECE 0301: Boolean Functions of 3 Variables." << endl;
	output << "Realization in Canonical Forms." << endl << endl;
	
	bool gate;
	//This starts the program by going to the truth table function
	//I immediately set a bool = 0 so it will run the or gate function within the truth table
	gate = 0;
	output << "Truth table for OR gate." << endl << endl;
	truthTable(output, false);
	
	//Then this changes the bool to 1 where then the and function will be accessed
	gate = 1;
	output << endl << "Truth table for AND gate." << endl << endl;
	truthTable(output, true);
}

//Or function 
bool functionOR(bool x, bool y, bool z){
	
	bool f;
	if (x == false && y == false && z == false)
	{
		return f = false;
	}
	else
	{
		return f = true;
	}
}

//Truth table
void truthTable(ofstream &output, bool gate){
	output << "X\ty\tz\tf(x,y,z)" << endl;
	output << "--------------------------------" << endl;
	
	bool x, y, z, f;
	
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
				
				if (gate == true)
				{
					f = functionAND(x,y,z);
					
					output << x << "\t" << y << "\t" << z << "\t" << f << "\t" << endl;
				}
				else
				{
					f = functionOR(x,y,z);
				
					output << x << "\t" << y << "\t" << z << "\t" << f << "\t" << endl;
				}
			}
		}
	}	
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
	
	
