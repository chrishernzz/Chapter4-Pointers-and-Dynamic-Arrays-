#include "Polynomial.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the variables to 0.0 since they are doubles (initialize them), allocating new memory
Polynomial::Polynomial(): coefficients(new double(0.0)), termSize(0) {}

//precondition: going to call my constructor with two arguments (parameters)
//postcondition: going to allocate new memory, and get the size
Polynomial::Polynomial(double* coeff, int size){
	//allocate new memory
	coefficients = new double[size];
	termSize = size;

	for (int i = 0; i < termSize; i++){
		coefficients[i] = 0;
	}
}
//precondition: going to call my deconstructor
//postcondition: going to then deallocate the memory for coefficients and set termSize to 0
Polynomial::~Polynomial(){
	delete[] coefficients;
	termSize = 0;
}
//precondition: going to set the coeff and the size of the
//postcondition: going to then do a for loop and if not good going to throw
double Polynomial::getCoefficients(double* coeff, int theTermSize) const{
	for (int i = 0; i < theTermSize; i++) {
		return coefficients[i];
	}
}
//precondition: going to pass two paraemeters, first is the coeff values, the second one is the size
//postcondition: going to then for loop through the array size, then set the coeff equal to it
void Polynomial::setCoefficients(double* coeff, int terms1){
	for (int i = 0; i < terms1; i++){
		coefficients[i] = coeff[i];
	}
}
//precondition: going to display the information
//postcondition: going to be get each coefficents display, have if/else statement to check the indexs
void Polynomial::display() const{
	cout << "\n\t\t\tThe P(x) is entered: ";
	for (int i = 0; i < termSize; i++){
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			cout << coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << coefficients[i] << "x^" << (termSize - 1) - i << " + ";
		}
	}
}
//preconditoin: going to display the information
//postcondition: going to then show the P1(x) formula, then going to multiply it
void Polynomial::displayP1X() const{
	cout << "\n\t\t\tP1(x) = ";
	for (int i = 0; i < termSize; i++) {
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			cout << coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << coefficients[i] << "x^" << (termSize - 1) - i << " + ";
		}
	}
}
//precondition: going to pass in 3 arguments (parameters)
//postcondition: going to then get the coefficients and multiply it by the value, then add the three multiplication and get the total
double Polynomial::getEvaluatePolyNomial(double* coeff, int theTermSize, double value) const{
	double total = 0.0;
	for (int i = 0; i < termSize; i++) {
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << "\n\t\t\t\t\t" << coefficients[i] * (pow(value, ((termSize - 1) - i))) << " <- " << "\t\t"<<coefficients[i] << "x";
			//going to multiply the coefficent with the powewr of ther own, then value will be our x
			//total will hold the total of the coefficent (the sum)
			total += coefficients[i] * (pow(value, ((termSize - 1) - i)));
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			
			cout << "\n\t\t\t\t\t" << coefficients[i] * (pow(value, ((termSize - 1) - i))) << " <- "<< "\t\t" << coefficients[i];
			total += coefficients[i] * (pow(value, ((termSize - 1) - i)));
			break;
		}
		else {
			//3 index[0][1][2][3] - 1 
			cout << "\n\t\t\t\t\t" << coefficients[i] * (pow(value, ((termSize - 1) - i))) << " <- " <<"\t\t" <<coefficients[i] << "x^" << (termSize - 1) - i;
			total += coefficients[i] * (pow(value, ((termSize - 1) - i)));
		}
	}
	cout << "\n\t\t\t+";
	cout << "\n\t\t\t" << string(45, char(205));
	cout << "\n\t\t\t\t\t"<<total;
	return total;
}
//precondition: going to display the information
//postcondition: going to then return the coefficients and have if and else statements checking where the index are at
void Polynomial::displayPolynomialDerivative() const{
	cout << "\n\t\t\tPolynomial(x) = ";
	for (int i = 0; i < termSize; i++) {
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			cout << coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << coefficients[i] << "x^" << (termSize - 1) - i << " + ";
		}
	}
	cout << "\n\n\t\t\tDerivative    = ";
	for (int i = 0; i < termSize; i++){
		if ((termSize - 1) - i == 1){
			cout << coefficients[i];
		}
		else if ((termSize - 1) - i == 0){
			//dont take the derivative, so break out since its at 0 
			//(no X)
			break;
		}
		else{
			//cout << coefficients[i] * ((termSize - 1) - i) << "x^" << (termSize - 2) - i << " + ";
			if ((termSize - 2) - i == 1) {
				cout << coefficients[i] * ((termSize - 1) - i) << "x + ";
			}
			else {
				cout << coefficients[i] * ((termSize - 1) - i) << "x^" << (termSize - 2) - i << " + ";
			}
		}
	}
}
//precondition: going to display the information of the integral
//postcondition: going to then get the integral by dividing the coeff wiht the square root
void Polynomial::displayPolynomialIntegral() const{
	cout << "\n\t\t\tPolynomial(x) = ";
	for (int i = 0; i < termSize; i++) {
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			cout << coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << coefficients[i] << "x^" << (termSize - 1) - i << " + ";
		}
	}
	cout << "\n\n\t\t\tIntegral     = ";
	for (int i = 0; i < termSize; i++){
		if ((termSize - 1) - i == 1){
			cout << coefficients[i] / 2 << "x^" << 2 << " + ";
		}
		//else if at index 0, then just put the coeff and x
		else if ((termSize - 1) - i == 0){
			cout << coefficients[i] << "x";
			break;
		}
		else{
			//take the coeff and divide it by the size 
			cout << coefficients[i] / (termSize - i) << "x^" << (termSize - i) << " + ";
		}
	}
}
//precondition: going to get the information for the first polynomial
//postcondition: going to then loop through the size and then set the coefficients
void Polynomial::displayFirstPolynomial() const{
	cout << "\n\tThe first polynomial (P1) is entered: ";
	for (int i = 0; i < termSize; i++) {
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			cout << coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << coefficients[i] << "x^" << (termSize - 1) - i << " + ";
		}
	}
}
//precondition: going to get the information for the first polynomial
//postcondition: going to then loop through the size and then set the coefficients
void Polynomial::displaySecondPolynomial() const{
	cout << "\n\tThe second polynomial (P2) is entered: ";
	for (int i = 0; i < termSize; i++) {
		//if index is at 1 
		if ((termSize - 1) - i == 1) {
			cout << coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((termSize - 1) - i == 0) {
			cout << coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << coefficients[i] << "x^" << (termSize - 1) - i << " + ";
		}
	}
}

//precondition: going to display all the information
//postcondition: going to allocate and deallocate memory so it does not leak, going to then call my polynomila function
void Polynomial::displayInformationMenu(){
	system("cls");
	char option;
	int optionAComp;
	int theTermSize = 0, multTermSize = 0, multTermSize2 = 0;
	//allocate new memory
	double* coefficientsTerms = new double[theTermSize];
	double* multCoefficientsTerms = new double[multTermSize];
	double* multCoefficientsTerms2 = new double[multTermSize2];
	bool check = false;
	do {
	    beginning:
		cout << "\n\t\tA polynomial is an expression consisting of variables(also called indeterminate) and\n"
			"\t\tcoefficients, that involves only the operations of addition, subtraction, multiplication\n"
			"\t\tand non-negative itneger exponentiation of variables\n";
		cout << "\n\t\t3> - Polynomials";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\tA> A Polynomial";
		cout << "\n\t\t\tB> Multiple Polynomials";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\t0> return";
		cout << "\n\t\t" << string(82, char(205)) << "\n";
		option = inputChar("\t\t\tOption: ", (static_cast<string>("AB0")));
		switch (toupper(option)) {
		case 'A': {
			do {
				system("cls");
				cout << "\n\t\tA> - Single Polynomial";
				cout << "\n\t\t" << string(82, char(205));
				cout << "\n\t\t\t1. Enter the numbers of terms";
				cout << "\n\t\t\t2. Specify the coefficients";
				cout << "\n\t\t\t3. Evaluate expression";
				cout << "\n\t\t\t4. Solve for the derivative";
				cout << "\n\t\t\t5. Solve for the integral";
				cout << "\n\t\t" << string(82, char(205));
				cout << "\n\t\t\t0. return";
				cout << "\n\t\t" << string(82, char(205));
				optionAComp = inputInteger("\n\t\t\tOption: ", 0, 5);
				switch (optionAComp) {
				case 1: {
					theTermSize = inputInteger("\n\t\t\tEnter the number of terms(1..100) for the polynomial : ",1,100);
					//falg it back to false so that it can check case 2 if the coeff have expressions
					check = false;
					cout << "\n";
					system("pause");
					system("cls");
				}
					  break;
				case 2: {
					//if there are no terms, then error
					if (theTermSize == 0) {
						cout << "\n\t\t\tERROR: 0 term. Please enter the number of terms.";
						cout << "\n\n";
						system("pause");
						system("cls");
						break;
					}
					coefficientsTerms = new double[theTermSize];
					cout << "\n";
					for (int i = 0; i < theTermSize; i++) {
						coefficientsTerms[i] = inputDouble("\t\t\tEnter the coefficient for term #" + to_string(i + 1) + ": ");
						//flag it to true
						check = true;
					}
					Polynomial coeff(coefficientsTerms, theTermSize);
					coeff.setCoefficients(coefficientsTerms, theTermSize);
					coeff.getCoefficients(coefficientsTerms, theTermSize);
					coeff.display();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 3: {
					//if there are no terms, then error
					if (theTermSize == 0) {
						cout << "\n\t\t\tERROR: 0 term. Please re-specify the number of terms.";
						cout << "\n\n";
						system("pause");
						system("cls");
						break;
					}
					//going to check if there are coefficients displayed if not, then error
					if (check != true) {
						cout << "\n\t\t\tERROR: expression. Please specify the coefficients.";
						cout << "\n\n";
						system("pause");
						break;
					}
					Polynomial coeff(coefficientsTerms, theTermSize);
					coeff.setCoefficients(coefficientsTerms, theTermSize);
					coeff.getCoefficients(coefficientsTerms, theTermSize);
					coeff.displayP1X();
					double xEvaluate = inputDouble("\n\n\t\t\tEnter the value of x to evaluate the polynomial: ");
					coeff.getEvaluatePolyNomial(coefficientsTerms,theTermSize,xEvaluate);
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 4: {
					//if there are no terms, then error
					if (theTermSize == 0) {
						cout << "\n\t\t\tERROR: 0 term. Please re-specify the number of terms.";
						cout << "\n\n";
						system("pause");
						system("cls");
						break;
					}
					//going to check if there are coefficients displayed if not, then error
					if (check != true) {
						cout << "\n\t\t\tERROR: expression. Please specify the coefficients.";
						cout << "\n\n";
						system("pause");
						break;
					}
					Polynomial coeff(coefficientsTerms, theTermSize);
					coeff.setCoefficients(coefficientsTerms, theTermSize);
					coeff.getCoefficients(coefficientsTerms, theTermSize);
					coeff.displayPolynomialDerivative();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 5: {
					//if there are no terms, then error
					if (theTermSize == 0) {
						cout << "\n\t\t\tERROR: 0 term. Please re-specify the number of terms.";
						cout << "\n\n";
						system("pause");
						system("cls");
						break;
					}
					//going to check if there are coefficients displayed if not, then error
					if (check != true) {
						cout << "\n\t\t\tERROR: expression. Please specify the coefficients.";
						cout << "\n\n";
						system("pause");
						break;
					}
					Polynomial coeff(coefficientsTerms, theTermSize);
					coeff.setCoefficients(coefficientsTerms, theTermSize);
					coeff.getCoefficients(coefficientsTerms, theTermSize);
					coeff.displayPolynomialIntegral();
					cout << "\n\n";
					system("pause");
					system("cls");
				}
					  break;
				case 0: {
					//delete so memory does not leak
					delete[] coefficientsTerms;
					coefficientsTerms = nullptr;
					theTermSize = 0;
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
			system("cls");
			cout << "\n\tB> Two Polynomials";
			multTermSize = inputInteger("\n\t\tEnter the number of terms(1..100) for the first polynomial (P1): ", 1, 100);
			multCoefficientsTerms = new double[multTermSize];
			for (int i = 0; i < multTermSize; i++) {
				multCoefficientsTerms[i] = inputDouble("\t\t\tEnter the coefficient for term #" + to_string(i + 1) + ": ");
			}
			Polynomial multCoefficients1(multCoefficientsTerms, multTermSize);
			multCoefficients1.setCoefficients(multCoefficientsTerms, multTermSize);
			multCoefficients1.getCoefficients(multCoefficientsTerms, multTermSize);
			multCoefficients1.displayFirstPolynomial();

			multTermSize2 = inputInteger("\n\n\t\tEnter the number of terms(1..100) for the second polynomial (P2): ", 1, 100);
			multCoefficientsTerms2 = new double[multTermSize2];
			for (int i = 0; i < multTermSize2; i++) {
				multCoefficientsTerms2[i] = inputDouble("\t\t\tEnter the coefficient for term #" + to_string(i + 1) + ": ");
			}
			Polynomial multCoefficients2(multCoefficientsTerms2, multTermSize2);
			multCoefficients2.setCoefficients(multCoefficientsTerms2, multTermSize2);
			multCoefficients2.getCoefficients(multCoefficientsTerms2, multTermSize2);
			multCoefficients2.displaySecondPolynomial();

			cout << "\n\n\t\tAddition of polynomilas \t\t -> P1 + P2 = "; 
			cout << endl;
			system("pause");
			system("cls");
			delete [] multCoefficientsTerms;
			multTermSize = 0;
			delete[] multCoefficientsTerms2;
			multTermSize2 = 0;

		}
				break;
		case '0': {
			return;
		}
		}

	} while (true);
}
//precondition: going to pass in an obj1 and the second argu as an object as well
//postcondition: going to be getting obj1 coefficients to add the obj2 coefficients
double operator+(const Polynomial& obj1, const Polynomial& obj2) {
	double total = 0.0;
	//first polynomial
	for (int i = 0; i < obj1.termSize; i++) {
		//if index is at 1 
		if ((obj1.termSize - 1) - i == 1) {
			cout << obj1.coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((obj1.termSize - 1) - i == 0) {
			cout << obj1.coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << obj1.coefficients[i] << "x^" << (obj1.termSize - 1) - i << " + ";
		}
	}
	//obj1.coefficients;
	//second polynomial
	for (int i = 0; i < obj2.termSize; i++) {
		//if index is at 1 
		if ((obj2.termSize - 1) - i == 1) {
			cout << obj2.coefficients[i] << "x + ";
		}
		//else index at 0
		else if ((obj2.termSize - 1) - i == 0) {
			cout << obj2.coefficients[i];
			break;
		}
		else {                        //3 index[0][1][2][3] - 1 
			cout << obj2.coefficients[i] << "x^" << (obj2.termSize - 1) - i << " + ";
		}
	}
	return 0.0;
	//total =(obj1.coefficients + obj2.coefficients);
	//return (obj1.coefficients) + (obj2.coefficients);
}