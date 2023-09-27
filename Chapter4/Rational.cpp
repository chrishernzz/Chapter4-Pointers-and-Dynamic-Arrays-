#include "Rational.h"

//precondition: going to call my default constructor
//postcondition: going to set the variables to 0 and 1 (initialize them)
Rational::Rational() : numerator(0), denominator(1) {}

//precondition: going to pass in two arguments that will accept the newNumerator and newDenominator
//postcondition: going to then now set the private variables with the new, check if denominator is 0, if 0 throw an error, call the normalize() function
Rational::Rational(int newNumerator, int newDenominator) {
	numerator = newNumerator;
	denominator = newDenominator;
}

// A copy constructor thats accepts the Rational objects and denominator and throw an exception if the denominator is zero.
Rational::Rational(const Rational& obj) {
	numerator = obj.numerator;
	denominator = obj.denominator;
}

//PreCondition: integer a and b parameter
//PostCondition: return the greatest common divisor between a and b
int Rational::gcd(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}

//precondition: going to turn the variables to a string since they are int
//postcondition: going to return the privates variables to a string, meaning if its 5 it will be "5" 
string Rational::toString() {
	return to_string(numerator) + "/" + to_string(denominator);
}
//precondition: going to call the denominator and the numerator with the gcd() function
//postcondition: going to then check for the greatest common denominator, using the abs(turn it to positive)
void Rational::normalize() {
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}
	int temp = gcd(abs(numerator), abs(denominator));

	if (temp != 0) {
		numerator /= temp;
		denominator /= temp;
	}
}

//PreCondition: a Rational object
//PostCondition: negated the rational number  
void Rational::negate(Rational& obj) {
	obj.setNumerator(numerator * -1);
}

//precondition: going to get the numerator
//postcondition: going to return the private numerator
int Rational::getNumerator() const {
	return numerator;
}

//precondition: going to get the denominator
//postcondition: going to return the private denominator
int Rational::getDenominator() const {
	return denominator;
}

//precondition: going to get the new numerator
//postcondition: going to set the private numerator with the new numerator member
void Rational::setNumerator(int newN) {
	numerator = newN;
}

//precondition: going to get the new denominator
//postcondition: going to set the private denominator with the new denominator member, check if its 0, if 0 throw an error
void Rational::setDenominator(int newD) {
	denominator = newD;
}

//precondition: 2 Rational objects
//postcondition: return a the object that is the copy of the original object
const Rational Rational::operator =(const Rational& right) {
	if (this != &right) {
		numerator = right.numerator;
		denominator = right.denominator;
	}
	return *this;
}

