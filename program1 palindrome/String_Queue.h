//Palindrome program by Krishna Bakka.
//CMPS-3013-program 1
//This program checks whether the given phrase/word is a palindrome or not.

#pragma once
class String_Queue
{
public:
	String_Queue(int);//constructor

	//This function adds a char to the queue
	//Requires a char
	//Returns none
	void enqueue(char);

	//This function removes a char from the queue
	//Requires none
	//Returns a character
	char dequeue();

	//This function checks whether the queue is empty
	//Requires none
	//Returns true or false
	bool is_empty();

	//This function checks whether the queue is full
	//Requires none
	//Returns true or false
	bool is_full();

	~String_Queue();//Destructor

private:
	char *queue_array;//Pointer to the queue array
	int queue_size;
	int front;
	int rear;
	int num_of_items;
};

