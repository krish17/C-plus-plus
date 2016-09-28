//Assignment 3: Comparison of AVL and Red Black trees.
//Krishna Bakka

#include "RBtree.h"
#include<iostream>
#include<fstream>
using namespace std;


//Method to insert data elements.
void RBtree::insert(int z)
{
	int i = 0;
	node *p, *q;
	node *t = new node;
	t->key = z;
	t->left = NULL;
	t->right = NULL;
	t->color = 'r';
	p = root;
	q = NULL;
	if (root == NULL)
	{
		root = t;
		t->parent = NULL;
	}
	else
	{
		while (p != NULL)
		{
			q = p;
			if (p->key<t->key)
				p = p->right;
			else
				p = p->left;
		}
		t->parent = q;
		if (q->key<t->key)
			q->right = t;
		else
			q->left = t;
	}
	insertfix(t);
}

//Method to print the tree in preorder format
void RBtree::InOrder(node * ptr)
{
	if (ptr){
		InOrder(ptr->left);
		cout << ptr->key << " ";
		InOrder(ptr->right);
	}
}

//Method to call Inorder function which prints the tree.
void RBtree::print()
{
	InOrder(root);
}

//Method which balances the color. This method rearranges all the colours 
//according to Red Black tree properties.
void RBtree::insertfix(node *t)
{
	node *u;
	if (root == t)
	{
		t->color = 'b';
		return;
	}
	while (t->parent != NULL&&t->parent->color == 'r')
	{
		node *g = t->parent->parent;
		if (g->left == t->parent)
		{
			if (g->right != NULL)
			{
				u = g->right;
				if (u->color == 'r')
				{
					t->parent->color = 'b';
					u->color = 'b';
					g->color = 'r';
					t = g;
				}
			}
			else
			{
				if (t->parent->right == t)
				{
					t = t->parent;
					leftrotate(t);
				}
				t->parent->color = 'b';
				g->color = 'r';
				rightrotate(g);
			}
		}
		else
		{
			if (g->left != NULL)
			{
				u = g->left;
				if (u->color == 'r')
				{
					t->parent->color = 'b';
					u->color = 'b';
					g->color = 'r';
					t = g;
				}
			}
			else
			{
				if (t->parent->left == t)
				{
					t = t->parent;
					rightrotate(t);
				}
				t->parent->color = 'b';
				g->color = 'r';
				leftrotate(g);
			}
		}
		root->color = 'b';
	}
}

void RBtree::leftrotate(node *p)
{
	if (p->right == NULL)
		return;
	else
	{
		node *y = p->right;
		if (y->left != NULL)
		{
			p->right = y->left;
			y->left->parent = p;
		}
		else
			p->right = NULL;
		if (p->parent != NULL)
			y->parent = p->parent;
		if (p->parent == NULL)
			root = y;
		else
		{
			if (p == p->parent->left)
				p->parent->left = y;
			else
				p->parent->right = y;
		}
		y->left = p;
		p->parent = y;
	}
}
void RBtree::rightrotate(node *p)
{
	if (p->left == NULL)
		return;
	else
	{
		node *y = p->left;
		if (y->right != NULL)
		{
			p->left = y->right;
			y->right->parent = p;
		}
		else
			p->left = NULL;
		if (p->parent != NULL)
			y->parent = p->parent;
		if (p->parent == NULL)
			root = y;
		else
		{
			if (p == p->parent->left)
				p->parent->left = y;
			else
				p->parent->right = y;
		}
		y->right = p;
		p->parent = y;
	}
}

// Method to help create GraphViz code so the expression tree can 
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive 
// tree traversal.

void RBtree::GraphVizGetIds(node *ptr, ofstream &VizOut){
	if (ptr){
		GraphVizGetIds(ptr->left, VizOut);
		//VizOut << "node" << ptr->color << "[label=\"" << ptr->color  << ptr->color << ")\"]" << endl;
		GraphVizGetIds(ptr->right, VizOut);
	}
}

// This method is partnered with the above method, but on this pass it 
// writes out the actual data from each node.

void RBtree::GraphVizMakeConnections(node *ptr, ofstream &VizOut){
	static int x = 0;
	if (ptr){
		x++;
		if (ptr->left)
			VizOut << ptr->key << "->" << ptr->left->key << endl;
		if (ptr->right)
			VizOut << ptr->key << "->" << ptr->right->key << endl;
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

void RBtree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename.c_str());
	VizOut << "digraph { \n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "}";
	VizOut.close();
}

RBtree::~RBtree()
{
}