//precondition: going to create a menu
//postcondition: going to then return the numerator and denominator (only one rational number)
void Rational::RationalOptionA() {

	Rational rational1;
	Rational rational2;
	int number = 0;
	int numerator = 0;
	int denominator = 0;

	do {
		system("cls");
		cout << "\n\tA> A Rational Number";
		cout << "\n\t" + string(90, char(205));
		cout << "\n\t\t1. Enter the numerator";
		cout << "\n\t\t2. Enter the denominator";
		cout << "\n\t\t3. Display the rational number";
		cout << "\n\t\t4. Normalize the rational number";
		cout << "\n\t\t5. Negate the rational number";
		cout << "\n\t\t6. Add (+) the rational number with a constant";
		cout << "\n\t\t7. Subtract (-) the rational number with a constant";
		cout << "\n\t\t8. Multiply (*) the rational number with a constant";
		cout << "\n\t\t9. Divide (/) the rational number with a constant";

		cout << "\n\t" + string(90, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" + string(90, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 9))
		{
		case 1:

			numerator = inputInteger("\n\t\tEnter an integer for the numerator: ");
			rational1.setNumerator(numerator);

			break;
		case 2:

			denominator = inputInteger("\n\t\tEnter an integer for the denominator: ");
			rational1.setDenominator(denominator);

			break;
		case 3:

			if (denominator == 0) {
				cout << "\n\t\tRational number R1 = undefine\n";
			}
			else {
				cout << "\n\t\tRational number R1 = " << rational1.toString() << "\n";
			}

			break;
		case 4:

			cout << "\n\t\tNormalized rational number R2 (a copy of R1)\n";

			if (denominator == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational2 = rational1;
				rational2.normalize();

				cout << "\n\t\t" << rational2 << "\n";
			}

			break;
		case 5:

			cout << "\n\t\tNegated rational number R2 (a copy of R1)\n";
			if (denominator == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational2 = rational1;
				rational2.negate(rational2);
				rational2.normalize();

				cout << "\n\t\t-(" << rational1 << ") = " << rational2 << "\n";
			}

			break;
		case 6:

			if (denominator == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational2 = rational1;
				number = inputInteger("\n\t\tEnter an integer value: ");

				rational2 = rational2 + number;
				rational2.normalize();
				cout << "\n\t\tR2 + value";
				cout << "\n\t\t(" + rational1.toString() + ") + " << number << " = " << rational2 << '\n';

				rational2 = rational1;
				rational2 = number + rational2;
				rational2.normalize();
				cout << "\n\t\tvalue + R2";
				cout << "\n\t\t" << number << " + (" << rational1 << ") = " << rational2 << '\n';
			}

			break;
		case 7:

			if (denominator == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational2 = rational1;
				number = inputInteger("\n\t\tEnter an integer value: ");

				rational2 = rational2 - number;
				rational2.normalize();

				cout << "\n\t\tR2 - value";
				cout << "\n\t\t(" + rational1.toString() + ") - " << number << " = " << rational2 << '\n';

				rational2 = rational1;
				rational2 = number - rational2;
				rational2.normalize();

				cout << "\n\t\tvalue - R2";
				cout << "\n\t\t" << number << " - (" << rational1 << ") = " << rational2 << '\n';
			}

			break;
		case 8:

			if (denominator == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational2 = rational1;
				number = inputInteger("\n\t\tEnter an integer value: ");

				rational2 = rational2 * number;
				rational2.normalize();

				cout << "\n\t\tR2 * value";
				cout << "\n\t\t(" + rational1.toString() + ") * " << number << " = " << rational2 << '\n';

				rational2 = rational1;
				rational2 = number * rational2;
				rational2.normalize();

				cout << "\n\t\tvalue * R2";
				cout << "\n\t\t" << number << " * (" << rational1 << ") = " << rational2 << '\n';
			}

			break;
		case 9:

			if (denominator == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational2 = rational1;
				number = inputInteger("\n\t\tEnter an integer value: ");

				if (number != 0) {
					rational2 = rational2 / number;
					rational2.normalize();

					cout << "\n\t\tR2 / value";
					cout << "\n\t\t(" + rational1.toString() + ") / " << number << " = " << rational2 << '\n';

					rational2 = rational1;
					rational2 = number / rational2;
					rational2.normalize();
				}
				else {
					cout << "\n\t\tR2 / value";
					cout << "\n\t\tundefine\n";
				}

				if (numerator == 0) {
					cout << "\n\t\tvalue / R2";
					cout << "\n\t\tundefine\n";
				}
				else {
					rational2 = number / rational1;
					cout << "\n\t\tvalue / R2";
					cout << "\n\t\t" << number << " / (" << rational1 << ") = " << rational2 << '\n';
				}
			}

			break;
		case 0: return;
		default: cout << "\t\tERROR - Invalid option."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}
//precondition: going to create a menu
//postcondition: going to then return the numerator and denominator (multiple)
void Rational::RationalOptionB() {
	Rational rational1;
	Rational rational2;
	Rational rational3; // for case 3
	Rational rational4; // for case 3 
	Rational rational5; // for case 3
	int number = 0;

	int numerator = 0;
	int denominator = 0;

	do {
		system("cls");
		cout << "\n\tB> Multiple Rational Numbers";
		cout << "\n\t" + string(90, char(205));
		cout << "\n\t\t1. Enter rational number R1";
		cout << "\n\t\t2. Enter rational number R2";
		cout << "\n\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
		cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2";
		cout << "\n\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";

		cout << "\n\t" + string(90, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" + string(90, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5)) {
		case 1:
			numerator = (inputInteger("\n\t\tEnter the numerator for R1: "));
			rational1.setNumerator(numerator);

			denominator = inputInteger("\t\tEnter the denominator for R1: ");
			rational1.setDenominator(denominator);

			if (denominator == 0) {
				cout << "\n\t\tR1 = undefine\n";
			}
			else {
				rational1.normalize();
				cout << "\n\t\tR1 = " << rational1 << '\n';
			}

			break;

		case 2:
			numerator = (inputInteger("\n\t\tEnter the numerator for R2: "));
			rational2.setNumerator(numerator);
			denominator = inputInteger("\t\tEnter the denominator for R2: ");

			rational2.setDenominator(denominator);

			if (denominator == 0) {
				cout << "\n\t\tR2 = undefine\n";
			}
			else {
				rational2.normalize();
				cout << "\n\t\tR2 = " << rational2 << '\n';
			}

			break;
		case 3:
			if (rational1.getDenominator() == 0 || rational2.getDenominator() == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				cout << "\n\t\tR1 == R2 -> (" << rational1 << ") == (" << rational2 << ") : ";
				rational1 == rational2 ? cout << "true" : cout << "false";

				cout << "\n\t\tR2 != R1 -> (" << rational2 << ") != (" << rational1 << ") : ";
				rational2 != rational1 ? cout << "true" : cout << "false";

				cout << "\n\t\tR1 >= R2 -> (" << rational1 << ") >= (" << rational2 << ") : ";
				rational1 >= rational2 ? cout << "true" : cout << "false";

				cout << "\n\t\tR2  > R1 -> (" << rational2 << ")  > (" << rational1 << ") : ";
				rational2 > rational1 ? cout << "true" : cout << "false";

				cout << "\n\t\tR1 <= R2 -> (" << rational1 << ") <= (" << rational2 << ") : ";
				rational1 <= rational2 ? cout << "true" : cout << "false";

				cout << "\n\t\tR2  < R1 -> (" << rational2 << ")  < (" << rational1 << ") : ";
				rational2 < rational1 ? cout << "true\n" : cout << "false\n";
			}

			break;
		case 4:
			if (rational1.getDenominator() == 0 || rational2.getDenominator() == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				cout << "\n\n\t\tAddition    : R1 + R2 -> " << rational1 << " + " << rational2 << " = " << rational1 + rational2;
				cout << "\n\n\t\tSubtraction : R1 + R2 -> " << rational1 << " - " << rational2 << " = " << rational1 - rational2;
				cout << "\n\n\t\tMutiplcation: R1 + R2 -> " << rational1 << " * " << rational2 << " = " << rational1 * rational2;

				if (rational1.getNumerator() == 0 || rational2.getNumerator() == 0) {
					cout << "\n\n\t\tDivision    : R1 + R2 -> " << rational1 << " * " << rational2 << " = undefine\n";
				}
				else {
					cout << "\n\n\t\tDivision: R1 + R2 -> " << rational1 << " / " << rational2 << " = " << rational1 / rational2;
				}
			}
			break;
		case 5:
			if (rational1.getDenominator() == 0 || rational2.getDenominator() == 0) {
				cout << "\n\t\tundefine\n";
			}
			else {
				rational3.setNumerator(621);
				rational3.setDenominator(889);

				//to display the numbers before calculations
				cout << "\n\t\tR1= : " << rational1.toString() << "\n";
				cout << "\t\tR2= : " << rational2.toString() << "\n";
				cout << "\t\tR3= : " << rational3.toString() << "\n";

				//rational5 = (3 * (rational1 + rational2) / 7) / (rational2 - rational1 / 9);
				// 
				//step 1

				rational4 = rational1 + rational2;
				rational5 = rational1 / 9;

				cout << "\n\t\tEvaluating expression...";
				cout << "\n\t\t\t (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889 ?";
				cout << "\n\t\tStep #1: (3 * (" << rational4.toString() << ") / 7) / ( " << rational2.toString()
					<< " - " << rational5.toString() << ")) >= 621/889 ?" << "\n";

				//step 2
				rational4 = 3 * rational4;
				rational5 = rational2 - rational5;

				cout << "\t\tStep #2: ((" << rational4.toString() << ") / 7) / ( " << rational5.toString()
					<< ")) >= 621/889 ?" << "\n";

				//step 3
				rational4 = rational4 / 7;

				cout << "\t\tStep #3: (" << rational4.toString() << ") / ( " << rational5.toString()
					<< " >= 621/889 ?" << "\n";

				//step 4
				rational5 = rational4 / rational5;
				cout << "\t\tStep #4: (" << rational5.toString() << ") >= 621/889 ?" << "\n";

				//final simplist forms before they are compared. Will also clean the negative signs to the correct position.
				rational5.normalize();
				rational3.normalize();
				//step5
				if (rational5 > rational3) {

					cout << "\t\tstep #5: true" << "\n";
				}
				else if (rational5 < rational3 || rational5 == rational3) {
					cout << "\t\tstep #5: false" << "\n";
				}
			}
			break;

		case 0:
			return;

		default: cout << "\t\tERROR - Invalid option."; break;
		}

		cout << "\n";
		system("pause");
	} while (true);
}

//precondition: creating the main menu
//postcondition: going to call my functions RationalOptionA() and RationalOptionB()
void Rational::RationalMenu() {
	do {
		system("cls");
		cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
		cout << "\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
		cout << "\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
		cout << "\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
		cout << "\n\tIn general, a number that can be written as a fraction while it is in its own form is rational.\n";
		cout << "\n\t2> Rational Numbers";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\t A> A Rational Number";
		cout << "\n\t\t B> Multiple Rational Numbers";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t 0> return";
		cout << "\n\t" + string(100, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
		{
		case 'A': system("cls"); RationalOptionA(); break;
		case 'B': system("cls"); RationalOptionB(); break;
		case '0': return;
		default: cout << "\t\tERROR - Invalid option."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

//precondition: 2 Rational objects
//postcondition: return a the object that is the result of the multiplication of the 2 rational objects
Rational operator *(const Rational& obj1, const Rational& obj2) {
	Rational temp;
	temp.numerator = obj1.numerator * obj2.numerator;
	temp.denominator = obj1.denominator * obj2.denominator;
	temp.normalize();

	return temp;
}

//precondition: 2 Rational objects
//postcondition: return a the object that is the result of the division of the 2 rational objects
Rational operator /(const Rational& obj1, const Rational& obj2) {
	Rational temp;
	temp.numerator = obj1.numerator * obj2.denominator;
	temp.denominator = obj1.denominator * obj2.numerator;
	temp.normalize();

	return temp;
}

//precondition: 2 Rational objects
//postcondition: return a the object that is the result of sum of the 2 rational objects
Rational operator +(const Rational& obj1, const Rational& obj2) {
	Rational temp;
	temp.denominator = obj1.denominator * obj2.denominator;
	temp.numerator = (obj1.numerator * obj2.denominator) + (obj2.numerator * obj1.denominator);
	temp.normalize();

	return temp;
}

//precondition: 2 Rational objects
//postcondition: return a the object that is the difference of the 2 rational objects
Rational operator -(const Rational& obj1, const Rational& obj2) {
	Rational temp;
	temp.denominator = obj1.denominator * obj2.denominator;
	temp.numerator = (obj1.numerator * obj2.denominator) - (obj2.numerator * obj1.denominator);
	temp.normalize();

	return temp;
}

//precondition: a Rational object, with an interger
//postcondition: return a the object that is the sum of a rational object and a number
Rational operator +(const Rational& obj, const int number) {
	Rational temp;
	temp.numerator = obj.numerator + (number * obj.denominator);
	temp.denominator = obj.denominator;

	return temp;
}

//precondition:  an interger with an Rational object
//postcondition: return a the object that is the sum of a number and a rational object
Rational operator +(const int number, const Rational& obj) {
	Rational temp;
	temp.numerator = obj.numerator + (number * obj.denominator);
	temp.denominator = obj.denominator;

	return temp;
}


//precondition: a Rational object, with an interger
//postcondition: return a the object that is the differences of a rational object and a number
Rational operator -(const Rational& obj, const int number) {
	Rational temp;
	temp.numerator = obj.numerator - (number * obj.denominator);
	temp.denominator = obj.denominator;

	return temp;
}

//precondition: an interger with an Rational object
//postcondition: return a the object that is the differences of a number and a rational object
Rational operator -(const int number, const Rational& obj) {
	Rational temp;

	temp.numerator = (number * obj.denominator) - obj.numerator;
	temp.denominator = obj.denominator;

	return temp;
}

//precondition: a Rational object, with an interger
//postcondition: return a the object that is the multiplicaton of a rational object and a number
Rational operator *(const Rational& obj, const int number) {
	Rational temp;
	temp.numerator = obj.numerator * number;
	temp.denominator = obj.denominator;

	return temp;
}

//precondition:  an interger with an Rational object
//postcondition: return a the object that is the mutilplication of a number and a rational object
Rational operator *(const int number, const Rational& obj) {
	Rational temp;
	temp.numerator = obj.numerator * number;
	temp.denominator = obj.denominator;

	return temp;
}

//precondition: a Rational object, with an interger
//postcondition: return a the object that is the division of a rational object and a number
Rational operator /(const Rational& obj, const int number) {
	Rational temp;
	temp.numerator = obj.numerator;
	temp.denominator = obj.denominator * number;
	return temp;
}

//precondition: a Rational object, with an interger
//postcondition: return a the object that is the division of a number and a rational object
Rational operator /(const int number, const Rational& obj) {
	Rational temp;
	temp.numerator = obj.denominator * number;
	temp.denominator = obj.numerator;
	return temp;
}

//precondition: 2 Rational objects
//postcondition: return a flag that compares two Rational numbers are equal
bool operator ==(const Rational& obj1, const Rational& obj2) {
	return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
}

//precondition: 2 Rational objects
//postcondition: return a flag which indicate one is lesser than another.
bool operator <(const Rational& obj1, const Rational& obj2) {
	return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
}

//precondition: 2 Rational objects
//postcondition: return a flag which indicate one is greater than another.
bool operator >(const Rational& obj1, const Rational& obj2) {
	return (obj1.numerator * obj2.denominator) > (obj2.numerator * obj1.denominator);
}

//precondition: 2 Rational objects
//postcondition: return a flag which indicate one is greater or equal to than another.
bool operator >=(const Rational& obj1, const Rational& obj2) {
	return (obj1.numerator * obj2.denominator) >= (obj2.numerator * obj1.denominator);
}

//precondition: 2 Rational objects
//postcondition: return a flag which indicate one is greater or equal to than another.
bool operator <=(const Rational& obj1, const Rational& obj2) {
	return (obj1.numerator * obj2.denominator) <= (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//postcondition: return a flag which indicate one different from another.
bool operator !=(const Rational& obj1, const Rational& obj2) {
	return (obj1.numerator * obj2.denominator) != (obj2.numerator * obj1.denominator);
}

//precondition: a ostream object and a Rational object
//postcondition: return the object that used for display 
ostream& operator << (ostream& out, Rational obj) {
	out << obj.toString();
	return out;
}
