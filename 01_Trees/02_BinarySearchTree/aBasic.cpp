#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }

};

Node* insert(Node* root, int target){
    
    if(!root){
        Node *temp = new Node(target);
        return temp;
    }
    if(target < root->data){
        root->left = insert(root->left, target);
    }else{
        root->right = insert(root->right, target);
    }

    return root;

    // time complexity of insertion in worst case is O(h) heigt of target
    // and if order is ascending or descending O(n) n no. of node
    // space complexity in worst case O(n)
}

int search(Node *root, int target){
    if(!root) return 0;

    if(root->data == target){
        return 1;
    }
    if(root->data > target){
        return search(root->left, target);
    }else{
        return search(root->right, target);
    }

    // time complexity worst case O(h)
    // ascending aur descending O(n)
    // space complexity worst case O(n)
}

void inorder(Node *root){
    if(!root) return;

    // left side
    inorder(root->left);
    // Node
    cout<<root->data<< " ";
    // right side
    inorder(root->right);

}

Node *deleteNode(Node *root, int target){
    if(!root){
        return NULL;
    }
    
    if(root->data > target){
        root->left = deleteNode(root->left, target);
        return root;
    }
    if(root->data < target){
        root->right = deleteNode(root->right, target);
        return root;
    }
    else{
        // leaf child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // 1 child exist
        else if(!root->right) // left child exist
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left) // right child exist
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child exist
        else
        {
            // find the greatest element from left
            Node * child = root->left;
            Node * parent = root;

            // right most node tak pahuchna hai
            while(child->right)
            {
                parent = child;
                child = child->right;
            }

            if(root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }


        }
    }
}

int main(){

    int arr[] = {13, 10, 19, 5, 21,15, 20,1, 6, 8};

    Node *root = NULL;
    // time complexity of tree creation in worst case O(n2)
    for(int i = 0; i < 10; i++){
        root = insert(root, arr[i]);
    }

    // Traverse
    inorder(root); // 1 5 6 8  10 13 15 19 20 21
    // inorder traversal in sorted form
    cout << endl;

    cout << search(root,8) << endl; // 1
    deleteNode(root, 5);
    inorder(root); // 1 6 8 10 13 15 19 20 21
}