
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
    node():data(0), next(NULL){}
    node(const int d): data(d), next(NULL){}
    friend class SLL;
};
class SLL{
    node* head;
    public:
    SLL():head(NULL){}
    SLL(node* n): head(n){}
    void insertAtFront(const int val){
        node* n = new node(val);
        if(head==NULL) head = n;
        else{
	        n->next = head;
	        head = n;
        }
    }
    void insertAtTail(const int val)
    {
        node* n = new node(val);
        if(head==NULL) head = n;
        else{
	        node* current = head;
	        while(current->next != NULL){current = current->next;} 
	        current->next = n;
        }
    }
    void InsertAfterValue(const int value, const int insertingValue)
    {
		node* n = new node(insertingValue);
		if(head==NULL){head = n;}
		else{
			node* currentPtr = head;
			while(currentPtr->data!= value){currentPtr = currentPtr->next;}
			node* temp = currentPtr->next;
			currentPtr->next = n;
			n->next = temp;
	        }
    }
    void InsertBeforeValue(const int value, const int insertingValue)
    {
    	node* n = new node(insertingValue);
    	if(head==NULL){head = n;}
    	else{
    		node* currentPtr = head;
    	    while(currentPtr->next->data!=value){currentPtr = currentPtr->next;} 
    	    n->next = currentPtr->next;
		    currentPtr->next = n;
		}
	}
	int numNodes()
	{
		int nodes=0;
		node* currentPtr = head;
		while(currentPtr!=NULL){
			nodes++;
			currentPtr = currentPtr->next;
		}
		return nodes;
	}
	void deleteFromHead()
	{
		if(head!=NULL){
			node* currPtr = head;
			head = currPtr->next;
			delete currPtr;
			currPtr = NULL;
	    }
	    else{
	    	cout<<"Linked list not found"<<endl;
		}
	}
	void deleteFromTail()
	{
		if(head!=NULL){
			node* currPtr = head;
			while(currPtr->next->next!=NULL){currPtr = currPtr->next;}
			delete currPtr->next;
			currPtr->next = NULL;
	    }
	    else{
	    	cout<<"Linked list not found"<<endl;
		}
	}
	void deleteValue(const int value)
	{
		if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
		node* n = head;
		while(n->next->data!=value){n = n->next;}
		node* temp = n->next;
		n->next = n->next->next;
		delete temp;
		temp = NULL; 
	}
	void printList()
	{
		node* currentPtr = head;
		while(currentPtr!=NULL)
		{
			cout<<currentPtr->data<<" ";
			currentPtr=currentPtr->next;
		}
	}
};
int main() {
    SLL list;
    // Inserting elements at the front
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtFront(30);
    cout << "After inserting at front:"<<endl;
    list.printList();
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtTail(60);
    // Inserting elements at the back
    cout << "\nAfter inserting at tail:"<<endl;
    list.printList();
	cout<<"\nTotal nodes in list: "<<list.numNodes()<<endl;
    list.deleteFromHead();
	cout << "\nAfter deleting from head:"<<endl;
    cout<<"\n";
    list.printList();
    list.deleteFromTail();
	cout << "\nAfter deleting from tail:"<<endl;
    cout<<"\n";
    list.printList();
	list.deleteValue(40);
	cout<<"\nAfter deleting value:"<<endl;
	list.printList();
	list.InsertAfterValue(20, 11);
	cout << "\nInserted value after 20:"<<endl;
	list.printList();
	list.InsertBeforeValue(50, 22);
	cout << "\nInserted value before 50:"<<endl;
	list.printList();
    list.deleteValue(40);
    cout<<"\nAfter deleting value:"<<endl;
    list.printList();
    list.InsertAfterValue(20, 11);
    cout << "\nInserted value after 20:"<<endl;
    list.printList();
    list.InsertBeforeValue(50, 22);
    cout << "\nInserted value before 50:"<<endl;
    list.printList();
    return 0;	
}

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
    SLL segregate()
    {
        SLL newList; 
        node* curr = head;
        while(curr!=NULL)
        {
            if(curr->data%2==0)newList.insertAtTail(curr->data); 
            curr = curr->next;
        }
        curr = head; 
        while(curr!=NULL)
        {
            if(curr->data%2!=0)newList.insertAtTail(curr->data); 
            curr = curr->next;
        }
        return newList;
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
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.print();
    list = list.segregate();
    cout<<"printing segregated list: "<<endl;
    list.print();
    return 0;
}

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-3
*/

