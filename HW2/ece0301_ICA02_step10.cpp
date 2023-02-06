#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Step 1
	cout << "ECE 0301 Propositional Logic Example" << endl << endl;
	
	//Step 2: Creating variables and displaying them to screen
	string p1 = "Pigs can fly.", p2 = "Earth is flat.", p3 = "The moon is cheese.";
	
	cout << "P1: " << p1 << endl; 
	cout << "P2: " << p2 << endl;
	cout << "P3: " << p3 << endl << endl;
	
	//Step 3: Asking user to enter values for P1, P2, and P3
	bool userP1, userP2, userP3;
	
	cout << "Enter P1 truth value: ";
	cin >> userP1;
	
	cout << "Enter P2 truth value: ";
	cin >> userP2;
	
	cout << "Enter P3 truth value: ";
	cin >> userP3;
	
	//Step 4: Displaying the users input to the screen and changing the 0/1 to true and false
	cout << boolalpha << endl << "You entered: P1 = " << userP1 << ", P2 = " << userP2 << ", P3 = " << userP3 << "." << endl << endl;
	
	//Step 5: Outputting the truth table with boolean variables
	bool p4 = userP1 && !userP2 && userP3;
	
	cout << "Truth table:" << endl << "Proposition\t" << "Truth Value" << endl;
	cout << "-----------\t-----------" << endl;
	cout << "P1\t\t" << userP1 << endl;
	cout << "P2\t\t" << userP2 << endl;
	cout << "P3\t\t" << userP3 << endl;
	cout << "P4\t\t" << p4 << endl;
	
	//Step 6: creating variable when pigs cannot fly, or earth is flat or moon is cheese
	bool p5 = !userP1 || userP2 || userP3;

	cout << "P5\t\t" << p5 << endl;

	//Step 7: creating variable where only one variable is true and rest are false
	bool p6 = userP1 + userP2 + userP3 == 1;
	cout << "P6\t\t" << p6 << endl;
	
	//Step 8: creating variable where all variables are false
	bool p7 = !userP1 && !userP2 && !userP3;
	cout << "P7\t\t" << p7 << endl;
	
	//Step 9: creating variable where a majority of variables are true
	bool p8 = userP1 + userP2 + userP3 > 1;
	cout << "P8\t\t" << p8 << endl;

	//Step 10: creating variable where pigs can't fly and Earth is flat or moon is cheese (but not both)
	bool p9 = !userP1 && ((!userP2 && userP3) || (userP2 && !userP3));
	cout << "P9\t\t" << p9;

	
	return 0;
}

