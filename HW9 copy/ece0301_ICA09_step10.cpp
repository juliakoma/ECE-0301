#include "SortableArray.h"
//#include "SortableArray.cpp"

int main()
{
	ofstream output;
	output.open("ece0301_merge_sort_results.txt");
	
	//Creates instance of class with 256 elements
	SortableArray Array1(256);
	//Fills the array with pseudo random numbers
	Array1.randomNum();

	//Writes the original unsorted array to the output file
	bool x = false;
	Array1.writeToFile(output, x);

	//Prints sorted array to output file
	bool y = true;
	Array1.writeToFile(output, y);
	
	output.close();
}

