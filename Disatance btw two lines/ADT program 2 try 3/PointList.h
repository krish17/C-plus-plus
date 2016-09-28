#pragma once
#include"Point.h"
const int SIZE = 20;
typedef Point pointList[SIZE];//what happens if i keep the sqr brackets here..

//This class stores the Point array and number of Points currently in the array.
class PointList
{
private:
	pointList pointObjects;
	int numOfpoints;//this gives the number of points in the array.

public:

	//This function fills the array of Point objects of the pointObjectArray which is a private data.
	//Precondition: a data type Point and intiger size of the array is needed to be sent.
	//Postcondition: returns none;
	void setPointObjects(Point pointObject, int i);

	//This function is provides the data from pointObjectArray to the user application
	//Precondition: an integer data type is needed to be provided.
	//Postcondition: returns a Point data type.
	Point getPointObjects(int i);//i is the counter in the array.

	//This function sets the number of points currently present in the array.
	//Preconditon: an integer data type is needed to be provided.
	//Postcondition: Returns none.
	void setNumOfPoints(int numOfPoints);

	//This function gives the number of points currently present in the array.
	//Precondition: none;
	//Postcondition: This function retuns an integer data type
	int getNumOfPoints();

	PointList();//constructor
	~PointList();//destructor
};

