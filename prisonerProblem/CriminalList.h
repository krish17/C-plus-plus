#pragma once
class CriminalList
{
private:

	struct Criminal{
		int criminal_ID = 0;
		Criminal *next;
	};
	Criminal *first;
	Criminal *last;
public:
	CriminalList();
	CriminalList(int numOfCriminals, int skipNum);
	void deleteCriminal();
	void print();
	~CriminalList();
};

