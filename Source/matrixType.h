/*
 * matrixType.h
 *
 *  Created on: Oct 4, 2014
 *      Author: ksru
 */

#ifndef MATRIXTYPE_H_
#define MATRIXTYPE_H_
#include<iostream>
class matrixType {
private:
	//Three private member variables
	int rowSize, colSize;
	int** matrix;
public:
	// Declarations of the member functions of class matrixType
	//Constructors
	matrixType();
	matrixType(int, int);
	matrixType(const matrixType &obj);
	//General Member functions
	void setMatrix();
	bool equal(matrixType &obj);
	bool equate(matrixType &obj);
	//overloading operators
	void operator=(const matrixType &matrix2) const;
	matrixType operator+(const matrixType &matrix2) const;
	matrixType operator-(const matrixType &matrix2) const;
	matrixType operator*(const matrixType &matrix2) const;
	friend std::ostream& operator<<(std::ostream&osobj, const matrixType &mat);
	friend std::istream& operator>>(std::istream&isobj, const matrixType &matin);
	//Destructor
	virtual ~matrixType();
};

#endif /* MATRIXTYPE_H_ */
