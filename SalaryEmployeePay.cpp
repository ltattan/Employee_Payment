/*
1-A child class of Employee, that get the annual income and the tax rate to calculate 
the weekly payment
2-tax rate 1-3 , and annual income should be greater tan zero
3- It print the salary employee information to the screen and a file.
*/

#include "SalaryEmployeePay.h"
#include <fstream> //always include when deal wih file
#include <iomanip>

SalaryEmployeePay::SalaryEmployeePay() { annualPay = 0; weeklyPay = 0; taxRateCode = 1; }

float SalaryEmployeePay:: getAnnualPay() { return annualPay; }
void SalaryEmployeePay::setAnnualPay(float input, bool* methodStatus)
{
	if (input >= 0)
	{
		*methodStatus = true;
		annualPay = input;
		weeklyPay = annualPay / 52; //(annual /# of weeks) will give us the weekly payment
	}
	else 
		*methodStatus = false;// if set true in case 1, should reset to false

}//end salaryEmploymentPay function

int SalaryEmployeePay::getTaxRateCode() { return taxRateCode; }
void SalaryEmployeePay::setTaxRateCode(int input, bool* methodStatus)
{
	if (input < 1 || input >3)
		*methodStatus = false;
	else
	{
		*methodStatus = true;
		taxRateCode = input;
	}
}//end method setTaxRate

void SalaryEmployeePay::printSalaryEmployeePay(ofstream& ofs)//without SalaryEmployeePay::, the function wont access any protected member
{
	float paymentDue, taxRate;
	if (taxRateCode ==1)
		taxRate = .25;
	else if (taxRateCode ==2)
		taxRate = .2;
	else
		taxRate = .15;

	paymentDue = weeklyPay - (weeklyPay * taxRate);

	cout << fixed << setprecision(2);//print 2 digit after the decimal 
	//print info to screen
	cout<< "Data for salary employee: "<<endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Annual pay: $"  << annualPay << endl
		<< "Weekly pay: $"  << weeklyPay << endl
		<< "Tax Rate code: " << taxRateCode << endl
		<< "Payment amount: $" << paymentDue << endl;

	//print to file
	ofs << fixed << setprecision(2);
	ofs << "\nData for salary employee:\n"
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Annual pay: $" << annualPay << endl
		<< "Weekly pay: $" << weeklyPay << endl
		<< "Tax Rate code: " << taxRateCode << endl
		<< "Payment amount: $" << paymentDue << endl;
	ofs.flush();
}//end of print salary employee class

		




