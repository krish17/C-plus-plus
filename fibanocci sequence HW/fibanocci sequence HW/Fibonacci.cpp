//Krishna Bakka						Jan 26, 2015

//This program finds the nth fibonacci number starting from 0.

#include<iostream>//directive for input and output streams.
using namespace std;//names used in the program are part of 
//std namespace

//This function asks for the integer and finds the fibonacci number
//corresponding to it and returns it.
//post-condition: return value must be only integer.

int fibonacci();//function protocol

int main()
{
	cout<<endl<<"The corresponding fibonacci number is "<<fibonacci()<<endl;
	cout << endl;
	return 0;
}


int fibonacci()
{
	int n=0;
	cout << "Which fibonacci do you want me to return:\n";
	cin >> n;
	cout << endl;

	if (n > 0){

		int firstNo = 1, secondNo = 2, thirdNo = 3;

		if (n == 1){

			return n;
		}
		else if (n == 2){
			return 1;
		}
		else if (n == 3){
			return 2;
		}

		else if (n >= 4){
			for (int x = 4; x <= n; x++)
			{
				thirdNo = firstNo + secondNo;
				firstNo = secondNo;
				secondNo = thirdNo;
			}
			return thirdNo;
		}
	}
	else{
		cout << "Permissible values are only integers greater than zero.\n";
		return NULL;
	}
}