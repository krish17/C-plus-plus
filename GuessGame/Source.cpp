/*
Aim:	This program uses a queue implemented by a singly linked list to operate a
game where the user guesses random numbers flashed on the screen.
*/
#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

// The code below declares the queue template class
template<class T>
class Queue
{
private:
	struct ListNode
	{
		T value;
		ListNode* next;
		ListNode(T v, ListNode* n = NULL)
		{
			value = v;
			next = n;
		}
	};
	ListNode* front;
public:
	Queue();
	~Queue();
	void enqueue(T num);
	T dequeue();
	T peek();
	bool isEmpty();


	class Underflow{};
};

template <class T>
Queue<T>::Queue()
{
	front = NULL;
}

template <class T>
Queue<T>::~Queue()
{
	ListNode* ptr = front;
	while (ptr != NULL)
	{
		front = front->next;
		delete ptr;
		ptr = front;
	}
}

template <class T>
void Queue<T>::enqueue(T num)
{
	ListNode* p = front;
	if (front == NULL)
		front = new ListNode(num);
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = new ListNode(num);
	}
}

template <class T>
T Queue<T>::dequeue()
{
	ListNode* pt = front;
	T temp = 0;
	if (isEmpty())
		throw Queue::Underflow();
	else
	{
		front = front->next;
		temp = pt->value;
		delete pt;
		pt = NULL;
		return temp;
	}

}

template <class T>
T Queue<T>::peek()
{
	if (!isEmpty())
		return front->value;
	throw Queue::Underflow();
}


template <class T>
bool Queue<T>::isEmpty()
{
	return (front == NULL);
}

int main()
{
	srand(time(NULL));
	Queue<int> guessA;
	int numGuess = 0, secs = 0, guess = 0, numRand = 0;

	cout << "For this game, the user would enter the amount of times he/she \n";
	cout << "wants to guess a number between 100,000 and 9,999,999. The user \n";
	cout << "would then be prompted to input the number of milliseconds he/she \n";
	cout << "wants to be able to see the number for before he/she can enter \n";
	cout << "their guess. If any of the guesses are incorrect, the user would \n";
	cout << "have to guess that number again at the end of the list. The game \n";
	cout << "will end when the user guesses all of the numbers correctly." << endl;

	system("pause");
	system("cls");

	cout << "Please enter the amount of numbers you would like to guess." << endl;
	cin >> numGuess;

	while (numGuess <= 0)
	{
		cout << "The amount entered must be reflected by a positive integer. \n";
		cout << "Please enter another number. " << endl;
		cin >> numGuess;
	}
	// The following code will insert random numbers into the queue
	for (int x = 0; x < numGuess; x++)
	{
		guessA.enqueue((rand() % 10000000) + 100000);
	}
	system("cls");
	cout << "Please enter the amount of milliseconds you will be allowed" << endl;
	cout << "to see the number for before guessing." << endl;

	cin >> secs;

	cout << "Press [Enter] when you're ready to begin the game." << endl;
	cin.ignore();
	system("cls");

	while (!(guessA.isEmpty()))
	{
		cout << guessA.peek();
		Sleep(secs);
		system("cls");

		cin >> guess;

		// This code will either remove the number from the lost completely or
		// place it at the back of the list if the guess was wrong.
		if (guess == guessA.peek())
			guessA.dequeue();
		else
			guessA.enqueue(guessA.dequeue());
		system("cls");

	}
	if (guessA.isEmpty())
		cout << "Congratulations! You have guessed all numbers correctly. \n ";
	system("pause");

}