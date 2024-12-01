/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 10
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int> arr, int k)
{

    // min heap
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] > p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }

    return p.top();
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << k << "th largest element: " << kthLargest(arr, k) << endl;
    return 0;
}
