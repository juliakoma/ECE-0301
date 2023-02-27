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
	void merge(double* premerge, double* postmerge, unsigned int index)
	{
		//Initalizing pointers
		double* black = premerge;
		double* gray = black + index;
		double* red = black + index;
		double* blue = premerge + size;
		double* green = postmerge;
		
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
	string firstLine;
	string num;
	getline(infile, firstLine, '\n');
	int pos1 = firstLine.find("LENGTH = ");	
	string result1 = firstLine.substr(pos1, 9);	
	string result2 = firstLine.substr(pos1 + 9);
	
	if (result1 != "LENGTH = ")		
	{
		cout << "ERROR! Invalid input file header.";
		exit(0);
	}
	
	unsigned int length;
	length = stoi(result2);
	
	SortableArray Array1(length);
	double* data = Array1.getArray();
	
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

	unsigned int index;
	
	//Finds size of index based on whether the array is even or odd
	if ((Array1.getSize() % 2) == 0)
	{
		index = ((Array1.getSize())/2) + 1;
	}
	else
	{
		index = ((Array1.getSize())/2) ;
	}
		
	//creates the second array using merge function
	Array1.merge(Array1.getArray(), Array2.getArray(), index);
	
	bool y = true;
	Array2.writeToFile(output, y);
	
	output.close();
	infile.close();
	
}








