#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string SENTINEL = "X0000";

//Ideally use constants for all fixed charges values, and for free mins etc.
const double REG_FIXED_FEE = 10.00;
const int REG_FREE_MINS = 50;
const double REG_FEE_PER_MIN = 0.20;
const double P_FIXED_FEE = 25.00;
const int P_FREE_MINS_DT = 75;
const int P_FREE_MINS_OP = 100;
const double P_FEE_PER_MIN_DT = 0.10;
const double P_FEE_PER_MIN_OP = 0.05;



void read (string &name, double &bal, char &code, int &mins1, int &mins2);
//does not handle the account number because this has to be read separately to allow sentinel to be noticed before this function is called
//if code is "R" one of the parameters is not used

double reg_charge (int mins);
//Computes charge for regular service accounts

double prem_charge (int peak_mins, int off_mins);
//Computes charges for premium service accounts

void print_bill(const string& acc, const string& name, char code, double charge, double tot_bal);

int main()
{
    string acc, name;
    char code;
    int mins1, mins2;
    double bal, tot_bal, charge;

    cout << setw(8) << "Account" << setw(15) << "Name" << setw(11)
    		<< "Act. Type" << setw(10) << "Charge" << setw(10) << "Balance" << endl;

    cin >> acc;

    while(acc != SENTINEL) {
        read(name, bal, code, mins1, mins2);

        if(code=='P') charge = prem_charge(mins1, mins2);
        else charge = reg_charge(mins1);

        tot_bal = bal + charge;

        print_bill(acc, name, code, charge, tot_bal);

        cin >> acc;
    }


    return 0;
}

void read(string &name, double &bal, char &code, int &mins1, int &mins2) {
    cin >> name >> bal >> code;
    if(code == 'P') {
        cin >> mins1 >> mins2;
    }
    else {
        cin >> mins1;
    }
}

double reg_charge(int mins) {
    return (mins > REG_FREE_MINS) ? ((mins - REG_FREE_MINS)*REG_FEE_PER_MIN)+REG_FIXED_FEE : REG_FIXED_FEE;
}

double prem_charge(int peak_mins, int off_mins) {
	double total = 0;

    if(peak_mins > P_FREE_MINS_DT) total += (peak_mins - P_FREE_MINS_DT)*P_FEE_PER_MIN_DT;
    if(off_mins > P_FREE_MINS_OP) total += (off_mins - P_FREE_MINS_OP)*P_FEE_PER_MIN_OP;

    return total + P_FIXED_FEE;
}

void print_bill(const string& acc, const string& name, char code, double charge, double tot_bal) {
  cout << fixed << showpoint << setprecision (2);

  string act_type = (code=='R') ? "Regular" : "Premium";

  cout << setw(8) << acc << setw(15) << name << setw(11) << act_type << setw(10) << charge << setw(10) << tot_bal << endl;
}
