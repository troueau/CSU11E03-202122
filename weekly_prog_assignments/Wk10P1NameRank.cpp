//Week 10 P1 name rank
#include <iostream>
#include <string>
using namespace std;

const int NUM_NAMES = 10;

int search (string s, const string sarray[], int size);
//returns the position of s in sarray or -1 if not found

int main () {
    string girls [NUM_NAMES] = {"Grace", "Fiadh", "Emily", "Sophie", "Ava", "Amelia", "Ella", "Hannah", "Lucy", "Alex"};
    string boys [NUM_NAMES] = {"Jack", "James", "Noah", "Daniel", "Conor", "Finn", "Liam", "Fionn", "Alex", "Charlie"};
    //source https://www.independent.ie/news/revealed-irelands-top-baby-names-in-2020-40134889.html
    //adapted by insertion of Alex in each list to test corect logic where a name appears on both lists
    string cur_name, sentinel;
    int pos;

    while(sentinel!="No") {
        cout << "Enter a name to search for:";
        cin >> cur_name;

        pos = search(cur_name, girls, NUM_NAMES);
        if(pos==-1) {
            pos = search(cur_name, boys, NUM_NAMES);
            if(pos==-1) {
                cout << cur_name << " is not in the top " << NUM_NAMES << " for girls or boys.\n";
            }
            else {
                cout << cur_name << " is ranked " << pos+1 << " in top boys name.\n";
            }
        }
        else {
            cout << cur_name << " is ranked " << pos+1 << " in top girls name.\n";
            pos = search(cur_name, boys, NUM_NAMES);
            if(pos!=-1) {
                cout << cur_name << " is ranked " << pos+1 << " in top boys name.\n";
            }
        }


        cout << "Look up the rank of another name? Enter No to end:";
        cin >> sentinel;
    }

    return 0;
}

int search (string s, const string sarray[], int size) {
//returns the position of s in sarray or -1 if not found
    for (int i=0; i < size; i++) {
        if (sarray[i] == s) {
            return i;
        }
    }
    //if we get here we didn't find s in the array
    return -1;
}