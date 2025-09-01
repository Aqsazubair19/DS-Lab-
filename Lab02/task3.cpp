#include<iostream>
using namespace std;

int main(){
int student;
cout<<"enter number of students :"<<endl;
cin>>student;

int **marks = new int*[student];
int *course = new int[student];

for(int i=0; i<student ;i++){
    cout<<"enter number of courses for student "<<i+1 <<endl;
    cin>> course[i];

    marks[i] = new int[course[i]];

  
    for(int j=0;j<course[i];j++){
     cout<<"enter marks for course "<<j+1 <<" "<<endl;
        cin>>marks[i][j];
    }

}

cout<<"marks of all students:"<<endl;
for(int i=0;i<student;i++){
    cout<<"student "<<i+1<<": ";
        for(int j=0;j<course[i];j++){
        cout<<marks[i][j]<<" ";

    }
    cout<<endl;

}

for(int i=0;i<student;i++){
    delete[]  marks[i];
}

delete[] marks;
delete[] course;

return 0;

}
