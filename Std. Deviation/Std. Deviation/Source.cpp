#include<iostream>
#include<cmath>

using namespace std;

void read_nums(int[], int num_of_num);
double find_mean(int[], int);
double find_std_dev(int[], int, double);

int main()
{
	int num_of_num;
	int num_array[20];
	double mean=0;
	cout << "how many numbers do you want to enter(it must be less than 20): "<<endl;
	cin >> num_of_num;
	cout << endl;
	read_nums(num_array, num_of_num);
	mean = find_mean(num_array, num_of_num);
	cout << endl << "Std. deviation is " << find_std_dev(num_array, num_of_num, mean) << endl<<endl;

	return 0;
}
void read_nums(int array_nums[], int total_nums){
	for (int i = 0; i < total_nums; i++)
	{
		cout << "enter the number " << i+1 << ": " << endl;
		cin >> array_nums[i];
	}
}

double find_mean(int array_nums[], int total_nums)
{
	double sum = 0;
	double mean1 = 0;
	for (int i = 0; i < total_nums; i++)
	{
		sum = sum + array_nums[i];
	}
	mean1 = sum / total_nums;
	cout <<endl<< "Mean " << mean1 << endl;

	return mean1;
}

double find_std_dev(int nums_array[], int total_nums, double mean){
	double std_dev = 0;
	double subsraction[20];
	double square[20];
	double sum = 0;

	for (int i = 0; i < total_nums; i++)
	{
		subsraction[i] = mean - nums_array[i];
	}
	for (int i = 0; i < total_nums; i++){
		square[i] = subsraction[i] * subsraction[i];
	}

	for (int i = 0; i < total_nums; i++){
		sum = sum + square[i];
	}
	std_dev = sqrt(sum / total_nums);

	return std_dev;
}

//int main()
//{
//	int sum=0;
//	int arraynums[3];
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> arraynums[i];
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		sum = sum + arraynums[i];
//	}
//	double average =(double) sum / 3;
//	cout << "average:"<< average << endl;
//
//	return 0;
//}
