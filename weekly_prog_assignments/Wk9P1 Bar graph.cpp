#include <iostream>
#include <iomanip>
using namespace std;

const int COLUMN_SIZE = 20; //20 is the range max + 1 to set the bottom bar of the graph
const int ROW_SIZE = 70; //70 integers to read + 5 characters to set the left bar of the graph

void print_graph(const int integers_array[]);

int main ()
{
    int current_integer; //the integer we are currently reading
    int integers_array[ROW_SIZE]; //declaration of the array that will contain the integers we read in the file "numbers.txt"

    //this loop will read all the input integers and put them into the array 'integers_array'
    cin >> current_integer;
    for(int i = 0; i < ROW_SIZE; i++) {
        integers_array[i] = current_integer;
        cin >> current_integer;
    }

    print_graph(integers_array);

    return 0;
}

void print_graph(const int integers_array[]) {
    for(int i = COLUMN_SIZE; i > 0; i--) {
        cout << setw(2) << right << i << "  |"; // this line will print the left bar i.e '18  |'
        for(int j = 0;  j < ROW_SIZE; j++) {
            if(integers_array[j] >= i) { //This condition will know, thanks to the array, if we need to print a star here
                cout << "*";
            }
            else { //no star = a blank character
                cout << " ";
            }
        }
        cout << endl;
    }

    //this loop will handle the bottom bar with the characters '|' and '-' and '+'
    for(int k = 1; k <= ROW_SIZE+5; k++) {
        if(k%10==0) {
            cout << "+";
        }
        else if(k%5==0) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
}
