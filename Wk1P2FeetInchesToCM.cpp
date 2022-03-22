//Converts feet and inches to centimetres//
//Worth 6 points
#include <iostream>
using namespace std;

int main () {
    int ft, in;//integer variables
    double centimetres;//a decimal variable for the answer

    //Prompt for and read the number of feet in to the variable ft
    cout << "Enter feet value:";
    cin >> ft;

    //Prompt for and read  the number of inches in to the variable in
    
    cout << "Enter inches value:";
    cin >> in;

    //compute the number of centimetres from the ft and in values
    //one foot is 12 inches and 1 inch is 2.54cm
    //So 5 foot 7 inches is 67 inches which is 170.18cm

    centimetres = ((ft*12)+in)*2.54;

    //This prints the required output of the program
    cout << ft << " feet " << in << " inches is ";
    cout << centimetres << "cm.\n";
  
    return 0;
}