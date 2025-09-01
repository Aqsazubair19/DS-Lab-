#include <iostream>
using namespace std;

int main() {
    int deptCount;
    cout << "Enter number of departments: ";
    cin >> deptCount;

    
    int** salaries = new int*[deptCount];
    int* empCount = new int[deptCount]; 

   
    for (int i = 0; i < deptCount; i++) {
        cout << "\nEnter number of employees in department " << i + 1 << ": ";
        cin >> empCount[i];

        salaries[i] = new int[empCount[i]]; 

        cout << "Enter salaries for department " << i + 1 << ":\n";
        for (int j = 0; j < empCount[i]; j++) {
            cout << "Employee " << j + 1 << ": ";
            cin >> salaries[i][j];
        }
    }

   
    cout << "\nHighest salary in each department:\n";
    for (int i = 0; i < deptCount; i++) {
        int highest = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > highest) {
                highest = salaries[i][j];
            }
        }
        cout << "Department " << i + 1 << ": " << highest << endl;
    }

   
    int bestDept = 0;
    double maxAvg = 0.0;

    for (int i = 0; i < deptCount; i++) {
        int sum = 0;
        for (int j = 0; j < empCount[i]; j++) {
            sum += salaries[i][j];
        }
        double avg = (double)sum / empCount[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }

    cout << "\nDepartment " << bestDept + 1 
         << " has the highest average salary = " << maxAvg << endl;

  
    for (int i = 0; i < deptCount; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;

    return 0;
}
