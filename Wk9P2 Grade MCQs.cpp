#include <iostream>
using namespace std;

// declare a read function that reads size chars into array a ...
void read_set(char set[], int set_size);

//declare a score function that takes two arrays of chars, correct answers and student answers, and their size, and returns the score ...
int score_set(const char solution[], const char student_set[], int sets_size);


int main ()
{
    const int MCQsize = 20;
    int studentID, grade;
    char solution[MCQsize], answers[MCQsize];

    //read the model/correct answers ...
    read_set(solution, MCQsize);

    //read the first student id
    cin >> studentID;

    //while loop with a sentinel
    while(studentID > 0) {
        read_set(answers, MCQsize); //we read the current student's set
        grade = score_set(solution, answers, MCQsize); //we give a grade to this set by calling this function

        cout << studentID << ": " << grade << endl; //print the current student's grade and his studentID
        cin >> studentID; //read the next studentID
    }


    return 0;
}

void read_set(char set[], int set_size) {
    for(int i = 0; i < set_size; i++) {
        cin >> set[i];
    }
}

int score_set(const char solution[], const char student_set[], int sets_size) {
    int current_grade = 0;

    for(int i = 0; i < sets_size; i++) {
        if(student_set[i] == solution[i]) current_grade+=2;
        else if((student_set[i] != solution[i]) && (student_set[i] != 'x')) current_grade-=1;
    }

    return current_grade;
}