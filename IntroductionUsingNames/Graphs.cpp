#include "Graphs.h"
#include<iostream>

using namespace std;
Graphs::Graphs()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			adj_matrix[i][j] = 0;
		}
	}
}

void Graphs::collect_data(string in_a[], string in_b[], int in_size, int in_s)
{
	for (int i = 0; i < in_s; i++)
	{
		a[i] = in_a[i];
		b[i] = in_b[i];
	}

	size = in_size;
	s = in_s;
	fill_vertices();
}
void Graphs::fill_vertices()
{
	int n = 0;
	bool there = false;

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (a[i] == vertices[j])
				there = true;
		}
		if (!there)
		{
			vertices[n] = a[i];
			n++;
		}
		there = false;
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (b[i] == vertices[j])
				there = true;
		}
		if (!there)
		{
			vertices[n] = b[i];
			n++;
		}
		there = false;
	}
	fill_matrix();

}

void Graphs::fill_matrix()
{
	int row, col;

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i] == vertices[j])
				row = j;
		}
		for (int k = 0; k < size; k++)
		{
			if (b[i] == vertices[k])
				col = k;
		}

		adj_matrix[row][col] = 1;
	}
}

void Graphs::print_data()
{
	cout << "Name/Explanation" << endl;
	cout << "Introductions:" << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (adj_matrix[i][j] == 0)
			{
				cout << vertices[i] << " : " << vertices[j] << endl;
			}
		}
	}
}



Graphs::~Graphs()
{
}
