#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//precondition:
//postcondition:
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


	//overloading operators  +, -, *, /
	friend double operator+(const Complex& obj1, double value);
	friend double operator-(const Complex& obj1, double value);
	friend double operator*(const Complex& obj1, double value);
	friend double  operator/(const Complex& obj1, double value);
};

