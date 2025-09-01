#include <iostream>
#include <string>
using namespace std;

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    // Jagged array: each row = category, different columns = books
    int** books = new int*[categories];
    string* categoryNames = new string[categories]; 
    int* bookCounts = new int[categories];          

    for (int i = 0; i < categories; i++) {
        cout << "\nEnter name of category " << i + 1 << ": ";
        cin >> categoryNames[i];

        cout << "Enter number of books in " << categoryNames[i] << ": ";
        cin >> bookCounts[i];

        books[i] = new int[bookCounts[i]]; 

        cout << "Enter book IDs for " << categoryNames[i] << ":\n";
        for (int j = 0; j < bookCounts[i]; j++) {
            cout << "Book " << j + 1 << " ID: ";
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < bookCounts[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book ID " << searchID << " found in category: " << categoryNames[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Book ID " << searchID << " not found in the library.\n";
    }

    
    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] categoryNames;
    delete[] bookCounts;

    return 0;
}
