/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Insertion Sort.
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i=1; i<n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[], int n){
    for (int i=0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Unsorted Array:\n";
    printArray(arr, n);
    cout<<endl;

    insertionSort(arr, n);
    cout<<"Sorted Array:\n";
    printArray(arr, n);
    cout<<endl;

    return 0;
}