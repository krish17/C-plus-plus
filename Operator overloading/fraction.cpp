//Program by Krishna Bakka and Kranthi kumar Paladugu
//Assignment 2 - Classes
//This program uses operator overloading to do mathematical operations on two functions.


#include "fraction.h"
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

fraction::fraction()
{
	a = 0;
	b = 1;
}

ostream& operator <<(ostream& output, fraction obj)
{
	if (obj.a == 0)
		cout << 0 << endl;
	else if (obj.b == 0)
		cout << "DIVISION BY ZERO." << endl;
	else
	(obj.b == 1) ? output << obj.a : output << obj.a << "/" << obj.b << endl;

	return output;
}

istream& operator >>(istream& input, fraction& obj)
{
	string temp;
	cin >> temp;
	char temp1[20] = { -1 };
	char temp2[20] = { -1 };
	int i = 0;
	bool validInput = true;
	int m = 0;
	while (m<temp.length())
	{
		if (int(temp[m]) < 45 || int(temp[m]) > 57 || int(temp[m])=='.')
		{
			validInput = false;
			cout << "You have entered the invalid input. So the fraction is set to 0." << endl;
			obj.a = 0;
			obj.b = 1;
			break;
		}
		m++;
	}
	if (validInput)
	{
		while (i < temp.length())
		{
			if (temp[i] == '/')
			{
				break;
			}
			temp1[i] = temp[i];
			i++;
		}
		obj.a = atoi(temp1);
		if (obj.a == 0)
		{
			obj.b = 1;
		}
		else 
		{
			int j = 0;
			i++;
			while (i <= temp.length())
			{
				temp2[j] = temp[i];
				i++;
				j++;
			}
			if (temp2[0] == -1)
			{
				obj.b = 1;
			}
			else
			{
				long tempVar = atoi(temp2);
				if (tempVar == 0)
				{
					cout << "DIVISION BY ZERO." << endl;
					cout << "Fraction is set to zero." << endl;
					obj.a = 0;
					obj.b = 1;
				}
				else
				{
					obj.b = tempVar;
				}
			}
		}
	}
	return input;
}

fraction fraction:: operator+(fraction fraction2)
{
	fraction fracAfterAdd;
	
	fracAfterAdd.a = (this->a*fraction2.b) + (fraction2.a*this->b);
	fracAfterAdd.b = this->b*fraction2.b;

	cout << "ADDING BOTH FRACTIONS:" << endl;
	(b == 1) ? cout << a : cout << a << "/" << b;
	cout << " (+) ";
	(fraction2.b == 1) ? cout << fraction2.a<<" : ": cout << fraction2.a << "/" << fraction2.b << " : ";

	return fracAfterAdd;
}

fraction fraction:: operator -(fraction fraction2)
{
	fraction fracAftrSub;

	fracAftrSub.a = (this->a * fraction2.b) - (fraction2.a * this->b);
	fracAftrSub.b = this->b * fraction2.b;

	cout << "SUBSTRACTING BOTH FRACTIONS:" << endl;
	(b == 1) ? cout << a : cout << a << "/" << b;
	cout << " (-) ";
	(fraction2.b == 1) ? cout << fraction2.a << " : ": cout << fraction2.a << "/" << abs(fraction2.b) << " : ";

	return fracAftrSub;
}
	
fraction fraction :: operator *(fraction fraction2)
{
	fraction fracAftrMult;

	fracAftrMult.a = (this->a * fraction2.a);
	fracAftrMult.b = this->b * fraction2.b;

	cout << "MULTIPLYING BOTH FRACTIONS:" << endl;
	(b == 1) ? cout << a : cout << a << "/" << b;
	cout << " (*) ";
	(fraction2.b == 1) ? cout << fraction2.a << " : " : cout << fraction2.a << "/" <<abs(fraction2.b) << " : ";

	return fracAftrMult;
}

fraction fraction :: operator /(fraction fraction2)
{
	fraction fracAftrDiv;

	fracAftrDiv.a = (this->a * fraction2.b);
	fracAftrDiv.b = this->b * fraction2.a;

	cout << "DIVIDING BOTH FRACTIONS:" << endl;
	(b == 1) ? cout << a : cout << a << "/" << b;
	cout << " (/) ";
	(fraction2.b == 1) ? cout << fraction2.a << " : " : cout << fraction2.a << "/" << abs(fraction2.b) << ": ";

	return fracAftrDiv;
}

fraction fraction:: operator -()
{
	fraction fraction1;

	cout << "The negated value for ";
	(b == 1) ? cout << a <<" is " : cout << a << "/" << b<<" is ";
	(b == 1) ? cout << -a << endl : cout << -a << "/" << b << endl;
	
	return fraction1;

}
void fraction:: operator =(fraction fraction1)
{
	a = fraction1.a;
	b = fraction1.b;
}

void fraction::reciprocal()
{
	cout << "The reciprocal for " << a << "/" << b << " is ";

	if (this->a == 1)
		cout << b << endl;
	else
	{
		if (abs(a) == 0)
			cout << "ERROR : DIVISION BY ZERO." << endl;
		else
		cout << b << "/" << abs(a) << endl;
	}
}

bool fraction::operator ==(fraction obj)
{
	if (a == obj.a && b == obj.b)
	{
		return true;
	}
	else
		return false;
}

bool fraction::operator !=(fraction obj)
{
	if (a == obj.a && b == obj.b)
	{
		return false;
	}
	else
		return true;
}

bool fraction :: operator <(fraction obj)
{
	double frac1 = double(a) /double(b);
	double frac2 = double(obj.a) /double(obj.b);

	if (frac1 < frac2)
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is Less than ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;
		return true;
	}
	else
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is NOT Less than ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;
		return false;
	}
}

bool fraction :: operator <=(fraction obj)
{
	double frac1 = double(a) / double(b);
	double frac2 = double(obj.a) / double(obj.b);

	if (frac1 <= frac2)
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is Less than or Equal ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;

		return true;
	}	
	else
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is NOT Less than or Equal ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;

		return false;
	}
}

bool fraction:: operator >(fraction obj)
{
	double frac1 = double(a) / double(b);
	double frac2 = double(obj.a) / double(obj.b);

	if (frac1 > frac2)
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is Greater than  ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;

		return true;
	}
	else
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is NOT Greater than  ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;

		return false;
	}
}

bool fraction:: operator >=(fraction obj)
{
	double frac1 = double(a) / double(b);
	double frac2 = double(obj.a) / double(obj.b);

	if (frac1 >= frac2)
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is Greater than or Equal to ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;

		return true;
	}
	else
	{
		(b == 1) ? cout << a : cout << a << "/" << b;
		cout << " is NOT Greater than or Equal to ";
		(obj.b == 1) ? cout << obj.a << endl : cout << obj.a << "/" << obj.b << endl;

		return false;
	}
}

void fraction::GCD_Call()
{
	long c = abs(a);
	long d =abs(b);
	GCDVar = GCD(c, d);
	a = a / GCDVar;
	b = b / GCDVar;
}

unsigned fraction::GCD(long c, long d)
{
	return c%d ? GCD(d, c%d) : d;
}


fraction :: operator double()
{
	double c = a;
	double d = b;
	cout <<a <<"/"<< b << " Converted to double is: " << c/d << endl;
	return a/b;
}

void fraction::exp(int i)
{
	(b == 1) ? cout << a : cout << a << "/" << abs(b);
	a = pow(a, i);
	b = pow(b, i);
	cout << " To the power of " << i << " is ";
	(b == 1) ? cout << a <<endl: cout << a << "/" << abs(b) << endl;;
}
fraction::~fraction()
{

}
