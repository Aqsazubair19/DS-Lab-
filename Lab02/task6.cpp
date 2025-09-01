#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;     
    int size;     

public:

    SafePointer(int n) {
        size = n;
        ptr = new int[size];  
    }

    // Prevent copying (to avoid double delete issues)
    // SafePointer(const SafePointer&) = delete;
    // SafePointer& operator=(const SafePointer&) = delete;


    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
        ptr[index] = value;
        } else {
      cout << "Error: Index out of bounds!\n";
        }
    }


    int getValue(int index) const {
        if (index >= 0 && index < size) {
        return ptr[index];
        } else {
        cout << "Error: Index out of bounds!\n";
        }
    }


    void release() {
        if (ptr != nullptr) {
            delete[] ptr;
            ptr = nullptr;
    
        }
    }

    
    ~SafePointer() {
        release();
    }
};

int main() {
    SafePointer marks(5);

  
    cout << "Enter marks of 5 students:\n";
    for (int i = 0; i < 5; i++) {
        int value;
        cout << "Student " << i + 1 << ": ";
        cin >> value;
        marks.setValue(i, value);
    }

    cout << "\nMarks of students:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ": " << marks.getValue(i) << endl;
    }

   
    return 0;
}
