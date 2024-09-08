/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 1
  Question # 1
  Description: Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
a) Default Constructor Usage:
Create a default-initialized BankAccount object named account1. Print out the balance of
account1.
b) Parameterized Constructor Usage:
Create a BankAccount object named account2 with an initial balance of $1000. Print out the
balance of account2.
c) Copy Constructor Usage:
Using the account2 you created earlier, create a new BankAccount object named account3 using
the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the
balance of account2 to ensure it hasn't been affected by the transaction involving account3. Note:
assume the variables in your case and print out the details.
*/


#include <iostream>
using namespace std;


class BankAccount {
private:
    double balance;
public:
    BankAccount() {
        balance = 0.0;
        cout<<"The initial balance is set as $0.0"<<endl;
    }
    BankAccount(double b) {
        balance = b;
        cout<<"The initial balance is: $"<<b<<endl;
    }
    BankAccount(const BankAccount& b1) : balance(b1.balance) {}
    double getBalance() const {
        return balance;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout<<"Insufficient funds"<<endl;
        } else {
            balance -= amount;
        }
    }
};


int main() {
    BankAccount account1;
    cout<<"Account1 balance: $"<<account1.getBalance()<<endl;


    BankAccount account2(1000);
    cout<<"Account2 balance: $"<<account2.getBalance()<<endl;


    BankAccount account3(account2);
    account3.withdraw(200);
    cout<<"Account3 balance after withdrawal: $"<<account3.getBalance()<<endl;
    cout<<"Account2 balance (should be unchanged): $"<<account2.getBalance()<<endl;


    return 0;
}
