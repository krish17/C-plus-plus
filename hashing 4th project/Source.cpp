//Krishna Bakka.
//Hashing project code.
//This program checks how many collisions are required to fill 
//a given set of data in different prime numbered tables.

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

const int MAX_TABLESIZE = 10000;

int main()
{
	int address = 0;
	int hashArray[MAX_TABLESIZE];
	int INCR = 3;//collision resolution policy.
	int tableSize = 0;//n
	int dataSize = 100;
	int key = 0;
	int dataArray[100];
	int collisions=-1;

	ifstream infile;
	infile.open("input2.txt");
	ofstream outfile;
	outfile.open("output2.txt");

	outfile << "Krishna Bakka." << endl;
	outfile << "Hashing project code." << endl;
	outfile << "This program checks how many collisions are required to fill" << endl;
	outfile<<"a given set of data in different prime numbered tables." << endl;
	

	outfile << "\n************************* HASH TABLE **************************\n" << endl;

	for (int i = 0; i < 100; i++)
		infile >> dataArray[i];

	infile.close();

	infile.open("primes.txt");
	
	outfile << setw(10) << "Table Size" << setw(18) << "Percent Full" << setw(20) << \
		"Total Collisions" << endl;

	int k = 0;

	while (collisions!=0)
	{
		collisions = 0;
		infile >> tableSize;

		for (int i = 0; i < tableSize; i++)
		{
			hashArray[i] = -1;
		}

		for (int i = 0; i < 100; i++)
		{
			key = dataArray[i];

			address = (key) % tableSize;//hash function.

			if (hashArray[address] != -1)//increments if collision
				collisions++;

			while (hashArray[address] != -1)//checks for collision.
			{
				address = (address + INCR) % tableSize;
			}

			hashArray[address] = key;
		}

		double percentFull = (double(100) / double(tableSize)) * 100;

			if (collisions != 0)
		outfile << fixed << setprecision(2) << setw(10) << tableSize << setw(18) << \
		percentFull << setw(20) << collisions << endl;
	}
	
	infile.close();
	outfile.close();

	system("pause");
	return 0;
}



















