#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

//Creates class Complex with private and public variables
class Complex
{
	private:
		double real;
		double imaginary;
	public:
		void setReal(double);
		void setImagine(double);
		double getReal() const;
		double getImagine() const;
		double getMag() const;
		double getAngle() const;
};

//Sets r to real number
void Complex::setReal(double r)
{
	real = r;
}

//Sets imaginary number to i
void Complex::setImagine(double i)
{
   imaginary = i;
}

//returns real value
double Complex::getReal() const
{
   return real;
}

//Returns imaginary number
double Complex::getImagine() const
{
   return imaginary;
}

//Calculates magnitude of numbers
double Complex::getMag() const
{
   return sqrt(pow(real, 2) + pow(imaginary, 2));
}

//Calculates angle of numbers
double Complex::getAngle() const
{
	return atan2(imaginary,real);
	
}

//main function
int main()
{
	//Creates num as an instance of the class
	Complex num;    
	double numReal; 
	double numImagine;

	cout << "This program will calculate the magnitude and phase" << endl << "angle of a complex number." << endl << endl;
   cout << "What is the real part? What is the imaginary part? Here are the data on complex number z:" << endl;
   cin >> numReal >> numImagine;

	//Calls all functions with user inputted values
   num.setReal(numReal);
   num.setImagine(numImagine);
     cout << "Real Part: " << num.getReal() << endl;
   cout << "Imaginary part: " << num.getImagine() << endl;
   cout << "Magnitude: " << num.getMag() << endl;
   cout << "Phase angle (radians): " << num.getAngle() << endl;
   
   return 0;
}



