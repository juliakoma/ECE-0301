#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	
	//Step 2
	//Reads input file 
	ifstream file1;
	file1.open("divider_wheatstone_circuits.txt");
	
	//Reads first line of input file	
	string firstLine;
	file1 >> firstLine;
	
	double Vs, Is;
	int R1, R2, R3, R4, R5;
		
	//If statement to detect what the first word is
	if (firstLine == "Divider" || firstLine == "Wheatstone"){
		//Step 3
		//If statement runs if first word is divider
		if (firstLine == "Divider"){
			file1 >> Vs >> R1 >> R2;
			file1.close();
			//Creates output file
			ofstream file2;
			file2.open("divider_wheatstone_solutions.txt");
			
			//Prints values and calculations to the output file				
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
			
			file2 << "Loop current: I = " << loopCurrent << " Amperes." << endl;
			file2 << "Resistor voltage: V1 = " << R1Voltage << " Volts." << endl;
			file2 << "Resistor voltage: V2 = " << R2Voltage << " Volts." << endl;
				
			file2.close();
		}
		//Else statement runs if first word is Wheatstone
		else {
			//Reads in values from value
			file1 >> Vs >> Is >> R1 >> R2 >> R3 >> R4 >> R5;
			file1.close();
			
			double test1, test2;
			test1 = Vs - (Is)*(R4);
			test2 = Vs + (Is)*(R5);
			
			//Creates output file to store calculations
			ofstream file2;
			file2.open("divider_wheatstone_solutions.txt");

			file2 << "ECE 0301: Circuit Solver for Voltage Divider " << endl;
			file2 << "and Wheatstone bridge example circuits." << endl;
			file2 << "-----" << endl;		
			file2 << "Circuit #1 (Voltage Divider)" << endl;
			file2 << "---" << endl;
			file2 << "Source voltage: Vs = " << Vs << " Volts." << endl;
			file2 << "Source current: Is = " << Is << " Amperes." << endl;
			file2 << "Resistor: R1 = " << R1 << " Ohms." << endl;
			file2 << "Resistor: R2 = " << R2 << " Ohms." << endl;
			file2 << "Resistor: R3 = " << R3 << " Ohms." << endl;
			file2 << "Resistor: R4 = " << R4 << " Ohms." << endl;
			file2 << "Resistor: R5 = " << R5 << " Ohms." << endl << endl;
			
			double V1, V2, V3, V4, V5, I1, I2, I3, I4, I5;
			double a, b, c, d, e, f, w, x, y, z;
			
			//If statment to test that values are not equal to zero
			if (R2 != 0 && R3 != 0 && test1 != 0 && test2 != 0){
				
				//Uses formulas to create variables
				a = (1 + (static_cast<double>(R4)/static_cast<double>(R2)));
				b = (Vs) - ((Is)*static_cast<double>(R4));
				c = (1 + (static_cast<double>(R5)/static_cast<double>(R3)));
				d = Vs + ((Is)*static_cast<double>(R5));
				e = static_cast<double>(R1) / static_cast<double>(R2);
				f =	static_cast<double>(R1) / static_cast<double>(R3);
				
				w = ((a+e)/b);
				x = (f/b);
				y = (e/d);
				z = (c+f)/d;
				
				//Uses general equations to then solve for voltages and currents at each resistor
				V3 = (y-w)/((x*y) - (w*z));
				V2 = (1 - (x*V3))/w;
				V1 = (e*V2) + (f*V3);
				V4 = Vs - V1 - V2;
				V5 = Vs - V1 - V3;
				
				I1 = (V1)/(R1);
				I2 = (V2)/(R2);
				I3 = (V3)/(R3);
				I4 = (V4)/(R4);
				I5 = (V5)/(R5);
			
				//Prints values of calulations to the output file
				file2 << "Resistor voltage: V1 = " << V1 << " Volts." << endl;
				file2 << "Resistor current: I1 = " << I1 << " Amperes." << endl;
				file2 << "Resistor voltage: V2 = " << V2 << " Volts." << endl;
				file2 << "Resistor current: I2 = " << I2 << " Amperes." << endl;
				file2 << "Resistor voltage: V3 = " << V3 << " Volts." << endl;
				file2 << "Resistor current: I3 = " << I3 << " Amperes." << endl;
				file2 << "Resistor voltage: V4 = " << V4 << " Volts." << endl;
				file2 << "Resistor current: I4 = " << I4 << " Amperes." << endl;
				file2 << "Resistor voltage: V5 = " << V5 << " Volts." << endl;
				file2 << "Resistor current: I5 = " << I5 << " Amperes." << endl;
			}
			//Error statment prints if the values are equal to zero
			else{
				cout << "ERROR! Unstable floating-point division.";
				return -1;
			}
		}
	}
	//Error statement prints if first word is not Divider or Wheatstone
	else {
		cout << "ERROR! Invalid header.";
		return -1;
	}
	return 0;
}

