#pragma once
class Graph
{
private:
	int matrix[200][200];
public:
	Graph();
	void setData(int i, int j);
	int getData(int i, int j);
	~Graph();
};

