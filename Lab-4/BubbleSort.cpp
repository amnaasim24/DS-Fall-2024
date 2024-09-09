/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Bubble Sort.
*/

#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n){

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void printArray(int arr[], int size){
    for (int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
}
int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int N = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted array:\n";
    printArray(arr, N);
    cout<<endl;

    bubbleSort(arr, N);
    cout<<"Sorted array:\n";
    printArray(arr, N);
    cout<<endl;

    return 0;
}