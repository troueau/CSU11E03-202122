//Compute statistics for temperature data - see lab sheet
//Sample Input:DUBAIRPORT 10.5 6.5 5.0 -3.5 -4.0 7.5 3.0 -999
//Output:DUBAIRPORT -4.0 10.5 3.6
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main () 
{
  //set the precision for the output 
  cout << fixed << setprecision(1);
  
  //declare variables ...
  int nb_values;
  double max, min, total_temp, actual_temp, average;
  string station_name;

  //NB Don't prompt for input!!
  //read the station name ...
  cin >> station_name;
  //read the first temprature ...
  cin >> actual_temp;
  //initialise variables ...
  total_temp = 0; nb_values = 0;
  // ... the loop ...
  while(actual_temp != -999) {
    //Determine if the actual temperature is the maximum
    if(actual_temp > max) max = actual_temp;
    //Determine if the actual temperature is the minimum
    if(actual_temp < min) min = actual_temp;
    //Increase the variable total_temp to compute the average at the end
    total_temp = total_temp + actual_temp;
    //Increase the variable nb_values in order to compute average at the end
    nb_values++;
    //get another temperature
    cin >> actual_temp;
  }

  //if the number of values is 0, then there is no data, prompt the right message
  if(nb_values == 0) {
    cout << station_name << " NO DATA" << endl;
  } //Else, prompt the data
  else {
    //Compute average
    average = total_temp/nb_values;
    //output the data
    cout << station_name << " " << min << " " << max << " " << average << endl; 
  }
  
  return 0;
}