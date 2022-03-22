//5 points of 20 for this week
//Indicate which pizza is better value
//Complete this program so that the if statement provided will print "FIRST", "SECOND or "SAME" as appropriate.
//Reuse your previous ppsi code
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415;

double computePPSI(int diameter, double price) {
  int radius;
  double ppsi, area;

  radius = diameter/2;
  area = PI*pow(radius, 2);
  ppsi = price/area;

  return ppsi;
}

int main() {
 //declare variables ...
  double price, ppsi1, ppsi2, diameter;

  //read data for pizza 1
  cout << "Enter the diameter and price of the first pizza:";
  cin >> diameter >> price;
  ppsi1 = computePPSI(diameter, price);

  //read data for pizza 2
  cout << "Enter the diameter and price of the second pizza:";
  cin >> diameter >> price;
  ppsi2 = computePPSI(diameter, price);

  //workout and print the answer
  if (ppsi1 < ppsi2) {
    cout << "FIRST";
  }
  else if (ppsi1 > ppsi2) {
    cout << "SECOND";
  } else {
    cout << "SAME";
  }

  cout << endl;
  
  return 0;
}