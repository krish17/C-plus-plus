#include<iostream>
#include<string>
#include<fstream>
#include"charList.h"

using namespace std;

int main()
{
	charList list;
	string word;
	string choice;

	cout << "give me the word" << endl;
	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		list.add(word[i]);
	}

	list.displayList();
	cout << endl;
	char removec;
	cout << "give me the letter you want to delete" << endl;
	cin >> removec;

	list.remove(removec);

	cout << "After removing the character the list is " << endl;
	list.displayList();
	cout << endl;
	list.deleteList();

	system("pause");
	return 0;
}