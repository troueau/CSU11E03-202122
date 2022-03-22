#include <cmath>
#include <iostream>
using namespace std;
// check the lab sheet carefully to ensure your functions behave exactly as
// specified

// declare distance function
double distance(double x1, double y1, double x2, double y2);

// classify triangles function
int triangleType(double x1, double y1, double x2, double y2, double x3,
                 double y3);

// for advanced version
bool veryClose(double x, double y);

int main() {

  double x1, y1, x2, y2, x3, y3;
  int type;

  cout << "Enter x1, y1, x2, y2, x3, y3:";
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  // call triangle type to obtain a value for "type"
  type = triangleType(x1, y1, x2, y2, x3, y3);
  
  // report the outcome ...
  cout << "That is ";

  if (type == 3) {
    cout << "equilateral";
  } else if (type == 2) {
    cout << "isoceles";
  } else {
    cout << "scalene";
  }

  cout << ".\n";

  return 0;
}

// define distance and triangleType ...
// make sure to call distance from inside triangleType to compute lengths of
// sides ...
double distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int triangleType(double x1, double y1, double x2, double y2, double x3,
                 double y3) {
  double sideA = distance(x1, y1, x2, y2);
  double sideB = distance(x1, y1, x3, y3);
  double sideC = distance(x2, y2, x3, y3);
  
  if (veryClose(sideA, sideB)) {
    // the tree sides are the same, the triangle is equilateral
    if (veryClose(sideA, sideC))
      return 3;
    // it's not equilateral, but sideA and sideB still are the same, the
    // triangle is isoceles
    return 2;
  }
  // If we come here, we know that the triangle is not equilateral, so we are
  // looking for other sides that might be the same, making the triangle
  // isocele
  else if (veryClose(sideA, sideC)) {
    return 2;
  } else if (veryClose(sideB, sideC)) {
    return 2;
  }
  // the lase case, no sides are the same, the triangle is scalene
  return 1;
}

// veryClose is needed for the advanced version / equilateral test
bool veryClose(double x, double y) {
  // return true iff the size of the difference between x and y
  // is less than 0.0001
  // fabs gives the absolute value of a floating point number

  return (fabs(x - y) < 0.0001);
}