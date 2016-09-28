#include<iostream>
#include<string>

using namespace std;
int main()
{
	string temp;
	cin >> temp;
	char temp1[20];
	char temp2[20];
	int i = 0;
	cout << "ascii " << int('/') << endl;
	while (i < temp.length())
	{
		if (temp[i] == '/')
		{
			break;
		}
		temp1[i] = temp[i];
	
		i++;
	}
	int x = atoi(temp1);
	if (x != 0)
	{
		int j = 0;
		i++;
		while (i <= temp.length())
		{
			temp2[j] = temp[i];
			cout << "i" << i << endl;
			i++;
			j++;
		}
	}
	int y = atoi(temp2);

	cout << "temmp"<<temp <<" x "<< x<<" y " << y << endl;
	system("pause");
	return 0;
}
