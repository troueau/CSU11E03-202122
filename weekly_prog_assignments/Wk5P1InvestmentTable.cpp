/* Investment Table */
#include <iostream>
#include <iomanip> //for io manipulation//
#include <cmath> //for the pow function//
using namespace std;

double compute_return_on_investement(int year, double investment, double rate) {
  return investment*pow(1+(rate/100), year);
}

int main() {
    //Not essential to declare constants but makes the program more flexible.
    const int YEAR_MIN = 5;
    const int YEAR_MAX = 30;
    const int YEAR_INCR = 5;

    const double RATE_MIN = 5;
    const double RATE_MAX = 10;
    const double RATE_INCR = 0.5;
    
    int year;
    double rate, initial_balance, return_on_investment;
    
    cout << fixed << setprecision (2);
    cout << "Enter initial investment amount:";
    cin >> initial_balance;
    /* print table header */
    cout << right << setw(10) << "Rate";
    for (year = YEAR_MIN; year <= YEAR_MAX; year = year + YEAR_INCR) {
      cout << setw(4) << year << " years" ;
    }
    cout << "\n";

    //First loop will create the first column with all the rates from 5 to 10
    for(rate = RATE_MIN; rate <= RATE_MAX; rate = rate + RATE_INCR) {
          cout << right << setw(10) << rate;
          //This loop will fill the table with the right values
          for(year = YEAR_MIN; year <= YEAR_MAX; year = year + YEAR_INCR) {
            //Determine the return of investement with the function we created, depending on the year we're in and on the current rate 
            return_on_investment = compute_return_on_investement(year, initial_balance,rate);
            //Print the right return on investement in the table
            cout << setw(10) << return_on_investment;
          }
          cout << "\n";
    }
    
    
    return 0;
}