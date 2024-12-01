/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-3
*/

#include "iostream"
using namespace std;
class node{
    int data;
    node* next;
    public:
    node():next(NULL), data(0){}
    node(const int d): data(d), next(NULL){}
    friend class SLL;
};
class SLL{
    node* head;
    public:
    SLL(): head(NULL){}
    SLL(node* n):head(n){}
    void insertAtTail(const int val)
    {
        node* n = new node(val);
        if(head==NULL) head = n;
        else{
            node* curr = head;
            while(curr->next!=NULL)curr = curr->next;
            curr->next = n;
        }
    }
    node* reverse(){
        node* curr = head, *prev = NULL, *next;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void print()
    {
        node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};
int main()
{
    SLL list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.print();
    list = list.reverse();
    list.print();
    return 0;
}
