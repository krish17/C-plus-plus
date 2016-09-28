#pragma once;
#include "BookList.h"
#include<iostream>
#include<string>
using namespace std;

BookList::BookList()
{
	length = 0;
	head = new Node;

	head->next = new Node;
	head->next->next = NULL;

	current = head;
}

string BookList::getBook1()
{
	return current->bookName;
}

bool BookList::atEnd()
{
	if (current->next->next == NULL)
		return true;
	else
		return false;
}

void BookList::addTheBook(string incomingBook)
{
	current = head;
	
	Node *temp;
	temp = new Node;

	temp->bookName = incomingBook;
	
	if (head->next->next == NULL && length == 0)
	{
		temp->next = head->next;
		head->next = temp;
		
		length++;
	}
	else
	{
		findBook(incomingBook);

		temp->next = current->next;
		current->next = temp;
		length++;
	}
}

string BookList::getTheBook()
{
	return current->next->bookName;
}

void BookList::reset()
{
	current = head;
}

void BookList::advance()
{
	current = current->next;
}

void BookList::removeBook(string book)
{
	findBook(book);
	Node *temp1;
	temp1 = current->next;
	current->next = temp1->next;

	delete temp1;
}

void BookList::findBook(string incomingBook)
{
	bool found = false;
	current = head;

	while (current->next->next != NULL && found == false)
	{
		if (current->next->bookName >= incomingBook)
		{
			found = true;
		}
		else
		{
			current = current->next;
		}
	}
}

void BookList::deleteList()
{
	current = head;
	while (current->next != NULL)
	{
		Node *garbage = current;
		current = current->next;
		delete garbage;
	}
}

int BookList::getLength()
{
	return length;
}
BookList::~BookList()
{

}