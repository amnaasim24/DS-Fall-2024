#include <iostream>
using namespace std;

int main(){
    const int numRows = 4;
    int numberOfSeats[numRows] = {2, 3, 2, 1};
    string *seatingChart[numRows];
    for (int i = 0; i < numRows; i++){
        seatingChart[i] = new string[numberOfSeats[i]];
    }
    for (int i = 0; i < numRows; i++){
        cout << "Enter the names of people who will be sitting in row " << i + 1 << ":\n";
        for (int j = 0; j < numberOfSeats[i]; j++){
            cout << "Seat " << j + 1 << ": ";
            cin >> seatingChart[i][j];
        }
    }
    cout << "\nSeating Chart:\n";
    for (int i = 0; i < numRows; i++){
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < numberOfSeats[i]; j++){
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < numRows; i++){
        delete[] seatingChart[i];
    }

    return 0;
}