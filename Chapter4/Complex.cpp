#include "Complex.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the variables to 0.0 since they are doubles (initialize them), allocating new memory
Complex::Complex() : realNumber(new double(0.0)), imaginaryNumber(new double(0.0)) {}

//precondition: going to call my deconstructor
//postcondition: going to then deallocate the memory for realNumber and imaginaryNumber
Complex::~Complex(){
	delete realNumber;
	delete imaginaryNumber;
}

//precondition: going to get the realNumber 
//postcondition: going to return the private realNumber
double Complex::getRealNumber() const{
	return *realNumber;
}
//precondition: going to get the new realNumber
//postcondition: going to set the private realNumber with the new realNumber member
void Complex::setRealNumber(double newRealNumber){
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
void Complex::getFormulaInformation(){
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
	else if(getImaginaryNumber() < 0) {

		cout << "\n\t\t\tComplex number C1 = " << getRealNumber() <<" - "<<-(getImaginaryNumber()) << "i";
	}
	else {
		cout << "\n\t\t\tComplex number C1 = " << getRealNumber() << " + " << getImaginaryNumber() << "i";
	}

}
//precondition: going to now get the negated numbers of real number and the imaginary number
//postcondition: going to do if and else statement to check if its negated, formula is -(realnumber + imaginarynumber)
void Complex::getNegatedComplexNumber() const{
	double negatedRealNumber, negatedImaginaryNumber;
	negatedRealNumber = -(getRealNumber());
	negatedImaginaryNumber = -(getImaginaryNumber());
	//if there are no real numbers or imaginary number, then 0
	if (getRealNumber() == 0 && getImaginaryNumber() == 0) {
		cout << "\n\t\t\t-(0) = 0";
	}
	//else if imaginary number is 0, now call the negated real number
	else if (getImaginaryNumber() == 0) {
		cout<<"\n\t\t\t-("<<getRealNumber()<<") = "<<negatedRealNumber;
	}
	//else if real number is 0, now call the negated imaginary number
	else if (getRealNumber() == 0) {
		cout << "\n\t\t\t-(" << getImaginaryNumber() << ") = " << negatedImaginaryNumber<<"i";
	}
	//else if the imaginary number is negative (less than 0) then it will negate to positive
	else if (getImaginaryNumber() < 0) {

		cout<<"\n\t\t\t-("<<getRealNumber()<<" - "<<-(getImaginaryNumber())<<") = "<<negatedRealNumber<<" + "<<(negatedImaginaryNumber)<<"i";
	}
	//else imaginary number is positive then it will negate to negative
	else {
		cout << "\n\t\t\t-(" << getRealNumber() << " + " << getImaginaryNumber() << ") = " << negatedRealNumber << " - " << -(negatedImaginaryNumber) << "i";
	}
}

							cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " - " <<abs(multC2.getImaginaryNumber()) << "i) != (" << multC1.getRealNumber() << ") ? ";
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
					else if (multC1.getImaginaryNumber() < 0) {
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
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " + " << (multC1.getImaginaryNumber()) << "i) == (" << multC2.getRealNumber() << " - " << abs(multC2.getImaginaryNumber()) << "i) ? ";
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
					else {
						cout << "\n\t\t\tC1 == C2 -> (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) == (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) ? ";
						if (multC1 == multC2) {
							cout << "true";
						}
						else {
							cout << "false";
						}
						cout << "\n\t\t\tC2 != C1 -> (" << multC2.getRealNumber() << " + " << multC2.getImaginaryNumber() << "i) != (" << multC1.getRealNumber() << " + " << multC1.getImaginaryNumber() << "i) ? ";
						if (multC2 != multC1) {
							cout << "true";
						}
						else {
							cout << "false";
						}
					}
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 4: {

				}
					  break;
				case 5: {

				}
					  break;
				case 0: {
					//delete memory so it does not leak
					/*multC1.~Complex();
					multC2.~Complex();*/
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
	} while (true);
}

//precondition: going to pass in an obj1 and the second argu to get the number to add
//postcondition: going to be getting the real number to add the num, not the imaginary number
double operator+(const Complex& obj1, double num){
	return obj1.getRealNumber() + num;
}
//precondition: going to pass in an obj1 and the second argu to get the number to sub
//postcondition: going to be getting the real number to sub the num, not the imaginary number
double operator-(const Complex& obj1, double num) {
	return obj1.getRealNumber() - num;
}
//precondition: going to pass in an obj1 and the second argu to get the number multiply
//postcondition: going to be getting the real number to multiply the num, not the imaginary number
double operator*(const Complex & obj1, double value) {
	return  obj1.getRealNumber() * value;//&& obj1.getImaginaryNumber()* value; 
}
