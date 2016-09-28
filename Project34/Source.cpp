#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double sum = 0, n =0,x=0;
	cout << "limit" << endl;
	cin >> n;
	cout << "x" << endl;
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		sum = (pow(-1, n) / (2 * n + 1))*(pow(x, 2 * n + 1));
	}

	cout << "sum" << sum*3.14/180 << endl;
	system("pause");
	return 0;
}