#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <array>
#include <vector>

using namespace std;
const int DIM = 3;

//Prototypes
int funRead(ifstream &infile, double A[DIM][DIM],double b[DIM]);
void matrix(ofstream &output, double A[][DIM], double b[], int N, int X[], double Ax[], double C[][DIM], int column, double solution[DIM]);
void matrixMulti(double A[][DIM], double solution[], double Ax[]);
void matrix(double A[][DIM], int n, ofstream &output);
void copy(double A[][DIM], double C[][DIM], int i, int j, int n);
double recursive(double A[][DIM], int N);
void copyColumns(double A[][DIM], double b[], double C[][DIM], int N, int column);
double determinant2(double C[][DIM], double A[][DIM], int N);

int main()
{
	ofstream output;
	output.open("ECE0301_ICA06_Axeqb_solution.txt");
	
	output << "ECE 0301 - Matrix-Vector Computations, " << endl << "Determinants and Cramer's Rule." << endl << endl;
	output << "Global array dimension: DIM = " << DIM << endl;
		
	ifstream infile;
	infile.open("ECE0301_ICA06_Axeqb_problem.txt");
	
	//Creates variables for matrices
	double A[DIM][DIM], b[DIM], subMatrix[DIM][DIM], Ax[DIM], C[DIM][DIM], newA[DIM][DIM];
	int X[DIM];
	
	//Calls funRead function
	int N = funRead(infile, A, b);
	output << "Input file: N = " << N << endl << endl;
	
	int column = 0;
	
	double solution[DIM];

	//For loop that creates the solution matrix by dividing the two determinants
	for(int i = 0; i < N; i++)
	{
		//Calls function that changes columns
		copyColumns(A, b, C, N, column);
		solution[i] = (recursive(C, N)) / (recursive(A, N));
		column++;
	}
	
	//Calls matrix multiplication function to check solution
	matrixMulti(A, solution, Ax);
	
	//Finally calls matrix function which prints everything to output
	matrix(output, A, b, N, X, Ax, C, column, solution);	
	
	output.close();
	infile.close();

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

void matrix(ofstream &output, double A[][DIM], double b[], int N, int X[], double Ax[], double C[][DIM], int column, double solution[DIM]){
	
	output << "A = " << endl;
	
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
	
	output << endl << "Problem: A * x = b" << endl;
	
	//Switch case that will print correct symbols in correct rows	
	switch(N){
		case 2:
			for (int i = 0; i < N; i++)					//For loops that prints matrix A * x = b to the output file
			{
				output << "[ ";
		
				for (int j = 0; j < N; j++)
				{
					output << setw(10) << A[i][j];
				}
		
				if (i == 0)
				{
					output << " ] * [ " << "x" << i << " ] = [ " << setw(10) << b[i] << " ]" << endl;
				}
		
				else
				{
					output << " ]   [ "<< "x" << i << " ]   [ " << setw(10) << b[i] << " ]" << endl;
				}
			}
		case 3:
		case 4:
			for (int i = 0; i < N; i++)					//For loops that prints matrix A * x = b to the output file
			{
				output << "[ ";
		
				for (int j = 0; j < N; j++)
				{
					output << setw(10) << A[i][j];
				}
		
				if (i == 1)
				{
					output << " ] * [ " << "x" << i << " ] = [ " << setw(10) << b[i] << " ]" << endl;
				}
		
				else
				{
					output << " ]   [ "<< "x" << i << " ]   [ " << setw(10) << b[i] << " ]" << endl;
				}
			}	
			break;
		case 5:
			for (int i = 0; i < N; i++)					//For loops that prints matrix A * x = b to the output file
			{
				output << "[ ";
		
				for (int j = 0; j < N; j++)
				{
					output << setw(10) << A[i][j];
				}
		
				if (i == 2)
				{
					output << " ] * [ " << "x" << i << " ] = [ " << setw(10) << b[i] << " ]" << endl;
				}
		
				else
				{
					output << " ]   [ "<< "x" << i << " ]   [ " << setw(10) << b[i] << " ]" << endl;
				}
			}
	
	}
	output << endl << "Solution: x = " << endl;
	
	//Same for loop in main except this one prints the solution to output
	for(int i = 0; i < N; i++)
	{
		output << "[ " << setw(10) << solution[i] << " ] " << endl;			
		column++;
	}
	
	output << endl << "Checking Solution: A * x = b" << endl;

	//Switch case that will print correct symbols in correct rows
	switch (N){
		case 2:
			for (int i = 0; i < N; i++)					//For loops that prints A * x = b to the output file
			{
				output << "[ ";
				
				for (int j = 0; j < N; j++)
				{
					output << setw(10) << A[i][j];
				}
		
				if (i == 0)
				{
					output << " ] * [ " << setw(10) << solution[i] << " ] = [ " << setw(10) << Ax[i] << " ]" << endl;
				}
		
				else
				{
					output << " ]   [ " << setw(10) << solution[i] << " ]   [ " << setw(10) << Ax[i] << " ]" << endl;
				}
			}
			break;
		case 3:
		case 4:
			for (int i = 0; i < N; i++)					//For loops that prints A * x = b to the output file
				{
				output << "[ ";
				
				for (int j = 0; j < N; j++)
				{
					output << setw(10) << A[i][j];
				}
		
				if (i == 1)
				{
					output << " ] * [ " << setw(10) << solution[i] << " ] = [ " << setw(10) << Ax[i] << " ]" << endl;
				}
		
				else
				{
					output << " ]   [ " << setw(10) << solution[i] << " ]   [ " << setw(10) << Ax[i] << " ]" << endl;
				}
			}
			break;
		case 5:
			for (int i = 0; i < N; i++)					//For loops that prints A * x = b to the output file
				{
				output << "[ ";
				
				for (int j = 0; j < N; j++)
				{
					output << setw(10) << A[i][j];
				}
		
				if (i == 2)
				{
					output << " ] * [ " << setw(10) << solution[i] << " ] = [ " << setw(10) << Ax[i] << " ]" << endl;
				}
		
				else
				{
					output << " ]   [ " << setw(10) << solution[i] << " ]   [ " << setw(10) << Ax[i] << " ]" << endl;
				}
			}
			break;
		}
	
	output << endl << "Error in RHS values: " << endl;
	
	//Finds error between b and solution I got which is Ax
	for (int e = 0; e < N; e++)
	{
		output << "[ " << setw(10) << (Ax[e] - b[e]) << " ]" << endl;
	}
	
	output << endl;
}

//Function that multiplies the matrices together: step 8
void matrixMulti(double A[][DIM], double solution[DIM], double Ax[]){
	
	double sum = 0;
	
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			sum += A[i][j]*solution[j];
		}
		
		Ax[i] = sum;
		sum = 0;
	}
}

