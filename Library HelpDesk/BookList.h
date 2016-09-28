#pragma once
#include<string>

using namespace std;

struct Node
{
	string bookName;
	Node *next;
};

class BookList
{
public:
	//returns the length
	//Precondition: none;
	//Postcondition:returns integer.
	int getLength();

	//adds the books to list
	//Precondition: requires the string;
	//Postcondition:none.
	void addTheBook(string book1);

	//returns the book
	//Precondition: none;
	//Postcondition: returns string.
	string getTheBook();

	//deletes the book
	//Precondition: none;
	//Postcondition:none.
	void removeBook(string book);

	//resets the current to head
	//Precondition: none;
	//Postcondition: current pointer will be equal to head.
	void reset();

	//This function finds the position of the given book in the list.
	//Precondition: requires the string of book name.
	//Postcondition: none.
	void findBook(string incomingBook);

	//This function finds whether the current is at the end.
	//Precondition: none;
	//Postcondition: returns true if at the end.
	bool atEnd();

	//returns the book
	//Precondition: none;
	//Postcondition: returns string.
	string getBook1();

	//This function advances the position of the current by one node
	//Precondition: none;
	//Postcondition: none.
	void advance();

	//This function deletes the list
	//Precondition: none;
	//Postcondition: none.
	void deleteList();
	
	BookList();//constructor
	~BookList();//destructor

private:
	int length = 0;
	Node *head;
	Node *current;
};