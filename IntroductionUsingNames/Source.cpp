#include<iostream>
#include<fstream>
#include"Graphs.h"

using namespace std;
 
int main()
{
	ifstream infile;
	infile.open("input.dat");

	string vertices[100];
	int matrix[100][100];
	int size;
	string a[100];
	string b[100];

	Graphs graphs;

	infile >> size;
	int s = 0;

	while (!infile.eof())
	{
		infile >> a[s];
		infile >> b[s];
		s++;
	}

	graphs.collect_data(a, b, size, s);
	graphs.print_data();



	system("pause");
	return 0;
}