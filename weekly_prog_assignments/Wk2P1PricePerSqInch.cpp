//5 points of 20 for this week
//Complete this price per square inch of a pizza program. 
//Use intermediate variables to hold the radius and the area

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  const double PI = 3.1415;
  double ppsi, price, area, diameter, radius;//for the price per sq inch

  cout << "Enter the diameter:";
  cin >> diameter;

  cout << "Enter the price:";
  cin >> price;

  //Compute the radius of the pizza
  radius = diameter/2;
  //cout << "radius : " << radius << endl;
  //Compute the area of the pizza (square inch)
  area = PI*pow(radius, 2);
  //cout << "area : " << area << endl;
  //Compute the price per square inch
  ppsi = price/area;
  //cout << "ppsi : " << ppsi << endl;
  
  cout << fixed << setprecision(2);//to get 2 decimal places in the output value
  cout << "The price per square inch of that pizza is " << ppsi*100 << " cent";

  return 0;
}