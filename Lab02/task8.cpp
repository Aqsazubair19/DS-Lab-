#include <iostream>
using namespace std;

int main() {
    int n, m;
      cout << "Enter number of days: ";
      cin >> n;
      cout << "Enter number of readings per day: ";
      cin >> m;

    double** temps = new double*[n];
      for (int i = 0; i < n; i++) {
        temps[i] = new double[m];
    }

    for (int i = 0; i < n; i++) {
      cout << "\nEnter temperatures for Day " << i + 1 << ":\n";
         for (int j = 0; j < m; j++) {
          cout << "Time " << j + 1 << ": ";
            cin >> temps[i][j];
           
        }
    }

  
    double* dailyAvg = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temps[i][j];
        }
        dailyAvg[i] = sum / m;
    }

    int hottest = 0, coldest = 0;
    for (int i = 1; i < n; i++) {
       if (dailyAvg[i] > dailyAvg[hottest]) hottest = i;
     if (dailyAvg[i] < dailyAvg[coldest]) coldest = i;
    }

    cout << "\nDaily Average Temperatures:\n";
    for (int i = 0; i < n; i++) {
      cout << "Day " << i + 1 << ": " << dailyAvg[i] << endl;
    }

    cout << "\nHottest Day: Day " << hottest + 1 << " with average temperature " << dailyAvg[hottest] << endl;

    cout << "Coldest Day: Day " << coldest + 1<< " with average temperature " << dailyAvg[coldest] << endl;


    for (int i = 0; i < n; i++) {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] dailyAvg;

    return 0;
}
