//Advanced Computer architecture - CMPS 5133.

//Project done by:
//			Krishna Bakka (M20207138)


//This program simulates the cache. The cache is 5-way set associative.
//Line sizes taken are 4, 8, 16, 32, 64, 128, 256, 512, 1024.

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<cmath>
#include<string>
#include<fstream>

using namespace std;

ifstream infile;
ofstream outfile;

//This function takes the input from the file. 
void address_input(long bin_array[], long lineSize, long &tagSize, long &setSize, long &offsetSize, long &tagDec, long &setDec, long &offsetDec);

//This converts the decimal into binary
void dec_to_bin(long long dec, long bin_ary[]);

//This function converts the binary into decimal
long long bin_to_dec(long bin_array[]);

//This function simulates the cache.
void cache(long tagDec, long setDec, long lineSize, long &miss, long &hits, long &fifo, long &first, long cacheArray[600][5]);

int main()
{
	cout << "Cache Simulation." << endl;
	cout << "Associativity: 5-way." << endl;
	cout << "Total cache size is 10240 Bytes.\n" << endl;

	infile.open("input.txt");
	long miss = 0;
	long hits = 0;
	long fifo = 0;//fifo alogorithm 
	long first = 0;
	long cacheArray[600][5];
	long lineSize = 0;
	long long address = 0;
	long tagSize = 0;
	long setSize = 0;
	long offsetSize = 0;

	long tagDec =0;//tag in decimal
	long setDec = 0;//set in decimal
	long addDec = 0;//address in decimal
	long offsetDec = 0;
	long bin_array[32];

	for (long i = 0; i < 600; i++)
	{
		for (long j = 0; j < 5; j++)
		{
			cacheArray[i][j] = -1;//initialization of cache array to -1
		}
	}

	cout << "Please enter the line size: ";
	cin >> lineSize;

	long temp;
	
	while (! infile.eof())
	{
		infile >> temp;
		address_input(bin_array,lineSize,tagSize,setSize,offsetSize,tagDec,setDec,offsetDec);
		cache(tagDec, setDec, lineSize, miss, hits, fifo, first, cacheArray);
	}

	for (long i = 0; i < 600; i++)
	{	
		cout  << i << " ";
		for (long j = 0; j < 5; j++)
		{
			cout << cacheArray[i][j]<<"  ";
		}
		cout << endl;
	}
	cout << "Above data shows the final Cache state after all the data is accessed. " << endl;
	cout << "\nLINE SIZE IS: " << lineSize << " BYTES." << endl;
	cout << "OFFSET: " << offsetSize << " BITS." << endl;
	cout << "SETNO: " << setSize << " BITS." << endl;
	cout << "TAG: " << tagSize << " BITS.\n" << endl;
	cout << "MISSES: " << miss << endl;
	cout<<  "HITS:   " << hits << endl;
	
	cout << endl;
	system("pause");
	return 0;
}

void address_input(long bin_array[],long lineSize, long &tagSize, long &setSize, long &offsetSize, long &tagDec, long &setDec, long &offsetDec)
{
	long tag[32];
	long setNo[32];
	long offset[32];
	long long address;
	long num_of_lines = 0;
	long num_of_sets = 0;

	offsetSize = log2(lineSize);
	num_of_lines = 10240 / lineSize;
	num_of_sets = num_of_lines / 5;

	setSize = log2(num_of_sets);
	tagSize = 32 - (offsetSize + setSize);

	for (int a = 0; a < 32; a++)
	{
		bin_array[a] = 0;
		tag[a] = 0;
		setNo[a] = 0;
		offset[a] = 0;
	}

	infile >> hex >> address;
	dec_to_bin(address, bin_array);

	long i = 0;
	long j = 31;
	long k = 0;
	while (i < offsetSize)
	{
		offset[j] = bin_array[i];
		i++;
		j--;
	}
	j = 31;
	while (k < setSize)
	{
		setNo[j] = bin_array[i];
		i++;
		j--;
		k++;
	}
	j = 31;
	k = 0;
	while (k < tagSize)
	{
		tag[j] = bin_array[i];
		i++;
		j--;
		k++;
	}

	offsetDec = bin_to_dec(offset);
	tagDec = bin_to_dec(tag);
	setDec = bin_to_dec(setNo);
}

void dec_to_bin(long long dec, long bin_ary[])
{
	long long tmp, i = 0, j = 0;
	tmp = dec;
	while (tmp != 0)
	{
		bin_ary[i] = tmp % 2;
		tmp = tmp / 2;
		i++;
		j++;
	}
}

long long bin_to_dec(long bin_array[])
{
	long power = 0;
	long long sum = 0;
	for (long i = 31; i >= 10; i--)
	{
		sum = sum + (pow(2, power)*(bin_array[i]));
		power++;
	}
	return sum;
}

void cache(long tagDec, long setDec, long lineSize, long &miss, long &hits, long &fifo,long &first, long cacheArray[600][5])
{
	bool found = false;

	for (long j = 0; j < 5; j++)
	{
		if (cacheArray[setDec][j] == tagDec)
		{
			hits++;
			found = true;
			break;
		}
	}
	if (found == false)
	{
		cacheArray[setDec][fifo] = tagDec;
		fifo++;
		miss++;
		found = false;
		if (fifo >= 5)
			fifo = 0;
	}
}
