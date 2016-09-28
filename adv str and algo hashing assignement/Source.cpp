//Krishna Bakka.
//Hashing project code.
//This program hashing technique to fill the given data in to a table by using two CRP's.
//CMPS 3013 

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const int MAX_TABLESIZE = 511;

int crp_1();//function for linear probing CRP
int crp_2();//function for quadratic probing

int main()
{
	cout << "Welcome to the hash table program." << endl;
	cout << "\nThis table performs hashing using 2 different CRPs." << endl;
	cout << "1. Linear Increment of 1." << endl;
	cout << "2. Quadratic Increment of square." << endl;

	cout << "\nThe size of the hashtable is " << MAX_TABLESIZE << " ." << endl;
	cout << "The number of elements inserted are " << 100 << " ." << endl;

	cout << "\nCollisions for collision resolution policy 1 is: " << crp_1() << endl;
	cout << "Collisions for collision resolution policy 2 is: " << crp_2() << endl;

	system("pause");
	return 0;
}
int crp_1()
{
	int INCR = 1;//collision resolution policy.
	int tableSize = MAX_TABLESIZE;
	int key = 0;
	int hashArray[MAX_TABLESIZE] = { 0 };
	int address = 0;//denotes the place where a particular key must go in the hast table.
	int collisions = 0;
	srand(20215580);//seed for generating random numbers.

	for (int i = 0; i < tableSize; i++)
	{//sets all the table values to -1.
		hashArray[i] = -1;
	}

	for (int i = 0; i < 100; i++)
	{
		key = (rand()) % 1000;//gets the numbers below 1000;

		address = (key) % tableSize;//hash function.

		while (hashArray[address] != -1)//collision detection and resolution.
		{
			address = (address + INCR) % tableSize;
			collisions++;//collision counter.
		}

		hashArray[address] = key;
	}
	return collisions;
}

int crp_2()
{
	srand(125263);
	int INCR = 1;//collision resolution policy.
	int tableSize = MAX_TABLESIZE;//n
	int key = 0;
	int hashArray[MAX_TABLESIZE] = { 0 };
	int address = 0;
	int collisions = 0;
	int increment = 0;//This is used to store the square of the number 
						//of times of collision for a particular key.

	for (int i = 0; i < tableSize; i++){//sets all the table values to -1.
		hashArray[i] = -1;
	}

	for (int i = 0; i < 100; i++)
	{
		key = rand() % 1000;

		address = (key) % tableSize;//hash function.

		while (hashArray[address] != -1)
		{
			increment = INCR*INCR;
			address = (address + increment) % tableSize;
			collisions++;
			INCR++;
		}

		hashArray[address] = key;
	}
	return collisions;
}


















