/*
 * matrixType.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: ksru
 */

#include "matrixType.h"
#include<iostream>
using namespace std;
//Default Constructor to Intialize private members of class
matrixType::matrixType() {

	this->rowSize = 0;
	this->colSize = 0;
	this->matrix=0;

}
//Parameterized Constructor  which performs deep copy of class member variables
//Purpose:- To Store the input into the object of class
//Pre-condition :- Class object is initialized to zero by the default constructor
//Post-condition:- Object is initialized with the parameters
matrixType::matrixType(int rowSize1, int colSize1) {
	cout<<"In Parameterized Constructor";
	this->rowSize = rowSize1;
	this->colSize = colSize1;
	matrix=new int*[rowSize];
	for(int i = 0 ; i < rowSize ; i++ )
		matrix[i] = new int [colSize];
}
//Copy constructor  which performs deep copy of class member variables
//Purpose:- To run before any operations on matrices
//Pre-condition :- Resultant matrix is zero
//Post-condition:- We get the resultant Matrix
matrixType::matrixType(const matrixType &matrix2) {
	cout<<"In copy Constructor";
	rowSize = matrix2.rowSize;
	colSize = matrix2.colSize;
	matrix = matrix2.matrix;
}
//Overload outStream << operator
//Purpose:- To show output on screen
ostream& operator<<(ostream&osobj, const matrixType &mat)
{
	cout << "matrix is::" << endl;
	for (int i = 0; i < mat.rowSize; i++)
	{
		for (int j = 0; j < mat.colSize; j++)
		{
			osobj  << mat.matrix[i][j];

		}
		cout << endl;

	}
	return osobj;
}
//Overload instream operator
//Purpose:- To take the input from user

istream& operator>>(istream&isobj, const matrixType &matin)
{
	for (int i = 0; i < matin.rowSize; i++)
	{
		for (int j = 0; j < matin.colSize; j++)
		{
			isobj >> matin.matrix[i][j];
		}

	}
	return isobj;
}

// member function setMatrix() to read matrix elements from console and initialize
//Purpose:- To read the values of matrices and set them inobject
void matrixType::setMatrix() {
	int c, d;

	cout << "\nEnter the elements of matrix\n";

	for (c = 0; c < rowSize; c++)
		for (d = 0; d < colSize; d++) {
			cin>>this->matrix[c][d];
		}
	cout << "\n\nMatrix :\n\n";
	for (c = 0; c < rowSize; c++) {
		for (d = 0; d < colSize; d++) {
			cout <<"\t"<<this->matrix[c][d];
		}
		cout <<"\n\n";
	}
}
//Equal member function to compare the row and column size of matrices for addition and subtraction
bool matrixType::equal(matrixType &h){
	if (this->rowSize==h.rowSize && this->colSize==h.colSize)

		return true;
	else
		return false;
}
//Equate member function to compare the row and column size of matrices for Multiplication
bool matrixType::equate(matrixType &h){
	if (this->colSize==h.rowSize)

		return true;
	else
		return false;
}
//Overloading Assignment Operator
//Purpose:- To perform assigning operations between the objects of class
void matrixType:: operator=(const matrixType &matrix2) const
{
	cout <<"Assign";

	for (int i= 0;i <matrix2.rowSize; i++)
	{
		for (int j = 0;j< matrix2.colSize;j++)
		{
			matrix2.matrix[i][j]=matrix[i][j];
		}
	}

}
//Overloading Addition Operator
//Purpose:- To perform addition of two objects
//Pre-condition :- Two class objects of matrixType
//Post-condition:- Output Object that is the sum of two objects
matrixType matrixType:: operator+(const matrixType &matrix2) const
{
	cout <<"Add";
	matrixType matrixSum(rowSize,colSize);
	for (int i= 0;i <matrix2.rowSize; i++)
	{
		for (int j = 0;j< matrix2.colSize;j++)
		{
			matrixSum.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
		}
	}
	cout << "\n\nMatrix :\n\n";
	for (int c = 0; c < rowSize; c++) {
		for (int d = 0; d < colSize; d++) {
			cout <<"\t"<<matrixSum.matrix[c][d];
		}
		cout <<"\n\n";
	}
	return matrixSum;
}
//Overloading subtraction operator
//Purpose:- To perform subtraction of two objects
//Pre-condition :- Two class objects of matrixType
//Post-condition:- Output Object that is the subtraction of two objects
matrixType matrixType:: operator-(const matrixType &matrix2) const
{
	cout <<"Subtract";
	matrixType matrixSum(rowSize,colSize);
	for (int i= 0;i <matrix2.rowSize; i++)
	{
		for (int j = 0;j< matrix2.colSize;j++)
		{
			matrixSum.matrix[i][j] = matrix[i][j] - matrix2.matrix[i][j];
		}
	}
	cout << "\n\nMatrix :\n\n";
	for (int c = 0; c < rowSize; c++) {
		for (int d = 0; d < colSize; d++) {
			cout <<"\t"<<matrixSum.matrix[c][d];
		}
		cout <<"\n\n";
	}
	return matrixSum;
}
//Overloading Multiplication Operator
//Purpose:- To perform multiplication of two objects
//Pre-condition :- Two class objects of matrixType
//Post-condition:- Output Object that is the multiplication of two input objects
matrixType matrixType:: operator*(const matrixType &matrix2) const
{
	cout <<"Multiplication";
	matrixType matrixM(rowSize,colSize);
	for (int i= 0;i <this->rowSize; i++)
	{
		for (int k = 0;k< matrix2.colSize;k++)
		{
			matrixM.matrix[i][k]=0;
			for (int j=0;j<matrix2.rowSize;j++){
				matrixM.matrix[i][k] = matrix[i][j] * matrix2.matrix[j][k];
			}
		}
	}
	cout << "\n\nMatrix :\n\n";
	for (int c = 0; c < rowSize; c++) {
		for (int d = 0; d < colSize; d++) {
			cout <<"\t"<<matrixM.matrix[c][d];
		}
		cout <<"\n\n";
	}
	return matrixM;
}
//destructor which properly removes any resources and deallocates memory
//Purpose:- To empty the memory used , to make it avaible again
//Pre-condition:- Objects are present in memory
//Post-condition:- Memory is empty after removing resources
matrixType::~matrixType(){
	for (int i = 0; i < rowSize; i++)
		delete[] matrix[i];
	    delete[] matrix;
}
