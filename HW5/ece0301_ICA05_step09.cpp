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
void truthTable(ofstream &output, int num);
string funMaxTerm(ifstream &input, int num);
bool funMaxTerm(int num, bool x, bool y, bool z);
string funCSOP(ifstream &input, int num);
bool funCSOP(int num, bool x, bool y, bool z);


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
	if (num >= 0 && num <= 255)
	{
		output << "ECE 0301: Boolean Functions of 3 Variables." << endl;
		output << "Realization in Canonical Forms." << endl << endl;
		
		//Runs function minterm
		string CSOP;
		CSOP = funCSOP(input, num);
		
		if (num != 0){
		output << "CSOP: f" << num << " = " << CSOP << endl << endl;
		}
		else {
		output << "CSOP: f0 = 0" << endl << endl;
		}			
		truthTable(output, num);
		
		output << endl;

	}
	//Else statement entered if number is not between 0 and 7
	else
	{
		cout << "ERROR! Function index out of range.";
	}
	
	output.close();
}

string funCSOP(ifstream &input, int num){
	
	string CSOP;
	
	int bit[8];
	int i = 0;
	
	for (i = 0; i < 8; ++i) {
		bit[i] = (num >> i) & 1;
	}
	
	for(int i = 7; i >= 0; i--) {
			switch(i) {
				case 0:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 7) + " + ";
						}
					break;
				case 1:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 6)+ " + ";
						}
					break;
				case 2:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 5)+ " + ";
						}
					break;
				case 3:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 4)+ " + ";

						}
					break;
				case 4:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 3)+ " + ";						
							
							}
					break;
				case 5:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 2)+ " + ";
						}
					break;
				case 6:
					if(bit[i] == 1) {
							CSOP = CSOP + funMinTerm(input, 1)+ " + ";
						}
					break;
				
				case 7:
					if(bit[i] == 1) 
					{
						CSOP = CSOP + funMinTerm(input, 0)+ " + ";
					}
					break;	
				}
				
		}
	CSOP.pop_back();
	CSOP.pop_back();
	CSOP.pop_back();

	return CSOP;
}


bool funCSOP(int num, bool x, bool y, bool z) {
	
	
		//bool truth = false;
		bool truth = false;
		bool val;
		
		int bit[8];
		int i = 0;
	
		for (i = 0; i < 8; i++) {
			bit[i] = (num >> i) % 2;
		}		
		
		for (int i = 0; i < 8; i++){
			if (bit[i] == 1){
			  	val = funMinTerm(7-i, x, y, z);
			  	truth = val || truth;
			}
	}
	
	return truth;
}


string funMinTerm(ifstream &input, int num) {
	
	string minterm;
	
	//Switch case that uses value of num from input file and sets it equal to its correct minterm string value
	switch (num) 
	{
		case 0:
			minterm = "x'y'z'";
			break;
		case 1:
			minterm = "x'y'z";
			break;
		case 2:
			minterm = "x'yz'";
			break;
		case 3:
			minterm = "x'yz";
			break;
		case 4:
			minterm = "xy'z'";
			break;
		case 5:
			minterm = "xy'z";
			break;
		case 6:
			minterm = "xyz'";
			break;
		case 7:
			minterm = "xyz";
			break;			
		}
		
	return minterm;
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

//Truth table
void truthTable(ofstream &output, int num){
	output << "Truth table for CSOP form of function " << num << "." << endl << endl;

	output << "X\ty\tz\tf(x,y,z)" << endl;
	output << "--------------------------------" << endl;
	bool x, y, z;
	
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
				
				bool val = funCSOP(num, x, y, z);
				output << x << "\t" << y << "\t" << z << "\t" << val << "\t" << endl;
			}
		}
	}
				
}



