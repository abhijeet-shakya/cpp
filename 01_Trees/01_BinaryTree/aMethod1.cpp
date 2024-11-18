#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 
int main() {
    int x;
    cout << "Enter the value of root node:\n";
    cin >> x;  // Take input for the root node

    // Create the root node
    Node* root = new Node(x);

    // Queue for level-order traversal
    queue<Node*> q;
    q.push(root);

    int first, second;

    // Build the binary tree level-wise
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Input for left child
        cout << "Enter the left child of " << temp->data << " (enter -1 for no child): ";
        cin >> first;
        if (first != -1) {
            temp->left = new Node(first);
            q.push(temp->left);
        }

        // Input for right child
        cout << "Enter the right child of " << temp->data << " (enter -1 for no child): ";
        cin >> second;
        if (second != -1) {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }

    cout << "Binary tree created successfully!" << endl;
    return 0;
}
