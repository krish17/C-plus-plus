
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const int rowSize = 21;
const int colSize = 21;
void mat(char blobarray[][colSize], int irow, int jcol)
{
	if (blobarray[irow][jcol] != '*')
		return;
	else
	{
		blobarray[irow][jcol] = '#';
	}
	mat(blobarray, irow + 1, jcol);
	mat(blobarray, irow, jcol + 1);
	mat(blobarray, irow - 1, jcol);
	mat(blobarray, irow, jcol - 1);
}
void counting(char blobarray[][colSize], int row, int col, int &blobCount)
{
	for (int irow = 0; irow < row; irow++)
	{
		for (int jcol = 0; jcol < col; jcol++)
		{
			if (blobarray[irow][jcol] == '*')
			{
				mat(blobarray, irow, jcol);
				blobCount++;
			}
		}
	}
}
int main(void)
{
	int blobCount = 0;
	char blobarray[rowSize][colSize];
	ifstream infile;
	ofstream outfile;
	infile.open("blobs.dat");
	for (int irow = 0; irow < rowSize; irow++)
	{
		for (int jcol = 0; jcol < colSize; jcol++)
		{
			blobarray[irow][jcol] = '0';
		}
	}

	for (int irow = 1; irow < rowSize; irow++)
	{
		for (int jcol = 1; jcol < colSize; jcol++)
		{
			infile >> blobarray[irow][jcol];
		}
	}
	counting(blobarray, rowSize, colSize, blobCount);
	outfile.open("output.txt");
	for (int irow = 1; irow < rowSize; irow++)
	{
		for (int jcol = 1; jcol < colSize; jcol++)
		{
			outfile << blobarray[irow][jcol];
		}
		outfile << endl;
	}
	outfile << endl;
	outfile << "NUMBER OF BLOBS " << blobCount << endl;
	outfile.close();
	infile.close();
	system("pause");
	return 0;
}