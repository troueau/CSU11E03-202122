//10 points of 20 for this week
//Complete the following program to turn a length in centimetres to its nearest whole inches value (using the round function)
//Then turn the inches into the equivalent yards/feet/inches value
//Sample output: 
//"254cm is approx. 100 inches which is 2 yards, 2 feet and 4 inches."
//Notes: 1 inch is 2.54cm
//a yard is 3 feet or 36 inches;
//a foot is 12 inches
//Use integer division and remainder.

#include <iostream>
#include <cmath> //for the round function
using namespace std;

int main ()
{
	//declare the variables you need
  //You will need to use ints for the yards feet and inches in order for integer division and remainder to work
  double cm;
  int inches, inches2, yards, feet;

	//prompt for and read input
	cout << "Enter a length in centimetres:";
	cin >> cm;

//compute total inches, using round function to get an integer total inches ...

  //print out first part of output; 
  //sample ..
  //"254cm is approx. 100 inches "
  inches = cm/2.54;
  inches2 = inches;

  //compute the number of yards and what's leftover ...
	
  yards = inches/36;
  inches = inches%36;

	//from what's leftover, compute the number of feet and the remaining inches ... 
  feet = inches/12;
  inches = inches%12;

  //output the answer ...
  //Sample output: 
  //"which is 2 yards, 2 feet and 4 inches."
  cout << cm << "cm is approx. " << inches2 << " inches which is " << yards << " yards, " << feet << " feet and " << inches << " inches." << endl;



	return 0;
}