/*
* Names:
    •Basmalah Algahmi
    •Thomas Metaxas
    •Khodr Salman
    •Ahsan Virk
* Date: 7/17/21 
* Description: The program will calculate and display employee payments for a company, 
  as well as store various information having to do with employees into an output file.
*/

#include <iostream>
#include <fstream> 
#include "Employee.h"
#include "SalaryEmployeePay.h"
#include "HourlyEmployeePay.h"
#include "AgencyCompanyPay.h"

int main()
{
    int intInput;
    string stringInput;
    float floatInput;
    string sentinel = "y";
    bool methodStatus = false;
    Employee employee;
    SalaryEmployeePay salaryEmployee;
    HourlyEmployee hourlyEmployee;
    HourlyEmployeePay hourlyEmployeePay;
    AgencyCompanyPay agencyEmployeePay;
    float userChoice;
    ofstream ofs("pay.dat");
    do
    {
        if (ofs.is_open())//check if open file
        {
            userChoice = 0;
            while (true)
            {
                cout << "1- Employee \n"
                    << "2- Salary employee pay \n"
                    << "3- Hourly employee \n"
                    << "4- Hourly employee pay \n"
                    << "5- Agency employee pay \n"
                    << "which type of employee would you like to create?\n";
                cin >> stringInput;
                try 
                {
                    userChoice = stof(stringInput);//change string to float, catch if was string or char
                    if (userChoice > 0 && userChoice < 6 && userChoice == int(userChoice))//check if int and in range
                        break;
                    else
                    {
                        cout << "Error, invalid input. Enter a value 1-5" << endl;
                        goto endloop;
                    }
                }
                catch (const exception& e) 
                { 
                    cout << "Error, invalid input. Enter a value 1-5" << endl; 
                    goto endloop;
                } //catch if char or string
            }//end while loop to validae user input of the menu 1-5

            switch (int(userChoice))//swtich accept just int so change float to int
            {
            case 1://regular employee
                cout << "Enter employee's first name: ";
                cin >> stringInput;
                employee.setFirstName(stringInput);
                cout << "Enter employee's last name: ";
                cin >> stringInput;
                employee.setLasttName(stringInput);

                cout << "Enter employee's ssn: ";
                cin >> stringInput;
                employee.setSsn(stringInput, &methodStatus);
                while (!methodStatus)//while not valid input
                {
                    cout << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx (x:number): ";
                    cin >> stringInput;
                    employee.setSsn(stringInput, &methodStatus);
                }//end while loop to validate user input for ssn

                cout << "Enter employee's id: ";
                cin >> stringInput;
                employee.setId(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Enter id of format xxx-L (x:number, L:letter a-m): ";
                    cin >> stringInput;
                    employee.setId(stringInput, &methodStatus);
                }//end while loop to validate user input for ssn
                employee.printEmployee(ofs);//print data to screen and file.
                break;
                // end case 1- create employee

            case 2://salaryEmploye
                cout << "Enter employee's first name: ";
                cin >> stringInput;
                salaryEmployee.setFirstName(stringInput);
                cout << "Enter employee's last name: ";
                cin >> stringInput;
                salaryEmployee.setLasttName(stringInput);
                
                cout << "Enter employee's ssn: ";
                cin >> stringInput;
                //validate ssn user input
                salaryEmployee.setSsn(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx (x:number): ";
                    cin >> stringInput;
                    salaryEmployee.setSsn(stringInput, &methodStatus);
                }
              
                cout << "Enter employee's id: ";
                cin >> stringInput;
                //validate Id user input
                salaryEmployee.setId(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Enter id of format xxx-L (x:number, L:letter a-m: ";
                    cin >> stringInput;
                    salaryEmployee.setId(stringInput, &methodStatus);
                }
                //get annual pay and validate it
                cout << "Enter employee's annual pay: ";
                cin >> floatInput;
                salaryEmployee.setAnnualPay(floatInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter a value greater than 0: ";
                    cin >> floatInput;
                    salaryEmployee.setAnnualPay(floatInput, &methodStatus);
                }
                //get the tax rate
                cout << "Enter tax rate(1-3): ";
                cin >> intInput;
                salaryEmployee.setTaxRateCode(intInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter tax rate code 1-3: ";
                    cin >> intInput;
                    salaryEmployee.setTaxRateCode(intInput, &methodStatus);
                }
                //print to screen and file
                salaryEmployee.printSalaryEmployeePay(ofs);
                break;
                //end case salaryEmployee
            case 3://Hourly employee
                cout << "Enter employee's first name: ";
                cin >> stringInput;
                hourlyEmployee.setFirstName(stringInput);
                cout << "Enter employee's last name: ";
                cin >> stringInput;
                hourlyEmployee.setLasttName(stringInput);
                //get ssn and validate it
                cout << "Enter employee's ssn: ";
                cin >> stringInput;
                hourlyEmployee.setSsn(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx (x:number): ";
                    cin >> stringInput;
                    hourlyEmployee.setSsn(stringInput, &methodStatus);
                }
                //get ID and validate it
                cout << "Enter employee's id: ";
                cin >> stringInput;
                hourlyEmployee.setId(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Enter id of format xxx-L (x:number, L:letter a-m: ";
                    cin >> stringInput;
                    hourlyEmployee.setId(stringInput, &methodStatus);
                }
                //get weekly pay and validate it
                cout << "Enter employee's weekly pay: ";
                cin >> floatInput;
                hourlyEmployee.setWeeklyPay(floatInput, &methodStatus);//not in his but need it
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 400-3000: ";
                    cin >> floatInput;
                    hourlyEmployee.setWeeklyPay(floatInput, &methodStatus);
                }
                //get number of hours and validate it
                cout << "Enter employee's number of hours worked: ";
                cin >> intInput;
                hourlyEmployee.setNumberOfHours(intInput, &methodStatus);//not in his but need it
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 1-60: ";
                    cin >> intInput;
                    hourlyEmployee.setNumberOfHours(intInput, &methodStatus);
                }
                //print to screen and file
                hourlyEmployee.printHourlyEmployee(ofs);
                break;
            case 4:
                cout << "Enter employee's first name: ";
                cin >> stringInput;
                hourlyEmployeePay.setFirstName(stringInput);
                cout << "Enter employee's last name: ";
                cin >> stringInput;
                hourlyEmployeePay.setLasttName(stringInput);
                //get ssn and validate it
                cout << "Enter employee's ssn: ";
                cin >> stringInput;
                hourlyEmployeePay.setSsn(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx (x:number): ";
                    cin >> stringInput;
                    hourlyEmployeePay.setSsn(stringInput, &methodStatus);
                }
                //get ID and validate it
                cout << "Enter employee's id: ";
                cin >> stringInput;
                hourlyEmployeePay.setId(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Enter id of format xxx-L (x:number, L:letter a-m: ";
                    cin >> stringInput;
                    hourlyEmployeePay.setId(stringInput, &methodStatus);
                }
                //get weekly pay and validate it
                cout << "Enter employee's weekly pay: ";
                cin >> floatInput;
                hourlyEmployeePay.setWeeklyPay(floatInput, &methodStatus);//not in his but need it
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 400-3000: ";
                    cin >> floatInput;
                    hourlyEmployeePay.setWeeklyPay(floatInput, &methodStatus);
                }
                //calc overrate for an hour
                hourlyEmployeePay.setOvertimePay(hourlyEmployeePay.getHourlyPay());//overpay=houly*1.5
                //get number of hours and validate it
                cout << "Enter employee's number of hours worked: ";
                cin >> intInput;
                hourlyEmployeePay.setNumberOfHours(intInput, &methodStatus);//not in his but need it
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 1-60: ";
                    cin >> intInput;
                    hourlyEmployeePay.setNumberOfHours(intInput, &methodStatus);
                }
                //get the tax rate
                cout << "Enter tax rate: ";
                cin >> intInput;
                hourlyEmployeePay.setTaxRateCode(intInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter tax rate code 1-3 ";
                    cin >> intInput;
                    hourlyEmployeePay.setTaxRateCode(intInput, &methodStatus);
                }
                //get the work status (Fulle-Part) and validate
                cout << "Enter work status: ";
                cin >> stringInput;
                hourlyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, work status must be 'F' for full time or 'P' for part time: ";
                    cin >> stringInput;
                    hourlyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                }
                hourlyEmployeePay.printHourlyEmployeePay(ofs);
                break;
            case 5:
                cout << "Enter employee's first name: ";
                cin >> stringInput;
                agencyEmployeePay.setFirstName(stringInput);
                cout << "Enter employee's last name: ";
                cin >> stringInput;
                agencyEmployeePay.setLasttName(stringInput);
                //get ssn and validate it
                cout << "Enter employee's ssn: ";
                cin >> stringInput;
                agencyEmployeePay.setSsn(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx (x:number): ";
                    cin >> stringInput;
                    agencyEmployeePay.setSsn(stringInput, &methodStatus);
                }
                //get ID and validate it
                cout << "Enter employee's id: ";
                cin >> stringInput;
                agencyEmployeePay.setId(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Enter id of format xxx-L (x:number, L:letter a-m: ";
                    cin >> stringInput;
                    agencyEmployeePay.setId(stringInput, &methodStatus);
                }
                //get weekly pay and validate it
                cout << "Enter employee's weekly pay: ";
                cin >> floatInput;
                agencyEmployeePay.setWeeklyPay(floatInput, &methodStatus);//not in his but need it
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 400-3000: ";
                    cin >> floatInput;
                    agencyEmployeePay.setWeeklyPay(floatInput, &methodStatus);
                }
                //calc te overpayment for an hour based on hourly pay
                agencyEmployeePay.setOvertimePay(agencyEmployeePay.getHourlyPay());

                //get number of hours and validate it
                cout << "Enter employee's number of hours worked: ";
                cin >> intInput;
                agencyEmployeePay.setNumberOfHours(intInput, &methodStatus);//not in his but need it
                while (!methodStatus)
                {
                    cout << "Error, enter a value between 1-60: ";
                    cin >> intInput;
                    agencyEmployeePay.setNumberOfHours(intInput, &methodStatus);
                }
                //get the tax rate
                cout << "Enter tax rate: ";
                cin >> intInput;
                agencyEmployeePay.setTaxRateCode(intInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, enter tax rate code 1-3 ";
                    cin >> intInput;
                    agencyEmployeePay.setTaxRateCode(intInput, &methodStatus);
                }
                //get the work status (Fulle-Part) and validate
                cout << "Enter work status: ";
                cin >> stringInput;
                agencyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                while (!methodStatus)
                {
                    cout << "Error, work status must be 'F' for full time or 'P' for part time: ";
                    cin >> stringInput;
                    agencyEmployeePay.setWorkStatus(stringInput, &methodStatus);
                }
                cout << "Enter name of the company: ";
                cin >> stringInput;
                agencyEmployeePay.setCompanyToPay(stringInput);
                agencyEmployeePay.printAgencyEmployeePay(ofs);
                break;
            default:
                ofs << endl << endl;
                break;
            }//end switch 
           
        }//end if statement( if file is open)

        //if fail to open file
        else
        {
            cout << "Error, file could not be opened\n";
            goto endloop;
        }

    endloop:
        cout << "Would you like to continue? y/n: ";
        cin >> sentinel;
        while (sentinel != "Y" && sentinel != "y" && sentinel != "N"&& sentinel != "n")
        {
            cout << "Would you like to continue? y/n: ";
            cin >> sentinel;
        }
        
    }while (sentinel == "Y" || sentinel == "y");//end do while loop

    cout << endl << "Thank you!"<<endl;
    if(ofs.is_open())
        ofs.close();

    return 0;
    
}

    