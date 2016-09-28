#include<iostream>
#include<fstream>
#include"Graph.h"
using namespace std;

int main()
{
	ifstream input;
	input.open("info.txt");
	Graph graph;

	int i, j, size;

	input >> size;

	while (!input.eof())
	{
		input >> i >> j;
		graph.setData(i, j);
	}

	cout << "Introductions" << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (graph.getData(i, j) == 0)
				cout << i << ":" << j << endl;
		}
	}

	system("pause");
	return 0;

}
