//Program by Krishna Bakka and Kranthi kumar Paladugu
//Assignment 2 - Classes
//This program uses operator overloading to do mathematical operations on two functions.


#include<iostream>
#include "fraction.h"
using namespace std;
unsigned long GCD(unsigned long a, unsigned long b);
int main()
{
	fraction fraction1;
	fraction fraction2;
	fraction NewFraction1;
	fraction NewFraction2;
	fraction resultFraction;
	bool oneMoreTime = false;

	do
	{
		cout << "PLEASE ENTER YOUR FRACTIONS AS 'A/B' WITHOUT QUOTES THEN --> ENTER." << endl;
		cout << "Numerator/Denominator : ";
		cin >> fraction1;
		cout << endl;

		cout << "Numerator/Denominator : ";
		cin >> fraction2;
		cout << endl;

		fraction1.GCD_Call();
		fraction2.GCD_Call();

		cout << "--------------------------------------------------" << endl;
		cout << "CONVERTING BOTH FRACTIONS TO DOUBLE." << endl;
		double a = fraction1; //using double operator overloading
		double b = fraction2;

		cout << "--------------------------------------------------" << endl;
		resultFraction = fraction1 + fraction2; //using addition and = operator overloading
		cout << resultFraction << endl;

		cout << "--------------------------------------------------" << endl;
		resultFraction = fraction1 - fraction2;//using substraction and = operator overloading
		cout << resultFraction << endl;

		cout << "--------------------------------------------------" << endl;
		resultFraction = fraction1 * fraction2;//using multiplication and = operator overloading
		cout << resultFraction << endl;

		cout << "--------------------------------------------------" << endl;
		resultFraction = fraction1 / fraction2;//using division and = operator overloading
		cout << resultFraction << endl;

		cout << "--------------------------------------------------" << endl;
		cout << "NEGATING BOTH FRACTIONS:" << endl;
		-fraction1;
		-fraction2;

		cout << "--------------------------------------------------" << endl;
		cout << "CALCULATING RECIPROCAL FOR BOTH FRACTIONS: " << endl;
		fraction1.reciprocal(); //calculates reciprocal 
		fraction2.reciprocal();

		cout << "--------------------------------------------------" << endl;
		cout << "CHECKING IF FRACTIONS ARE EQUAL:" << endl;

		if (fraction1 == fraction2) //overloads ==
			cout << "Fractions ARE equal." << endl;

		if (fraction1 != fraction2)//overloads !=
			cout << "Fractions are NOT equal." << endl;

		cout << "--------------------------------------------------" << endl;
		cout << "CHECKING IF FRACTION (A) IS LESS THAN FRACTION (B):" << endl;
		fraction1 < fraction2;//overloads <

		cout << "--------------------------------------------------" << endl;
		cout << "CHECKING IF FRACTION (A) IS LESS THAN OR EQUAL TO FRACTION (B):" << endl;
		fraction1 <= fraction2;//overloads <=

		cout << "--------------------------------------------------" << endl;
		cout << "CHECKING IF FRACTION (A) IS GREATER THAN FRACTION (B):" << endl;
		fraction1 > fraction2;//overloads >

		cout << "--------------------------------------------------" << endl;
		cout << "CHECKING IF FRACTION (A) IS GREATER THAN OR EQUAL TO FRACTION (B):" << endl;
		fraction1 >= fraction2;//overloads >=

		cout << "--------------------------------------------------" << endl;
		cout << "ASSIGNING A NEW VALUE TO A FRACTION." << endl;

		cout << "Please type a new value for Fraction A: ";
		cin >> NewFraction1; //overloads input stream

		cout << "Please type a new value for Fraction B: ";
		cin >> NewFraction2;

		cout << "--------------------------------------------------" << endl;

		cout << "Previous value for (A) was " << fraction1 << "----> New value for (A) is: ";//overloads output stream
		fraction1 = NewFraction1;
		cout << fraction1 << endl;

		cout << "Previous value for (B) was " << fraction2 << "----> New value for (B) is: ";
		fraction2 = NewFraction2;
		cout << fraction2 << endl;

		cout << "--------------------------------------------------" << endl;
		int power = 0;
		cout << "FRACTIONS TO THE POWER OF i:" << endl;
		cout << "Please enter the power value i: ";
		cin >> power;

		fraction1.exp(power);//finds exponential
		fraction2.exp(power);
		cout << endl << endl;

		char flag;
		cout << "WOULD YOU LIKE TO START OVER ? YES --->(any # different to 0) NO --->(Enter 0)." << endl;
		cin >> flag; //takes input whether to repeat whole process one more time
		if (flag == '0')
			oneMoreTime = false;
		else
			oneMoreTime = true;

	} while (oneMoreTime);

	system("pause");
	return 0;
}