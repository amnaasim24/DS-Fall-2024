/*Programmer: Amna Asim Khan
  ID: 23K-0859
  DATA STRUCTURES LAB - FALL 2024
  LAB - 8
*/


#include "iostream"
#include "stack"
#include "vector"
#include "queue"
using namespace std;
class Node{
    int data;
    Node* left, *right;
    public:
    Node(int data):data(data), left(NULL), right(NULL){}
    friend class BT;
};
class BT{
    public:
    Node* root;
    BT():root(NULL){}
    void addNode(int d)
    {
        Node* n = new Node(d);
        if(!root) root = n;
        else{
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* curr = q.front();
                q.pop();
                if(!curr->left){
                    curr->left = n;
                    return;
                }
                else q.push(curr->left);
                if(!curr->right){
                    curr->right = n;
                    return;
                }
                else q.push(curr->right);
            }
        }
    }
     vector<int> zigzag (Node* r) 
    {
        stack <Node*> s1, s2;
        s1.push(r);
        vector<int> spiral; 
        while(!s1.empty()||!s2.empty())
        {
            if(!s1.empty()) 
            {
                while(!s1.empty()) 
                {
                    Node* temp = s1.top(); 
                    s1.pop(); 
                    spiral.push_back(temp->data);
                    if(temp->left) s2.push(temp->left);
                    if(temp->right) s2.push(temp->right);
                }
            }
            else
            {
                while(!s2.empty())
                {
                    Node* temp = s2.top();
                    s2.pop();
                    spiral.push_back(temp->data);
                    if(temp->right) s1.push(temp->right);
                    if(temp->left) s1.push(temp->left); 
                }
            }
        }
        return spiral;
    }
    
    Node* getRoot() const{return root;}
};
int main()
{
    BT tree;
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(6);
    tree.addNode(7);
    tree.addNode(8);

/* 
tree structure:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  /
 8  
 */

    vector<int> zz = tree.zigzag(tree.getRoot());
    for(int i: zz) cout<<i<<" ";
    return 0;
}