//Creates new array to store modified matrix
void matrix(double A[][DIM], int N, ofstream &output){
		
	for (int i = 0; i < N; i++)					//For loops that prints new matrix A to the output file
	{
		output << "[ ";
		for (int j = 0; j < N; j++)
		{
			output << setw(10) << A[i][j];
		}
		output << " ]" << endl;
	}
}

//This is step 11
void copy(double A[][DIM], double C[][DIM], int i, int j, int n){
	
	int x = 0, y = 0;
	
	for (int k = 0; k < n + 1; k++)				////function that creates the correct matrix and only writes first n rows and columns	
	{
		if (k == i)
		{
			continue;
		}
		y = 0;
		for (int m = 0; m < n + 1; m++)
		{
			if (m != j)
			{
				C[x][y] = A[k][m];
				y++ ;
			}
		}
		x++;
	}
}

//Step 12:
//This creates the recursive function to solve for the determinant
double recursive(double A[][DIM], int N){
	
	double det1 = 0;
	
	//I used a switch case to sort for numbers 1 and 2 and then used a loop for anything else
	switch (N){
		case 1:
			det1 = A[0][0];
			break;
			
		case 2:
			det1 = (A[0][0] * A[1][1] - A[0][1]*A[1][0]);
			break;
			
		default:
			double subMatrix[DIM][DIM];
			
			for (int j = 0; j < N; j++)
			{
				copy(A, subMatrix, 0, j, N);
				det1 += A[0][j] * (recursive(subMatrix, N - 1) * pow(-1, j));
			}
		}
	
	return det1;
}

void copyColumns(double A[][DIM], double b[], double C[][DIM], int N, int column){
	
	for (int i = 0; i < N; i++)				//This is the function that changes the selected column of A with b
	{
		for (int j = 0; j < N; j++)
		{
			if (j == column)
			{
				C[i][j] = b[i];
			}
			else
			{
				C[i][j] = A[i][j];
			}
		}
	}
}


	
