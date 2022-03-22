/**
* Week 3 - Finding Net Pay
*
* Task 2 - Formatted output
*
* Copy the body of your solution to task 1 in here. Then arrange to
* (1) read a multipart name from the rest of the line of input e.g. given input "35 15 0 Michael McConnell" the name is "Michael McConnell".
* (2) format output, using fixed, showpoint, setprecision, setw, left, right, etc. to produce output exactly like this, 30 characters per line:
Name         Michael McConnell
Hours                    35.00
Hourly rate              15.00
Gross wage              525.00
Tax @ 20%               105.00
PRSI @ 2.5%              13.12
------------------------------
Net pay                 406.88
*
*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  //Use these constants in your calculations. 
  //These allow easy changes to rates, etc. when there is a change in policy, etc.
  const double BASIC_HOURS = 35;//hours above this is overtime
	const double OTIME_MULT = 1.5;//the multiplier for overtime hours
	const double TAX_RATE = 0.20;//all pay is taxed at 20%
	const double PRSI_RATE = 0.025;//PRSI is 2.5% of gross pay

	//Declare all the variables as doubles ...
  string name;
  double hours, hourly_rate, tax_credit, gross_pay, tax, prsi, net_pay;
	//Read in the values

	//All inputs entered on one line, one prompt only
	cout << "Enter hours, hourly rate, tax credit, name:";
	cin >> hours >> hourly_rate >> tax_credit;
  getline(cin, name);

	//Calculate the gross pay
	//To pass test 3, adjust the following to arrange for gross_pay to include overtime pay...
  if(hours > BASIC_HOURS) {
    gross_pay = (BASIC_HOURS * hourly_rate) + ((hours - BASIC_HOURS)*(hourly_rate * OTIME_MULT));  
  } else {
    gross_pay = hours * hourly_rate; 
  }
  
	//Calculate the deductions based on the gross pay
	//calculate tax ...
  tax = gross_pay * TAX_RATE; 

	//apply the tax credit (to pass tests 4 & 5) ...
	if(tax_credit > tax) {
    tax = 0;
  } else {
    tax = tax - tax_credit;
  }

  //calculate PRSI ...
  prsi = gross_pay * PRSI_RATE;

	//calculate net_pay after deductions ...
  net_pay = gross_pay - prsi - tax;

	//Print out the main details
  cout << endl;
  cout << "Name" << setw(26) << name << endl;
  cout << "Hours" << setw(25) << fixed << setprecision(2) << hours << endl;
  cout << "Hourly rate" << setw(19) << fixed << setprecision(2) << hourly_rate << endl;
  cout << "Gross wage" << setw(20) << fixed << setprecision(2) << gross_pay << endl;
  cout << "Tax @ 20%" << setw(21) << fixed << setprecision(2) << tax << endl;
  cout << "PRSI @ 2.5%" << setw(19) << fixed << setprecision(2) << prsi << endl;
  cout << "------------------------------" << endl;
  cout << "Net pay" << setw(23) << fixed << setprecision(2) << net_pay << endl;

	return 0;
}
