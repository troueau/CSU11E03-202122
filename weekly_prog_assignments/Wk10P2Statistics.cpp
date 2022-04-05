/**
* Week 10 P2
Statistical Functions
*
* This program reads in an unknown number of values, and then
* computes the mean, variance, standard deviation and the
* number of zero crossing for these values.
*
*/

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void read_to_sentinel(double array[], int capacity, int& size, double sentinel);

double mean(const double array[], int size);
double variance(const double array[], int size);
double std_dev(const double array[], int size);
int zero_crossings(const double array[], int size);


int main()
{
    const int CAPACITY = 100;
    double array[CAPACITY];
    int size, zeros;
    double sentinel = 9999;

    double ave, var, stddev;

    //call read_to_sentinel ...
    read_to_sentinel(array, CAPACITY, size, sentinel);

    //call the functions to compute stats,
    //passing in the size value provided by read_to_sentinel ...
    ave = mean(array, size);
    var = variance(array, size);
    stddev = std_dev(array, size);
    zeros = zero_crossings(array, size);

    //Print the output
    cout << "Count:" << size << endl;
    cout << "Mean:" << ave << endl;
    cout << "Variance:" << var << endl;
    cout << "Std. Dev.:" << stddev << endl;
    cout << "Zero Xs:" << zeros << endl;

    return 0;
}

// read_to_sentinel is as in lectures and in squarearbseq.cpp
// capacity is the maximum capacity (declared size) of the array;
// size (changed within the function, hence the &) becomes the number of values actually added
// sentinel is the number that marks the end of the sequence;
void read_to_sentinel (double array[], int capacity, int& size, double sentinel)
{
    size = 0;
    double x;
    cin >> x;
    while(size < capacity && x != sentinel)
    {
        array[size] = x;
        size = size+1;
        cin >> x;
    }
    if (size == capacity) {
        cout << "\nWARNING OVERFLOW Only first " << capacity << " numbers handled.\n";
    }
}

double mean(const double array[], int size) {
    double sum = 0;

    for(int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum/size;
}

double variance(const double array[], int size) {
    double sum = 0;
    double ave = mean(array, size);
    for(int i = 0; i < size; i++) {
        sum += pow((array[i] - ave), 2);
    }

    return sum/(size-1);
}

double std_dev(const double array[], int size) {
    return sqrt(variance(array, size));
}

int zero_crossings(const double array[], int size) {
    int rep = 0;

    for(int i = 1; i < size; i++) {
        if(array[i]*array[i-1] < 0) rep++;
    }

    return rep;
}




