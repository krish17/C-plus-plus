//Assignment 3: Comparison of AVL and Red Black trees.
//Krishna Bakka 

#include "AVLTree.h"
#include<iostream>
#include<fstream>
#include<chrono>

using namespace std;

AVLTree::AVLTree()
{
	root = NULL;
}

AVLTree::~AVLTree()
{
}
// If balance factor is positive,
// the subtree is left heavy

bool AVLTree::LeftHeavy(Node * ptr)
{
	if (ptr->bf > 0)
		return true;
	else
		return false;
}

// If balance factor is negative,
// the subtree is right heavy

bool AVLTree::RightHeavy(Node * ptr)
{
	if (ptr->bf < 0)
		return true;
	else
		return false;
}

// Method to perform left rotation if AVL tree
// is out of balance.  First determines if a right
// rotation is required.

void AVLTree::RotateLeft(Node *& SubRoot)
{
	if (SubRoot->right != NULL && LeftHeavy(SubRoot->right)){
		RotateRight(SubRoot->right);
	}

	Node *Temp;
	Temp = SubRoot->right;
	SubRoot->right = Temp->left;
	Temp->left = SubRoot;
	SubRoot = Temp;
	ComputeBF(SubRoot);
}
// Method to perform right rotation if AVL tree
// is out of balance.  First determines if a left
// rotation is required.

void AVLTree::RotateRight(Node *& SubRoot)
{
	if (SubRoot->left != NULL && RightHeavy(SubRoot->left)){
		RotateLeft(SubRoot->left);
	}

	Node *Temp;
	Temp = SubRoot->left;
	SubRoot->left = Temp->right;
	Temp->right = SubRoot;
	SubRoot = Temp;
	ComputeBF(SubRoot);
}

// Method called by BalFact
// Returns the height of a node by
// recursively traveling down the tree
// to determine the longest path.
int AVLTree::Height(Node * ptr)
{
	int leftheight = 0;
	int rightheight = 0;
	if (ptr == NULL)
		return 0;
	else
	{
		leftheight = Height(ptr->left) + 1;
		rightheight = Height(ptr->right) + 1;
	}
	if (leftheight > rightheight)
		return leftheight;
	else
		return rightheight;
}

// Method called by ComputeBF 
// Returns leftheight - righthight of
// the pointer given.

int AVLTree::BalFact(Node * ptr)
{
	int leftheight = Height(ptr->left);
	int rightheight = Height(ptr->right);
	return leftheight - rightheight;
}
// Method to recursively update all balance
// factors from the pointer given

void AVLTree::ComputeBF(Node *& ptr)
{
	if (ptr){
		ComputeBF(ptr->left);
		ComputeBF(ptr->right);
		ptr->bf = BalFact(ptr);
	}
}

// Private insert method

void AVLTree::InsertNode(Node * & ptr, int x)
{
	if (ptr == NULL)
	{
		ptr = new Node;
		ptr->value = x;
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->bf = 0;
		ptr->count = 1;
	}
	else
	{
		if (x < ptr->value)    // Insert in left subtree
			InsertNode(ptr->left, x);
		else if (x > ptr->value)	// Insert in right subtree
			InsertNode(ptr->right, x);
		else     // duplicate node; don't insert, just update count        
			ptr->count++;
		// after method recurses down to the point of insertion,
		// execution will feed back to calculate the balance 
		// factors of nodes along the path to the inserted node.
		// Rotations will take place as needed.
		ptr->bf = BalFact(ptr);
		if (ptr->bf > 1)
			RotateRight(ptr);
		else if (ptr->bf < -1)
			RotateLeft(ptr);
	}
}

// Public method to call insert

void AVLTree::Insert(int x)
{
	InsertNode(root, x);
}

// Private InOrder print

void AVLTree::InOrder(Node * ptr)
{
	if (ptr){
		InOrder(ptr->left);
		cout << ptr->value << " ";
		InOrder(ptr->right);
	}
}

// Public method to call inorder print 

void AVLTree::Print()
{
	InOrder(root);
}
// Method to help create GraphViz code so the expression tree can 
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive 
// tree traversal.

void AVLTree::GraphVizGetIds(Node *ptr, ofstream &VizOut){
	if (ptr){
		GraphVizGetIds(ptr->left, VizOut);
		VizOut << "node" << ptr->value << "[label=\"" << ptr->value << " (" << ptr->bf << ", " << ptr->count << ")\"]" << endl;
		GraphVizGetIds(ptr->right, VizOut);
	}
}

// This method is partnered with the above method, but on this pass it 
// writes out the actual data from each node.

void AVLTree::GraphVizMakeConnections(Node *ptr, ofstream &VizOut){
	static int x = 0;
	if (ptr){
		x++;
		if (ptr->left)
			VizOut << "node" << ptr->value << "->" << "node" << ptr->left->value << endl;
		if (ptr->right)
			VizOut << "node" << ptr->value << "->" << "node" << ptr->right->value << endl;
		GraphVizMakeConnections(ptr->left, VizOut);
		GraphVizMakeConnections(ptr->right, VizOut);
	}
	else{
		//cout<<"NULL"<<endl;
	}
}

// Public method which works with two methods directly above to print
// file readable by GraphViz.
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.

void AVLTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename.c_str());
	VizOut << "digraph { \n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "}";
	VizOut.close();
}

