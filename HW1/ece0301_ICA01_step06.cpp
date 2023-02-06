#include <iostream>
using namespace std;

int main()
{
	cout << "ECE 0301 DC Resistive Circuit Simulation" << endl << "Modeled after www.falstad.com/circuit/" << endl << "Circuits -> Basics -> Ohm's Law" << endl;
	
	//Part 2
	double Vs = 120, R1 = 10, R2 = 15;
		
	cout << "Vs = " << Vs << " Volts" << endl;
	cout << "R1 = " << R1 << " Ohms" << endl << "R2 = " << R2 << " Ohms" << endl;
	
	//Part 3: Solving for current and power of each resisitor
	double I1,I2,P1,P2;
	
	I1 = Vs / R1;
	I2 = Vs / R2;
	P1 = I1*Vs;
	P2 = I2*Vs;
	
	cout << "I1 = " << I1 << " Amperes" << endl << "P1 = " << P1 << " Watts" << endl;
	cout << "I2 = " << I2 << " Amperes" << endl << "P2 = " << P2 << " Watts" << endl;

	//Part 4:Using E=(P1+P2)*t to solve for the total energy of each time increment

	double energy1sec, energy1hour, energy1day, energy1year;

	energy1sec = (P1 + P2) * 1;
	energy1hour = (P1 + P2) * 3600;
	energy1day = energy1hour * 24;
	energy1year = energy1day * 365;
	
	cout << "Energy supplied in one second = " << energy1sec << " Joules" << endl;
	cout << "Energy supplied in one hour = " << energy1hour << " Joules" << endl;
	cout << "Energy supplied in one day = " << energy1day << " Joules" << endl;
	cout << "Energy supplied in one year = " << energy1year << " Joules" << endl;

	//Part 5: Converting all variables from Joules to kWh and then multiplying by the fixed cost 

	double fixedCost, costSec, costHour, costDay, costYear;
	
	fixedCost = 0.10;
	costSec = (energy1sec / (1000*3600)) * fixedCost;
	costHour = (energy1hour / (1000*3600)) * fixedCost;
	costDay = (energy1day / (1000*3600)) * fixedCost;
	costYear = (energy1year / (1000*3600)) * fixedCost;
	
	cout << "Cost of supplying energy for one second at $0.10/kWh = $" << costSec << endl;
	cout << "Cost of supplying energy for one hour at $0.10/kWh = $" << costHour << endl;
	cout << "Cost of supplying energy for one day at $0.10/kWh = $" << costDay << endl;
	cout << "Cost of supplying energy for one year at $0.10/kWh = $" << costYear << endl;

	//Part 6
	//Annual electric bill = $2102.4
	
	return 0;
}

