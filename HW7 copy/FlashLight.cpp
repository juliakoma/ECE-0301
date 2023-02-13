#include "FlashLight.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

//Sets flashlight private variables to a value
FlashLight::FlashLight()
{
	batteryVoltage = 3;
	bulbResistance = 100;
	switchState = 1;
}

FlashLight::FlashLight(double batteryVoltage, double bulbResistance, bool switchState)
{
	this->batteryVoltage = batteryVoltage;
	this->bulbResistance = bulbResistance;
	this->switchState = switchState;
}

	//Sets battery voltage = voltage
	void FlashLight::setBatteryVoltage(double voltage)
	{
		batteryVoltage = voltage;
	}

	//Sets bulbResistance to resistance
	void FlashLight::setBulbResistance(double resistance)
	{
		bulbResistance = resistance;
	}

	//Creates the opposite of switch state
	void FlashLight::toggleSwitch()
	{
		switchState = !switchState;
	}

	//Returns bulbResistance when called
	double FlashLight::getBulbResistance() const
	{
		return bulbResistance;
	}

	//Returns switchState when called
	bool FlashLight::getSwitchState() const
	{
		return switchState;
	}

	//Returns 0 if switchstate = 1 otherwise calculates current and returns value
	double FlashLight::getBulbCurrent() const
	{
		if(switchState==1){
			return 0;
		}
		return batteryVoltage / bulbResistance;
	}	
	
	//Returns 0 if switchstate = 1 otherwise calculates power and returns value
	double FlashLight::getBulbPower() const
	{
		if(switchState==1){
			return 0;
		}
		return getBulbCurrent() * batteryVoltage;
	}
	
	//Prints all information to output
	void FlashLight::printInfo() const
	{
		cout << "Here are the data on the FlashLight:" << endl;

		cout << "The battery voltage is " << batteryVoltage << " Volts." << endl;
		cout << "The bulb resistance is " << bulbResistance << " Ohms." << endl;
		
		if (switchState == 0){
			cout << "The switch is closed." << endl;
			cout << "The FlashLight is on." << endl;
		}
		else 
		{
			cout << "The switch is open. " << endl;
			cout << "The FlashLight is off." << endl;
		}
		
		if (switchState == 0)
		{
			cout << "The bulb current is 0 Amperes." << endl;
			cout << "The bulb power is " << getBulbPower() << endl;
		}
		else
		{
			cout << "The bulb current is " << getBulbCurrent() << " Amperes." << endl;
			cout << "The bulb power is " << getBulbPower() << " Watts." << endl;
		}
	}

