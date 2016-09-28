//This program asks for number of numbers user want to give and give their
//LCM and GCD as output.
#include<iostream>

using namespace std;

int gcd(int nums[], int,int);
int find_smallest(int nums[], int);
void readvalues(int nums[],int);
int lcm(int nums[], int, int);
int find_largest(int nums[], int);

int main()
{
	int no_of_numbers;
	int array12[10];
	int smallest=0;
	int largest = 0;

	cout << "How many numbers do you want to give: " << endl;
	cin >> no_of_numbers;

	readvalues(array12,no_of_numbers);
	
	smallest = find_smallest(array12, no_of_numbers);
	
	cout<<endl<<"The GCD is: "<< gcd(array12, smallest, no_of_numbers)<<endl<<endl;

	largest = find_largest(array12, no_of_numbers);

	cout << "The LCM is: " << lcm( array12, largest, no_of_numbers)<<endl<<endl;

	return 0;
}

void readvalues(int array12[],int noofnumbers)
{
	cout << endl;
	if (noofnumbers <= 10){
		for (int i = 0; i < noofnumbers; i++)
		{
			cout << "Enter the number "<< i+1 <<": "<<endl;
			cin >> array12[i];
		}
	}
	else
		cout << "The maximum number of numbers is 10." << endl;
}

int find_smallest( int array1[], int total_numbers){
	int smallest1 = array1[0];
	for (int i = 0; i < total_numbers; i++)
	{
		if (array1[i] < smallest1)
			smallest1 = array1[i];
	}
	return smallest1;
}

int gcd(int array123[], int small, int numbers){
	int x = 0;
	for ( x = small; x > 0; x--)
	{
		int i = 0;
		while (i < numbers) {
			if (array123[i] % x != 0)
				break;
			i++;
		}
		if (i == numbers){
			break;
		}
	}
	return x;
}

int find_largest(int nums[], int num_of_nums)
{
	int largest = nums[0];
	for (int i = 0; i < num_of_nums; i++)
	{
		if (nums[i] > largest)
			largest = nums[i];
	}
	return largest;
}
int lcm(int numarray[], int large, int numbers){
	
	for (int i = large; i >= large; i++)
	{
		int x = 0;
		while (x < numbers){
			if (i % numarray[x] != 0)
				break;
			x++;
		}
		if (x==numbers)
		return i;
	}
}