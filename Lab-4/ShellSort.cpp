/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Shell Sort.
*/

#include <iostream> 
using namespace std;

void shellSort(int arr[], int n) { 
    for (int gap=n/2; gap>0; gap/=2) { 
        for (int i=gap; i<n; i+=1) { 
            int temp = arr[i]; 
            int j; 
            for (j=i; j>=gap && arr[j-gap]>temp; j-=gap) {
                arr[j] = arr[j-gap]; 
            }
            arr[j] = temp; 
        } 
    } 
} 
void printArray(int arr[], int n) { 
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" "; 
    }
} 
int main() { 
    int arr[] = { 12, 34, 54, 2, 3 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
 
    cout<<"Unsorted Array:\n"; 
    printArray(arr, n); 
    cout<<endl; 
 
    shellSort(arr, n); 
    cout<<"Sorted Array:\n"; 
    printArray(arr, n); 
    cout<<endl; 

} 