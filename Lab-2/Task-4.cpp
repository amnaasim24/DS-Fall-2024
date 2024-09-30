#include <iostream>
using namespace std;

int main(){
    float *gpas[4];
    int courseCount[4] = {3, 4, 2, 1};
    gpas[0] = new float[3]{2.5, 1.7, 2.0};
    gpas[1] = new float[4]{2.8, 2.6, 3.9, 3.0};
    gpas[2] = new float[2]{3.4, 2.8};
    gpas[3] = new float[1]{2.9};
    string departments[4] = {"Software Engineering", "Artificial Intelligence", "Computer Science", "Data Science"};
    for (int i = 0; i < 4; i++){
        cout << departments[i] << " core courses GPAs: ";
        for (int j = 0; j < courseCount[i]; j++){
            cout << gpas[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 4; i++){
        delete[] gpas[i];
    }

    return 0;
}