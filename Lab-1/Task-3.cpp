/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 1
  Question # 3
  Description: You're tasked with designing a Document class for a document editor program. The class should
handle text content, ensuring that copying a document creates a deep copy of the content to maintain
data integrity. Follow the Rule of Three to manage resource allocation and deallocation correctly.
Here are the key requirements:
(a) Create a constructor that takes initial text content and allocates memory for it.
(b) Implement a destructor to deallocate memory used for the text content.
(c) Create a copy constructor that performs a deep copy of the text content, preventing unintended
sharing.
(d) Create a copy assignment operator that ensures a deep copy of the text content, maintaining
separation between objects.
(e) Provide a sample program that showcases your Document class. Create an original document,
generate copies using both the copy constructor and copy assignment operator, modify the
original's content, and show that the copies remain unaffected.
*/


#include <iostream>
#include <string>
using namespace std;


class Document {
private:
    char* content;
    int length;
public:
    Document(string t) {
        length = t.length();
        content = new char[length + 1];
        for (int i = 0; i < length; i++) {
            content[i] = t[i];
        }
        content[length] = '\0';
    }
    ~Document() {
        delete[] content;
    }
    Document(const Document& d1) {
        length = d1.length;
        content = new char[length + 1];
        for (int i = 0; i < length; i++) {
            content[i] = d1.content[i];
        }
        content[length] = '\0';
    }
    Document& operator=(const Document& d1) {
        if (this != &d1) {
            delete[] content;
            length = d1.length;
            content = new char[length + 1];
            for (int i = 0; i < length; i++) {
                content[i] = d1.content[i];
            }
            content[length] = '\0';
        }
        return *this;
    }
    void modifyContent(string c) {
        delete[] content;
        length = c.length();
        content = new char[length + 1];
        for (int i = 0; i < length; i++) {
            content[i] = c[i];
        }
        content[length] = '\0';
    }
    void displayContent() {
        cout<<content<<endl;
    }
};


int main() {
    Document original("Hello, World!");


    Document copy1(original);


    Document copy2 = original;


    original.modifyContent("Modified Content");


    cout << "Original Document: ";
    original.displayContent();


    cout << "Copy 1: ";
    copy1.displayContent();


    cout << "Copy 2: ";
    copy2.displayContent();


    return 0;
}
