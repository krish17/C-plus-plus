//Assignment 3: Comparison of AVL and Red Black trees.
//Krishna Bakka 

#pragma once
#include<iostream>

using namespace std;

struct node
{
	int key;
	node *parent;
	char color;
	node *left;
	node *right;
};
class RBtree
{
	node *root;

public:
	RBtree()
	{
		root = NULL;
	}
	void insert(int z);
	void insertfix(node *);
	void leftrotate(node *);
	void rightrotate(node *);
	void InOrder(node * ptr);
	void print();
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);
	void GraphVizOut(string filename);
	~RBtree();
};

