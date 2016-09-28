#include "charList.h"
#include<iostream>
#include<string>
using namespace std;

charList::charList()
{
	length = 0;
	head = new Node;

	head->next = new Node;
	head->next->next = NULL;

	current = head;
}

void charList::add(char incomingc)
{
	current = head;

	Node *temp;
	temp = new Node;

	temp->c = incomingc;

	if (head->next->next == NULL && length == 0)
	{
		temp->next = head->next;
		head->next = temp;

		length++;
	}
	else
	{
		findc(incomingc);

		temp->next = current->next;
		current->next = temp;
		length++;
	}
}

void charList::findc(char incomingc)
{
	bool found = false;
	current = head;

	while (current->next->next != NULL && found == false)
	{
		if (current->next->c >= incomingc)
		{
			found = true;
		}
		else
		{
			current = current->next;
		}
	}
}

void charList::displayList() 
{
	Node *nodePtr = head->next;
	while (nodePtr->next != NULL)
	{
		//Print the value in the current node
		cout << nodePtr->c << ' ';
		//move onto the next node
		nodePtr = nodePtr->next;
	}
}

void charList::remove(char c)
{
	findc(c);
	Node *temp1;
	temp1 = current->next;
	current->next = temp1->next;

	delete temp1;
}

void charList::deleteList()
{
	current = head;
	while (current->next != NULL)
	{
		Node *garbage = current;
		current = current->next;
		delete garbage;
	}
}



charList::~charList()
{
}
