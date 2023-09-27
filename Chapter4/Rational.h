#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int startRange, int endRange);
int inputInteger(string prompt);
double inputDouble(string prompt);

//precondition: going to create the class that has the information of rational, then in public create the ZeroDenominato class
//postcondition: going to create a constructor for both class, gcd and normalize function, accessors, mutators, overloading operators to use
class Rational {
private:
	int numerator;
	int denominator;
	int gcd(int a, int b);

public:
	//default constructor
	Rational();
	Rational(int, int);
	//constructor
	//friends copy
	Rational(const Rational&);

	string toString();
	//getters(accesors)
	int getNumerator() const;
	int getDenominator() const;

	void normalize();
	//setters(mutators)
	void setNumerator(int);
	void setDenominator(int);
	void negate(Rational&);

	//overloaidng operators for one object
	const Rational operator =(const Rational&);
	friend Rational operator +(const Rational& obj, const int number);
	friend Rational operator +(const int number, const Rational& obj);
	friend Rational operator -(const int number, const Rational& obj);
	friend Rational operator -(const Rational& obj, const int number);
	friend Rational operator *(const Rational& obj, const int number);
	friend Rational operator *(const int number, const Rational& obj);
	friend Rational operator /(const Rational& obj, const int number);
	friend Rational operator /(const int number, const Rational& obj);

	//overloading two objects 
	friend Rational operator *(const Rational& obj1, const Rational& obj2);
	friend Rational operator /(const Rational& obj1, const Rational& obj2);
	friend Rational operator +(const Rational& obj1, const Rational& obj2);
	friend Rational operator -(const Rational& obj1, const Rational& obj2);
	friend bool operator !=(const Rational& obj1, const Rational& obj2);
	friend bool operator ==(const Rational& obj1, const Rational& obj2);
	friend bool operator <(const Rational& obj1, const Rational& obj2);
	friend bool operator >(const Rational& obj1, const Rational& obj2);
	friend bool operator >=(const Rational& obj1, const Rational& obj2);
	friend bool operator <=(const Rational& obj1, const Rational& obj2);
	//cout overloading object
	friend ostream& operator << (ostream& out, Rational obj);

	//memberfunction to display
	void RationalOptionB();
	void RationalOptionA();
	void RationalMenu();
};

