#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	
	//Step 2
	//Reads in input file to get values
	ifstream file1;
	file1.open("divider_wheatstone_circuits.txt");
		
	//Reads in first word from the input file
	string firstLine;
	file1 >> firstLine;
	
	double Vs, Is, n;
	int R1, R2, R3, R4, R5;
	
	//If statement to read first word
	if (firstLine == "Divider" || firstLine == "Wheatstone"){
		//Step 3
		//If statement that runs if first word is Divider
		if (firstLine == "Divider"){
			file1 >> Vs >> R1 >> R2 >> n;
			file1.close();
			
			//Creates output file to store values
			ofstream file2;
			file2.open("divider_wheatstone_solutions.txt");
						
			//Prints to output file		
			file2 << "ECE 0301: Circuit Solver for Voltage Divider " << endl;
			file2 << "and Wheatstone bridge example circuits." << endl;
			file2 << "-----" << endl;
			file2 << "Circuit #1 (Voltage Divider)" << endl;
			
			int MODR2 = R2;
			int MODR1 = R1;
			double loopCurrent, R1Voltage, R2Voltage;
			
			//For statement that increases i
			for(int i = 0; i < n; i++) {
				//resets R2
				R2 = MODR2;
				
				//For statement that increases j and prints the values of R1 and R2
				for(int j = 0; j < n; j++) {
					loopCurrent = (Vs) / (R1 + R2);
					R1Voltage = (loopCurrent)*(R1);
					R2Voltage = (loopCurrent)*(R2);

					file2 << "---" << endl;					
					file2 << "Source voltage: Vs = " << Vs << " Volts." << endl;
					file2 << "Resistor: R1 = " << R1 << " Ohms." << endl;
					file2 << "Resistor: R2 = " << R2 << " Ohms." << endl << endl;
					
					file2 << "Loop current: I = " << loopCurrent << " Amperes." << endl;
					file2 << "Resistor voltage: V1 = " << R1Voltage << " Volts." << endl;
					file2 << "Resistor voltage: V2 = " << R2Voltage << " Volts." << endl;
					
					//This increments R2
					R2 = R2 + MODR2;
				}
				
				//Increments R1
				R1 = R1 + MODR1;
			}
			file2.close();
		}
		else {
			//Reads values from file and stores them in respective variables
			file1 >> Vs >> Is >> R1 >> R2 >> R3 >> R4 >> R5 >> n;
			file1.close();
			
			double test1, test2;
			test1 = Vs - (Is)*(R4);
			test2 = Vs + (Is)*(R5);
			
			//Creates output file to send values to
			ofstream file2;
			file2.open("divider_wheatstone_solutions.txt");
			
			//Prints statements to output
			file2 << "ECE 0301: Circuit Solver for Voltage Divider " << endl;
			file2 << "and Wheatstone bridge example circuits." << endl;
			file2 << "-----" << endl;		
			file2 << "Circuit #1 (Wheatstone Bridge)" << endl;
			
			double V1, V2, V3, V4, V5, I1, I2, I3, I4, I5;
			double a, b, c, d, e, f, w, x, y, z;
			
			//First testing if conditions are true
			if (R2 != 0 && R3 != 0 && test1 != 0 && test2 != 0){
				
				
				int MODR1, MODR2, MODR3, MODR4, MODR5;
				
				//Creating incrementing variables
				MODR1 = R1;
				MODR2 = R2;
				MODR3 = R3;
				MODR4 = R4;
				MODR5 = R5;
				
				//Each for loop increases a value of a variable
				//At the end of each for loop value of respective R is increased
				//At the beginning of each for loop each value is reset to its original value
				for(int i = 0; i < n; i++) {
					R2 = MODR2;
					for(int j = 0; j < n; j++) {
						R3 = MODR3;
						for(int k = 0; k < n; k++) {
							R4 = MODR4;
							for(int l = 0; l < n; l++) {
								R5 = MODR5;
								for(int m = 0; m < n; m++) {
									//Calculations for current and voltage
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
									
									//Prints values to output file
									file2 << "---" << endl;
									file2 << "Source voltage: Vs = " << Vs << " Volts." << endl;
									file2 << "Source current: Is = " << Is << " Amperes." << endl;
									file2 << "Resistor: R1 = " << R1 << " Ohms." << endl;
									file2 << "Resistor: R2 = " << R2 << " Ohms." << endl;
									file2 << "Resistor: R3 = " << R3 << " Ohms." << endl;
									file2 << "Resistor: R4 = " << R4 << " Ohms." << endl;
									file2 << "Resistor: R5 = " << R5 << " Ohms." << endl << endl;
			
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

									R5 = MODR5 + R5;
									}
									R4 = MODR4 + R4;
								}
								R3 = MODR3 + R3;
							}
							R2 = MODR2 + R2;
						}
						R1 = MODR1 + R1;
	
					}

			}
			//Else statement that is run when test cases are not met and return to main with value of -1
			else{
				cout << "ERROR! Unstable floating-point division.";
				return -1;
			}
		}
	}
	//Else statment that runs when divider or wheatstone is not the first line of the input file
 	else {
		cout << "ERROR! Invalid header.";
		return -1;
	}
	return 0;
}