#include "iostream"
using namespace std;
class node{
    int data;
    node* next, *prev;
    public:
    node():next(NULL), prev(NULL), data(0){}
    node(const int d): data(d), next(NULL), prev(NULL){}
    friend class DLL;
};
class DLL{
    node *head, *tail;
    public:
    DLL():head(NULL), tail(NULL){}
    void insertAtEnd(const int val)
    {
        node* n = new node(val);
        if(head==NULL)head = tail = n;
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void insertAtFront(const int val)
    {
        node* n = new node(val);
        if(head==NULL)head = tail = n;
        else{
            head->prev = n;
            n->next = head;
            head = n;
        }
    }
    void insertAfterValue(const int after, const int val)
    {
        node* n = new node(val);
        if(not head){ 
            cout<<"list not found"<<endl;
            return;
        }
        node* curr = head;
        while(curr->data!=after) curr=curr->next;
        n->prev = curr;
        n->next =  curr->next;
        curr->next = n;
    }
    void insertBeforeValue(const int before, const int val)
    {
        node* n = new node(val);
        if(not head)
        {
            cout<<"list not found"<<endl;
            return;
        }
        node* curr = head;
        while(curr->next->data!=before) curr = curr->next;
        n->prev = curr;
        n->next = curr->next;
        curr->next = n;
    }
    void deleteHead()
    {
        if(not head)
        {
            cout<<"list not found"<<endl;
            return;
        }
        node* temp = head;
        head = head->next;
        if(head) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }
    void deleteTail()
    {
        if(not tail)
        {
            cout<<"list not found"<<endl;
            return;
        }
        node* temp = tail;
        tail = tail->prev;
        if(tail)tail->next = NULL;
        else head = NULL;
        delete temp;
    }
    void deleteVal(const int val)
    {
        node* curr = head;
        while(curr->next->data!=val) curr = curr->next;
        curr->next = curr->next->next;
        curr->next->next->prev = curr->next;
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
    DLL list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.print();
    list.insertAtFront(6);
    list.print();
    list.insertAfterValue(2,3);
    list.print();
    list.insertBeforeValue(3, 9);
    list.print();
    list.deleteVal(9);
    list.print();
    list.deleteHead();
    list.print();
    list.deleteTail();
    list.print();
    return 0;
}

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-3
*/

#include "iostream"
using namespace std;
class node{
    int data;
    node* next, *prev;
    public:
    node():next(NULL), prev(NULL), data(0){}
    node(const int d): data(d), next(NULL), prev(NULL){}
    friend class DLL;
};
class DLL{
    node *head, *tail;
    public:
    DLL():head(NULL), tail(NULL){}
    void insertAtEnd(const int val)
    {
        node* n = new node(val);
        if(head==NULL)head = tail = n;
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void deleteVal(const int val)
    {
        node* curr = head;
        while(curr->next->data!=val) curr = curr->next;
        curr->next = curr->next->next;
        curr->next->next->prev = curr->next;
    }
  void sortList()
{
    node* curr, *index, *temp;
    if(head==NULL) return;
    for(curr = head; curr->next!=NULL; curr = curr->next)
    {
        for (index = curr->next; index!=NULL; index = index->next)
        {
            if(curr->data > index->data)
            {
                temp = curr->next;
                curr->next = index->next;
                index->next = temp;
                if (curr == head) head = index;
                else {
                    node* prev = head;
                    while (prev->next != curr) prev = prev->next;
                    prev->next = index;
                }
                temp = curr;
                curr = index;
                index = temp;
            }
        }
    }
    
    // Removing duplicates
    for(curr = head; curr->next!=NULL; )
    {
        if(curr->data == curr->next->data)
        {
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else curr = curr->next;
    }
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
    DLL list;
    list.insertAtEnd(6);
    list.insertAtEnd(3);
    list.insertAtEnd(9);
    list.insertAtEnd(12);
    list.insertAtEnd(12);
    list.insertAtEnd(13);
    list.print();
    list.sortList();
    list.print();
    return 0;
}



// Recursion
#include "iostream"
using namespace std;
class Recursion{
    public:
    int static factorial(int n)
   {
    if(n==1 || n==0) return 1; //factorial of 0 is also 1
    else return n* factorial(n-1);
   }
   int static sumOfNaturalNums(int n)
   {
    if(n==1) return 1;
    else return n + sumOfNaturalNums(n-1);
   }
   int static fibonacci(int n) //n will be incremented in main
   {
    if(n==0 || n== 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2); //return sum of last two terms
   }
   void static fibonacci2(int a, int b, int n) //for this variant 0 & 1 need to be printed in main
   {
    if(n==0) return;
    int c = a+b;
    cout<<c<<" "; //printing is done in function
    fibonacci2(b,c,n-1);
   }
   int static power(int x, int n) //stack height = n
   {
    if(n==0) return 1;
    if(x==0) return 0;
    else return x * power(x, n-1);
   }
};
int main()
{
    cout<<Recursion::factorial(5)<<endl;
    cout<<Recursion::sumOfNaturalNums(5)<<endl;
    for (size_t i = 0; i < 5; i++)cout<<Recursion::fibonacci(i)<<" ";
    cout<<endl;
    Recursion::fibonacci2(0,1,5);
    cout<<endl;
    cout<<Recursion::power(2,3)<<endl;
}



//Circular singly linked list
#include "iostream"
using namespace std;
class node {
    int data;
    node* next;
public:
    node() : data(0), next(NULL) {}
    node(const int d) : data(d), next(NULL) {}
    friend class CSLL;
};
class CSLL {
    node* head;
public:
    CSLL() : head(NULL) {}
    void insertAtFront(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            head->next = head;  // Circular link to itself
        } else {
            node* curr = head;
            // Traverse to the last node to update the circular link
            while (curr->next != head) {
                curr = curr->next;
            }
            n->next = head;  // Insert the new node before the head
            curr->next = n;   // Last node points to new head
            head = n;         // Update head
        }
    }
    void insertAtTail(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            head->next = head;  // Circular link to itself
        } else {
            node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = n;
            n->next = head;  // Circular link to head
        }
    }
    void InsertAfterValue(const int value, const int insertingValue) {
        node* n = new node(insertingValue);
        if (head == NULL) {
            head = n;
            head->next = head;
        } else {
            node* curr = head;
            do {
                if (curr->data == value) {
                    n->next = curr->next;
                    curr->next = n;
                    break;
                }
                curr = curr->next;
            } while (curr != head);
        }
    }
    void InsertBeforeValue(const int value, const int insertingValue) {
        node* n = new node(insertingValue);
        if (head == NULL) {
            head = n;
            head->next = head;
        } else {
            node* curr = head;
            node* prev = NULL;
            do {
                if (curr->data == value) {
                    if (prev == NULL) {  // Insert before head
                        node* tail = head;
                        while (tail->next != head) {
                            tail = tail->next;
                        }
                        n->next = head;
                        tail->next = n;
                        head = n;
                    } else {
                        n->next = curr;
                        prev->next = n;
                    }
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);
        }
    }

    int numNodes() {
        if (head == NULL) return 0;
        int nodes = 0;
        node* curr = head;
        do {
            nodes++;
            curr = curr->next;
        } while (curr != head);
        return nodes;
    }

    void deleteFromHead() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->next == head) {  // Single node case
            delete head;
            head = NULL;
        } else {
            node* curr = head;
            while (curr->next != head) {  // Find the last node
                curr = curr->next;
            }
            node* temp = head;
            head = head->next;  // Move head
            curr->next = head;  // Update last node's next to new head
            delete temp;
        }
    }

    void deleteFromTail() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->next == head) {  // Single node case
            delete head;
            head = NULL;
        } else {
            node* curr = head;
            node* prev = NULL;
            while (curr->next != head) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;  // Update last node to point to head
            delete curr;
        }
    }

