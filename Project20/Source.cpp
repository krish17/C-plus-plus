#include<iostream>
#include<string>
 
using namespace std;

int main()
{
	//int someint = atoi(some);
	//cout << "some int  "<<someint << endl;

	//long address;
	//cout << " give me the number " << endl;
	//cin >> hex >> address;
	//cout << address << endl;

	long power = 0;
	int sum = 0;
	for (int i = 31; i >= 13; i--)
	{
		sum = sum + (pow(2, power)*1);
		power++;
	}
	cout << "sum " << sum << endl;

	system("pause");
	return 0;
}