/*
* A child class of HourlyEmployee, which a child of Employee
* Employee->HourlyEmployee->HourlyEmployeePay
* 1- It calculate the overpayment based on the hourly payment
* 2- get the tax rate from the user and calculate the due payment
* 3- get the work statu from the user (Full, Part)
* 4- print all information to the screen and a file.
*/

#pragma once
#ifndef HOURLYEMPLOYEEPAY_HPP
#define HOURLYEMPLOYEEPAY_HPP

#include "HourlyEmployee.h"
#include <iostream>
#include <string>
using namespace std;
class HourlyEmployeePay:public HourlyEmployee
{
protected:
	float overtimePay;
	int taxRateCode;
	string workStatus;  
public:
	HourlyEmployeePay();
	float getOvertimePay();
	void setOvertimePay(float input);
	void setTaxRateCode(int input, bool* methodStatus);
	int getTaxRateCode();
	void setWorkStatus(string input, bool* methodStatus);
	string getWorkStatus();
	void printHourlyEmployeePay(ofstream& ofs);
};

#endif
