
//Implemention of BSTree.h File
#pragma once
#include<fstream>
using namespace std;
struct Node
{
	int data;
	int count;
	Node *left, *right;
};
class BST
{
public:
	BST();
	~BST();
//This function inserts the integer into binary tree
	void Insert(int);

	void GraphVizMakeConnections(Node *nodePtr, ofstream &VizOut);
	void GraphVizOut(string filename);
//Traverses the binary tree through inorder principle
	void inOrder(Node* n);
//Traverses the binary tree through preorder principle
	void preOrder(Node* n);
//Traverses the binary tree through postorder principle
	void postOrder(Node* n);
	void traversal();
	
private:
	
	Node *root;
	void InsertNode(Node *&ptr, int x);

};

