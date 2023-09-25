//Christian Hernandez
//Date: 9/28/2023
//subscription: CMPR131

#include<iostream>
#include"input (1).h"
#include"Complex.h"
#include"Polynomial.h"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge3();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		//case 2: challenge2(); break;
		case 3: challenge3(); break;
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
	cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Christian Hernandez(9/28/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Complex Numbers";
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t3> Polynomials";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: going to call my Complex class that has the real number and imaginary number
//postcondition: going to then call my displayInformation function that will have all the information and the menus as well
void challenge1(){
	Complex menu;
	menu.displayInformation();
}


//precondition: going to call my Polynomial class that single and multiple polynoials
//postcondition: going to then call the dispalyInformation function that will have the informations of what we need with the menus as well
void challenge3() {
	Polynomial menu;
	menu.displayInformationMenu();
}