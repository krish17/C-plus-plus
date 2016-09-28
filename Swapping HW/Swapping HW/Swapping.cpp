//krishna Bakka							Jan 26th 2015.

//This program asks for two numbers and swaps them

#include<iostream>//Pre-processor directive for input and output streaming
//objects
using namespace std;

void swap(int&, int&);//function protocol

int main()
{
	int a, b;
	cout << "Give me two numbers and I will swap them for you. " << endl;
	cout << endl<<"Now enter the first Number: ";
	cin >> a;
	cout << endl<<"Now enter the second Number: ";
	cin >> b;
	swap(a, b);//function calling
	cout <<endl<< "The numbers after swapping are ";
	cout << a << " and " << b << "."<< endl;
	return 0;
}

//This functions get two integers from the main function
//and swap and returns them through referencing

//Precondition: x and y must be integers.
void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}