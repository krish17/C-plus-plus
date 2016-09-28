#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;

	infile.open("inputData.txt");
	outfile.open("outputData.txt");

	const double ITpercent = 15;
	const double FICApercent = 8.25;
	const double payrollSavingsPer = 5;
	const double retirementPercent = 5;
	const double healthInsurance = 50;

	int employeeID;
	double grossPay;
	double incomeTax;
	double FICA;
	double payrollSavings;
	double retirement;
	double hours;
	double netpay;
	double hourlyPay;

	while (!infile.eof())
	{
		infile >> employeeID;
		infile >> hours;
		infile >> hourlyPay;

		grossPay = hours*hourlyPay;
		incomeTax = grossPay*(ITpercent / 100);
		FICA = grossPay*(FICApercent / 100);
		payrollSavings = grossPay*(payrollSavingsPer / 100);
		retirement = grossPay * (retirementPercent / 100);

		netpay = grossPay - (incomeTax + FICA + payrollSavings + retirement + healthInsurance);

		outfile << "Employee: " << employeeID<<endl;
		outfile << fixed;

		outfile << left << setw(25) << setprecision(2) << "Gross Pay" << "$ " << grossPay << endl;
		outfile << left << setw(25) << setprecision(2) << "Federal Income Tax" << "$ " << incomeTax << endl;
		outfile << left << setw(25) << setprecision(2) << "FICA"  << "$ " << FICA << endl;
		outfile << left << setw(25) << setprecision(2) << "Payroll Savings"  << "$ " << payrollSavings << endl;
		outfile << left << setw(25) << setprecision(2) << "Retirement"  << "$ " << retirement << endl;
		outfile << left << setw(25) << setprecision(2) << "Health Insurance"  << "$ " << healthInsurance << endl << endl;
		outfile << left << setw(25) << setprecision(2) << "Net Pay"   << "$ " << netpay << endl<<endl;
		outfile << "----------------------------------------------------------------" << endl<<endl;
	}
	system("pause");
	return 0;
}