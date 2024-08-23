#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input()
{
    int val, l, r;
    Node *root, *temp, *left, *right;

    cin >> val;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        cin >> l >> r;

        if (l == -1)
            left = NULL;
        else
            left = new Node(l);
        if (r == -1)
            right = NULL;
        else
            right = new Node(r);

        temp->left = left;
        temp->right = right;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return root;
}

void print(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int count_leaf(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    else
    {
        int l = count_leaf(root->left);
        int r = count_leaf(root->right);
        return l + r;
    }
}

int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int l = maxHeight(root->left);
        int r = maxHeight(root->right);
        return l > r ? l + 1 : r + 1;
    }
}

int nodeLevel(Node *root, int search)
{
    if(root == NULL) return 0;
    if(root->val == search) return 1; 
    // if(root->left->val == search || root->right->val == search) return 2;

    int l = nodeLevel(root->left, search);
    if(l) return l+1;

    int r = nodeLevel(root->right, search);
    if(r) return r+1;
    
    return 0;
}

int main()
{
    Node *root = input();

    int n;
    cin >> n;
    cout << nodeLevel(root, n);

    // print(root);
    // cout << endl;
    // cout << "Leaf Nodes:" << count_leaf(root) << endl;
    // cout << "Maximum Height" << maxHeight(root) << endl;

    return 0;
}