#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node * right;

    Node(int val){
        data = val;
        left = right = NULL;    
    }
};

Node* binaryTree(){

    int x;
    cin>>x;

    if(x == -1) return NULL;
    
    Node* temp = new Node(x);
    // left side create
    cout << "enter the left child of " << x << ": ";
    temp->left = binaryTree();

    // right side create
    cout << "enter the right child of " << x << ": ";
    temp->right = binaryTree();

    return temp;
}
int main(){
    cout << "Enter the root node: ";
    Node* root;
    root = binaryTree();
    cout << "Binary Tree created Successfully";
}