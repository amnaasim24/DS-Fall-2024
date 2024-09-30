#include <iostream>
using namespace std;

int main(){
    int rows1 = 3;
    int cols1 = 5;
    int cols2 = 5;
    int rowSizes1[] = {2, 3, 5};
    int rowSizes2[] = {5, 5, 5};
    int **arr1 = new int *[rows1];
    int **arr2 = new int *[cols1];
    for (int i = 0; i < rows1; i++){
        arr1[i] = new int[rowSizes1[i]];
    }
    for (int i = 0; i < cols1; i++){
        arr2[i] = new int[cols2];
    }
    int initValues1[3][5] = {
        {1, 2, 0, 0, 4},
        {1, 7, 8, 0, 3},
        {2, 3, 4, 5, 6}
    };
    int initValues2[5][5] = {
        {1, 4, 0, 0, 0},
        {1, 2, 9, 0, 2},
        {1, 3, 2, 5, 7},
        {1, 0, 0, 0, 2},
        {3, 0, 0, 0, 3}
    };
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < rowSizes1[i]; j++){
            arr1[i][j] = initValues1[i][j];
        }
    }
    for (int i = 0; i < cols1; i++){
        for (int j = 0; j < cols2; j++){
            arr2[i][j] = initValues2[i][j];
        }
    }
    int **result = new int *[rows1];
    for (int i = 0; i < rows1; i++){
        result[i] = new int[cols2]();
    }
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols2; j++){
            result[i][j] = 0;
            for (int k = 0; k < rowSizes1[i]; k++) {
                if (k < cols1){
                    result[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    }
    cout << "Multiplication result:" << endl;
    for (int i = 0; i < rows1; i++){
        for (int j = 0; j < cols2; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows1; i++){
        delete[] arr1[i];
        delete[] result[i];
    }
    delete[] arr1;
    delete[] result;
    for (int i = 0; i < cols1; i++){
        delete[] arr2[i];
    }
    delete[] arr2;

    return 0;
}