//Palindrome program by Krishna Bakka.
//CMPS-3013-program 1
//This program checks whether the given phrase/word is a palindrome or not.

#include "string_stack.h"
#include<iostream>
using namespace std;

string_stack::string_stack()
{
	head = NULL;
}

void string_stack::push(char letter1)
{
	if (head == NULL)
	{
		head = new Node;
		head->letter = letter1;
		head->next = NULL;
		top = head;
	}
	
	else
	{
		top->next = new Node;
		top = top->next;
		top->letter = letter1;
		top->next = NULL;
	}
}

char string_stack::pop()
{
	char letter1;
	top = head;
	while (top->next != NULL)
	{
		previous = top;
		top = top->next;
	}
	Node* temp = top;

	letter1 = top->letter;
	top = previous;
	top->next = NULL;
	delete temp;
	return letter1;
}

string_stack::~string_stack()
{
}
