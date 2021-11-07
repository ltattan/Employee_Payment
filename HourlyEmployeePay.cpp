/*
* A child class of HourlyEmployee, which a child of Employee
* Employee->HourlyEmployee->HourlyEmployeePay
* 1- It calculate the overpayment based on the hourly payment
* 2- get the tax rate from the user and calculate the due payment
* 3- get the work statu from the user (Full, Part)
* 4- print all information to the screen and a file.
*/
#include "HourlyEmployeePay.h"
#include <fstream>
#include <iomanip>

HourlyEmployeePay::HourlyEmployeePay() { overtimePay = 0; taxRateCode = 1;workStatus = "P"; }//captial P


float HourlyEmployeePay::getOvertimePay(){return overtimePay;}
void HourlyEmployeePay::setOvertimePay(float input){overtimePay = input * 1.5;}



void HourlyEmployeePay::setTaxRateCode(int input, bool* methodStatus)
{
	if (input < 1 || input >3)
		*methodStatus = false;
	else
	{
		*methodStatus = true;
		taxRateCode = input;
	}
}
int HourlyEmployeePay::getTaxRateCode() { return taxRateCode; }

void HourlyEmployeePay::setWorkStatus(string input, bool* methodStatus)
{
	//validate work status
	if (input != "F" && input != "f" && input != "P" && input != "p")
		*methodStatus = false;
	else if (input == "F" || input == "f")
	{
		input = "F";
		*methodStatus = true;
		workStatus = input;
	}
	else if (input == "P" || input == "p")
	{
		input = "P";
		*methodStatus = true;
		workStatus = input;
	}
}
string HourlyEmployeePay::getWorkStatus() { return workStatus; }

void HourlyEmployeePay::printHourlyEmployeePay(ofstream& ofs)
{
	float paymentDue, taxRate;
	if (taxRateCode == 1)
		taxRate = .25;
	else if (taxRateCode == 2)
		taxRate = .2;
	else
		taxRate = .15;

	float fullTimeWeeklyPayment= (40 * hourlyPay) - ((40 * hourlyPay) * taxRate);
	//check hours
	if (numberOfHours > 40)
	{
		paymentDue = (overtimePay * (numberOfHours % 40) - (overtimePay * (numberOfHours % 40) * taxRate));//reminder
		paymentDue += fullTimeWeeklyPayment;
	}
	else if (numberOfHours <= 40)//see if just do else
		paymentDue = (numberOfHours * hourlyPay) - ((numberOfHours * hourlyPay) * taxRate);
	
	cout << fixed << setprecision(2);//print 2 digit after the decimal 

	//print to screen
	cout << "Data for hourly employee pay: " << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Weekly pay " << weeklyPay << endl
		<< "Hourlypay: " << hourlyPay << endl
		<< "Hours worked " << numberOfHours << endl
		<< "Overtime pay: $" << overtimePay << endl
		<< "Tax rate: " << taxRateCode << endl
		<< "Work status: " << workStatus << endl
		<< "Payment due: $" << paymentDue << endl;

	//print to file
	ofs << fixed << setprecision(2);
	ofs << "Data for hourly employee pay: " << endl
		<< "First name: " << firstName << endl
		<< "Last name: " << lastName << endl
		<< "Ssn: " << hideSsn << endl
		<< "Id: " << id << endl
		<< "Weekly pay " << weeklyPay << endl
		<< "Hourlypay: " << hourlyPay << endl
		<< "Hours worked " << numberOfHours << endl
		<< "Overtime pay: $" << overtimePay << endl
		<< "Tax rate: " << taxRateCode << endl
		<< "Work status: " << workStatus << endl
		<< "Payment due: $" << paymentDue << endl;
	ofs.flush();
}//end printHourlyEmployeePay function 


