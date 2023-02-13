#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

//Defining the class with private and public variables
class FlashLight
{
	private:
		double batteryVoltage;
		double bulbResistance;
		bool switchState;
	public:
		FlashLight();
		FlashLight(double batteryVoltage, double bulbResistance, bool switchState);
		void setBatteryVoltage(double batteryVoltage);
		void setBulbResistance(double bulbResistance);
		void toggleSwitch();
		double getBatteryVoltage() const;
		double getBulbResistance() const;
		bool getSwitchState() const;
		double getBulbCurrent() const;
		double getBulbPower() const;
		void printInfo() const;
};

#endif