    void deleteValue(const int value) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->data == value && head->next == head) {  // Single node case
            delete head;
            head = NULL;
            return;
        }
        node* curr = head;
        node* prev = NULL;
        do {
            if (curr->data == value) {
                if (prev == NULL) {  // Deleting head
                    node* tail = head;
                    while (tail->next != head) {
                        tail = tail->next;
                    }
                    node* temp = head;
                    head = head->next;
                    tail->next = head;
                    delete temp;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    CSLL list;
    
    // Inserting elements at the front
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtFront(30);
    cout << "After inserting at front:" << endl;
    list.printList();
    
    // Inserting elements at the back
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtTail(60);
    cout << "After inserting at tail:" << endl;
    list.printList();
    
    cout << "Total nodes in list: " << list.numNodes() << endl;

    // Deleting from head
    list.deleteFromHead();
    cout << "After deleting from head:" << endl;
    list.printList();

    // Deleting from tail
    list.deleteFromTail();
    cout << "After deleting from tail:" << endl;
    list.printList();

    // Deleting a value
    list.deleteValue(40);
    cout << "After deleting value 40:" << endl;
    list.printList();

    // Insert after a specific value
    list.InsertAfterValue(20, 11);
    cout << "Inserted value 11 after 20:" << endl;
    list.printList();

    // Insert before a specific value
    list.InsertBeforeValue(50, 22);
    cout << "Inserted value 22 before 50:" << endl;
    list.printList();

    return 0;
}


//circular doubly linked list

#include "iostream"
using namespace std;

class node {
    int data;
    node* next, *prev;
public:
    node() : next(NULL), prev(NULL), data(0) {}
    node(const int d) : data(d), next(NULL), prev(NULL) {}
    friend class DCLL;
};

class DCLL {
    node *head, *tail;
public:
    DCLL() : head(NULL), tail(NULL) {}

    void insertAtEnd(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = tail = n;
            head->next = head;  // Circular link
            head->prev = head;
        } else {
            tail->next = n;
            n->prev = tail;
            n->next = head;  // Circular link to head
            head->prev = n;   // Head's previous points to new tail
            tail = n;
        }
    }

    void insertAtFront(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = tail = n;
            head->next = head;  // Circular link
            head->prev = head;
        } else {
            n->next = head;
            n->prev = tail;
            head->prev = n;
            tail->next = n;  // Circular link to new head
            head = n;        // Update head
        }
    }

    void insertAfterValue(const int after, const int val) {
        node* n = new node(val);
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        node* curr = head;
        do {
            if (curr->data == after) {
                n->prev = curr;
                n->next = curr->next;
                curr->next->prev = n;
                curr->next = n;
                if (curr == tail) {
                    tail = n;  // Update tail if inserted at the end
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void insertBeforeValue(const int before, const int val) {
        node* n = new node(val);
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        node* curr = head;
        do {
            if (curr->data == before) {
                n->next = curr;
                n->prev = curr->prev;
                curr->prev->next = n;
                curr->prev = n;
                if (curr == head) {
                    head = n;  // Update head if inserted before the head
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void deleteHead() {
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            tail->next = head->next;
            head->next->prev = tail;
            head = head->next;
            delete temp;
        }
    }

    void deleteTail() {
        if (!tail) {
            cout << "List not found" << endl;
            return;
        }
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
        } else {
            node* temp = tail;
            tail->prev->next = head;
            head->prev = tail->prev;
            tail = tail->prev;
            delete temp;
        }
    }

    void deleteVal(const int val) {
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        node* curr = head;
        do {
            if (curr->data == val) {
                if (curr == head) {
                    deleteHead();
                } else if (curr == tail) {
                    deleteTail();
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    DCLL list;
    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.print();  // Output: 1 2 4 5
    
    list.insertAtFront(6);
    list.print();  // Output: 6 1 2 4 5
    
    list.insertAfterValue(2, 3);
    list.print();  // Output: 6 1 2 3 4 5
    
    list.insertBeforeValue(3, 9);
    list.print();  // Output: 6 1 2 9 3 4 5
    
    list.deleteVal(9);
    list.print();  // Output: 6 1 2 3 4 5
    
    list.deleteHead();
    list.print();  // Output: 1 2 3 4 5
    
    list.deleteTail();
    list.print();  // Output: 1 2 3 4
    
    return 0;
}






/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Bubble Sort.
*/

#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n){

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void printArray(int arr[], int size){
    for (int i=0; i<size; i++) {
        cout<<" "<<arr[i];
    }
}
int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int N = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted array:\n";
    printArray(arr, N);
    cout<<endl;

    bubbleSort(arr, N);
    cout<<"Sorted array:\n";
    printArray(arr, N);
    cout<<endl;

    return 0;
}

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

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of sorting using Insertion Sort.
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i=1; i<n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[], int n){
    for (int i=0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Unsorted Array:\n";
    printArray(arr, n);
    cout<<endl;

    insertionSort(arr, n);
    cout<<"Sorted Array:\n";
    printArray(arr, n);
    cout<<endl;

    return 0;
}

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
 
    shellSort(arr, n); /*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-4
  Description: An Implementation of searching Algorithms using Linear Search.
*/

#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x) {
            return i;
        }
    return -1;
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = search(arr, n, x);
    (result==-1) ? 
     cout<<"Element is not present in array": 
     cout<<"Element is present at index "<<result;
    return 0;
}

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

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-5
  stack LL
*/

#include "iostream"
using namespace std;
class Node{
    Node* next;
    int data;
    public:
    Node(const int d):data(d), next(nullptr){}
    friend class Stack;
};
class Stack{
    Node* head;
    public:
    Stack():head(nullptr){}
    bool isEmpty() const{
        return head == nullptr;
    }
    void push(const int val)
    {
        Node* newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout<<"pushed "<<newNode->data<<" onto the stack"<<endl;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow "<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout<<"popped "<<temp->data<<" from the stack"<<endl;
        delete temp;
    }
    int peek() const{
        if(isEmpty()) return -1;
        return head->data;
    }
};
int main()
{
    Stack s;
    s.pop();
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
}

    cout<<"Sorted Array:\n"; 
    printArray(arr, n); 
    cout<<endl; 

} 

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  Lab-5
  stack arr
*/

#include "iostream"
using namespace std;
class Stack{
    int *arr, size, top;
    public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int [s];
    }
    void push(int val){
        if(top == size-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else {
            top++;
            arr[top] = val;
            cout<<"pushed "<<val<<" into the stack"<<endl;
        }
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            top --;
            cout<<"popped "<< arr[top+1] << " from the stack"<<endl;
        }
    }
    int peek()
    {
        if(top== -1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
    int isSize()
    {
        return top+1;
    }
};
int main()
{
    Stack s(5);
    s.push(5);
    s.push(8);
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.push(3);
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.isSize();
    int val = s.peek();
    if(s.isSize()==0) cout<<val;
}
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

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 6
*/

#include "iostream"
#define n 10
using namespace std;
class TicketQueue{
    int *arr, front, rear, passengers = 0;
    public:
    TicketQueue(){
        arr = new int[n];
        front= -1;
        rear = -1;
    }
    void push()
    {
        if(rear == n-1){ 
            cout<<"queue overflow"<<endl;
            return;
        }
        arr[++rear] = ++passengers;
        if(front == -1) front++;
    }
    void pop()
    {
        if(front == -1 || front > rear) 
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        front++;
        passengers--;
    }
    int peek()
    {
        if(front == -1 || front > rear)
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
};

int main() {
    TicketQueue q;
    for (size_t i = 0; i < 10; i++) q.push();
    cout<<q.peek()<<endl;;
    for (size_t i = 0; i < 5; i++) q.pop();
    cout<<q.peek()<<endl;;
    for (size_t i = 0; i < 5; i++) q.push();
    cout<<q.peek()<<endl;
    return 0;
}

/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 6

  
  Description: after removing the first 5 passengers, more passengers can't be added even though there are
available spaces at the front of the array. Since queue is linear, rear ptr doesn't wrap around to 
reuse the freed spaces at the front. To solve this, we need to implement a circular queue. 
In a circular queue, the rear pointer wraps around to the beginning of the array when it reaches the end, 
allowing us to reuse the freed space at the front.
*/

#include <iostream>
using namespace std;

class Ticket{
    int *arr;
    int passenger;
    int size;
    int front;
    int rear;

public:
    Ticket(){
        size = 10;
        arr = new int[size];
        passenger = 0;
        front = -1;
        rear = -1;
    }

    ~Ticket(){
        delete[] arr;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void push(){
        if (isEmpty()){
            front = rear = 0;
            passenger++;
            arr[rear] = passenger;
        }
        else if (isFull()){
            cout << "Queue overflow" << endl;
        }
        else{
            rear = (rear + 1) % size;
            passenger++;
            arr[rear] = passenger;
        }
    }

    void pop(){
        if (isEmpty()){
            cout << "Queue underflow" << endl;
        }
        else{
            if (front == rear){
                front = rear = -1; 
            }
            else{
                front = (front + 1) % size;
            }
        }
    }

    int peek(){
        if (isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    void print(){
        if (!isEmpty()){
            cout << "Queue: ";
            int i = front;
            while(true){
                cout << arr[i] << " ";
                if (i == rear) 
                    break; 
                i = (i + 1) % size;  
            }
            cout << endl;
        }
        else{
            cout << "Queue is empty." << endl;
        }
    }
};
/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 6
*/

#include "iostream"
#define size 10
using namespace std;
class node
{
    node *next;
    int data;
public:
    node(const int d = 0) : data(d), next(NULL) {}
    friend class TicketQueue;
};

class TicketQueue
{
    node *front, *rear;
    int currentPassengerNumber = 0;  
    int queueSize = 0;               
public:
    TicketQueue() : front(NULL), rear(NULL) {}
    bool isEmpty() const
    {
        return front == NULL;
    }
    void enqueue()
    {
        if (queueSize == size)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        currentPassengerNumber++;
        node *x = new node(currentPassengerNumber);
        if (isEmpty())
        {
            front = x;
            rear = x;
            cout<<"Passenger "<<currentPassengerNumber<<" added to queue"<<endl;
            return;
        }
        else
        {
            rear->next = x;
            rear = x;
            cout<<"Passenger "<<currentPassengerNumber<<" added to queue"<<endl;
            queueSize++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        else
        {
            node *temp = front;
            front = front->next;
            if (!front)
                rear = NULL;
            cout<<"Passenger "<<temp->data<<" dequeued"<<endl;
            delete temp;
            queueSize--;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        node *curr = front;
        cout << "Passengers in Queue: " << endl;
        while (curr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};
int main()
{
    TicketQueue q;
    for (size_t i = 0; i < 10; i++)
        q.enqueue();
    cout <<"Passenger at front of queue: "<< q.peek() << endl;
    for (size_t i = 0; i < 5; i++)
        q.dequeue();
    cout <<"Passenger at front of queue: "<< q.peek() << endl;
    for (size_t i = 0; i < 5; i++)
        q.enqueue();
    cout <<"Passenger at front of queue: "<< q.peek() << endl;
    return 0;
}
/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 6
*/

#include "iostream"
using namespace std;
class Stack {
    int top, size, *arr;
public:
    Stack() : top(-1){}
    bool isEmpty() {
        return top == -1;
    }
    void push(int x) {
        if (top < size - 1) {
            arr[++top] = x;
        } else {
            cout << "Stack overflow" << endl;
        }
    }
    int peek() const {
        if (top >= 0) return arr[top];
        return 0;
    }
    int pop() {
        if (top >= 0)
        {
             return arr[top--];
        }
        else {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }
    void print()
    {
        for (size_t i = 0; i<= top ; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
        
    }
};
int main() {
    Stack enqueue, dequeue;
    for (size_t i = 1; i <= 5; i++) enqueue.push(i);
    cout<<"enqueued elements: "<<endl;
    enqueue.print();
    for (size_t i = 1; i <= 3; i++) dequeue.push(enqueue.pop());
    cout<<"dequeued elements: "<<endl;
    dequeue.print();
    cout<<"remaining elements in queue: "<<endl;
    enqueue.print();
    return 0;
}



//Stack Reverse string
#include "iostream"
#include "stack"
using namespace std;
string reverseString(string str)
{
    stack<char> s;
    for(char ch: str){
        s.push(ch);
    }
    string reversed = "";
    while(!s.empty())
    {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}
int main()
{
    string str = "Hello World!";
    cout << "Original string: " << str << endl;
    cout<<"Reversed string: "<<reverseString(str)<<endl;
    return 0;
}



// Advance sort
#include "iostream"
using namespace std;
int findPivot(int* arr, int low, int high){
    int i = low, j = high;
    int pivot = arr[low];
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1) i++;
        while(arr[j]>pivot && j>=low+1) j--;
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int* arr, int low, int high)
{
    if(low<high)
    {
        int pivotPos = findPivot(arr, low, high);
        quickSort(arr, low, pivotPos-1);
        quickSort(arr, pivotPos+1, high);
    }
}

void merge(int* arr, int low, int mid, int high)
{
    int i = low,j = mid+1, k = 0;
    int* temp = new int[high-low+1];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (size_t idx = 0; idx<k; idx++)
    {
        arr[low+idx] = temp[idx];
    }
    delete[] temp;
}
void mergeSort(int* arr,int low,int high)
{
    if(low>=high)return;
    int mid = low + (high - low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}



//AVL

#include <iostream>
using namespace std;

class Node {
    int val, height;
    Node* left, *right;
public:
    Node(int v) : val(v), height(1), left(NULL), right(NULL) {}

    friend class AVL;
};

class AVL {
public:
    Node* root;
    AVL() : root(NULL) {}

    int getHeight(Node* r) {
        if (!r) return 0;
        return r->height;
    }

    int getBalance(Node* r) {
        if (!r) return 0;
        return getHeight(r->left) - getHeight(r->right);
    }

    Node* rightRotation(Node* r) {
        Node* child = r->left;
        Node* childRight = child->right;

        // Perform rotation
        child->right = r;
        r->left = childRight;

        // Update heights
        r->height = 1 + max(r->left->height, r->right->height);
        child->height = 1 + max(child->left->height, child->right->height);

        return child; // Return new root
    }

    Node* leftRotation(Node* r) {
        Node* child = r->right;
        Node* childLeft = child->left;

        // Perform rotation
        child->left = r;
        r->right = childLeft;

        // Update heights
        r->height = 1 + max(r->left->height, r->right->height);
        child->height = 1 + max(child->left->height, child->right->height);

        return child; // Return new root
    }

    Node* insert(Node* r, int d) {
        if (!r) return new Node(d);
        if (d < r->val) r->left = insert(r->left, d);
        else if (d > r->val) r->right = insert(r->right, d);
        else return r; // Duplicate values not allowed

        // Update height
        r->height = 1 + max(r->left->height, r->right->height);

        // Check balance
        int balance = getBalance(r);

        // LL Case
        if (balance > 1 && d < r->left->val) return rightRotation(r);

        // LR Case
        if (balance > 1 && d > r->left->val) {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }

        // RR Case
        if (balance < -1 && d > r->right->val) return leftRotation(r);

        // RL Case
        if (balance < -1 && d < r->right->val) {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }

        // No unbalancing
        return r;
    }
    void preOrder(Node* r) { // NLR
        if (r) {
            cout << r->val << " ";
            preOrder(r->left);
            preOrder(r->right);
        }
    }
};

int main() {
    AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 100);
    tree.root = tree.insert(tree.root, 95);
    cout << "Pre-order traversal of the AVL tree: ";
    tree.preOrder(tree.root);
    cout << endl;
    return 0;
}



//BST

#include "iostream"
#include "queue"
#include "vector"
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right, *next;
    Node(int d):data(d), right(NULL), left(NULL), next(NULL){}
    friend class BST;
};
class BST{
    public:
    Node*  root;
    BST(): root(NULL){}
    Node* insert(int d, Node* r)
    {
        if(!r) return new Node(d);
        if(d<r->data) r->left = insert(d, r->left);
        if(d>r->data) r->right = insert(d, r->right);
        return r;
    }

    void levelOrder()
    {
        if(!root) return; 
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* curr = q.front();
            cout<<q.front()->data<<" ";
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);        
        }
    }

    void inOrder(Node* r) //returns the node values in ascending order
    {
        if(!r) return;
        inOrder(r->left);
        cout<<r->data<<" ";
        inOrder(r->right);
    }

    bool search(Node* r, int target)
    {
        if(!r) return false; //if all nodes have been traversed and target isn't found
        if(r->data == target) return true;
        if(target < r->data) return search(r->left, target);
        else return search(r->right, target);
    }

    Node* deleteNode (Node* r, int target)
    { 
        if(!r) return NULL; //if target isn't present 
        if(r->data > target) r->left = deleteNode(r->left, target);
        else if(r->data < target) r->right = deleteNode(r->right, target);
        else
        {
            //leaf node
            if(!r->left && !r->right)
            {
                delete r; //simply delete node
                return NULL;
            }
            // one child exists
            if(!r->left && r->right)
            {
                Node* temp = r->right; //if only right child exists replace the node with it & delete node
                delete r;
                return temp;
            }
            if(r->left && !r->right)
            {
                Node* temp = r->left; //if only left child exists replace the node with it & delete node
                delete r;
                return temp;
            }

            //both children exist
            if(r->left && r->right)
            {
                //find greatest element in left sub-tree (n)
                Node* child = r->left;
                Node* parent = r;

                //to traverse to n
                while(child->right) 
                {
                    parent = child;
                    child = child->right;
                }
                if(r!=parent)
                {
                    parent->right = child->left;
                    child->left = r->left;
                    child->right = r->right;
                    delete r;
                    return child;
                }
                else {
                    child->right = r->right;
                    delete r;
                    return child;
                }
            }
        }
    }
    vector<int> inOrder_vec(vector<int>& IO, Node* r)
    {
        if(!r) return IO;
        inOrder_vec(IO, r->left);
        IO.push_back(r->data);
        inOrder_vec(IO, r->right);
        return IO;
    }
};
/*Array to Balanced BST
    Extract the smallest lexicographical preorder traversal from array
    */

    void ArrayToBST(vector<int>& arr, int start, int end, vector<int>& ans)
    {
        if(start>end) return; 
        int mid = start+(end-start)/2; //mid = starting point + half the distance b/w start & end
        ans.push_back(arr[mid]);
        ArrayToBST(arr,start,mid-1,ans); //for left child
        ArrayToBST(arr,mid+1,end,ans); //for right child
    }
    //lab 8 Q5 Node ptr implementation

Node* buildBST(vector<int>& Tree, int start,int end)
{
    if(start>end) return NULL;
    //get middle of the LL and make it the root of the BST
    int mid = start+(end-start)/2;
    Node* root = new Node(Tree[mid]);
    //Recurisvely do the same for the left & right children
    root->left = buildBST(Tree, start, mid-1); //getting middle of left half and making it left child of the root (considers all nodes before the midpoint)
    root->right = buildBST(Tree,mid+1,end); //getting middle of right half and making it right child of the root (considers all nodes after midpoint)
    return root;
}
Node* BST_fromLL(Node* head)
{
    //store LL node vals in a vector
    vector<int> Tree;
    Node* temp = head;
    while(temp)
    {
        Tree.push_back(temp->data);
        temp = temp->next;
    }
    return buildBST(Tree,0,Tree.size()-1);
}

vector<int> mergeBST(BST t1, BST t2)
{
    vector<int> v1, v2, v3;
    //extract inorder traversals of both trees
    t1.inOrder_vec(v1,t1.root); 
    t2.inOrder_vec(v2,t2.root);
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        //add the smaller element at the same index of both vectors
        if(v1[i]<v2[j]) v3.push_back(v1[i++]); 
        else v3.push_back(v2[j++]);
    }
    //add remaining elements
    while(i<v1.size()) v3.push_back(v1[i++]);
    while(j<v2.size())v3.push_back(v2[j++]);
    return v3;
}
int main()
{
    BST tree;
    tree.root = tree.insert(8,tree.root);
    tree.root = tree.insert(4, tree.root);
    tree.root = tree.insert(3, tree.root);
    tree.root = tree.insert(6, tree.root);
    tree.root = tree.insert(11, tree.root);
    tree.root = tree.insert(13, tree.root);
    tree.root = tree.insert(12, tree.root);
    tree.root = tree.insert(5, tree.root);

    /*
        
            8
          /   \
        4      11
       /  \      \
      3    6      13  
          /      /
         5     12
                     
    */
    tree.levelOrder();
    cout<<endl;
    tree.inOrder(tree.root); 
    cout<<endl;
    cout<<tree.search(tree.root, 6)<<endl;
    cout<<tree.search(tree.root, -9)<<endl;
    vector<int> arr = {1,2,3,4,5,6}, bst;
    ArrayToBST(arr, 0, arr.size()-1, bst);
    /*
            3
          /   \
         1     5
          \   / \
           2 4   6
    */
    for(int i: bst) cout<<i<<" ";  //return preorder traversal of array
    cout<<endl;
    vector<int> traversal;
    tree.inOrder_vec(traversal, tree.root);
    for(int i: traversal) cout<<i<<" ";
    cout<<endl;
    Node* node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);
    node->next->next->next->next = new Node(5);

    Node* BinaryST = BST_fromLL(node);
    
    BST t1, t2;
    t1.root = t1.insert(5,t1.root);
    t1.root = t1.insert(3, t1.root);
    t1.root = t1.insert(6, t1.root);
    t1.root = t1.insert(2, t1.root);
    t1.root = t1.insert(4, t1.root);
    t2.root = t2.insert(2, t2.root);
    t2.root = t2.insert(1, t2.root);
    t2.root = t2.insert(3, t2.root);
    t2.root = t2.insert(7, t2.root);
    t2.root = t2.insert(6, t2.root);
    vector<int> merged = mergeBST(t1,t2);
    for(int i: merged) cout<<i<<" ";
    cout<<endl;
    return 0;
}


//BT

#include "iostream"
#include "vector"
using namespace std;
class Node{
    public:
    int data;
    Node *right, *left, *next;
    Node(int d):data(d), right(NULL), left(NULL), next(NULL){}
    friend class BT;
    friend class queue;
};
class queue{  //rear = tail, front = head (FIFO)
   Node *front, *rear; 
   public:
   queue():front(NULL), rear(NULL){}
   void enqueue(Node* n)
   {
        if(!front)
        {
            front = rear = n;
            return;
        }
        else{
            rear->next = n;
            rear = n;
        }
   }
   void dequeue()
   {
        if(isEmpty()) return;
        front = front->next; // Move the front pointer to the next node
        // We do not delete temp here
        if(!front) rear = NULL; // If the queue becomes empty, set rear to NULL
   }

   bool isEmpty() const {return front == NULL;}
   Node* getFront() const{return front;}
   void print(){
    Node* curr = front;
    while(curr){
        cout<<front->data<<" ";
        curr = curr->next;
    }
   }
};

static int numNodes = 0, total = 0; //used to calculate number of nodes in size function as well as total sum

class BT{
    Node* root;
    public:
    BT():root(NULL){}
    void addNode(int d){ 
    queue q; //since we are not deleting nodes when dequeuing, we will declare a new queue every time a function needs to use it
    Node* n = new Node(d);
        if(!root) root = n;
        else{
                q.enqueue(root); 
                while(!q.isEmpty())
                {
                    Node* curr = q.getFront(); //save front of queue before dequeueing
                    q.dequeue();
                    if(!curr->left){ //if there is no left child, we insert node
                        curr->left = n;
                        return;
                    }
                    else q.enqueue(curr->left); //if left child existed we enqueue it
                    if(!curr->right) //if there is no right child, we insert node
                    {
                        curr->right = n;
                        return;
                    }
                    else q.enqueue(curr->right); //if right child existed then we enqueue it
            }
        }
    }
    Node* getRoot(){return root;}
    void inOrder(Node* r) //LNR
    {
        if(r)
        {
            inOrder(r->left);
            cout<<r->data<<" ";
            inOrder(r->right);
        }
        
    }

    static int size(Node* r)
    {
        if(!r) return numNodes;
        else{
            size(r->left);
            numNodes++; //we can calculate size by using any traversal method, we simply replace the cout with an int increment
            size(r->right);
        }
        return numNodes;
    }
    int countNodes(Node* r){
        if(!r) return 0;
        else return 1+countNodes(r->left)+countNodes(r->right); //alternate method of counting nodes (traversing root's left & right ST & adding 1 to include root)
    }
    void countLeaves(Node* r, int& leaves)
    {
        if(!r) return;
        if(!r->left && !r->right) leaves++; //if a node has no children we increment cnt
        //we traverse left and right sub-trees
        countLeaves(r->left, leaves); 
        countLeaves(r->right, leaves);
    }
    void countInternalNodes(Node* r, int& internal)
    {
        if(!r) return;
        if(r->left || r->right) internal++; //if a node has a child we increment count 
        //we traverse left and right sub-trees
        countInternalNodes(r->left, internal);
        countInternalNodes(r->right, internal);
    }
    static int sum(Node* r)
    {
        if(!r) return total;
        else{
            sum(r->left);
            total+=r->data; //we can calculate sum by using any traversal method
            sum(r->right);
        }
        return total;
    }
    int height(Node* r){
        if(!r) return 0;
        int a = height(r->left); //height of left sub-tree
        int b = height(r->right); //height of right sub-tree
        return 1 + max(a,b); //return the larger height + 1 to accommodate for root 
    }
    int minDepth(Node* r) {
        if(!r) return 0;
        int left = minDepth(r->left);
        int right = minDepth(r->right);
        if(left==0||right==0) return 1 + max(left, right); //if a subtree doesn't exist we will return the largest and the only subtree present
        return 1 + min(left, right); //otherwise we return the minimum depth subtree
    }    
    void preOrder(Node* r) //NLR
    {
        if(r)
        {
            cout<<r->data<<" ";
            preOrder(r->left);
            preOrder(r->right);
        }
        
    }
    void postOrder(Node* r) //LRN
    {
        if(r)
        {
            postOrder(r->left);
            postOrder(r->right);
            cout<<r->data<<" ";
        }
        
    }
    void levelOrder() //we insert Nodes in level order so here the implementation is the same as insertion 
    {
        queue q;
        q.enqueue(root);
        while(!q.isEmpty())
        {
            Node* n = q.getFront();
            cout<<q.getFront()->data<<" ";
            q.dequeue();
            if(n->left) q.enqueue(n->left);
            if(n->right)q.enqueue(n->right);
        }
    }

    //https://www.geeksforgeeks.org/largest-value-level-binary-tree/
    void largestElementPerLevel(vector<int>& largest, Node* r, int depth)
    {
        if(!r) return;
        else{
            if(depth == largest.size()) largest.push_back(r->data); // if current depth equals size of array it means a node hasn't been encountered at this level so we add current node's val to array
            else largest[depth] = max(largest[depth], r->data); //if a node has already been encountered at this level, store max element
            largestElementPerLevel(largest, r->left, depth+1); //traverse left subtree and increase depth
            largestElementPerLevel(largest, r->right, depth+1); //traverse right subtree and increase depth
        }
    }
    /*max path sum strategy:
       for each node compute
       (1)node val
       (2)max path through left child + node val
       (3)max path through right child + node val
       (4)max path through left & right child + node val
    */

   int maxPathSumUtil(Node* r, int& ans)
   {
        if(!r) return 0; //if no path exists then return 0
        //now we will calculate the sum of paths flowing through left & right nodes
        int left = maxPathSumUtil(r->left, ans);
        int right = maxPathSumUtil(r->right, ans);
        //here the strategy has been implemented for (1) & (4) , (2) & (3)
        int nodeMax = max(max(r->data, r->data+left+right), max(r->data+left, r->data+right));
        ans = max(ans, nodeMax); //now we update the pre existing sum val with the nodeMax by comparing the values
        int singlePathSum = max(r->data, max(r->data+left, r->data+right)); // we won't consider  r->data+left+right since it considers path from both subtrees which will form a complete path traversing the whole tree
        return singlePathSum;
   }
   int maxPathSum(Node* r)
   {
        int ans = INT16_MIN;
        maxPathSumUtil(r, ans);
        return ans;
   }
   //code that merges two trees, if both nodes exist, values of those nodes are added
   Node* mergeTrees(Node* root1, Node* root2) {
        if(!root1) return root2;
        else if (!root2) return root1;
        else{
            root2->left = mergeTrees(root1->left, root2->left);
            root2->data += root1->data;
            root2->right = mergeTrees(root1->right, root2->right);
        }
        return root2;
    }
};
int main(){
    BT tree;
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(10);
    tree.addNode(50);
    tree.addNode(51);
/*
    BT structure after inserting 1,2,3,4,5,10,50,51
               1
            /    \
           2      3
         /   \   /  \ 
        4     5 10   50  
      /
    51 
*/
    tree.inOrder(tree.getRoot());
    cout<<endl;
    tree.postOrder(tree.getRoot());
    cout<<endl;
    tree.preOrder(tree.getRoot());
    cout<<endl;
    tree.levelOrder();
    cout<<endl;
    cout<<tree.size(tree.getRoot())<<endl;
    cout<<tree.countNodes(tree.getRoot())<<endl;
    int numLeaves = 0;
    tree.countLeaves(tree.getRoot(), numLeaves);
    cout<<numLeaves<<endl;
    int numInternalNodes = 0;
    tree.countInternalNodes(tree.getRoot(), numInternalNodes);
    cout<<numInternalNodes<<endl;
    cout<<tree.sum(tree.getRoot())<<endl;
    cout<<tree.height(tree.getRoot())<<endl;
    cout<<tree.minDepth(tree.getRoot())<<endl;
    vector<int> max;
    tree.largestElementPerLevel(max, tree.getRoot(), 0);
    for (int n: max) cout<< n <<" ";
    cout<<endl;
    cout<<tree.maxPathSum(tree.getRoot());
    return 0;
}


//HEAP SORT

#include "iostream"
#include "vector"
using namespace std;
void heapify(vector<int>& arr,int index)
{
    int largest = index;
    int left = 2*index + 1, right = 2*index +2;
    if(left<arr.size() && arr[left]>arr[largest]) largest = left;
    if(right<arr.size() && arr[right]>arr[largest]) largest = right;
    if(largest!=index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, largest);
    }
}
void heapSort(vector<int>& arr)
{
    //build max heap first 
    for(int i = arr.size()/2 - 1; i>=0; i--) heapify(arr,i);

    for(int i=arr.size()-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i);
    }
}
void print(vector<int> arr)
{
    for(int i: arr)cout<<i<<" ";
    cout<<endl;
}
int main()
{
    vector <int> arr = {12, 11, 13, 5, 6, 7};
    print(arr);
    heapSort(arr);
    print(arr);
    return 0;
}


//Heap implimentation

#include "iostream"
#include "vector"
#include "queue"
using namespace std;
class MaxHeap{
    void HeapifyUP(int index)
    {
        while(index>0 && heap[index]>heap[(index-1)/2])
        {
            swap(heap[index], heap[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void HeapifyDOWN(int index)
    {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
        if(left < heap.size() && heap[largest]<heap[left]) largest = left;
        if(right < heap.size() && heap[largest]<heap[right]) largest = right;
        if(largest!=index)
        {
            swap(heap[index], heap[largest]);
            HeapifyDOWN(largest);
        }
    }
    public:
    
    vector<int> heap;
    void enqueue(int d)
    {   
        heap.push_back(d);
        HeapifyUP(heap.size()-1);
    }
    void dequeue()
    {
        heap.pop_back();
        HeapifyDOWN(0);
    }
    void print()
    {
        for(int i: heap) cout<<i<<" ";
    }
};
class MinHeap{
    void HeapifyUP(int index)
    {
        while(index>0 && heap[index]<heap[(index-1)/2])
        {
            swap(heap[index], heap[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void HeapifyDOWN(int index)
    {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 1;
        if(left < heap.size() && heap[largest]>heap[left]) largest = left;
        if(right < heap.size() && heap[largest]>heap[right]) largest = right;
        if(largest!=index)
        {
            swap(heap[index], heap[largest]);
            HeapifyDOWN(largest);
        }
    }
    public:
    
    vector<int> heap;
    void enqueue(int d)
    {   
        heap.push_back(d);
        HeapifyUP(heap.size()-1);
    }
    void dequeue()
    {
        heap.pop_back();
        HeapifyDOWN(0);
    }
    void print()
    {
        for(int i: heap) cout<<i<<" ";
    }
};
int main()
{
    MaxHeap maxHeap;
    MinHeap minHeap;
    maxHeap.enqueue(10);
    maxHeap.enqueue(20);
    maxHeap.enqueue(15);
    maxHeap.enqueue(27);
    maxHeap.enqueue(18);
    maxHeap.enqueue(23);
    maxHeap.enqueue(9);
    maxHeap.enqueue(4);
    maxHeap.enqueue(98);
    maxHeap.enqueue(45);
    maxHeap.print();
    cout<<endl;
    minHeap.enqueue(10);
    minHeap.enqueue(20);
    minHeap.enqueue(15);
    minHeap.enqueue(27);
    minHeap.enqueue(18);
    minHeap.enqueue(23);
    minHeap.enqueue(9);
    minHeap.enqueue(4);
    minHeap.enqueue(98);
    minHeap.enqueue(45);
    minHeap.print();
    return 0;
}
