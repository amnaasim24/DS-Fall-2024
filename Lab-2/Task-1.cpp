#include <iostream>
using namespace std;

int main(){
    int Rows = 5;
    int Size[5]={2,3,4,5,1};
    int **arr = new int *[Rows];
    for (int i = 0; i < Rows; i++){
        arr[i] = new int[Size[i]];
    }
    for (int i = 0; i < Rows; i++){
        cout << "Enter " << Size[i] << " elements for row " << i + 1 << ":" << endl;
        for (int j = 0; j < Size[i]; j++){
            cin >> arr[i][j];
        }
    }
    cout << "The elements of the jagged array:" << endl;
    for (int i = 0; i < Rows; i++){
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < Size[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int temparr[Rows][10] = {0}; 
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Size[i]; j++){
            temparr[i][j] = arr[i][j];
        }
    }
    cout << "The elements of the temporary array:" << endl;
    for (int i = 0; i < Rows; i++){
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 10; j++){
            cout << temparr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < Rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}