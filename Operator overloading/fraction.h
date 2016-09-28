//Program by Krishna Bakka and Kranthi kumar Paladugu
//Assignment 2 - Classes
//This program uses operator overloading to do mathematical operations on two functions.

#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class fraction
{
private:
	long a;
	long b;
	long GCDVar = 0;

public:
	fraction();
	//converts a fraction into double
	operator double();
	//calls gcd function
	void GCD_Call();
	//finds the gcd of numerator and denominator
	unsigned GCD(long c,long d);

	//multiplies the fractions
	fraction operator *(fraction);
	//divides the fractions
	fraction operator /(fraction);
	//adds the two fractions
	fraction operator +(fraction);
	//substracts the fractions
	fraction operator -(fraction);
	//negates a fraction
	fraction operator -();
	//assigns a fraction value to another
	void operator =(fraction);
	//returns the reciprocal of a fraction
	void reciprocal();
	//returns a fraction raised to the power according to the passed in value
	void exp(int);
	//comparison operators
	bool operator ==(fraction);
	bool operator !=(fraction);
	bool operator <(fraction);
	bool operator <=(fraction);
	bool operator >(fraction);
	bool operator >=(fraction);

	//input stream operator
	friend istream& operator >>(istream&, fraction&);
	//output stream operator
	friend ostream& operator <<(ostream&, fraction);

	//destructor
	~fraction();
};

