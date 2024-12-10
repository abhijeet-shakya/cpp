#include <iostream>
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

void preOrder(Node* root){

    if(!root)  return;

    // print node
    cout << root->data << " ";

    // left side
    preOrder(root->left);

    // right side
    preOrder(root->right);

}

void postOrder(Node* root){

    if(!root)  return;
    
    // left side
    postOrder(root->left);

    // right side
    postOrder(root->right);

    // print node
    cout << root->data << " ";
}
void inOrder(Node* root){

    if(!root)  return;

    // left side
    inOrder(root->left);
    
    // print node
    cout << root->data << " ";

    // right side
    inOrder(root->right);

}
int main(){
    cout << "Enter the root node: ";
    Node* root;
    root = binaryTree();
    cout << "Binary Tree created Successfully"<< endl;

    // Traverse
    cout << "PreOrder: ";
    preOrder(root); cout<<endl;

    cout << "Inorder: ";
    inOrder(root); cout<<endl;

    cout << "Postorder: ";
    postOrder(root); cout<<endl;

}