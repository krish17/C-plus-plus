//Palindrome program by Krishna Bakka.
//CMPS-3013-program 1
//This program checks whether the given phrase/word is a palindrome or not.

#include<iostream>
#include<string>
#include "string_stack.h"
#include"String_Queue.h"

using namespace std;

int main()
{
	cout << "Palindrome program by Krishna Bakka." << endl;
	cout << "CMPS 3013 - Program 1." << endl;
	cout << "This program checks whether the given word/phrase is a palindrome\n";
	cout<<"or not." << endl;

	string_stack string_stack_obj;
	String_Queue String_Queue_obj(100);

	bool if_one_more = false;//checks if user wants to enter another word
	string one_more_word;

	do
	{
		bool if_palindrome = true;
		string word;//stores the user given word
		std::string phrase;//stores the word after processing like removing the spaces.
		int word_len;
		int phrase_length;

		cout << "Please enter the word/phrase: " << endl;
		getline(cin, word);

		word_len = word.length();
		phrase_length = 0;

		for (int i = 0; i < word_len; i++)
		{
			word[i] = toupper(word[i]);//converts each character into upper case.
			int ichar = word[i];
			//Removes every thing except lower and upper case letter from the word.
			if ((ichar >= 65 && ichar <= 90) || (ichar >= 97 && ichar <= 122))
				phrase.append(1, word[i]);//appends a single copy of char each time to phrase
		}

		phrase_length = phrase.length();

		for (int i = 0; i < phrase_length; i++)
		{
			string_stack_obj.push(phrase[i]);//pushing into stack
			String_Queue_obj.enqueue(phrase[i]);//adding to the queue
		}

		for (int j = 0; j < phrase_length; j++)
		{
			if (string_stack_obj.pop() != String_Queue_obj.dequeue())
				if_palindrome = false;
		}

		if (if_palindrome)
			cout << "Given word/phrase '" << word << "' is a palindrome.\n" << endl;
		else
			cout << "Given word/phrase '" << word << "' is not a palindrome.\n" << endl;

		cout << "Do you want enter another phrase/word?" << endl;
		cout << "If so, please enter yes else enter no." << endl;

		cin >> one_more_word;
		cin.ignore();
		cout << endl;

		for (int i = 0; i < one_more_word.length(); i++)
		{
			one_more_word[i] = toupper(one_more_word[i]);
		}

		if (one_more_word == "YES")
			if_one_more = true;
		else
			if_one_more = false;

		if_palindrome = true;

	} while (if_one_more);

	system("pause");
	return 0;
}