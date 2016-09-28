//Assignment 3.
//This program calculates line equation.


#include<stdio.h>
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int **arr;
int rows = 0;
int cols = 2;
int n = 0;

double slope();
double indepTerm(double a1);
void theEquation(double a0, double a1);

int main()
{
	srand(time(NULL));
	cout << "How many samples" << " " << endl;
	cin >> n;
	rows = n;

	arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = (rand() % 25) + 1;
		}
	}

	int *x;
	x = new int[rows];
	int *y;
	y = new int[rows];

	for (int i = 0; i < rows; i++)
	{
		x[i] = arr[i][0];
	}
	for (int i = 0; i < rows; i++)
	{
		y[i] = arr[i][1];
	}

	cout << endl;
	double a1 = slope();
	double a0 = indepTerm(a1);

	cout << "slope is (a1) =" << a1 << endl;
	cout << "independent term(a0) = " << a0 << endl;
	theEquation(a0, a1);

	delete[]arr;
	system("pause");
	return 0;
}

double slope()
{
	double xi = 0;
	double yi = 0;
	double xiyi = 0;
	double sqxi = 0;
	double whole_sqxi = 0;
	double slope;

	for (int i = 0; i < rows; i++)
	{
		xi = xi + arr[i][0];
		yi = yi + arr[i][1];
	}

	for (int i = 0; i < rows; i++)
	{
		xiyi = xiyi + (arr[i][0] * arr[i][1]);
	}

	for (int i = 0; i < rows; i++)
	{
		sqxi = sqxi + (arr[i][0] * arr[i][0]);
	}
	slope = ((rows*xiyi) - (xi*yi)) / ((rows*sqxi) - (xi*xi));

	return slope;
}

double indepTerm(double a1)
{
	double xi = 0, yi = 0, a0 = 0;
	for (int i = 0; i < rows; i++)
	{
		xi = xi + arr[i][0];
		yi = yi + arr[i][1];
	}
	xi = xi / rows;
	yi = yi / rows;

	a0 = yi - (a1*xi);

	return a0;
}

void theEquation(double a0, double a1)
{
	cout << "The following set of samples:" << endl;
	cout << setw(3) << "X" << setw(9) << "Y" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << setw(3) << arr[i][0] << setw(9) << arr[i][1] << endl;
	}
	if (a1<0)
		cout << "The equation that describes this system is: y = " << a0 << " " << a1 << "*x." << endl;
	else
		cout << "The equation that describes this system is: y = " << a0 << " + " << a1 << "*x." << endl;
}