//Krishna Bakka.
//Hashing project code.
//This program hashing technique to fill the given data in to a table by using two CRP's.


#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

const int MAX_TABLESIZE = 999;

int main()
{
	int address = 0;
	int probeArray[999] = { 0 };
	int hashArray[MAX_TABLESIZE] = { 0 };
	char inputFileName[100];
	char outputFileName[100];
	int INCR = 0;//collision resolution policy.
	int tableSize = 0;//n
	double totalProbeCount = 0;
	double avgProbesPerKey = 0;
	int dataSize = 0;
	int key = 0;

	cout << "\nPlease enter the file name you wanted to give: " << endl;
	cin >> inputFileName;

	cout << "Please enter the name of the output file: " << endl;
	cin >> outputFileName;

	cout << "Please enter the size of the table, maximum table size is "<<MAX_TABLESIZE<<":";
	cin >> tableSize;

	cout << "Please enter the CRP, INCR = 1 or 2 or 5: ";
	cin >> INCR;

	ifstream infile;
	infile.open(inputFileName);
	ofstream outfile;
	outfile.open(outputFileName);

	outfile << "Krishna Bakka." << endl;
	outfile << "Hashing project code." << endl;
	outfile << "This program hashing technique to fill the given data in to a table by using two CRP's." << endl;
	outfile << "This table has INCR of 1." << endl;

	outfile << "\n****** HASH TABLE ******\n" << endl;

	for (int i = 0; i < tableSize; i++){//sets all the table values to -1.
		hashArray[i] = -1;
	}
	
	infile >> key;
	
	while (!infile.eof()){
		dataSize++;

		int probe = 1;//probe counter.

		address = (key) % tableSize;//hash function.
		
		while (hashArray[address] != -1){//checks for collision.
			probe++;
			
			address = (address + INCR) % tableSize;
		}

		hashArray[address] = key;
		probeArray[address] = probe;
		//outfile << key << endl;
		//outfile << "address" << address << endl;
		infile >> key;
	}
	//outfile << fixed << setprecision(2);
	cout << "total keys are " << dataSize << endl;
	//outfile << "1. Name                              : Krishna Bakka." << endl;
	//outfile << "2. Table Size                        : " << tableSize<< endl;
	//outfile << "3. Increment Value                   : " << INCR << endl;
	
	for (int i = 0; i < tableSize; i++){
		totalProbeCount = totalProbeCount + probeArray[i];
	}

	//avgProbesPerKey = totalProbeCount / dataSize;

	//outfile << "4. Total Number of probes            : " << totalProbeCount << endl;
	//outfile << "5. Average number of probes per key  : " << avgProbesPerKey << endl;

	outfile << setw(5) << "Index" << setw(7) << "KEY" << setw(10) << "Probe" << endl;
	for (int i = 0; i < tableSize; i++){
		outfile << setw(3) << i << ". " << setw(7) << hashArray[i] << setw(8) << probeArray[i] << endl;
	}
	outfile << "\nThe total probe count is: " << totalProbeCount << endl;

	infile.close();
	outfile.close();

	system("pause");
	return 0;
}
	


















	