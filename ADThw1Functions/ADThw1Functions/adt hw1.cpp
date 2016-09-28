//Krishna Bakka			                    Program 1

//This program reads the data consisting of x and y from a file and stores
//it in a 2D array. Then it finds out a value of y when some random x, which
//is in between the first and last x value of the table, value is given.

#include<iostream>//preprocessor directive for input and output operations.
#include<iomanip>
#include<fstream>//Preprocessor directive for input and output streams.

using namespace std;

const int SIZE = 10;
typedef double TwoDArray[SIZE][SIZE];
TwoDArray dataValues;//array declaration of the type TwoDArray.

//This function prints the heading to the outfile and to the window.
//Precondition: The function must receive an opened ouputfile.
void printHeading(ofstream &outfile);

//This function prints the array to the output file and to the output window.
//Precondition: the function must receive an opened outfile, array(double), 
//size of the array(int), size of the data(int).
void printTheArray(ofstream &outfile, double dataValues[][SIZE], int SIZE, \
	int dataSize);

//This function opens the file which conain the x and y values.
//Precondition: valid stream objects.
//postcondition: opens both input file and output files for later use and
//returns an integer which represents the size of the data 
//		provided and also stores the data in a 2D array.
int openFiles(ifstream &infile, ofstream &outfile);

//This function reads the data and stores it in a 2D array.
//Precondition: an integer, ifstream object and a double array which contain 
//		the data about x and y.
//Postcondition: 
void readInfile(int, int size, ifstream &, double[][SIZE]);

//This function asks for the x values user wanted to give and validates
//whether the values is in between the first and last x values.
//Precondtion: size of the array, array and the size of the data has to
//		be sent. Both sizes are integer values.
//Postconditon: Returns the double value of x.
double ask_Validate_x(int sizeofarray, double[][SIZE], int sizeofdata);

//This function computes the corresponding y value x.
//Precondition: double value of x, integer values of size of the array and
//		datasize and array has to be sent.
//Postconditon: returns the double value of y.
double compute_Y(double valueofx, int sizeofdata, int sizeofarray, \
	double[][SIZE]);

//This function asks whether the user wanted to give another x value.
//Precondition: the variable bool oneMoreTime has to be set to false.
//Postcondition: returns a bool value.
bool anotherXValue();

//This function enables the user to enter the x value from a different \
//set of input data.
//Precondition: The user has to enter only any of the two characters y or\
//		 n, they are not case sensitive.
//Postcondition: returns bool type data.
bool anotherXfromDifFile();

int main(){
	bool againFromDifFile = false;//This checks whether the user wanted to 
	//give the x value from another input data file.
	int dataSize = 0;
	ifstream infile;
	ofstream outfile;

	do{//This loop is used to facilitate the user to enter the x value
		//from the other input data set file.
		bool againFromSameFile = true;// this checks whether the user wanted
		//to give another x value from the same input file.
		double x = 0;
		double y = 0;

		dataSize = openFiles(infile, outfile);

		printHeading(outfile);

		readInfile(dataSize, SIZE, infile, dataValues);

		printTheArray(outfile, dataValues, SIZE, dataSize);

		while (againFromSameFile == true){//This loop facilitates the user
			//to enter another x from the same input data file.

			if (infile){// condition to check whether the input file is opened.

				x = ask_Validate_x(SIZE, dataValues, dataSize);

				y = compute_Y(x, dataSize, SIZE, dataValues);

				cout << "\nThe corresponding value of x, " << fixed << setprecision(2)\
					<< x << ", is ";
				cout << fixed << setprecision(4) << y << "." << endl;

				outfile << "\nThe corresponding value of x, " << fixed << setprecision(2)\
					<< x << ", is ";
				outfile << fixed << setprecision(4) << y << "." << endl;

				againFromSameFile = anotherXValue();
			}
		}
		infile.close();
		outfile.close();

		againFromDifFile = anotherXfromDifFile();

		againFromSameFile = true;//This resets the variable to true so that the
		//while loop executes when the user enters another x value.

	} while (againFromDifFile == true);

	system("pause");
	return 0;
}

