//lkjdlkfjsd

#include<iostream>
#include"CriminalList.h"

using namespace std;

int main(){

	int totalCriminals = 0;
	int skipVal = 0;
	cout << "Enter the total number of criminals ";
	cin >> totalCriminals;
	cout << "Enter skip value ";
	cin >> skipVal;
	CriminalList criminal(totalCriminals, skipVal);


	system("pause");
	return 0;


}