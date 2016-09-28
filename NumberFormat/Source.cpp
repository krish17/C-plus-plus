//Krishna Bakka
//This program prints the number with commas when a long number is given.

#include<iostream>

using namespace std;

//This function prints out the given number with appropriate commas.
//Precondition: requires a long integer and reference to an integer "count".
//Postcondition: prints the number to the output.
void printNumber(long num, int &count);

int main()
{
	long number = 0;

	cout << "Dear user, please enter a long number: " << endl;
	cin >> number;
	cout << "The number you entered with appropriate commas is: "<<endl;

	while (number != -1)
	{
		int count = 0;//counter for the number of digits in the given number.
		printNumber(number, count);
		cout << endl;
		cout << "\nDear user, if you wish to enter another long number," << endl;
		cout<<"type the number, else type - 1:"<<endl;
		cin >> number;
		if (number != -1)
			cout << "The number you entered with appropriate commas is: "<<endl;
	} 
	cout << endl;
	system("pause");
	return 0;
}

void printNumber(long num, int &count)
{
	count++;

	if (num != 0)
	{
		printNumber(num / 10, count);

		cout << (num % 10);

		if (((count + 2) % 3) == 0 && count != 1)
		{
			cout << ",";
		}
	}
	count--;
}