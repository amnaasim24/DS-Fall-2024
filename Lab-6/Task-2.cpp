/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 6
  Question # 2
  Description: You are building an expression evaluator as part of a simple calculator application. Your
task is to implement
o infix_to_postfix
o Modify the infix_to_postfix algorithm to implement infix_to_prefix, include
comments where the code is modified.
Test with the given expressions: K+L-M*N+(O^P)*W/U/V*T+Q
*/

#include <iostream>
#include <string>
using namespace std;

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infix_to_postfix(string infix) {
    const int maxSize = 100;
    char operators[maxSize];
    int top = 0;
    string postfix = "";

    for (char c : infix) {
        if (c == ' ') continue;
        if (isalnum(c)) {
            postfix += c;
        } 
        else if (c == '(') {
            operators[top++] = c;
        } 
        else if (c == ')') {
            while (top > 0 && operators[top - 1] != '(') {
                postfix += operators[--top];
            }
            if (top > 0 && operators[top - 1] == '(') {
                top--;
            }
        } 
        else {
            while (top > 0 && operators[top - 1] != '(' && getPrecedence(c) <= getPrecedence(operators[top - 1])) {
                postfix += operators[--top];
            }
            operators[top++] = c;
        }
    }
    while (top > 0) {
        postfix += operators[--top];
    }
    return postfix;
}

string infix_to_prefix(string infix) {
    string reversed_infix = string(infix.rbegin(), infix.rend());
    for (char& c : reversed_infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infix_to_postfix(reversed_infix);
    string prefix = string(postfix.rbegin(), postfix.rend());
    return prefix;
}

int main() {
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";
    string postfix = infix_to_postfix(infix);
    string prefix = infix_to_prefix(infix);

    cout<<"Infix: "<<infix<<endl;
    cout<<"Postfix: "<<postfix<<endl;
    cout<<"Prefix: "<<prefix<<endl;

    return 0;
}