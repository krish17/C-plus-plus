#pragma once
#include<string>
using namespace std;


class Graphs
{
private:
	string vertices[100];
	int adj_matrix[100][100];
	string a[100];
	string b[100];
	int s;
	int size;

public:
	Graphs();
	void collect_data(string a[], string b[], int size, int s);
	void fill_vertices();
	void fill_matrix();
	void print_data();
	~Graphs();
};

