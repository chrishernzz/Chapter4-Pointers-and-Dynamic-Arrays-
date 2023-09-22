#include<iostream>
#include"input (1).h"
#include"Complex.h"
using namespace std;

//prototype
int menuOption();
void challenge1();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		//case 2: challenge2(); break;
		//case 3: challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption()
{
	system("cls");
	cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Christian Hernandez(9/20/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Complex Numbers";
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t3> Polynomials";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting numbers from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}



//precondition: going to call my Complex class that has the real number and imaginary number
//postcondition: going to make a menu that can handle complex number and multiple complex number, then going to call my class
void challenge1()
{
	system("cls");
	char option;
	int optionAComp;
	Complex numbers;

	do {
	    beginning:
		cout << "\t\tA complex number is a number that can be expressed in the form a + b i, where a and b are real\n"
			"\t\tnumbers, and i represents the " << "'imaginary uni'," << " satisfying the equation i ^ 2 = -1. Because no\n"
			"\t\ttreal number satisfies this equation, i is called an imaginary number.For the complex number\n"
			"\t\ta + b i, a is called the real part and b is called the imaginary part.\n";
		cout << "\n\t\t1> - Complex Numbers";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\tA> A Complex Number";
		cout << "\n\t\t\tB> Multiple Complex Numbers";
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
					numbers.setRealNumber(inputDouble("\n\t\t\tEnter a number (double value) for the real part: "));
					cout << "\n";
					system("pause");
					system("cls");
				}
					  break;
				case 2: {
					numbers.setImaginaryNumber(inputDouble("\n\t\t\tEnter a number (double value) for the imaginary part: "));
					cout << "\n";
					system("pause");
					system("cls");
				}
					  break;
				case 3: {
					numbers.getFormulaInformation();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 4: {
					cout << "\n\t\t\tNegated the complexx number C2 (a copy of C1)\n";
					numbers.getNegatedComplexNumber();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 5: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					cout << "\n\t\t\tC2 + value";
					if (numbers.getImaginaryNumber()<0) {
						cout << "\n\t\t\t(" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i) + " << number2 << " = " << numbers + number2 << " - "<<-(numbers.getImaginaryNumber())<<"i";
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t"<< number2<<" + (" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i)" << " = " << numbers + number2 << " - " << -(numbers.getImaginaryNumber()) << "i";
					}
					else {
						cout << "\n\t\t\t(" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i) + " << number2 << " = " << numbers + number2 << " + " << numbers.getImaginaryNumber()<<"i";
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t" << number2 << " + (" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i)" << " = " << numbers + number2 << " + " << numbers.getImaginaryNumber() << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 6: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					cout << "\n\t\t\tR2 - value";
					if (numbers.getImaginaryNumber() < 0) {
						cout << "\n\t\t\t(" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i) - " << number2 << " = " << numbers - number2 << " - " << -(numbers.getImaginaryNumber()) << "i";
						cout << "\n\n\t\t\tvalue - R2";
						cout << "\n\t\t\t" << number2 << " - (" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i)" << " = " << -(numbers - number2) << " - " << -(numbers.getImaginaryNumber()) << "i";
					}
					else {
						cout << "\n\t\t\t(" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i) - " << number2 << " = " << numbers - number2 << " + " << numbers.getImaginaryNumber() << "i";
						cout << "\n\n\t\t\tvalue - R2";
						cout << "\n\t\t\t" << number2 << " - (" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i)" << " = " << -(numbers - number2) << " + " << numbers.getImaginaryNumber() << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 7: {
					double number2 = inputDouble("\n\t\t\tEnter a value (double): ");
					cout << "\n\t\t\tC2 * value";
					if (numbers.getImaginaryNumber() < 0) {
						cout << "\n\t\t\t(" << numbers.getRealNumber() << " * " << numbers.getImaginaryNumber() << "i) * " << number2 << " = " << numbers * number2 << " + "<< - (numbers.getImaginaryNumber() * -number2) << "i";
						cout << "\n\n\t\t\tvalue * C2";
						cout << "\n\t\t\t" << number2 << " * (" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i)" << " = " << numbers * number2 << " + " << -(numbers.getImaginaryNumber() * -number2) << "i";
					}
					else {
						cout << "\n\t\t\t(" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i) + " << number2 << " = " << numbers * number2 << " - " << -(numbers.getImaginaryNumber() * number2) << "i";
						cout << "\n\n\t\t\tvalue + C2";
						cout << "\n\t\t\t" << number2 << " * (" << numbers.getRealNumber() << " + " << numbers.getImaginaryNumber() << "i)" << " = " << numbers * number2 << " - " << -(numbers.getImaginaryNumber() * number2) << "i";
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 8: {

				}
					  break;
				case 0: {
					//delete memory so it does not leak
					numbers.~Complex();
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
			cout << "bye";
			system("pause");
			system("cls");
		}
				break;
		case '0': {
			return;
		}
		}
	} while (true);
}