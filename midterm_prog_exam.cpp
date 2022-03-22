#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//********
// NB Paste your repl url(s) in here
// https://replit.com/...
//*******

/* This program would work correctly if the input were 
12345678 2Mat4 57 1E3 24 1CS3 45 3Fr1 45 2E2 40 2BA7 68 3BS3 58 3SS 45
999
*/ 

const int MIN_GRADE = 40; //minimum grade 40%
const int NUM_MODULES = 8; //number of modules per student

double print_per_student(string student_no);

string average_to_grade(double average);

int main()
{
  string current_student_no, best_student_no;
  double current_average, best_average;
  best_average = 0;
  best_student_no = "";

  cout << fixed << setprecision(1);//gives one decimal place for the averages

  //while loop will stop when it sees the flag 999 in the file
  cin >> current_student_no;
  while(current_student_no != "999") {
    //we call our main function "print_per_student" that returns athe average not of our current student. Thanks to that, we will be able to determine the best average among all students
    current_average = print_per_student(current_student_no);
    if(current_average > best_average) {
      best_average = current_average;
      best_student_no = current_student_no;
    }
    cin >> current_student_no;
  }
  
  cout << "Best student: " << best_student_no << endl;//will only work for testing a program that reads only    one record.
   
	return 0;
}


double print_per_student(string student_no) {
  string current_exam_code, failed_exam, grade;
  double average, sum;
  bool is_any_module_failed = false;
  int current_mark;
  
  failed_exam = "";
  sum = 0;

  //This loop will go through all grade of our current student and see if he had any failed exam (in this case, we add the exam code to the string "failed_exam"). This loop will compute the average grade of our student thanks to the variable "sum" and "average"
  for(int i = 0; i < NUM_MODULES; i++) {
    cin >> current_exam_code;
    cin >> current_mark;
    if(current_mark < MIN_GRADE) {
      failed_exam = failed_exam + " " + current_exam_code;
      is_any_module_failed = true;
    }
    sum = sum + current_mark;
  }

  //computer the average
  average = (sum/NUM_MODULES);

  //grade is determined bu the function "average_to_grade" except if a module is failed
  if(is_any_module_failed) {
    grade = "F";
  }
  else {
    grade = average_to_grade(average);
  }
  
  //Prints part
	cout << student_no << " "; 
	cout << "Failed:";
	cout << failed_exam << " ";
	cout << "Average: " << average << "% ";	
	cout << "Grade: " << grade;
	cout << endl;

  return average;
}

string average_to_grade(double average) {
  if(average >= 70) return "D";
  else if(average >= 60 && average < 70) return "P1";
  else if(average >= 50 && average < 60) return "P2";
  else return "P3";
  return "";
}