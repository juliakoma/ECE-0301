#include <iostream>
#include "FlashLight.h"
//#include "FlashLight.cpp"

int main()
{
	//Creates instance of the class called flashLight
	FlashLight flashLight;    

	//Starts by printing all information
	flashLight.printInfo();
	
	int userChoice;
	//do while loop that asks user what value they would like to change
	do {
		cout << "What would you like to do with the FlashLight? " << endl;
		cout << "(1) Change the battery voltage" << endl;
		cout << "(2) Change the bulb resistance" << endl;
		cout << "(3) Toggle the switch state" << endl;
		cout << "(4) Exit program" << endl;
		cout << "Your selection? " << endl;
		cin >> userChoice;
		
		//Switch case depending on user input
        switch (userChoice) {
            case 1: 
            {
                double newBatteryVoltage;
                cout << "Enter the new battery voltage:";
                cin >> newBatteryVoltage;
                flashLight.setBatteryVoltage(newBatteryVoltage);
                flashLight.printInfo();

                break;
            }
            case 2: 
            {
                double newBulbResistance;
                cout << "Enter the new bulb resistance:";	
                cin >> newBulbResistance;
                flashLight.setBulbResistance(newBulbResistance);
                flashLight.printInfo();
                
                break;

			}
			case 3:
			{
				flashLight.toggleSwitch();
				flashLight.printInfo();
				
				break;

			}
			case 4:
			{
				return -1;
				break;
			}
		}
	}while (userChoice >= 1 && userChoice <= 4);
				
	
   return 0;
}

