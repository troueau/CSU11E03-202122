//Program to determine how many months it takes to pay off a loan. See lab sheet.
/* Sample:: Loan amount:1500
      Monthly payment:50
      36 months.
      292.31 euro total interest.
      42.31 euro final payment.     */
#include <iostream>
#include <iomanip> //for fixed and setprecision
using namespace std;

int main() {
  const double ANNUAL_RATE = 12; 
  double loan_amount, monthly_payment, total_interest, monthly_interest;
  double monthly_rate = (ANNUAL_RATE/12.0)/100;//to give a monthly multiplier
  //declare more variables ...
  int no_month;

  //get input
  cout << "Loan amount:";
  cin >> loan_amount;
  
  cout << "Monthly payment:";
  cin >> monthly_payment;
  
  //initialise variables ...
  no_month = 0;
  monthly_interest = 0;

  //set up how the output looks
  cout << fixed << setprecision (2);

  //use a loop to see how long repayment takes and track interest ...
  while (loan_amount > 0)
  {
    //Determine the interests of the current month
    monthly_interest = loan_amount * monthly_rate;
    //Add monthly interest to the total interests
    total_interest = total_interest + monthly_interest;
    //cout << "mois " << no_month << " -> total interest = " << total_interest << endl;
    //Decrease the loan amount
    loan_amount = loan_amount - (monthly_payment - monthly_interest);//Increase the month number each iteration 
    no_month++;
  }

  //compute final payment ...
  double final_payment = loan_amount + monthly_payment;

  //output the three values, one per line ...
  cout << no_month << " months.\n";
  cout << total_interest << " euro total interest.\n";
  
  cout << final_payment <<  " euro final payment.\n";

  return 0;
  }