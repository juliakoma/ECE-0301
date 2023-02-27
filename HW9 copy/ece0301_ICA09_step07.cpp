

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>

using namespace std;

//Creates Sortable Array class
class SortableArray
{
	//Defines private and public variables
	private:
		double* array;
		unsigned int size;
	public:

	SortableArray()
	{
		size = 10;
		array = new double[size];
		initalize();
	}

	//Step 2
	SortableArray(unsigned int numElements)
	{
		size = numElements;
		array = new double[size];
		initalize();
	}

	~SortableArray()
	{
		delete[] array;
	}

	//Returns array
	double* getArray() const
	{
		return array;
	}

	//Gets size of Array
	unsigned int getSize() const
	{
		return size;
	}

	//Initalizes array of zeros
	void initalize()
	{
		for (unsigned int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
	}

	//Prints both the unsorted and sorted array to output file 
	void writeToFile(ofstream &output, bool choice)
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
			output << "Sorted Array:" << endl;
			for (unsigned int i = 0; i < size; i++)
			{
				output << array[i] << endl;
			}
		}
	}
	
	//Step 3: Function that merges the arrays together
	void merge(double* premerge, double* postmerge, unsigned int start, unsigned int midpoint, unsigned int end)
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
	
	void splittingFun(double* presplit, double* postsplit, unsigned int start, unsigned int end)
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
	
	void complete_merge()
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
	
};

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


int main()
{
	ofstream output;
	ifstream infile;
	
	infile.open("ece0301_unsorted_array.txt");
	output.open("ece0301_merge_sort_results.txt");
	
	//Creates first instance of class
	SortableArray Array1 = readArray(infile);

	//Writes the original unsorted array to the output file
	bool x = false;
	Array1.writeToFile(output, x);

	//Calling complete merge function
	Array1.complete_merge();

	//Prints sorted array to output file
	bool y = true;
	Array1.writeToFile(output, y);
	
	output.close();
	infile.close();
	
}

