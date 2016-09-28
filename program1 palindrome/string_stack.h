//Palindrome program by Krishna Bakka.
//CMPS-3013-program 1
//This program checks whether the given phrase/word is a palindrome or not.

#pragma once
#include<string>

struct Node
{
	char letter;
	Node* next;
};

class string_stack
{
public:
	string_stack();//constructor
	~string_stack();//destructor

	//This function pushes a character on to the stack
	//Requires a character
	//Returns none
	void push(char letter);

	//This function pops up a character from the top of stack
	//Requires none
	//Returns a  character from the top of the stack
	char pop();

private:
	Node* head;// pointer to head
	Node* top;//pointer to top element of  the stack.
	Node * previous;
};


