//Krishna Bakka."
//This program helps the librarian to shelve the returned book by
//showing its appropriate position.


#include<iostream>
#include<string>
#include<fstream>
#include"BookList.h"

using namespace std;

//This function prints the headings
//Precondition: none
//Postcondition:none
void header();

//reads the books from the file and gives it to the class
//Precondition: reference to infile and list;
//Postcondition:returns string.
string readInBooks(ifstream &infile, BookList &SortedList);

//prints the list
//Precondition: requires the refernce to the list;
//Postcondition:none.
void printTheBookList(BookList &SortedList);

//This function removes the book from the sortedlist
//Precondition: reference to infile and list;
//Postcondition:none
void borrowBook(ifstream &infile, BookList &sortedList);

//This function tells the librarian which book precedes which book
//Precondition: reference to librarydesk object and list;
//Postcondition:returns string.
void shelveBooks(BookList libraryDesk, BookList &sortedList);

//This function adds the returned books to the librarydesk list
//Precondition: reference to infile and list;
//Postcondition:returns string.
string addToDesk(ifstream &infile, BookList libraryDesk);

int main()
{
	header();

	ifstream infile;

	char inputFileName[40];
	cout << "\nPlease enter the input file name:" << endl;
	cin.getline(inputFileName, 40);
	infile.open(inputFileName);
	cout << endl;
	
	cout << "\nShelf List" << endl;
	cout << "--------------" << endl;
	string endOfList = "";
	string command;

		BookList sortedList;
		BookList libraryDesk;

		while (endOfList != "END")
		{
			endOfList = readInBooks(infile, sortedList);
		}

		infile >> command;
		while (!infile.eof())
		{
			if (command == "BORROW")
			{
				borrowBook(infile, sortedList);
			}
			if (command == "PRINT")
			{
				printTheBookList(sortedList);
			}
			if (command == "RETURN")
			{
				string book;
				book = addToDesk(infile, libraryDesk);
			}
			if (command == "END")
			{
				
			}
			if (command == "SHELVE")
			{
				shelveBooks(libraryDesk, sortedList);
			}
			infile >> command;
		}

	infile.close();
	system("pause");

	return 0;
	libraryDesk.deleteList();
	sortedList.deleteList();
}

void header()
{
	cout << "Krishna Bakka." << endl;
	cout << "This program helps the librarian to shelve the returned book by" << endl;
		cout<< "showing its appropriate position." << endl;
}
string addToDesk(ifstream &infile, BookList libraryDesk)
{
	string s, junk;
	char ch;

	infile >> ch;
	if (!infile.eof() && (ch == '"'))
	{
		getline(infile, s, '"');
		getline(infile, junk);
		cout << junk << endl;
		libraryDesk.addTheBook(s);
	}
	if (ch != '"')
	{
		getline(infile, junk);
		return "END";
	}
	return s;
}

void shelveBooks(BookList libraryDesk, BookList &sortedList)
{
	string book = "";
	
	libraryDesk.reset();

	while (!libraryDesk.atEnd())
	{
		book = libraryDesk.getTheBook();

		libraryDesk.advance();
		sortedList.findBook(book);
		cout << "Put \"" << book << "\" after the book \"" << sortedList.getBook1()\
			<<"\"." << endl;
		sortedList.addTheBook(book);
		libraryDesk.removeBook(book);
	}
	cout << "END\n" << endl;
	
}

void borrowBook(ifstream &infile, BookList &sortedList)
{
	string s, junk;
	char ch;

	infile >> ch;
	if (!infile.eof() && (ch == '"'))
	{
		getline(infile, s, '"');
		getline(infile, junk);
		sortedList.removeBook(s);
	}
}

string readInBooks(ifstream &infile, BookList &sortedList)
	{
		string s, junk;
		char ch;

		infile >> ch;
		if (!infile.eof() && (ch == '"'))
		{
			getline(infile, s, '"');
			getline(infile, junk);
			sortedList.addTheBook(s);
		}
		if (ch != '"')
		{
			getline(infile, junk);
			return "END";
		}
		return s;
	}


void printTheBookList(BookList &sortedList)
{
	string book = "";
	sortedList.reset();
	int i = 0;
	while (i <= sortedList.getLength())
	{
		book = sortedList.getTheBook();
		cout << book << endl;
		sortedList.advance();
		i++;
	}
}