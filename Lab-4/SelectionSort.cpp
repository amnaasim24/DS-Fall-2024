/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Selection Sort.
*/

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i=0; i<n-1; i++)
    {
        int min_idx = i;
        for (int j=i+1; j<n; j++){
            if (arr[j]<arr[min_idx])
                min_idx = j;
        }
        if (min_idx!=i)
            swap(arr[min_idx], arr[i]);
    }
}
void printArray(int arr[], int n){
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted array:\n";
    printArray(arr, n);
    cout<<endl;

    selectionSort(arr, n);
    cout<<"Sorted array:\n";
    printArray(arr, n);
    cout<<endl;

    return 0;
}