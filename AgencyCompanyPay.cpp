/*
* A child class of HourlyEmployeePay
* Employee->HourlyEmployee->HourlyEmployeePay->AgnecyCompanyPay
* 1- get the name of the company from the user.
* 2- print all information to the screen and a file.
*/

#include "AgencyCompanyPay.h"
#include <fstream>
#include <iomanip>

AgencyCompanyPay::AgencyCompanyPay() { companyToPay = ""; }

void AgencyCompanyPay::setCompanyToPay(string input) { companyToPay = input; }

string AgencyCompanyPay::getCompanyToPay() { return companyToPay; }

void AgencyCompanyPay::printAgencyEmployeePay(ofstream& ofs)
{
	float paymentDue, taxRate;
	if (taxRateCode == 1)
		taxRate = .25;
	else if (taxRateCode == 2)
		taxRate = .2;
	else
		taxRate = .15;
	float fullTimeWeeklyPayment = (40 * hourlyPay) - ((40 * hourlyPay) * taxRate);
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
	cout << "Data for agency employee pay:" << endl
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
		<< "Payment due: $" << paymentDue << endl
		<< "Company to pay: " << companyToPay << endl;

	//print to file
	ofs << fixed << setprecision(2);
	ofs << "Data for agency employee pay:" << endl
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
		<< "Payment due: $" << paymentDue << endl
		<< "Company to pay: " << companyToPay << endl;//not complete
	ofs.flush();
}// end printAgencyEmployeePay