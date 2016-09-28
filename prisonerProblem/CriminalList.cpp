//This program uses circular linked list to solve a lucky prisoner problem. Given a number of 
//prisoners are arranged in a circle and start counting from first prisoner, after counting some arbitrary fixed number, the
//present prisoner, where the couning stops, is taken out of the circle. This coninues until one prisoner is left and that prisoner is set free.


#include "CriminalList.h"
#include <iostream>

using namespace std;

CriminalList::CriminalList(){

}

CriminalList::CriminalList(int numOfCriminals, int skipNum)
{
	int count = numOfCriminals;
	int id = 1;
	first = new Criminal;
	last = first;
	first->criminal_ID = id;
	last = first;
	id++;
	while (numOfCriminals != 1){
		Criminal *temp = new Criminal;
		temp->criminal_ID = id;
		id++;
		last->next = temp;
		last = temp;
		last->next = first;
		numOfCriminals--;
	}

	Criminal *delTemp = first;
	Criminal *del;
	cout << "Criminal IDs of criminals who are skipped of freeing are ";
	while (count != 1){
		for (int i = 0; i < skipNum-1; i++)
		{
			delTemp = delTemp->next;
		}

		del = delTemp->next;
		cout << del->criminal_ID << "  ";
		delTemp->next = delTemp->next->next;
		delTemp = delTemp->next;
		delete del;
		del = NULL;
		count--;
	}

	cout << "\nThe escaped prisoner ID is " << delTemp->criminal_ID << endl;
}



CriminalList::~CriminalList()
{
}
