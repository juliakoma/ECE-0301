#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>

using namespace std;

class SortableArray
{
	//Prototypes of private and public variables of class
	private:
		double* array;
		unsigned int size;
		void splittingFun(double* presplit, double* postsplit, unsigned int start, unsigned int end);
		void complete_merge();

	public:
		SortableArray();
		SortableArray(unsigned int numElements);
		~SortableArray();
		double* getArray() const;
		unsigned int getSize() const;
		void initalize();
		void writeToFile(ofstream &output, bool choice);
		void merge(double* premerge, double* postmerge, unsigned int start, unsigned int midpoint, unsigned int end);
		void randomNum();
};

#endif


