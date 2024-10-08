/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Comb Sort.
*/

#include <iostream>
using namespace std;
 
int getNextGap(int gap) {
    gap = (gap*10)/13;
    if (gap<1) {
        return 1;
    }
    return gap;
}
void combSort(int a[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap!=1 || swapped==true) {
        gap = getNextGap(gap);
        swapped = false;
        for (int i=0; i<n-gap; i++) {
            if (a[i]>a[i+gap]) {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}
int main() {
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    cout<<endl;
 
    combSort(a, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    cout<<endl;
 
    return 0;
}
