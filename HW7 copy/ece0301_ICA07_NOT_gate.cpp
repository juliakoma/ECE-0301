#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

//Creates class NOT with private and public variables
class NOT
{
	private:
		string inputLabel;
		bool inputValue;
	public:
		void setInputLabel(string);
		void setInputValue(bool);
		string getInputLabel() const;
		bool getInputValue() const;
		string getOutputLabel() const;
		bool getOutputValue() const;
};

//Sets input label to label
void NOT::setInputLabel(string label)
{
	inputLabel = label;
}

//Sets input value to value
void NOT::setInputValue(bool value)
{
   inputValue = value;
}

//Returns input label when called
string NOT::getInputLabel() const
{
   return inputLabel;
}

//Returns input value when called
bool NOT::getInputValue() const
{
   return inputValue;
}

//Returns input label with _not added to end
string NOT::getOutputLabel() const
{
	return inputLabel + "_not";
}

//Returns opposite of input value
bool NOT::getOutputValue() const
{
	return !inputValue;
}

//main function
int main()
{
	//Creates instance of class called gate
	NOT gate;    
	string logic; 
	bool value;

	cout << "This program will simulate a not gate." << endl << "What is the label for the gate input? What is the logic value at the input (0/1)? Here are the data on the not gate:" << endl;
	cin >> logic >> value;

	//Prints all values to output
	gate.setInputLabel(logic);
	gate.setInputValue(value);

	cout << "Input label: " << gate.getInputLabel() << endl;
	cout << "Output label: " << gate.getOutputLabel() << endl;
	cout << "Logic value at input: " << gate.getInputValue() << endl;
	cout << "Logic value at output: " << gate.getOutputValue() << endl;
   
   return 0;
}