void printHeading(ofstream &outfile)
{
	cout << "\nKrishna Bakka.                     Program 1." << endl;
	outfile << "\nKrishna Bakka.                  Program 1" << endl;
	outfile << "----------------------------------------------------\n\n";
	cout << "-------------------------------------------------------\n\n";

	cout << "This program reads the data consisting of x and y from a file\n";
	cout << "and stores it in a 2D array. Then it computes the value of y when\n";
	cout << "some random x is given. x must be in between the first" << endl;
	cout << "and last x value of the table." << endl;

	outfile << "This program reads the data consisting of x and y from a file\n";
	outfile << "and stores it in a 2D array.Then it finds out a value of y when\n";
	outfile << "some random x is given, which must be in between the first\n";
	outfile << "and last x value of the table." << endl;
}

void printTheArray(ofstream &outfile, double dataValues[][SIZE], int SIZE, \
	int dataSize)
{
	cout << endl << "The table with x and y values is given below: \n\n";

	outfile << endl << "The table with x and y values is given below: \n\n";

	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < dataSize; col++)
		{

			outfile << setw(6) << fixed << setprecision(2)\
				<< dataValues[row][col];

			cout << setw(6) << fixed << setprecision(2) << \
				dataValues[row][col];
		}

		cout << endl;
		outfile << endl;
	}
}

int openFiles(ifstream &infile, ofstream &outfile){
	const int SIZE_OF_FILENAME = 50;
	char inputFile[SIZE_OF_FILENAME];
	char outputFile[SIZE_OF_FILENAME];
	int sizeOfData = 0;

	cout << "\nEnter the input file name: " << endl;
	cin >> inputFile;
	infile.open(inputFile);

	cout << "\nEnter the output file name: " << endl;
	cin >> outputFile;
	outfile.open(outputFile);

	if (!infile || !outfile)
	{
	cout << "\nThere is a problem opening the input and output files.\n\n";
	}
	infile >> sizeOfData;

	return sizeOfData;
}

void readInfile(int dataSize, int size, ifstream &infile, double dataarray[][SIZE])
{
	for (int row = 0; row < 2; row++)//loop to read values into the array.
	{
		for (int col = 0; col < dataSize; col++)
		{
			infile >> dataarray[row][col];
		}
	}
}

double ask_Validate_x(int size, double dataarray[][SIZE], int datasize)
{
	double valueOfx = 0;
	cout << "\nPlease enter the value of x." << endl;

	do{
		cin >> valueOfx;
		if (valueOfx < dataarray[0][0] || valueOfx > dataarray[0][datasize - 1])
		{
			cout << "\nSorry, The value of x must be in between " << \
				dataarray[0][0] << " and " << dataarray[0][datasize - 1] << ".\n";
			cout << "Now enter the value of x." << endl;
		}
	} while (valueOfx < dataarray[0][0] || valueOfx > dataarray[0][datasize - 1]);

	return valueOfx;
}

double compute_Y(double x, int datasize, int size, double dataarray[][SIZE])
{

	double y_a, y_b, x_a, x_b, y = 0;
	int col = 0;

	while (dataarray[0][col] < x){
		x_b = dataarray[0][col];
		y_b = dataarray[0 + 1][col];
		x_a = dataarray[0][col + 1];
		y_a = dataarray[0 + 1][col + 1];

		y = y_b + ((y_a - y_b) / (x_a - x_b))*(x - x_b);

		col++;
	}
	col = 0;
	while (col < datasize)
	{
		if (dataarray[0][col] == x)
			y = dataarray[1][col];
		col++;
	}
	return y;
}

bool anotherXValue(){
	char y_n;

	cout << endl << "Please type y, if you want enter another x else";
		cout << " type n: " << endl;
	cin >> y_n;

	if (y_n == 'N' || y_n == 'n')
		return false;
	else
		return true;
}

bool anotherXfromDifFile()
{
	char yesOrNo;

	cout << "\nDo you want to give x value from a different set of input data?\n";
	cout << "If so, please type y else type n." << endl;

	cin >> yesOrNo;

	if (yesOrNo == 'y' || yesOrNo == 'Y')
		return true;
	else
		return false;
}

