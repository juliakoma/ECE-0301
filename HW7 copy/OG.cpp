#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

class FlashLight
{
	private:
		double batteryVoltage;
		double bulbResistance;
		bool switchState;
	public:
		FlashLight()
		{
			batteryVoltage = 3.0;
			bulbResistance = 100.0;
			switchState = false;
		}
		
	void setBatteryVoltage(double voltage)
	{
		batteryVoltage = voltage;
	}

	void setBulbResistance(double resistance)
	{
		bulbResistance = resistance;
	}

	void toggleSwitch()
	{
		switchState = !switchState;
	}

	double getBulbResistance() const
	{
		return bulbResistance;
	}

	bool getSwitchState() const
	{
		return switchState;
	}

	double getBulbCurrent() const
	{
		return batteryVoltage / bulbResistance;
	}	
	
	double getBulbPower() const
	{
		return getBulbCurrent() * batteryVoltage;
	}
	
	void printInfo() const
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
			cout << "The bulb power is 0 Watts." << endl;
		}
		else
		{
			cout << "The bulb current is " << getBulbCurrent() << " Amperes." << endl;
			cout << "The bulb power is " << getBulbPower() << " Watts." << endl;
		}
	}
};

int main()
{
	FlashLight flashLight;    

	flashLight.printInfo();
	
	int userChoice;
	do {
		cout << "Select an option: " << endl;
		cout << "1. Change the battery voltage" << endl;
		cout << "2. Change the bulb resistance" << endl;
		cout << "3. Toggle the switch state" << endl;
		cout << "4. Exit the program" << endl;
		cin >> userChoice;
		
        switch (userChoice) {
            case 1: 
            {
                double newBatteryVoltage;
                cout << "Enter the new battery voltage:" << endl;
                cin >> newBatteryVoltage;
                flashLight.setBatteryVoltage(newBatteryVoltage);
                flashLight.printInfo();

                break;
            }
            case 2: 
            {
                double newBulbResistance = 0;
                cout << "Enter the new bulb resistance:" << endl;	
                flashLight.setBulbResistance(newBulbResistance);
                flashLight.printInfo();

			}
			case 3:
			{
				flashLight.toggleSwitch();
				flashLight.printInfo();

			}
			case 4:
			{
				return -1;
			}
		}
	}while (userChoice >= 1 && userChoice <= 4);
				
	
   return 0;
}



