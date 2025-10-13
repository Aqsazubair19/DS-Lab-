#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Process {
    int id;
    int priority;
    string name;
};


void displayProcess(const Process &p) {
    cout << "Process ID: " << p.id
         << ", Name: " << p.name
         << ", Priority: " << p.priority << endl;
}

int main() {
    queue<Process> arrivalQueue;   
    stack<Process> executionStack; 

   
    cout << "=== Job Scheduling System ===\n";
    cout << "Enter number of processes: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        cout << "\nEnter details for Process " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> p.id;
        cout << "Name: ";
        cin >> p.name;
        cout << "Priority (1 = Low, 2 = Medium, 3 = High): ";
        cin >> p.priority;
        arrivalQueue.push(p);
    }

 
    cout << "\n\n--- Processes arriving in Queue (FIFO) ---\n";
    queue<Process> temp = arrivalQueue;
    while (!temp.empty()) {
        displayProcess(temp.front());
        temp.pop();
    }

   
    cout << "\n--- Scheduling based on Priority (Stack used) ---\n";
    while (!arrivalQueue.empty()) {
        Process current = arrivalQueue.front();
        arrivalQueue.pop();

        if (current.priority == 3) {
          
            executionStack.push(current);
        } else {
            
            cout << "Queued for later: ";
            displayProcess(current);
        }
    }


    cout << "\n--- Executing High Priority Tasks (Stack – LIFO) ---\n";
    while (!executionStack.empty()) {
        displayProcess(executionStack.top());
      
        executionStack.pop();
    }

    cout << "\nAll high priority processes executed.\n";
    return 0;
}
