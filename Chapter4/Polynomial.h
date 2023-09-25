#pragma once
#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);

//precondition: going to creat a class that gets me the coefficients 
//postcondition: going to be using a pointer, then allocate and deallocate so memory does not leak
class Polynomial{
private:
	double* coefficients;
	int termSize;

public:
	//defualt constructor
	Polynomial();
	//constructor
	Polynomial(double* coeff, int size);
	//deconstructor
	~Polynomial();
	
	//getters(accesors)
	double getCoefficients(double* coeff, int theTermSize) const;
	//setters(mutators
	void setCoefficients(double* coeff, int theTermSize);
	
	//member function to display the information
	void display() const;

	//member function that gets me the total coeffiecnts and then adds them
	void displayP1X() const;
	//member function that returns the evaluate of the plolynomial
	double getEvaluatePolyNomial(double *coeff, int theTermSize, double value) const;

	//member function that gets me the polynomial derivative 
	void displayPolynomialDerivative() const;
	//member function that gets me the integral 
	void displayPolynomialIntegral() const;

	//member function to display the first polynomial
	void displayFirstPolynomial() const;
	//member function to display the second polynomial
	void displaySecondPolynomial() const;

	//overloading operators +,-,*
	friend double operator+(const Polynomial& obj1, const Polynomial& obj2);
	friend double operator-(const Polynomial& obj1, const Polynomial& obj2);


	//member function that gets all the information and menus 
	void displayInformationMenu();
};

