/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of searching Algorithms using Linear Search.
*/

#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int search)
{
    int low = 0;
    int high = n;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (search == arr[mid])
        {
            return mid;
        }
        if (search > arr[mid])
        {
            low += 1;
        }
        if (search < arr[mid])
        {
            high -= 1;
        }
    }
}
int main()
{
    int arr[7] = {1, 2, 3, 5, 6, 8, 10};
    cout << "Original Array" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Key : 6" << endl;
    cout << "Key found at index : " << BinarySearch(arr, 7, 6) << endl;

    return 0;
}