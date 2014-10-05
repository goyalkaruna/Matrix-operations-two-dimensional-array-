/*
 * testMatrixType.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: ksru
 */

#include "testMatrixType.h"
#include "matrixType.h"
#include <iostream>
using namespace std;

int main(){
int rows, cols,x;

matrixType h,k,sum,sub,mul;
cout<<"Karuna Goyal Assignment Hw3"<<endl;
//Input Values from the user
cout << "Enter the number of rows and columns of Matrix A";
cin >> rows >> cols;
cout<<"MATRIX"<<rows<<"*"<<cols<<endl;
h=matrixType(rows,cols);
h.setMatrix();

cout << "Enter the number of rows and columns of Matrix B";
cin >> rows >> cols;
cout<<"Matrix"<<rows<<"*"<<cols<<endl;
k=matrixType(rows,cols);
k.setMatrix();
//Input for selecting Addition, Subtraction and Multiplication
do{
   cout<<"Enter 1. Addition."<<endl;
   cout<<"2. Subtraction."<<endl;
   cout<<"3. Multiplication."<<endl;

   cin>>x;

   switch(x){

   case 1:
	   if (h.equal(k)){
		   sum= h+k;
	   }else{
		   cout<<"Addition is not possible\n";
	   }
	   break;
   case 2:
	   if (h.equal(k)){
		   sub=h-k;
	   }else{
		   cout<<"Subtraction is not possible\n";
	   }
	   break;

   case 3:
	   if(h.equate(k)){
		   mul=h*k;
	   }else
		   cout<<"Multiplication is not possible\n";
	   break;

   default:
	   cout<<"Give valid input please\n";
	   break;
   }
}while(x>0);
   return 0;
}
