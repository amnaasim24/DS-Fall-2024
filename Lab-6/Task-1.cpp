/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 6
  Question # 1
  Description: Given one stack with n elements, separate out even values in one stack and odd values in
another stack.
*/

#include <iostream>
#include <stack>
using namespace std;

void SepEvenOdd(stack<int>& ors, stack<int>& es, stack<int>& ods) {
    while (!ors.empty()) {
        int element = ors.top();
        ors.pop();
        if (element % 2 == 0) {
            es.push(element);
        } 
        else {
            ods.push(element);
        }
    }
}

void printStack(const stack<int>& s) {
    stack<int> temp = s;
    while (!temp.empty()) {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main() {
    stack<int> ors;
    stack<int> es;
    stack<int> ods;

    ors.push(3);
    ors.push(6);
    ors.push(5);
    ors.push(2);
    ors.push(8);

    SepEvenOdd(ors, es, ods);

    cout<<"Even Stack: ";
    printStack(es);
    
    cout<<"Odd Stack: ";
    printStack(ods);

    return 0;
}