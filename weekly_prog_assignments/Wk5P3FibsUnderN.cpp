/* 
Fibonnacis up to an entered number.
To avoid printing the term after the limit, you need set up your loop so that
you check next *before* printing it. 
*/
#include <iostream>
using namespace std;

int main() {
  int limit, next, count;
  int prev = 0, curr = 1;
  cout << "Fibs below what:";
  cin >> limit;
  cout << prev << " " << curr << " ";
  count = 2;
  //set up and loop ...
  while(prev + curr < limit) {
    next = prev + curr;
    cout << next << " "; 
    prev = curr;
    curr = next;
    count++;
  }

  //report how many terms ...  
	cout << "\nThat was " << count << " terms.\n";       
  return 0;
}