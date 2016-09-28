#include <iostream>
using namespace std;

int recGCD(int x, int y);
int main()
{
	int x, y;
	cout << "get me two numbers: " << endl;
	cin >> x >> y;

	cout<<"GCD is : "<< recGCD(x, y)<<endl;

	system("pause");

	return 0;

	
}

int recGCD(int x, int y)
{
	if (x%y == 0)
		return y;
	recGCD(y, x%y);

}