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
	void merge(double* premerge, double* postmerge, unsigned int bck, unsigned int grey_red, unsigned int blu)
	{
		//Initalizing pointers
		double* black = premerge + bck;
		double* gray = black + grey_red;
		double* red = black + grey_red;
		double* blue = premerge + blu;
		double* green = postmerge + bck;
		
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

	//Writes the unsorted array to the output file
	bool x = false;
	Array1.writeToFile(output, x);
	
	//Creates second instance
	SortableArray Array2(Array1.getSize());

	//Initalizing new locations for the pointers
	unsigned int bck = 2;
	unsigned int grey_red = 4;
	unsigned int blu = 11;
	
	
	//Creating second array
	Array1.merge(Array1.getArray(), Array2.getArray(), bck, grey_red, blu);
	
	//Printing sorted array to the output file
	bool y = true;
	Array2.writeToFile(output, y);
	
	output.close();
	infile.close();
	
}










