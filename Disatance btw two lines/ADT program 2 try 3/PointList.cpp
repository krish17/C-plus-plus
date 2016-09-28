#include "PointList.h"

PointList::PointList()
{
}

PointList::~PointList()
{
}

void PointList::setPointObjects(Point pointObject, int i){
	pointObjects[i] = pointObject;
}

Point PointList::getPointObjects(int i){
	return pointObjects[i];
}

void PointList::setNumOfPoints(int num_of_Points){
	numOfpoints = num_of_Points;
}

int PointList::getNumOfPoints(){
	return numOfpoints;
}
