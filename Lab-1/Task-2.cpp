/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 1
  Question # 2
  Description: Create a C++ class named "Exam" designed to manage student exam records, complete with a
shallow copy implementation? Define attributes such as student name, exam date, and score within the
class, and include methods to set these attributes and display exam details. As part of this exercise,
intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward,
create an instance of the "Exam" class, generate a shallow copy, and observe any resulting issues?
*/


#include <iostream>
#include <string>
using namespace std;


class Exam {
private:
    string studentName;
    string examDate;
    int score;
    string* notes;
public:
    Exam(string n, string d, int s): studentName(n), examDate(d), score(s), notes(new string) {}
    ~Exam() {
        delete notes;
    }
    void setStudentName(string n) {
        studentName = n;
    }
    void setExamDate(string d) {
        examDate = d;
    }
    void setScore(int s) {
        score = s;
    }
    void setNotes(string notes) {
        *(this->notes) = notes;
    }
    void displayExamDetails() {
        cout<<"Student Name: "<<studentName<<endl;
        cout<<"Exam Date: "<<examDate<<endl;
        cout<<"Score: "<<score<<endl;
        cout<<"Notes: "<<*(this->notes)<<endl;
    }
};


int main() {
    Exam exam1("Amna Asim", "2022-01-01", 80);
    exam1.setNotes("Good job!");


    Exam exam2 = exam1;


    exam2.setStudentName("Amna Asim");
    exam2.setNotes("Excellent work!");


    cout << "Exam 1 details:" << endl;
    exam1.displayExamDetails();


    cout << "Exam 2 details:" << endl;
    exam2.displayExamDetails();


    return 0;
}
