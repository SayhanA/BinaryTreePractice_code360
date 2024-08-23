#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to input the tree level-wise
Node* input() {
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            temp->left = new Node(l);
            q.push(temp->left);
        }
        if (r != -1) {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
}

int calculateDiameter(Node* root, int& diameter) {
    if (root == NULL)
        return 0;

    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = input();
    int diameter = 0;
    calculateDiameter(root, diameter);
    cout << diameter << endl;

    return 0;
}

