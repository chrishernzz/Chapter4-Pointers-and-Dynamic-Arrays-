#include "Complex.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the variables to 0.0 since they are doubles (initialize them), allocating new memory
Complex::Complex() : realNumber(new double(0.0)), imaginaryNumber(new double(0.0)) {}
//precondition: going to call my constructor
//postcondition: going to be allocating new to the a and b with realNumber and imaginaryNumber
Complex::Complex(double a, double b){
	realNumber = new double(a);
	imaginaryNumber = new double(b);
}

//precondition: going to call my deconstructor
//postcondition: going to then deallocate the memory for realNumber and imaginaryNumber
Complex::~Complex() {
	realNumber = nullptr;
	imaginaryNumber = nullptr;
	delete realNumber;
	delete imaginaryNumber;
}

//precondition: going to get the realNumber 
//postcondition: going to return the private realNumber
double Complex::getRealNumber() const {
	return *realNumber;
}
//precondition: going to get the new realNumber
//postcondition: going to set the private realNumber with the new realNumber member
void Complex::setRealNumber(double newRealNumber) {
	*realNumber = newRealNumber;
}
//precondition: going to get the imaginaryNumber 
//postcondition: going to return the private imaginaryNumber
double Complex::getImaginaryNumber() const {
	return *imaginaryNumber;
}
//precondition: going to get the new imaginaryNumber
//postcondition: going to set the private imaginaryNumber with the new imaginaryNumber member
void Complex::setImaginaryNumber(double newImaginaryNumber) {
	*imaginaryNumber = newImaginaryNumber;
}
//precondition: going to get the display informations
//postcondition: going to do if and else statements to check if there is real number or imaginary number, then return
void Complex::getFormulaInformation() {
	//if there are no real numbers or imaginary number, then 0
	if (getRealNumber() == 0 && getImaginaryNumber() == 0) {
		cout << "\n\t\t\tComplex number C1 = 0";
	}
	//else if imaginary number is 0 but there is a real number
	else if (getImaginaryNumber() == 0) {
		cout << "\n\t\t\tComplex number C1 = " << getRealNumber();
	}
	//else if real number is 0 but there is an imaginary number
	else if (getRealNumber() == 0) {
		cout << "\n\t\t\tComplex number C1 = " << getImaginaryNumber() << "i";
	}
	//else there is real number and imaginary number
	else if (getImaginaryNumber() < 0) {

		cout << "\n\t\t\tComplex number C1 = " << getRealNumber() << " - " << -(getImaginaryNumber()) << "i";
	}
	else {
		cout << "\n\t\t\tComplex number C1 = " << getRealNumber() << " + " << getImaginaryNumber() << "i";
	}

}
//precondition: going to now get the negated numbers of real number and the imaginary number
//postcondition: going to do if and else statement to check if its negated, formula is -(realnumber + imaginarynumber)
void Complex::getNegatedComplexNumber() const {
	double negatedRealNumber, negatedImaginaryNumber;
	negatedRealNumber = -(getRealNumber());
	negatedImaginaryNumber = -(getImaginaryNumber());
	//if there are no real numbers or imaginary number, then 0
	if (getRealNumber() == 0 && getImaginaryNumber() == 0) {
		cout << "\n\t\t\t-(0) = 0";
	}
	//else if imaginary number is 0, now call the negated real number
	else if (getImaginaryNumber() == 0) {
		cout << "\n\t\t\t-(" << getRealNumber() << ") = " << negatedRealNumber;
	}
	//else if real number is 0, now call the negated imaginary number
	else if (getRealNumber() == 0) {
		cout << "\n\t\t\t-(" << getImaginaryNumber() << ") = " << negatedImaginaryNumber << "i";
	}
	//else if the imaginary number is negative (less than 0) then it will negate to positive
	else if (getImaginaryNumber() < 0) {

		cout << "\n\t\t\t-(" << getRealNumber() << " - " << -(getImaginaryNumber()) << ") = " << negatedRealNumber << " + " << (negatedImaginaryNumber) << "i";
	}
	//else imaginary number is positive then it will negate to negative
	else {
		cout << "\n\t\t\t-(" << getRealNumber() << " + " << getImaginaryNumber() << ") = " << negatedRealNumber << " - " << -(negatedImaginaryNumber) << "i";
	}
}
//precondition: going to creat the menu options that lets us do what we need to do
//postcondition: going to then get the complex numbers and the multiple complex numbers, going to be using my setters and getters and overloading operators
void Complex::displayInformation() {
	system("cls");
	char option;
	int optionAComp;
	Complex c1;
	Complex multC1, multC2;
	do {
	beginning:
		cout << "\n\t\tA complex number is a number that can be expressed in the form a + b i, where a and b are real\n"
			"\t\tc1, and i represents the " << "'imaginary uni'," << " satisfying the equation i ^ 2 = -1. Because no\n"
			"\t\ttreal number satisfies this equation, i is called an imaginary number.For the complex number\n"
			"\t\ta + b i, a is called the real part and b is called the imaginary part.\n";
		cout << "\n\t\t1> - Complex c1";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\tA> A Complex Number";
		cout << "\n\t\t\tB> Multiple Complex c1";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\t0> return";
		cout << "\n\t\t" << string(82, char(205)) << "\n";
		option = inputChar("\t\t\tOption: ", (static_cast<string>("AB0")));

		switch (toupper(option)) {
		case 'A': {
			do {
				system("cls");
				cout << "\n\t\tA> - A Complex Number";
				cout << "\n\t\t" << string(82, char(205));
				cout << "\n\t\t\t1. Enter the real number";
				cout << "\n\t\t\t2. Enter the imaginary number";
				cout << "\n\t\t\t3. Display the complex number";
				cout << "\n\t\t\t4. Negate the complex number";
				cout << "\n\t\t\t5. Add (+) the complex number with a constant";
				cout << "\n\t\t\t6. Subtract (-) the complex number with a constant";
				cout << "\n\t\t\t7. Multiply (*) the complex number with a constant";
				cout << "\n\t\t\t8. Divide (/) the complex number with a constant";
				cout << "\n\t\t" << string(82, char(205));
				cout << "\n\t\t\t0. return";
				cout << "\n\t\t" << string(82, char(205));
				optionAComp = inputInteger("\n\t\t\tOption: ", 0, 8);

				switch (optionAComp) {
				case 1: {
					c1.setRealNumber(inputDouble("\n\t\t\tEnter a number (double value) for the real part: "));
					cout << "\n";
					system("pause");
					system("cls");
				}
					  break;
				case 2: {
					c1.setImaginaryNumber(inputDouble("\n\t\t\tEnter a number (double value) for the imaginary part: "));
					cout << "\n";
					system("pause");
					system("cls");
				}
					  break;
				case 3: {
					c1.getFormulaInformation();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 4: {
					cout << "\n\t\t\tNegated the complexx number C2 (a copy of C1)\n";
					c1.getNegatedComplexNumber();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 5: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					cout << "\n\t\t\tC2 + value";
					if (number2 == 0) {
						if (c1.getRealNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") + " << number2 << " = " << c1 + number2;
							cout << "\n\n\t\t\tvalue + C2";
							cout << "\n\t\t\t" << number2 << " + (" << c1.getRealNumber() << ") = " << c1 + number2;
						}
						else if (c1.getImaginaryNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) + " << number2 << " = " << c1.getImaginaryNumber() << "i";
							cout << "\n\n\t\t\tvalue + C2";
							cout << "\n\t\t\t" << number2 << " + (" << c1.getImaginaryNumber() << "i) = " << c1.getImaginaryNumber() << "i";
						}
						else {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") + " << number2 << " = " << c1 + number2;
							cout << "\n\n\t\t\tvalue + C2";
							cout << "\n\t\t\t" << number2 << " + (" << c1.getRealNumber() << ") = " << c1 + number2;
						}
					}
					else if (c1.getRealNumber() == 0 && c1.getImaginaryNumber() != 0) {
						cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) + " << number2 << " = " << number2 << " + " << c1.getImaginaryNumber() << "i";
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t" << number2 << " + (" << c1.getImaginaryNumber() << "i) = " << number2 << " + " << c1.getImaginaryNumber() << "i";
					}
					else if (c1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << ") + " << number2 << " = " << c1 + number2;
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t" << number2 << " + (" << c1.getRealNumber() << ") = " << c1 + number2;
					}
					else if (c1.getImaginaryNumber() < 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) + " << number2 << " = " << c1 + number2 << " - " << -(c1.getImaginaryNumber()) << "i";
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t" << number2 << " + (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << c1 + number2 << " - " << -(c1.getImaginaryNumber()) << "i";
					}
					else {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) + " << number2 << " = " << c1 + number2 << " + " << c1.getImaginaryNumber() << "i";
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t" << number2 << " + (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << c1 + number2 << " + " << c1.getImaginaryNumber() << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 6: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					cout << "\n\t\t\tR2 - value";
					if (number2 == 0) {
						if (c1.getRealNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") - " << number2 << " = " << c1 - number2;
							cout << "\n\n\t\t\tvalue - R2";
							cout << "\n\t\t\t" << number2 << " - (" << c1.getRealNumber() << ") = " << -(c1 - number2);
						}
						else if (c1.getImaginaryNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) - " << number2 << " = " << c1.getImaginaryNumber() << "i";
							cout << "\n\n\t\t\tvalue - R2";
							cout << "\n\t\t\t" << number2 << " - (" << c1.getImaginaryNumber() << "i) = " << c1.getImaginaryNumber() << "i";
						}
						else {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") - " << number2 << " = " << c1 - number2;
							cout << "\n\n\t\t\tvalue - R2";
							cout << "\n\t\t\t" << number2 << " - (" << c1.getRealNumber() << ") = " << c1 - number2;
						}
					}
					else if (c1.getRealNumber() == 0 && c1.getImaginaryNumber() != 0) {
						if (number2 > 0 || number2 < 0) {
							cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) - " << number2 << " = " << -number2 << " + " << c1.getImaginaryNumber() << "i";
							cout << "\n\n\t\t\tvalue - R2";
							cout << "\n\t\t\t" << number2 << " - (" << c1.getImaginaryNumber() << "i) = " << number2 << " + " << c1.getImaginaryNumber() << "i";
						}
					}
					else if (c1.getImaginaryNumber() == 0) {
						if (c1.getRealNumber() == 0) {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") - " << number2 << " = " << c1 - number2;
							cout << "\n\n\t\t\tvalue - R2";
							cout << "\n\t\t\t" << number2 << " - (" << c1.getRealNumber() << ") = " << c1 - (-number2);
						}
						else {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") - " << number2 << " = " << c1 - number2;
							cout << "\n\n\t\t\tvalue - R2";
							cout << "\n\t\t\t" << number2 << " - (" << c1.getRealNumber() << ") = " << -(c1 - number2);
						}
					}
					else if (c1.getImaginaryNumber() < 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) - " << number2 << " = " << c1 - number2 << " - " << -(c1.getImaginaryNumber()) << "i";
						cout << "\n\n\t\t\tvalue - R2";
						cout << "\n\t\t\t" << number2 << " - (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << -(c1 - number2) << " - " << -(c1.getImaginaryNumber()) << "i";
					}
					else {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) - " << number2 << " = " << c1 - number2 << " + " << c1.getImaginaryNumber() << "i";
						cout << "\n\n\t\t\tvalue - R2";
						cout << "\n\t\t\t" << number2 << " - (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << -(c1 - number2) << " + " << c1.getImaginaryNumber() << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 7: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					cout << "\n\t\t\tC2 * value";
					if (number2 == 0) {
						if (c1.getRealNumber() != 0 && c1.getImaginaryNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) * " << number2 << " = " << abs(number2);
							cout << "\n\n\t\t\tvalue * C2";
							cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << abs(number2);
						}
						else if (c1.getRealNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") * " << number2 << " = " << abs(c1 * number2);
							cout << "\n\n\t\t\tvalue - C2";
							cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << ") = " << abs(c1 * number2);
						}
						else if (c1.getImaginaryNumber() != 0) {
							cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) * " << number2 << " = " << abs(c1.getImaginaryNumber() * number2) << "i";
							cout << "\n\n\t\t\tvalue - C2";
							cout << "\n\t\t\t" << number2 << " * (" << c1.getImaginaryNumber() << "i) = " << abs(c1.getImaginaryNumber() * number2) << "i";
						}
						else {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") * " << number2 << " = " << abs(c1 * number2);
							cout << "\n\n\t\t\tvalue - C2";
							cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << ") = " << abs(c1 * number2);
						}
					}
					else if (c1.getRealNumber() == 0 && c1.getImaginaryNumber() != 0) {
						cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) * " << number2 << " = " << c1.getImaginaryNumber() * number2 << "i";
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << c1.getImaginaryNumber() << "i) = " << c1.getImaginaryNumber() * number2 << "i";
					}
					else if (c1.getRealNumber() == 0 || c1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << ") * " << number2 << " = " << c1 * number2;
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << ") = " << c1 * number2;
					}
					else if (c1.getImaginaryNumber() < 0 && number2 < 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) * " << number2 << " = " << c1 * number2 << " + " << (c1.getImaginaryNumber() * number2) << "i";
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << c1 * number2 << " + " << (c1.getImaginaryNumber() * number2) << "i";
					}
					else if (c1.getImaginaryNumber() > 0 && number2 < 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) * " << number2 << " = " << c1 * number2 << " - " << (c1.getImaginaryNumber() * -number2) << "i";
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << c1 * number2 << " - " << (c1.getImaginaryNumber() * -number2) << "i";
					}
					else if (c1.getImaginaryNumber() < 0 && number2 > 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) * " << number2 << " = " << c1 * number2 << " - " << (c1.getImaginaryNumber() * -number2) << "i";
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << c1 * number2 << " - " << (c1.getImaginaryNumber() * -number2) << "i";
					}
					else {
						cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) * " << number2 << " = " << c1 * number2 << " + " << -(c1.getImaginaryNumber() * -number2) << "i";
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i)" << " = " << c1 * number2 << " + " << -(c1.getImaginaryNumber() * -number2) << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 8: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					if (number2 == 0) {
						cout << "\n\t\t\tValue input cannot be set to 0, Cannot divide by 0, try again.\n";
						system("pause");
						system("cls");
						break;
					}
					cout << "\n\t\t\tC2 / value";
					if (c1.getRealNumber() == 0 && c1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\t(" << c1.getRealNumber() << ") / " << number2 << " = " << abs(c1 / number2);
						cout << "\n\n\t\t\tvalue / C2";
						cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << ") = " << number2 / c1.getRealNumber();
					}
					else if (c1.getRealNumber() != 0 && c1.getImaginaryNumber() == 0) {
						if (number2 < 0) {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") / " << number2 << " = " << c1 / number2;
							cout << "\n\n\t\t\tvalue / C2";
							cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << ") = " << number2 / c1.getRealNumber() << " - infi";
						}
						else {
							cout << "\n\t\t\t(" << c1.getRealNumber() << ") / " << number2 << " = " << c1 / number2;
							cout << "\n\n\t\t\tvalue / C2";
							cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << ") = " << number2 / c1.getRealNumber() << " + infi";
						}
					}
					else if (c1.getRealNumber() == 0 && c1.getImaginaryNumber() != 0) {
						if (number2 < 0) {
							if (c1.getImaginaryNumber() > 0) {
								cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1.getImaginaryNumber() / number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getImaginaryNumber() << "i) = -inf - " << abs(number2 / c1.getImaginaryNumber()) << "i";
							}
							else {
								cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1.getImaginaryNumber() / number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getImaginaryNumber() << "i) = -inf + " << abs(number2 / c1.getImaginaryNumber()) << "i";
							}
						}
						else {
							if (c1.getImaginaryNumber() > 0) {
								cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1.getImaginaryNumber() / number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getImaginaryNumber() << "i) = inf + " << number2 / c1.getImaginaryNumber() << "i";
							}
							else {
								cout << "\n\t\t\t(" << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1.getImaginaryNumber() / number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getImaginaryNumber() << "i) = inf - " << abs(number2 / c1.getImaginaryNumber()) << "i";
							}
						}
					}
					else {
						if (number2 < 0) {
							if (c1.getImaginaryNumber() < 0) {
								cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1 / number2 << " + " << -c1.getImaginaryNumber() / -number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) = " << number2 / c1.getRealNumber() << " + " << -number2 / -c1.getImaginaryNumber() << "i";
							}
							else {
								cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1 / number2 << " - " << c1.getImaginaryNumber() / -number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) = " << number2 / c1.getRealNumber() << " - " << -number2 / c1.getImaginaryNumber() << "i";
							}
						}
						if (number2 > 0) {
							if (c1.getImaginaryNumber() < 0) {
								cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1 / number2 << " - " << -c1.getImaginaryNumber() / number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) = " << number2 / c1.getRealNumber() << " - " << number2 / -c1.getImaginaryNumber() << "i";
							}
							else {
								cout << "\n\t\t\t(" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) / " << number2 << " = " << c1 / number2 << " + " << c1.getImaginaryNumber() / number2 << "i";
								cout << "\n\n\t\t\tvalue / C2";
								cout << "\n\t\t\t" << number2 << " / (" << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i) = " << number2 / c1.getRealNumber() << " + " << number2 / c1.getImaginaryNumber() << "i";
							}
						}
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 0: {
					//delete memory so it does not leak
					c1.setRealNumber(0.0);
					c1.setImaginaryNumber(0.0);
					cout << endl;
					system("pause");
					system("cls");
					goto beginning;
				}
				}
			} while (true);
		}
				break;
		case 'B': {
			do {
				system("cls");
				cout << "\n\t\tB> - Multiple Complex Number";
				cout << "\n\t\t" << string(90, char(205));
				cout << "\n\t\t\t1. Enter complex number C1";
				cout << "\n\t\t\t2. Enter complex number C2";
				cout << "\n\t\t\t3. Verify condition operator (== and !=) of C1 and C2";
				cout << "\n\t\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2";
				cout << "\n\t\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?";
				cout << "\n\t\t" << string(90, char(205));
				cout << "\n\t\t\t0. return";
				cout << "\n\t\t" << string(90, char(205));
				optionAComp = inputInteger("\n\t\t\tOption: ", 0, 5);
				switch (optionAComp) {
				case 1: {
					multC1.setRealNumber(inputDouble("\n\t\t\tEnter a number (double value) for the real part of C1: "));
					multC1.setImaginaryNumber(inputDouble("\t\t\tEnter a number (double value) for the imaginary part of C1: "));
					if (multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tC1 = " << multC1.getRealNumber() << "\n\n";
					}
					else if (multC1.getRealNumber() == 0) {
						cout << "\n\t\t\tC1 = " << multC1.getImaginaryNumber() << "i\n\n";
					}
					else if (multC1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tC1 = " << multC1.getRealNumber() << "\n\n";
					}
					else if (multC1.getImaginaryNumber() < 0) {
						cout << "\n\t\t\tC1 = " << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i\n\n";
					}
					else {
						cout << "\n\t\t\tC1 = " << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i\n\n";
					}
					system("pause");
					system("cls");
				}
					  break;
				case 2: {
					multC2.setRealNumber(inputDouble("\n\t\t\tEnter a number (double value) for the real part of C2: "));
					multC2.setImaginaryNumber(inputDouble("\t\t\tEnter a number (double value) for the imaginary part of C2: "));
					if (multC2.getRealNumber() == 0 && multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tC2 = " << multC1.getRealNumber() << "\n\n";
					}
					else if (multC2.getRealNumber() == 0) {
						cout << "\n\t\t\tC2 = " << multC2.getImaginaryNumber() << "i\n\n";
					}
					else if (multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tC2 = " << multC2.getRealNumber() << "\n\n";
					}
					else if (multC2.getImaginaryNumber() < 0) {
						cout << "\n\t\t\tC2 = " << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i\n\n";
					}
					else {
						cout << "\n\t\t\tC2 = " << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i\n\n";
					}
					system("pause");
					system("cls");
				}
					  break;
				case 3: {
					if (multC1.getRealNumber() != 0 && multC2.getRealNumber() != 0 && multC1.getImaginaryNumber() == 0 && multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getRealNumber() << ") ? ";
						if (multC1 == multC2) {
							cout << "true";
						}
						else {
							cout << "false";
						}
						cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getRealNumber() << ") ? ";
						if (multC2 != multC1) {
							cout << "true";
						}
						else {
							cout << "false";
						}
					}
					else if (multC1.getRealNumber() != 0 && multC1.getImaginaryNumber() != 0 && multC2.getRealNumber() != 0 && multC2.getImaginaryNumber() == 0) {
						if (multC1.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) == (" << multC2.getRealNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC1.getImaginaryNumber() != 0 && multC2.getImaginaryNumber() != 0 && multC1.getRealNumber() == 0 && multC2.getRealNumber() == 0) {
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getImaginaryNumber() << "i) == (" << multC2.getImaginaryNumber() << "i) ? ";
						if (multC1 == multC2) {
							cout << "true";
						}
						else {
							cout << "false";
						}
						cout << "\n\t\t\tC2 != C1 -> (" << multC2.getImaginaryNumber() << "i) != (" << multC1.getImaginaryNumber() << "i) ? ";
						if (multC2 != multC1) {
							cout << "true";
						}
						else {
							cout << "false";
						}
					}
					else if (multC1.getRealNumber() != 0 && multC1.getImaginaryNumber() != 0 && multC2.getRealNumber() == 0 && multC2.getImaginaryNumber() != 0) {
						if (multC1.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) == (" << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) == (" << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC2.getRealNumber() != 0 && multC2.getImaginaryNumber() != 0 && multC1.getRealNumber() != 0 && multC1.getImaginaryNumber() == 0) {
						if (multC2.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) != (" << multC1.getRealNumber() << ") ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << ") ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC2.getRealNumber() != 0 && multC2.getImaginaryNumber() != 0 && multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() != 0) {
						if (multC2.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) != (" << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) != (" << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() != 0) {
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << ") ? ";
						if (multC1 == multC2) {
							cout << "true";
						}
						else {
							cout << "false";
						}
						cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getImaginaryNumber() << "i) ? ";
						if (multC2 != multC1) {
							cout << "true";
						}
						else {
							cout << "false";
						}
					}
					else if (multC1.getRealNumber() != 0 && multC1.getImaginaryNumber() == 0) {
						if (multC2.getImaginaryNumber() == 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getImaginaryNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getImaginaryNumber() << ") != (" << multC1.getRealNumber() << ") ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << ") ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC2.getRealNumber() == 0 && multC2.getImaginaryNumber() != 0) {
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getImaginaryNumber() << "i) ? ";
						if (multC1 == multC2) {
							cout << "true";
						}
						else {
							cout << "false";
						}
						cout << "\n\t\t\tC2 != C2 -> (" << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << ") ? ";
						if (multC2 != multC1) {
							cout << "true";
						}
						else {
							cout << "false";
						}
					}
					else if (multC2.getRealNumber() != 0 && multC2.getImaginaryNumber() == 0) {
						if (multC1.getImaginaryNumber() == 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getImaginaryNumber() << ") == (" << multC2.getRealNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getImaginaryNumber() << ") ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << "i) == (" << multC2.getRealNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getImaginaryNumber() << ") != (" << multC1.getRealNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC1.getRealNumber() == 0 && multC2.getRealNumber() == 0) {
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getRealNumber() << ") ? ";
						if (multC1 == multC2) {
							cout << "true";
						}
						else {
							cout << "false";
						}
						cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getRealNumber() << ") ? ";
						if (multC2 != multC1) {
							cout << "true";
						}
						else {
							cout << "false";
						}
					}
					else if (multC2.getRealNumber() == 0) {
						if (multC1.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) == (" << multC2.getRealNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << ") ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << ") != (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else if (multC1.getRealNumber() == 0) {
						if (multC2.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << ") == (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) != (" << multC1.getRealNumber() << ") ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					else {
						if (multC1.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) == (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else if (multC2.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) != (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else if (multC1.getImaginaryNumber() < 0 && multC2.getImaginaryNumber() < 0) {
							cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) == (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) != (" << multC1.getRealNumber() << " - " << abs(multC1.getImaginaryNumber()) << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
						else {
							cout << "\n\t\t\tC1 == C1 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) ? ";
							if (multC1 == multC2) {
								cout << "true";
							}
							else {
								cout << "false";
							}
							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " + " << abs((multC2.getImaginaryNumber())) << "i) != (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) ? ";
							if (multC2 != multC1) {
								cout << "true";
							}
							else {
								cout << "false";
							}
						}
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 4: {
					//overloading  operator
					if (multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tAddition       : C1 + C2 -> (" << multC1.getRealNumber() << ")";
					}
					else if (multC1.getRealNumber() == 0) {
						cout << "\n\t\t\tAddition       : C1 + C2 -> (" << multC1.getImaginaryNumber() << "i)";
					}
					else if (multC1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tAddition       : C1 + C2 -> (" << multC1.getRealNumber() << ")";
					}
					else if (multC1.getImaginaryNumber() < 0) {
						cout << "\n\t\t\tAddition       : C1 + C2 -> (" << multC1.getRealNumber() << " - " << -(multC1.getImaginaryNumber()) << "i)";
					}
					else {
						cout << "\n\t\t\tAddition       : C1 + C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i)";
					}
					cout << " + ";
					if (multC2.getRealNumber() == 0 && multC2.getImaginaryNumber() == 0) {
						cout << "(" << multC2.getRealNumber() << ") = ";
					}
					else if (multC2.getRealNumber() == 0) {
						cout << "(" << multC2.getImaginaryNumber() << "i) = ";
					}
					else if (multC2.getImaginaryNumber() == 0) {
						cout << "(" << multC2.getRealNumber() << ") = ";
					}
					else if (multC2.getImaginaryNumber() < 0) {
						cout << "(" << multC2.getRealNumber() << " - " << -(multC2.getImaginaryNumber()) << "i) = ";
					}
					else {
						cout << "(" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) = ";
					}
					if (multC1.getImaginaryNumber() + multC2.getImaginaryNumber() < 0) {
						cout << multC1.getRealNumber() + multC2.getRealNumber() << " - " << abs(multC1.getImaginaryNumber() + multC2.getImaginaryNumber()) << "i";
					}
					else {
						cout << multC1.getRealNumber() + multC2.getRealNumber() << " + " << multC1.getImaginaryNumber() + multC2.getImaginaryNumber() << "i";
					}
					if (multC1.getRealNumber() == 0 && multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tSubtraction    : C2 - C1 -> (" << multC2.getRealNumber() << ")";
					}
					else if (multC2.getRealNumber() == 0) {
						cout << "\n\t\t\tSubtraction    : C2 - C1 -> (" << multC2.getImaginaryNumber() << "i)";
					}
					else if (multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tSubtraction    : C2 - C1 -> (" << multC2.getRealNumber() << ")";
					}
					else if (multC2.getImaginaryNumber() < 0) {
						cout << "\n\t\t\tSubtraction    : C2 - C1 -> (" << multC2.getRealNumber() << " - " << -(multC2.getImaginaryNumber()) << "i)";
					}
					else {
						cout << "\n\t\t\tSubtraction    : C2 - C1 -> (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i)";
					}
					cout << " - ";
					if (multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() == 0) {
						cout << "(" << multC1.getRealNumber() << ") = ";
					}
					else if (multC1.getRealNumber() == 0) {
						cout << "(" << multC1.getImaginaryNumber() << "i) = ";
					}
					else if (multC1.getImaginaryNumber() == 0) {
						cout << "(" << multC1.getRealNumber() << ") = ";
					}
					else if (multC1.getImaginaryNumber() < 0) {
						cout << "(" << multC1.getRealNumber() << " - " << -(multC1.getImaginaryNumber()) << "i) = ";
					}
					else {
						cout << "(" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) = ";
					}
					if (multC2.getImaginaryNumber() - multC1.getImaginaryNumber() < 0) {
						cout << multC2.getRealNumber() - multC1.getRealNumber() << " - " << abs(multC2.getImaginaryNumber() - multC1.getImaginaryNumber()) << "i";
					}
					else {
						cout << multC2.getRealNumber() - multC1.getRealNumber() << " + " << multC2.getImaginaryNumber() - multC1.getImaginaryNumber() << "i";
					}
					double total = 0;
					if (multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tMultiplication : C1 * C2 -> (" << multC1.getRealNumber() << ")";
					}
					else if (multC1.getRealNumber() == 0) {
						cout << "\n\t\t\tMultiplication : C1 * C2 -> (" << multC1.getImaginaryNumber() << "i)";
					}
					else if (multC1.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tMultiplication : C1 * C2 -> (" << multC1.getRealNumber() << ")";
					}
					else if (multC1.getImaginaryNumber() < 0) {
						cout << "\n\t\t\tMultiplication : C1 * C2 -> (" << multC1.getRealNumber() << " - " << -(multC1.getImaginaryNumber()) << "i)";
					}
					else {
						cout << "\n\t\t\tMultiplication : C1 * C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i)";
					}
					cout << " * ";
					if (multC2.getRealNumber() == 0 && multC2.getImaginaryNumber() == 0) {
						cout << "(" << multC2.getRealNumber() << ") = ";
					}
					else if (multC2.getRealNumber() == 0) {
						cout << "(" << multC2.getImaginaryNumber() << "i) = ";
					}
					else if (multC2.getImaginaryNumber() == 0) {
						cout << "(" << multC2.getRealNumber() << ") = ";
					}
					else if (multC2.getImaginaryNumber() < 0) {
						cout << "(" << multC2.getRealNumber() << " - " << -(multC2.getImaginaryNumber()) << "i) = ";
					}
					else {
						cout << "(" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) = ";
					}

					total = multC1.getRealNumber() * multC2.getRealNumber();
					double total2 = multC1.getRealNumber() * multC2.getImaginaryNumber();
					double total3 = multC1.getImaginaryNumber() * multC2.getRealNumber();
					double total4 = multC1.getImaginaryNumber() * multC2.getRealNumber();
					double total5 = multC1.getImaginaryNumber() * multC2.getImaginaryNumber();
					double total6 = total + (-total5);
					double total7 = total2 + total3;
					if (total7 < 0) {

						cout << total6 << " - " << abs(total7) << "i";
					}
					else {
						cout << total6 << " + " << total7 << "i";
					}
					if (multC2.getRealNumber() == 0 && multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tDivision       : C2 / C1 -> (" << multC2.getRealNumber() << ")";
					}
					else if (multC2.getRealNumber() == 0) {
						cout << "\n\t\t\tDivision       : C2 / C1 -> (" << multC2.getImaginaryNumber() << "i)";
					}
					else if (multC2.getImaginaryNumber() == 0) {
						cout << "\n\t\t\tDivision       : C2 / C1 -> (" << multC2.getRealNumber() << ")";
					}
					else if (multC2.getImaginaryNumber() < 0) {
						cout << "\n\t\t\tDivision       : C2 / C1 -> (" << multC2.getRealNumber() << " - " << -(multC2.getImaginaryNumber()) << "i)";
					}
					else {
						cout << "\n\t\t\tDivision       : C2 / C1 -> (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i)";
					}
					cout << " / ";

					if (multC1.getRealNumber() == 0 && multC1.getImaginaryNumber() == 0) {
						cout << "(" << multC1.getRealNumber() << ") = ";
					}
					else if (multC1.getRealNumber() == 0) {
						cout << "(" << multC1.getImaginaryNumber() << "i) = ";
					}
					else if (multC1.getImaginaryNumber() == 0) {
						cout << "(" << multC1.getRealNumber() << ") = ";
					}
					else if (multC1.getImaginaryNumber() < 0) {
						cout << "(" << multC1.getRealNumber() << " - " << -(multC1.getImaginaryNumber()) << "i) = ";
					}
					else {
						cout << "(" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) = ";
					}
					double a;
					double b;
					double denominator;
					denominator = pow(multC1.getRealNumber(), 2) + pow(multC1.getImaginaryNumber(), 2);

					a = (multC1.getRealNumber() * multC2.getRealNumber()) + (-(-multC1.getImaginaryNumber() * multC2.getImaginaryNumber()));
					b = (multC1.getRealNumber() * multC2.getImaginaryNumber()) + (-multC1.getImaginaryNumber() * multC2.getRealNumber());

					a /= denominator;
					b /= denominator;
					if (b < 0) {
						cout << a << " - " << abs(b) << "i";
					}
					else {
						cout << a << " + " << b << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 5: {
					evaluteSteps(multC1, multC2);
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 0: {
					//delete memory so it does not leak
					multC1.setRealNumber(0.0);
					multC1.setImaginaryNumber(0.0);
					multC2.setRealNumber(0.0);
					multC2.setImaginaryNumber(0.0);
					cout << endl;
					system("pause");
					system("cls");
					goto beginning;
				}
				}
			} while (true);
		}
				break;
		case '0': {
			return;
		}
		} 
	}while (true);
}
//preconditon: going to pass in two objects 
//postcondition: going to then call my overloading operators, do 5 steps, if/else statements to check if realNumber or imaginaryNumber are postive or negative
void Complex::evaluteSteps(Complex& c1, Complex& c2){
	Complex c3(1.07109, 0.120832);
	Complex c4;
	Complex c5;
	Complex c6;
	Complex c7;
	Complex c8;
	Complex c9;

	c4 = c1 + c2;
	c5 = c1 / 9;
	c6 = c4 * 3;
	c7 = c6 / 7;
	c8 = c2 - c5;
	c9 = c7 / c8;

	if (c1.getRealNumber() == 0 && c1.getImaginaryNumber() == 0)
	{
		cout << "\n\t\t\tC1 = 0\n";
	}
	else if (c1.getRealNumber() == 0)
	{
		cout << "\n\t\t\tC1 = " << c1.getImaginaryNumber() << "i" << endl;
	}
	else if (c1.getImaginaryNumber() == 0)
	{
		cout << "\n\t\t\tC1 = " << c1.getRealNumber() << endl;
	}
	else if (c1.getImaginaryNumber() < 0)
	{
		cout << "\n\t\t\tC1 = " << c1.getRealNumber() << " - " << -(c1.getImaginaryNumber()) << "i" << endl;
	}
	else
	{
		cout << "\n\t\t\tC1 = " << c1.getRealNumber() << " + " << c1.getImaginaryNumber() << "i" << endl;
	}

	if (c2.getRealNumber() == 0 && c2.getImaginaryNumber() == 0)
	{
		cout << "\t\t\tC1 = 0\n\n";
	}
	else if (c2.getRealNumber() == 0)
	{
		cout << "\t\t\tC1 = " << c2.getImaginaryNumber() << "i" << endl;
	}
	else if (c2.getImaginaryNumber() == 0)
	{
		cout << "\t\t\tC1 = " << c2.getRealNumber() << endl;
	}
	else if (c2.getImaginaryNumber() < 0)
	{
		cout << "\t\t\tC2 = " << c2.getRealNumber() << " - " << -(c2.getImaginaryNumber()) << "i" << endl;
	}
	else
	{
		cout << "\t\t\tC2 = " << c2.getRealNumber() << " + " << c2.getImaginaryNumber() << "i" << endl;
	}

	if (c3.getRealNumber() == 0 && c3.getImaginaryNumber() == 0)
	{
		cout << "\t\t\tC3 = 0\n\n";
	}
	else if (c3.getRealNumber() == 0)
	{
		cout << "\t\t\tC3 = " << c3.getImaginaryNumber() << "i" << endl << endl;
	}
	else if (c3.getImaginaryNumber() == 0)
	{
		cout << "\t\t\tC3 = " << c3.getRealNumber() << endl << endl;
	}
	else if (c3.getImaginaryNumber() < 0)
	{
		cout << "\t\t\tC3 = " << c3.getRealNumber() << " - " << -(c3.getImaginaryNumber()) << "i" << endl << endl;
	}
	else
	{
		cout << "\t\t\tC3 = " << c3.getRealNumber() << " + " << c3.getImaginaryNumber() << "i" << endl << endl;
	}

	cout << "\t\t\tEvaluating expression...\n";
	cout << "\t\t\t\t (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ? \n";
	cout << "\t\t\tstep #1: (3 * (";

	if (c4.getRealNumber() == 0 && c4.getImaginaryNumber() == 0){
		cout << c4.getRealNumber();
	}
	else if (c4.getRealNumber() == 0){
		cout << c4.getImaginaryNumber() << "i";
	}
	else if (c4.getImaginaryNumber() == 0){
		cout << c4.getRealNumber();
	}
	else if (c4.getImaginaryNumber() < 0){
		cout << c4.getRealNumber() << " - " << -(c4.getImaginaryNumber()) << "i";
	}
	else{
		cout << c4.getRealNumber() << " + " << c4.getImaginaryNumber() << "i";
	}

	cout << ") / 7) / ((";

	if (c2.getRealNumber() == 0 && c2.getImaginaryNumber() == 0){
		cout << c2.getRealNumber();
	}
	else if (c2.getRealNumber() == 0){
		cout << c2.getImaginaryNumber() << "i";
	}
	else if (c2.getImaginaryNumber() == 0){
		cout << c2.getRealNumber();
	}
	else if (c2.getImaginaryNumber() < 0){
		cout << c2.getRealNumber() << " - " << -(c2.getImaginaryNumber()) << "i";
	}
	else{
		cout << c2.getRealNumber() << " + " << c2.getImaginaryNumber() << "i";
	}

	cout << ") - (";

	if (c5.getRealNumber() == 0 && c5.getImaginaryNumber() == 0){
		cout << c5.getRealNumber();
	}
	else if (c5.getRealNumber() == 0){
		cout << c5.getImaginaryNumber() << "i";
	}
	else if (c5.getImaginaryNumber() == 0){
		cout << c5.getRealNumber();
	}
	else if (c5.getImaginaryNumber() < 0){
		cout << c5.getRealNumber() << " - " << -(c5.getImaginaryNumber()) << "i";
	}
	else{
		cout << c5.getRealNumber() << " + " << c5.getImaginaryNumber() << "i";
	}

	cout << ")) != (1.07109 + 0.120832i)\n";

	cout << "\t\t\tstep #2: ((";

	if (c6.getRealNumber() == 0 && c6.getImaginaryNumber() == 0){
		cout << c6.getRealNumber();
	}
	else if (c6.getRealNumber() == 0){
		cout << c6.getImaginaryNumber() << "i";
	}
	else if (c6.getImaginaryNumber() == 0){
		cout << c6.getRealNumber();
	}
	else if (c6.getImaginaryNumber() < 0){
		cout << c6.getRealNumber() << " - " << -(c6.getImaginaryNumber()) << "i";
	}
	else{
		cout << c6.getRealNumber() << " + " << c6.getImaginaryNumber() << "i";
	}

	cout << ") / 7) / (";

	if (c8.getRealNumber() == 0 && c8.getImaginaryNumber() == 0){
		cout << c8.getRealNumber();
	}
	else if (c8.getRealNumber() == 0){
		cout << c8.getImaginaryNumber() << "i";
	}
	else if (c8.getImaginaryNumber() == 0){
		cout << c8.getRealNumber();
	}
	else if (c8.getImaginaryNumber() < 0){
		cout << c8.getRealNumber() << " - " << -(c8.getImaginaryNumber()) << "i";
	}
	else{
		cout << c8.getRealNumber() << " + " << c8.getImaginaryNumber() << "i";
	}

	cout << ") != (1.07109 + 0.120832i)\n";

	cout << "\t\t\tstep #3: (";

	if (c7.getRealNumber() == 0 && c7.getImaginaryNumber() == 0){
		cout << c7.getRealNumber();
	}
	else if (c7.getRealNumber() == 0){
		cout << c7.getImaginaryNumber() << "i";
	}
	else if (c7.getImaginaryNumber() == 0){
		cout << c7.getRealNumber();
	}
	else if (c7.getImaginaryNumber() < 0){
		cout << c7.getRealNumber() << " - " << -(c7.getImaginaryNumber()) << "i";
	}
	else{
		cout << c7.getRealNumber() << " + " << c7.getImaginaryNumber() << "i";
	}

	cout << ") / (";

	if (c8.getRealNumber() == 0 && c8.getImaginaryNumber() == 0){
		cout << c8.getRealNumber();
	}
	else if (c8.getRealNumber() == 0){
		cout << c8.getImaginaryNumber() << "i";
	}
	else if (c8.getImaginaryNumber() == 0){
		cout << c8.getRealNumber();
	}
	else if (c8.getImaginaryNumber() < 0){
		cout << c8.getRealNumber() << " - " << -(c8.getImaginaryNumber()) << "i";
	}
	else{
		cout << c8.getRealNumber() << " + " << c8.getImaginaryNumber() << "i";
	}

	cout << ") != (1.07109 + 0.120832i)\n";

	cout << "\t\t\tstep #4: (";

	if (c9.getRealNumber() == 0 && c9.getImaginaryNumber() == 0){
		cout << c9.getRealNumber();
	}
	else if (c9.getRealNumber() == 0){
		cout << c9.getImaginaryNumber() << "i";
	}
	else if (c9.getImaginaryNumber() == 0){
		cout << c9.getRealNumber();
	}
	else if (c9.getImaginaryNumber() < 0){
		cout << c9.getRealNumber() << " - " << -(c9.getImaginaryNumber()) << "i";
	}
	else{
		cout << c9.getRealNumber() << " + " << c9.getImaginaryNumber() << "i";
	}

	cout << ") != (1.07109 + 0.120832i) ?\n";

	cout << "\t\t\tstep #5: ";

	if (c9 != c3){
		cout << "true\n\n";
	}
	else{
		cout << "false\n\n";
	}
}

//precondition: going to pass in an obj1 and the second argu to get the number to add
//postcondition: going to be getting the real number to add the num, not the imaginary number
double operator+(const Complex& obj1, double num) {
	return obj1.getRealNumber() + num;
}
//precondition: going to pass in an obj1 and the second argu to get the number to sub
//postcondition: going to be getting the real number to sub the num, not the imaginary number
double operator-(const Complex& obj1, double num) {
	return obj1.getRealNumber() - num;
}
//precondition: going to pass in an obj1 and the second argu to get the number multiply
//postcondition: going to be getting the real number to multiply the num, not the imaginary number
double operator*(const Complex& obj1, double value) {
	return  obj1.getRealNumber() * value;
}
//precondition: going to pass in an obj1 and the second argu to get the number divided
//postcondition: going to be getting the real number to divide the num, not the imaginary number
double operator/(const Complex& obj1, double value) {
	return obj1.getRealNumber() / value;
}
//precondition: going to pass in two objects and check if they are equal
//postcondition: going to check the obj1 and obj2 real nubmber if they are equal and same thing for the imaginary number
bool operator==(const Complex& obj1, const Complex& obj2){
	return (obj1.getRealNumber() == obj2.getRealNumber()) && (obj1.getImaginaryNumber() == obj2.getImaginaryNumber());
}
//precondition: going to pass in two objects and check if they are NOT equal
//postcondition: going to check the obj1 and obj2 real nubmber if they are NOT equal and same thing for the imaginary number
bool operator!=(const Complex& obj1, const Complex& obj2){
	return (obj1.getRealNumber() != obj2.getRealNumber()) && (obj1.getImaginaryNumber() != obj2.getImaginaryNumber());
}
//precondition: going to have two objects
//postcondition: going to then add the obj1 realNumber() and obj2 realNumber() and same thing for imaginaryNumber 
Complex operator+(Complex& obj1, Complex& obj2){
	double sumA;
	double sumB;
	sumA = obj1.getRealNumber() + obj2.getRealNumber();
	sumB = obj1.getImaginaryNumber() + obj2.getImaginaryNumber();

	return Complex(sumA, sumB);
}
//precondition: going to have one objects and one varaible (int)
//postcondition: going to then multiply the c3 realNumber() times value and  also c3 imaginaryNumber() times value
Complex operator*(const Complex& c3, int value){
	double productA;
	double productB;
	productA = c3.getRealNumber() * value;
	productB = c3.getImaginaryNumber() * value;

	return Complex(productA, productB);
}
//precondition: going to have one objects and one varaible (int)
//postcondition: going to then divide the c3 realNumber() divide value and  also c3 imaginaryNumber() divide value
Complex operator/(const Complex& c3, int value){
	double a;
	double b;

	a = c3.getRealNumber() / value;
	b = c3.getImaginaryNumber() / value;

	return Complex(a, b);
}
//precondition: going to have two objects
//postcondition: going to then subtract the obj2 realNumber() and obj1 realNumber() and same thing for imaginaryNumber 
Complex operator-(Complex& obj2, Complex& obj1){
	double sumA;
	double sumB;
	sumA = obj2.getRealNumber() - obj1.getRealNumber();
	sumB = obj2.getImaginaryNumber() - obj1.getImaginaryNumber();

	return Complex(sumA, sumB);
}
//precondition: going to have two objects
//postcondition: going to then add the obj1 realNumber() times obj2 realNumber() plues and obj1 imaginaryNumber() times obj2 imaginaryNumber() 
Complex operator*(Complex& obj1, Complex& obj2){
	double productA;
	double productB;
	productA = (obj1.getRealNumber() * obj2.getRealNumber()) + (-(obj1.getImaginaryNumber() * obj2.getImaginaryNumber()));
	productB = (obj1.getRealNumber() * obj2.getImaginaryNumber()) + (obj1.getImaginaryNumber() * obj2.getRealNumber());

	return Complex(productA, productB);
}
//precondition: going to have two objects
//postcondition: going to thent take the power of obj1 realNumber() then add it with the power of obj1 imaginaryNumber()
Complex operator/(Complex& obj2, Complex& obj1){
	double a;
	double b;
	double denominator;
	denominator = pow(obj1.getRealNumber(), 2) + pow(obj1.getImaginaryNumber(), 2);

	a = (obj1.getRealNumber() * obj2.getRealNumber()) + (-(-obj1.getImaginaryNumber() * obj2.getImaginaryNumber()));
	b = (obj1.getRealNumber() * obj2.getImaginaryNumber()) + (-obj1.getImaginaryNumber() * obj2.getRealNumber());

	a /= denominator;
	b /= denominator;

	return Complex(a, b);
}




