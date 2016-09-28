#include<iostream>
#include<time.h>
using namespace std;

int mainArray[100][4];
int secondarray[100][4];
int a[2][5];
void fitness();
void tournSelection(int t);
void callingFillArrray();
void crossOver();
bool maxFitness();
void Mutate();
//void crossOver();
int main()
{
	srand(time(0)); //use current time as seed for random generator
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mainArray[i][j] = rand() % 50 + 1; //gives values between 1 and 50
		}
	}
	int roundCount = 0;
	fitness();
	while ((roundCount<1000) && (maxFitness())){
		cout << "The Round Count is : " << roundCount << "\n";
		roundCount++;
		//fitness();
		callingFillArrray();
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mainArray[i][j] = secondarray[i][j];
			}

		}
		for (int i = 0; i < 100; i++)
		{
			cout << "\n";
			for (int j = 0; j < 5; j++)
			{
				cout << mainArray[i][j] << " ";
			}
		}

		Mutate();
		fitness();
	}
	system("pause");
	return 0;
}

bool maxFitness(){
	bool flag = true;
	for (int i = 0; i < 100; i++)
	{
		if (mainArray[i][4] == 0){
			flag = false;

		}
	}
	return flag;
}
void callingFillArrray(){

	for (int i = 0; i < 50; i++){
		tournSelection(0);
		tournSelection(1);
		crossOver();
		for (int j = 0; j < 4; j++){
			secondarray[i][j] = a[0][j];
		}
		for (int j = 0; j < 4; j++){
			secondarray[i + 50][j] = a[1][j];
		}
	}
}


void fitness()
{
	//double fit_num = 0.0;
	for (int i = 0; i < 100; i++){
		if ((mainArray[i][0] == mainArray[i][1] == mainArray[i][2] == mainArray[i][3]) ||
			((mainArray[i][0] == mainArray[i][2]) && (mainArray[i][1] == mainArray[i][3])) ||
			((mainArray[i][0] == mainArray[i][3]) && (mainArray[i][1] == mainArray[i][2])))
		{
			mainArray[i][4] = INT_MAX;
		}
		else
		{
			mainArray[i][4] = abs((pow(mainArray[i][0], 3) + pow(mainArray[i][1], 3)) - (pow(mainArray[i][2], 3) + pow(mainArray[i][3], 3)));
		}
	}
}

void tournSelection(int t)
{
	//srand(10);
	int i = rand() % 99 + 1;
	int j = rand() % 99 + 1;
	int bestfit = j;

	if (mainArray[i][4] < mainArray[j][4]){
		bestfit = i;

	}
	for (int p = 0; p <= 4; p++)
	{
		a[t][p] = mainArray[bestfit][p];

	}
}

void crossOver()
{
	int i = rand() % 4;
	int temp1 = 0;

	for (int temp = i; temp < 4; temp++){
		temp1 = a[0][temp];
		a[0][temp] = a[1][temp];
		a[1][temp] = temp1;
	}
}

void Mutate()
{
	int mutateCount = ((rand() % 5)*.01 * 400);

	for (int i = 0; i < mutateCount; i++){
		int ith = rand() % 99 + 1;
		int jth = rand() % 99 + 1;
		if (mainArray[ith][jth] + 3 < 50)
			mainArray[ith][jth] = mainArray[ith][jth] + 3;
		else
			i--;
	}
}