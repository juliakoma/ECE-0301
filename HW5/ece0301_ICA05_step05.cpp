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
string funMinTerm(ifstream &input, int num);
string funMaxTerm(ifstream &input, int num);

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
		output << minterm << endl;
		
		//Runs function maxterm
		string maxterm = funMaxTerm(input, num);
		output << maxterm << endl;
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
