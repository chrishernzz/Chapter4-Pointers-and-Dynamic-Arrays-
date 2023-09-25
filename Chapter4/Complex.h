#pragma once
#include<iostream>
#include<string>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);

//precondition: going to create a class that has 2 pointers
//postcondition: going to then return the realNumber and imaginaryNumber, allocate and deallocate memory as well
class Complex{
private: 
	double *realNumber, *imaginaryNumber;
public:
	//default constructor
	Complex();
	//deconstructor to delete memory
	~Complex();

	//getters(accesors)
	double getRealNumber() const;
	double getImaginaryNumber() const;
	//setters(mutators)
	void setRealNumber(double newRealNumber);
	void setImaginaryNumber(double newImaginaryNumber);

	//member function that is going to get the display information (formula for formula compelx)
	void getFormulaInformation();
	//member function that gets me the negated formula answer
	void getNegatedComplexNumber() const;

	//member function that has my information
	void displayInformation();

	//overloading operators  +, -, *, /
	friend double operator+(const Complex& obj1, double value);
	friend double operator-(const Complex& obj1, double value);
	friend double operator*(const Complex& obj1, double value);
	friend double  operator/(const Complex& obj1, double value);

	//overloading operators for 2 objects and overloading operators  ==,!=,+,-,*,/
	friend bool operator==(const Complex& obj1, const Complex& obj2);
	friend bool operator!=(const Complex& obj1, const Complex& obj2);
	friend string operator+(const Complex& obj1, const Complex& obj2);
	friend string operator-(const Complex& obj1, const Complex& obj2);
	friend string operator*(const Complex& obj1, const Complex& obj2);
	friend string operator/(const Complex& obj1, const Complex& obj2);
	
};

