//Krishna Bakka.
//Program 2.
//CMPS 1063.
//This program finds the distance between the two points and add them all.

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include"Point.h"
#include"PointList.h"
#include<string>
#include<iomanip>

using namespace std;

Point pointObject;
PointList pointListObject;

//This function prints the heading to the outfile and the screen.
//Precondition: ofstream object and the referenced outfile is needed.
//Postcondition: outfile must be opened.
void printHeader(ofstream &outfile);

//This function opens the input and output files.
//Precondition: Files needed to be opened are to be sent to the function.
//Postcondition: none.
void openFiles(ifstream &infile, ofstream &outfile);

//This function prints the bye bye message and footer.
//Precondition: output file is needed.
//Postcondition: none.
void printFooter(ofstream &outfile);

//This function reads the coordinates from input data and puts in the pointObjects, 
		//which is private data of PointList class object.
//Precondition: two doubles(x and y), Point object, input file, two integers, 
		//all are to be referenced.
//Postcondition: input file remains opened, all Point objects are filled with 
		//x and y coordintes.
void readX_Y(double &x, double &y, Point &pointObject, int &sizeOfData,\
				int &arraycounter, ifstream &infile);

//This function checks whether the file is opened correctly or not.
//Precondition: infile and outfile should be referenced.
//Postcondition: files either opened or not opened.
void ifFilesOpen(ifstream &infile, ofstream &outfile);

//This function prints distances to the output file.
//Precondition: outfile, double(distance), double(totalDistance) are to be referenced.
//Postcondition: output is printed to the output file.
void printTheResult(ofstream &outfile, double &distance, double &totaldistance);

int main(){

	int sizeOfData = 0;//counter to know total number of points in input data.
	int arrayCounter = 0;//counter for number of objects in objects-array.
	double totalDistance = 0;
	double distance = 0;

	ifstream infile;
	ofstream outfile;

	openFiles(infile, outfile);
	ifFilesOpen(infile,outfile);
	printHeader(outfile);

	double x, y;

	readX_Y(x, y, pointObject, sizeOfData, arrayCounter, infile);
	
	pointListObject.setNumOfPoints(sizeOfData);//updates the number of points in the in the array.

	printTheResult(outfile, distance, totalDistance);
	
	printFooter(outfile);

	infile.close();
	outfile.close();

	system("pause");
	return 0;
}
void openFiles(ifstream &infile, ofstream &outfile){
	char inputFileName[40], outputFileName[40];
	cout << "Dear user, welcome to the Many Points Distance Program." << endl;

	cout << "\nPlease enter the input file name:" << endl;
	cin.getline(inputFileName,40);

	cout << "Now please enter the output file name:" << endl;
	cin.getline(outputFileName, 40);

	infile.open(inputFileName);
	outfile.open(outputFileName);
}

void printHeader(ofstream &outfile){
	outfile << "Krishna Bakka." << endl;
	outfile << "Program 2." << endl;
	outfile << "CMPS 1063." << endl;
	outfile << "This program finds the distance between the two points and add them all." << endl;
	outfile << "\nWelcome to the many Points distance program.\n" << endl;
}

void printFooter(ofstream &outfile){
	outfile << "Thank you for using many Points distance program." << endl;
	outfile << "Bye....." << endl;
}

void readX_Y(double &x, double &y, Point &pointObject, int &sizeOfData, \
											int &arrayCounter, ifstream &infile){
	while (!infile.eof()){

		infile >> x;
		infile >> y;

		pointObject.setx(x);
		pointObject.sety(y);

		pointListObject.setPointObjects(pointObject, arrayCounter);

		sizeOfData++;
		arrayCounter++;
	}
}

void ifFilesOpen(ifstream &infile, ofstream &outfile){
	if (infile && outfile){
		cout << "\nCongratulations, input and output files are successfully opened." << endl;
		cout << "Now, please check the output file for the results.\n" << endl;
	}

	else
	{
		cout << "\nSorry, there is a problem in opening the input and output files." << endl;
	}
}

void printTheResult(ofstream &outfile, double &distance, double &totalDistance){
	outfile << "  Point" << setw(20) << "Point" << setw(22) << "   Distance" << endl;

	for (int i = 0; i < pointListObject.getNumOfPoints() - 2; i++){

		distance = sqrt(pow(pointListObject.getPointObjects(i + 1).getx() - \
			pointListObject.getPointObjects(i).getx(), 2) + \
			   pow(pointListObject.getPointObjects(i + 1).gety() - \
			       pointListObject.getPointObjects(i).gety(), 2));

		totalDistance = totalDistance + distance;

		outfile << fixed << setprecision(2);

		outfile << "(" << pointListObject.getPointObjects(i).getx() << "," <<\
			pointListObject.getPointObjects(i).gety() << ")" << setw(10) << "(" \
			  << pointListObject.getPointObjects(i + 1).getx() << "," << \
			     pointListObject.getPointObjects(i + 1).gety() << ")" << setw(15) <<\
			        distance << ".\n" << endl;
	}
	outfile << endl << "The total distance is " << totalDistance << "." << endl;
}