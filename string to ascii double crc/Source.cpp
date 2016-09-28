//Krishna Bakka.

//Programming project
//CMPS-5213: Wireless Computer Communications and Networks.


//This program performs the double CRC(16 and 12) to the given string of message
//and displays the final message in the hexadecimal format.

#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include<string>
#include<iostream>

using namespace std;

//This function converts the given string into binary digits and stores them in an array
//Precondition: integer, an integer array and an address of another integer array
//Postcondition: none.
void binar(int charr, int bin[], int &binlength);

//This function runs the whole program twice, such that two CRC's are implemented.
void mainFunction();

//This function converts the given binary digits into hexadecimal values.
void HexVal();

//This function does the EXOR operation
//Precondition: requires two integers on which exor has to be implemented
//Postcondition: returns integer.
int EXOR(int x, int y);

//This function appends the crc-16 to the message.
void Append1();

//This function appends the crc-12 to the message.
void Append2();

//This function performs the CRC-16.
void CRC16();

//This function performs the CRC-12.
void CRC12();


int finalLength = 0;
int finalBinary[1000] = { -1 };//stores the message
int length = 0;//length of the message.
int CRC16Arr[16] = { 0 };
int CRC12Arr[12] = { 0 };
string HexTempVal = "";

int main()
{
	int bin[1000] = { -1 };//Array to store the binary values.
	int binlength = 0;
	int charr[100];//Array to store the integer values of the string.
	string strVal;
	int i = 0;

	cout << "Enter the string:" << endl;
	cin >> strVal;

	int a;
	for (int j = 0; j < strVal.length(); j++)
	{
		a = (int)strVal[j];
		charr[j] = a;

		binar(a, bin, binlength);

		for (int i = 0; i < binlength; i++)
		{
			int a = bin[i];
			finalBinary[length] = a;
			length++;
		}
	}

	mainFunction();

	HexVal();

	system("pause");

	return 0;
}

void binar(int dec, int bin_ary[], int &i)
{
	int tmp;
	i = 0;
	tmp = dec;

	while (tmp != 0)
	{
		bin_ary[i] = tmp % 2;
		tmp = tmp / 2;
		i++;
	}
	
	while (i < 8)
	{
		bin_ary[i] = 0;
		i++;
	}

	int temp;
	int len = i;

	for (int i1 = 0, i2 = len - 1; i1 < len / 2; i1++, i2--)
	{
		temp = bin_ary[i2];
		bin_ary[i2] = bin_ary[i1];
		bin_ary[i1] = temp;
	}

	finalLength = i;
}

int EXOR(int x, int y)
{
	if (x + y == 1)
		return 1;
	else
		return 0;
}

void Append1()
{
	int TempLen = length;

	for (int i = 15; i >= 0; i--)
	{
		finalBinary[TempLen] = CRC16Arr[i];
		TempLen++;
	}

	length = TempLen;
}

void Append2()
{
	int TempLen = length;

	for (int i = 11; i >= 0; i--)
	{
		finalBinary[TempLen] = CRC12Arr[i];
		TempLen++;
	}

	length = TempLen;
}

void CRC16()
{
	int outBit, TempVal;

	for (int i = 0; i < length; i++)
	{
		outBit = CRC16Arr[15];

		for (int k = 15; k > 0; k--)
		{
			CRC16Arr[k] = CRC16Arr[k - 1];
		}

		TempVal = EXOR(outBit, finalBinary[i]);
		CRC16Arr[0] = TempVal;
		CRC16Arr[2] = EXOR(TempVal, CRC16Arr[2]);
		CRC16Arr[15] = EXOR(TempVal, CRC16Arr[15]);
	}

	Append1();
}

void HexVal()
{
	int cVal = 0;
	int count = 0;
	int intSumVal = 0;
	stringstream strs;

	for (int i = 0; i < length; i++)
	{
		intSumVal += finalBinary[i] * pow(2.0, 3 - count);
		count++;

		if (count == 4){
			if (intSumVal < 10)
			{
				strs << intSumVal;
			}
			else
			{
				switch (intSumVal){
				case 10:
					strs << "A";
					break;
				case 11:
					strs << "B";
					break;
				case 12:
					strs << "C";
					break;
				case 13:
					strs << "D";
					break;
				case 14:
					strs << "E";
					break;
				case 15:
					strs << "F";
					break;
				}
			}

			count = 0;
			intSumVal = 0;
		}
	}
	cout << strs.str() << endl;
	cout << endl;
}

void CRC12()
{
	int outBit, TempVal;

	for (int i = 0; i < length; i++)
	{
		outBit = CRC12Arr[11];

		for (int k = 11; k > 0; k--)
		{
			CRC12Arr[k] = CRC12Arr[k - 1];
		}

		TempVal = EXOR(outBit, finalBinary[i]);
		CRC12Arr[11] = EXOR(TempVal, CRC12Arr[11]);
		CRC12Arr[3] = EXOR(TempVal, CRC12Arr[3]);
		CRC12Arr[2] = EXOR(TempVal, CRC12Arr[2]);
		CRC12Arr[1] = EXOR(TempVal, CRC12Arr[1]);
		CRC12Arr[0] = TempVal;
	}

	Append2();
}

void mainFunction()
{
	CRC16();
	CRC12();
}