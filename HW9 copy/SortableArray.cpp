#include "SortableArray.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>

using namespace std;

void SortableArray::splittingFun(double* presplit, double* postsplit, unsigned int start, unsigned int end)
	{
		unsigned int midpoint;
		
		//Checking if second integer is one more than the first integer
		if (end - start == 1)
		{
			return;
		}

		//Calculating midpoint
		midpoint = (start + end) / 2; 
		
		//Recursively calling split for first half of the data array
		splittingFun(postsplit, presplit, start, midpoint);
		
		//Recursively calling split for the second half of the data array
		splittingFun(postsplit, presplit, midpoint, end);
		
		//Calling merge function
		merge(presplit, postsplit, start, midpoint, end);
	}
	
void SortableArray::complete_merge()
	{	
		//First pointer set to the original array
		double* data_array = getArray();
		
		//Object of class with same elements as original array
		SortableArray working_array(getSize());
		
		//Second pointer
		double* working_pointer = working_array.getArray();
		
		//Loop that copies data from the object and sets it equal to the working array
		for (int i = 0; i < getSize(); i++)
		{
			*working_pointer = *data_array;
			working_pointer++;
			data_array++;
		}
		
		unsigned int start = 0;
		unsigned int end = getSize();
		
		//Calls splitting function 
		splittingFun(working_array.getArray(), getArray(), start, end);
		
	}


SortableArray::SortableArray()
	{
		size = 10;
		array = new double[size];
		initalize();
	}

	//Step 2
SortableArray::SortableArray(unsigned int numElements)
	{
		size = numElements;
		array = new double[size];
		initalize();
	}

SortableArray::~SortableArray()
	{
		delete[] array;
	}

	//Returns array
double* SortableArray::getArray() const
	{
		return array;
	}

	//Gets size of Array
unsigned int SortableArray::getSize() const
	{
		return size;
	}

	//Initalizes array of zeros
void SortableArray::initalize()
	{
		for (unsigned int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
	}

	//Prints both the unsorted and sorted array to output file 
void SortableArray::writeToFile(ofstream &output, bool choice)
	{
		if (choice == false)
		{
			output << "ECE 0301 - Sorting Arrays" << endl;
			output << "Unsorted Array: " << endl;
			for (unsigned int i = 0; i < size; i++)
			{
				output << array[i] << endl;
			}
		}
		if (choice == true)
		{
			complete_merge();
			
			output << "Sorted Array:" << endl;
			for (unsigned int i = 0; i < size; i++)
			{
				output << array[i] << endl;
			}
		}
	}
	
	//Step 3: Function that merges the arrays together
void SortableArray::merge(double* premerge, double* postmerge, unsigned int start, unsigned int midpoint, unsigned int end)
	{
		//Initalizing pointers
		double* black = premerge + start;
		double* gray = premerge + midpoint;
		double* red = premerge + midpoint;
		double* blue = premerge + end;
		double* green = postmerge + start;
		
		//While loops to sort through array and will set postmerge array to the sorted array
		while ((black < red) && (gray < blue))
		{
			if (*black < *gray)
			{
				*green = *black;
				black++;
			}
			else
			{
				*green = *gray;
				gray++;
			}

			green++;
		}
		
		
		while (black < red)
		{
			*green = *black;

			black++;
			green++;
		}
		
		while (gray < blue)
		{
			*green = *gray;
			gray++;
			green++;

		}
	}

//Function to create an array of pseudo random numbers
void SortableArray::randomNum()
	{
		//Converts the random numbers from int to double
		srand(static_cast<unsigned int>(time(nullptr)));
		
		for (int i = 0; i < size; i++)
		{
			double rand_01 = static_cast<double>(rand()) / RAND_MAX;
			double rand_pm1 = 2 * rand_01 - 1;
			array[i] = rand_pm1;
		}
	}


//Step 2
SortableArray readArray(ifstream &infile)
{
	//Reads array from the input file
	string firstLine;
	string num;
	getline(infile, firstLine, '\n');
	int pos1 = firstLine.find("LENGTH = ");	
	string result1 = firstLine.substr(pos1, 9);	
	string result2 = firstLine.substr(pos1 + 9);
	
	//Error checks if first line starts with LENGTH =
	if (result1 != "LENGTH = ")		
	{
		cout << "ERROR! Invalid input file header.";
		exit(0);
	}
	
	//converts size of the array from the string value
	unsigned int length;
	length = stoi(result2);
	
	SortableArray Array1(length);
	double* data = Array1.getArray();
	
	//For loop to read all values from file
	for (unsigned int i = 0; i < length; i++)
	{
		getline(infile, num); 
		data[i] = stod(num);
	}
	return Array1;
}





