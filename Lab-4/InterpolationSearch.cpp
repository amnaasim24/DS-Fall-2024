/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of searching Algorithms using Interpolation Search.
*/

#include <iostream>
using namespace std;
int InterpolationSearch(int arr[], int n, int search)
{
    int low = 0;
    int high = n;

    while (low < high)
    {
        int pos = low + (((search - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[pos] == search)
        {
            return pos;
        }
        if (search > arr[pos])
        {
            low += 1;
        }
        if (search < arr[pos])
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
        cout << arr[i] << "  ";
    }
    cout << "\nKey : 6" << endl;
    cout << "Key found at index : " << InterpolationSearch(arr, 7, 6) << endl;

    return 0;
}