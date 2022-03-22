//Week 8
#include <iostream>
using namespace std;

int month_length (int m, int y);
int year_length (int y);
bool leap_year (int year);
int daynumber (int day, int month, int year);

void dayMthYr (int daynum, int& day, int& month, int& year);
void calc_date(int &daynum, char sign, int value, char period);

int main ()
{
    int number, day, month, year, d,m,y;
    int choice;

    //testing dayMthYr
    cout << "Enter 1 to test date conversion; enter 2 to calculate a new date:";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter d, m, y: ";
        cin >> d >> m >> y;
        //convert to daynumber
        number = daynumber (d,m,y);
        cout << "That is daynumber " << number << endl;

        //calling our function
        dayMthYr(number, day, month, year);

        cout << number << " is " << day;
        cout << "/" << month << "/" << year << endl;
    }
    else {//choice is not 1
        //test calc_date
        cout << "Enter a date to be modified: ";
        cin >> d >> m >> y;
        number = daynumber (d,m,y);
        char s,p;
        int v;
        cout << "Enter the sign, value, and period (d/w/y) of the modification: ";
        cin >> s >> v >> p;
        //calling our function
        calc_date(number, s, v, p);
        //we recompute the modified date with the new daynum value
        dayMthYr(number, day, month, year);

        cout << "New Date is " << day;
        cout << "/" << month << "/" << year << endl;
    }
    return 0;
}


void dayMthYr (int daynum, int& day, int& month, int& year)
//converts daynum to date format and puts the answers into the call-by-refeence parameters, day, month and year
{
    year = 1900;
    while(daynum > year_length(year)) {
        daynum = daynum - year_length(year);
        year++;
    }
    month = 1;
    while(daynum > month_length(month, year)) {
        daynum = daynum - month_length(month, year);
        month++;
    }
    day = daynum;
}

void calc_date(int &daynum, char sign, int value, char period)
{
    //The switch statement act as a simple and easy way to check for multiple values for one variable, in our case 'period'
    switch (period)  {
        case 'd':
            //Ternary operator to avoid big if/else statement block
            daynum = (sign == '+') ? daynum + value : daynum - value;
            break;

        case 'w':
            daynum = (sign == '+') ? daynum + (7*value) : daynum - (7*value);
            break;

        case 'y':
            //for years, we reuse again our functions 'dayMthYr' and 'daynumber', it is a bit overloaded but it works. We may think of easier ways to do that
            int d, m, y;
            dayMthYr(daynum, d, m, y);
            y = (sign == '+') ? y + value : y - value;
            daynum = daynumber(d,m,y);
            break;

        default: //detect if the cases above are not true
            cout << "Enter a valid period.";
    }
}



//converts a date to a daynumber
int daynumber (int day, int month, int year)
{
    int y, m, daynumber;
    //accumelate days in all years before the given one
    daynumber = 0;
    for (y = 1900; y < year; y++)
    {
        daynumber = daynumber + year_length (y);
    }

    //in the given year, accumulate days in all months before the given month
    for (m = 1; m < month; m++)
    {
        daynumber = daynumber + month_length(m, year);
    }

    //accumulate all the days in the given month, including the given day
    daynumber = daynumber + day;

    return daynumber;
}

//gives back the number of days in the given month of the given year
int month_length (int m, int y)
{
    if (m==2)
        if (leap_year(y))
            return 29;
        else
            return 28;

    else if (m==9 || m==4 || m==6 || m==11)  //i.e. September, April, June, or November
        return 30;

    else
        return 31;
}

int year_length (int y)
{
    if (leap_year (y))
        return 366;

    else
        return 365;
}

bool leap_year (int year)
{
    //returns true if year is a leap year

    if (year % 4 == 0) //all others are definitely not leap
        if (year < 1583)
            return true;

        else //after 1583
        if ((year % 100 == 0) && (year % 400 != 0))   //e.g. 1900
            return false;
        else //e.g. 1904 or 2000
            return true;

    else //not divisible by 4
        return false;
}