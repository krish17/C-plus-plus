#pragma once
struct Node
{
	char c;
	Node* next;
};
class charList
{
public:

	charList();

	void insert(char c);

	void add(char c1);

	void remove(char c);

	void findc(char incomingChar);

	void displayList();

	void deleteList();

	~charList();

private:
	int length = 0;
	Node *head;
	Node *current;
};


