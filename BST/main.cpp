//Krishna Bakka
//Program 2 Binary Search Tree
//This program generates ten randon numbers and constructs a binary tree from it.

#include"BST.h"
#include<iostream>

using namespace std;

int main()
{
	BST b;
	int a,count=0;
	while (count!=10)
	{
		a=rand() % 100 + 1;//Generates random numbers
		b.Insert(a);//Inserts the random number.
		cout << a<<endl;
		count = count + 1;
	}
	b.traversal();
	b.GraphVizOut("original.dot");
	system("pause");
	return 0;
	
}