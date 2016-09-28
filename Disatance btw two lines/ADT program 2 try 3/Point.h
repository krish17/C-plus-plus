#pragma once
#ifndef POINT_H
#define POINT_H
class Point
{
private:
	double x = 0, y = 0;

public:
	Point();//constructor.
	~Point();//destructor.

	//This function sets the value of x.
	//Precondition: a double x is must be sent.
	//Postcondition: sets the value of x, a double.
		void setx(double x);

	//This function sets the value of y.
	//Precondition: a double y is must be sent.
	//Postcondition: sets the value of y, a double.
		void sety(double y);

	//This function sets retrieves the value of x and gives it to the application code.
	//Precondition: Must be assigned to the double variable.
	//Postcondition: Gives the value of x, a double.
		double getx();


	//This function sets retrieves the value of y and gives it to the application code.
	//Precondition: Must be assigned to the double variable.
	//Postcondition: Gives the value of y, a double.
		double gety();
};
#endif