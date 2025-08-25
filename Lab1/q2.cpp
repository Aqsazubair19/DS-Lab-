#include <iostream>
using namespace std;

class Exam{
    private:
        string *studentName;
        string *examDate;
        int *score;

    public:
        Exam(string name, string date, int score){
            studentName = new string(name);
            examDate = new string(date);
            this->score = new int(score);
        }
        /*
        Exam(const Exam& other){
            studentName = new string(*other.studentName);
            examDate = new string(*other.examDate);
            score = new float(*other.score);
        }
        */

        void set_name(string n){
            studentName = new string(n);
        }
        void set_date(string d){
            examDate = new string(d);
        }
        void set_score(int s){
            score = new int(s); 
        }

        void displayDetails(){
            cout << "Student Name: " << *studentName << endl;
            cout << "Exam Date: " << *examDate << endl;
            cout << "Score: " << *score << endl;
        }

        ~Exam(){
            delete studentName;
            delete examDate;
            delete score;
        }

};

int main(){
    Exam student1("Aqsa", "20/12/2025", 80);
    cout<< "Student 1\n";
    student1.displayDetails();

    Exam student2 = student1;
    cout << "Student 2\n";
    student2.displayDetails();

    student2.set_name("fatima");
    student2.set_date("02/05/2024");
    student2.set_score(90);
    cout << "Student 2\n";
    student2.displayDetails();

    return 0;

}
