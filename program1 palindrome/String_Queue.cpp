//Palindrome program by Krishna Bakka.
//CMPS-3013-program 1
//This program checks whether the given phrase/word is a palindrome or not.

#include "String_Queue.h"
#include<iostream>

using namespace std;

String_Queue::String_Queue(int size)
{
	queue_array = new char[size];
	queue_size = size;
	front = -1;
	rear = -1;
	num_of_items = 0;
}

void String_Queue::enqueue(char alpha)
{
	if (is_full())
		cout << "Queue is full." << endl;
	else
	{
		rear = (rear + 1)%queue_size;
		queue_array[rear] = alpha;
		num_of_items++;
	}
}

char String_Queue::dequeue()
{
	if (is_empty())
		cout << "Queue is empty." << endl;
	else
	{
		char alpha;
		front = (front + 1) % queue_size;
		alpha = queue_array[front];
		num_of_items--;
		return alpha;
	}
}

bool String_Queue::is_empty()
{
	if (num_of_items > 0)
		return false;
	else
		return true;
}

bool String_Queue::is_full()
{
	if (num_of_items < queue_size)
		return false;
	else
		return true;
}

String_Queue::~String_Queue()
{
	delete queue_array;
}
