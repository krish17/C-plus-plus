//Assignment 3: Comparison of AVL and Red Black trees.
//Krishna Bakka 

#include<fstream>
#include<iostream>

using namespace std;

class AVLTree
{
private:
	struct Node {
		int value;
		Node *left;
		Node *right;
		int bf;		// store balance factor for each node
		int count;  // store the count of number; duplicate not stored in tree
	};
	Node *root;
	bool LeftHeavy(Node * ptr);
	bool RightHeavy(Node * ptr);
	void RotateLeft(Node *& SubRoot);
	void RotateRight(Node *& SubRoot);
	int Height(Node * ptr);
	int BalFact(Node * ptr);
	void ComputeBF(Node *& ptr);
	void InsertNode(Node * & ptr, int x);
	void InOrder(Node * ptr);
	void GraphVizGetIds(Node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(Node *nodePtr, ofstream &VizOut);
public:
	AVLTree();
	~AVLTree();
	void Insert(int x);
	void Print();
	void GraphVizOut(string filename);
};



