#include "BST.h"
#include<iostream>
using namespace std;

BST::BST()
{
	root = NULL;
	
}

BST::~BST()
{
}

// The InsertNode method is a recursive private method that will be passed
// a pointer (root initially) and a character to be added to the tree.  If the 
// character already exists in the tree, counts are updated, but no new node is 
// inserted.  If the character does not already exist in the tree, a new node is 
//  created and appropriately linked in to the correct position.
///////////////////////////////////////////////////////////////////////////////

void BST::InsertNode(Node * &ptr, int x)
{
	if (ptr != NULL && ptr->data == x)
	{
		ptr->count++;
	
	}
	else if (ptr == NULL)  // ptr points to NULL insertion position
	{
		ptr = new Node;
		ptr->data = x;
		ptr->count = 1;
		ptr->left = NULL;
		ptr->right = NULL;

	}
	else if (x <= ptr->data)			// node should be inserted in left subtree
		InsertNode(ptr->left, x);
	else								// node should be inserted in right subtree
		InsertNode(ptr->right, x);
	//cout << TotCount << endl;
}


// The Insert method is a public method that calls InsertNode.
////////////////////////////////////////////////////////////////

void BST::Insert(int x)
{
	InsertNode(root, x);

}

void BST::preOrder(Node *root)
{

	if (root != NULL)
	{
		cout << root->data << "  ";
		preOrder(root->left);
		preOrder(root->right);
	}
}


void BST::inOrder(Node *root)
{

	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->data << "  ";
		inOrder(root->right);
	}
}

void BST::postOrder(Node *root)
{

	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << "  ";
	}
}

// Credit to:  Terry Griffin
// This method writes out the edge connections.
//////////////////////////////////////////////////////////////////////
void BST::GraphVizMakeConnections(Node *nodePtr, ofstream &VizOut){
	if (nodePtr){
		if (nodePtr->left)
			VizOut << nodePtr->data << "->" << nodePtr->left->data << ";\n";
		if (nodePtr->right)
			VizOut << nodePtr->data << "->" << nodePtr->right->data << ";\n";
		GraphVizMakeConnections(nodePtr->left, VizOut);
		GraphVizMakeConnections(nodePtr->right, VizOut);
	}
}

// Credit to:  Terry Griffin
// Recieves a filename to place the GraphViz data into.
// It then calls the above graphviz method to create a 
// data file that can be used to visualize your tree.
//////////////////////////////////////////////////////////////////////
void BST::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename.c_str());
	VizOut << "//Krishna Bakka \n";
	VizOut << "// Graph for Binary tree\n";
	VizOut << "digraph { \n";
	VizOut << "name [label = \"Krishna Bakka \\nCMPS 3013\", shape = box]; \n";
	GraphVizMakeConnections(root, VizOut);
	VizOut << "} \n";
	VizOut.close();
}

void BST::traversal()
{
	cout << "Inorder:: ";
	inOrder(root);
	cout << endl << "preOrder::";
	preOrder(root);
	cout << endl << "postOrder::";
	postOrder(root);
}