
//Assignment 3: Comparison of AVL and Red Black trees.
//Krishna Bakka 


#include<iostream>
#include"AVLTree.h"
#include<time.h>
#include"RBtree.h"
#include<chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	srand(unsigned(1110));
	high_resolution_clock::time_point t1 = high_resolution_clock::now();


	//AVLTree A;
	//int rn;
	//srand(unsigned(time(0)));
	//for (int count = 0; count < 5; count++)
	//{
	//	rn = rand() % 100;
	//	A.Insert(rn);
	//}
	//cout << "In order print of tree:  \n";
	//A.Print();
	//cout << endl;
	//A.GraphVizOut("test.gv");


	RBtree obj;
	int ch = 0, num;

	while (ch<5)
	{
		num = rand() % 100;

		obj.insert(num);
		ch++;
	}
	obj.print();
	cout << endl;
	obj.GraphVizOut("test1.gv");


	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout << duration << endl;
	system("pause");
	return 0;
}