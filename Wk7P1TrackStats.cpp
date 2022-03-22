// use functions to compute the area of a circular track and the distance of one
// lap along its centre
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415;

double circle_circumference(double diameter);
double ring_area(double circleD, double holeD);
// also declare circumference ...

int main() {
  double outerD, innerD, area, distance, distance_circle_diameter;

  cout << "Enter outer and inner diameters:";
  cin >> outerD >> innerD;

  // compute area and distance using the functions ..
  area = ring_area(outerD, innerD);
  // distance is for the circle half way between outer and inner ....
  distance_circle_diameter = (outerD+innerD)/2;
  distance = circle_circumference(distance_circle_diameter);
  

  cout << "Area:" << area << " Distance:" << distance << endl;

  return 0;
}

double circle_circumference(double diameter) { return diameter * PI; }

double ring_area(double circleD, double holeD) {
  double circleR = circleD / 2;
  double holeR = holeD / 2;

  return PI * (pow(circleR, 2) - pow(holeR, 2));
}