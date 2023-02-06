#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	
	//Step 2
	//Opens input file to read from
	ifstream file1;
	file1.open("divider_wheatstone_circuits.txt");
	
	//Reads first line of the file
	string firstLine;
	file1 >> firstLine;
	
	double Vs;
	int R1, R2;
	
	//Checks whether first line is Divider or Wheatstone
	if (firstLine == "Divider"){
		//Step 3
		if (firstLine == "Divider"){
			//If first line is divider, the code reads in the first line 
			file1 >> Vs >> R1 >> R2;
			file1.close();
			//Creates output file where solutions will be sent to
			ofstream file2;
			file2.open("divider_wheatstone_solutions.txt");
							
			//Prints values and statements to file 	
			file2 << "ECE 0301: Circuit Solver for Voltage Divider " << endl;
			file2 << "and Wheatstone bridge example circuits." << endl;
			file2 << "-----" << endl;
			file2 << "Circuit #1 (Voltage Divider)" << endl;
			file2 << "---" << endl;
			file2 << "Source voltage: Vs = " << Vs << " Volts." << endl;
			file2 << "Resistor: R1 = " << R1 << " Ohms." << endl;
			file2 << "Resistor: R2 = " << R2 << " Ohms." << endl << endl;
				
			double loopCurrent, R1Voltage, R2Voltage;
			loopCurrent = (Vs) / (R1 + R2);
			R1Voltage = (loopCurrent)*(R1);
			R2Voltage = (loopCurrent)*(R2);
			
			//Takes calculated values and prints them to the file
			file2 << "Loop current: I = " << loopCurrent << " Amperes." << endl;
			file2 << "Resistor voltage: V1 = " << R1Voltage << " Volts." << endl;
			file2 << "Resistor voltage: V2 = " << R2Voltage << " Volts." << endl;
				
			file2.close();
		}
	}
	//If first word is not divider then the error statement prints to the terminal, nothing is printed to the file
	else {
		cout << "ERROR! Invalid header.";
		return -1;
	}
	return 0;
}

