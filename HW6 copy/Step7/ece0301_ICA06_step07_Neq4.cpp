#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>

using namespace std;
const int DIM = 4;

//Prototypes
int funRead(ifstream &infile, double A[DIM][DIM],double b[DIM]);
void matrix(ofstream &output, double A[][DIM], double b[], int N);

int main()
{
	ofstream output;
	output.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	output << "ECE 0301 - Matrix-Vector Computations, " << endl << "Determinants and Cramer's Rule." << endl << endl;
	output << "Global array dimension: DIM = " << DIM << endl;
		
	ifstream infile;
	infile.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	//Creates variables for matrices
	double A[DIM][DIM], b[DIM];
	
	//Calls funRead function
	int N = funRead(infile, A, b);

	output << "Input file: N = " << N << endl;
	
	//Calls the printing of matrix function
	matrix(output, A,b,N);	
	
	output.close();

}

int funRead(ifstream &infile, double A[][DIM], double b[]){
	string firstLine[24], secondLine[5],thirdLine[4];
	int N;
	
	getline(infile, firstLine[23],'\n');		//Reads first line of file and stops when a new line is next
	getline(infile, secondLine[4],'\n');		//Reads second line of file and stops when new line is made
	
	string test1, test2, test3;
	test1 = "ECE 0301: Ax = b Problem";			//Creates test strings to use in error check
	test2 = "N = ";
	test3 = "A = ";
	
	int pos1 = secondLine[4].find("N = ");				//Finding where the = is in the line and sets only "N = " to result
	string result1 = secondLine[4].substr(pos1, 4);
		
	int pos2 = secondLine[4].find("=");					//Finds where the = sign is and then reads the number after it to store as N
	string value = secondLine[4].substr(pos2 + 1);
		
	if ((firstLine[23] != test1) && (result1 != test2))		//Error checks that first and second line are correct
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}

	N = stoi(value);		//Converts string to value of N and returns to main
	
	if (N != DIM)				// Error checks if N is equal to DIM
	{
		cout << "ERROR! Dimension mismatch, N != DIM.";
		return -1;
	}
	
	getline(infile, thirdLine[3], '\n');				//Gets third line which is A =
	
	int pos3 = thirdLine[3].find("A = ");		
	string result2 = thirdLine[3].substr(pos3, 4);
	
	
	if (result2 != test3)								//Error checking that the line is equal to A =
	{
		cout << "ERROR! Input file format error.";
		return -1;
	}
	
	string array1;
	
	for (int i = 0; i < N; i++)				//For loop that reads in the next N^2 values and assigns them to A[][]
	{
		for (int j = 0; j < N; j++)
		{
			getline(infile, array1);
			A[i][j] = stod(array1);
		}
	}
	
	string fourthLine[5];						//Gets "b = " line
	getline(infile, fourthLine[4],'\n');
		
	int pos4 = fourthLine[4].find("b = ");
	string result3 = fourthLine[4].substr(pos4, 4);
	string test4 = "b = ";
	
	if (result3 != test4)			//Error checks that line is equal to "b = "
	{
		cout << "ERROR! Input file formate error.";
		return -1;
	}
	
	string array2;
			
	for (int k = 0; k < N; k++){			//For loop that stores b values into b[]
		getline(infile, array2);
		b[k] = stod(array2);
	}

	return N;
}

void matrix(ofstream &output, double A[][DIM], double b[], int N){
	
	output << endl << "A = " << endl;
	
	for (int i = 0; i < N; i++)					//For loops that prints matrix A to the output file
	{
		output << "[ ";
		for (int j = 0; j < N; j++)
		{
			output << setw(10) << A[i][j];
		}
		output << " ]" << endl;
	}
	
	output << endl << "b = " << endl;
	
	for (int k = 0; k < N; k++)					//For loop that prints matrix b to the output file
	{
		output << "[ " << setw(10) << b[k] << " ]" << endl;
	}
}
