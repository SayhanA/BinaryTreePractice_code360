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

// vector<int> getLeftView(Node *root)
// {
//     vector<int> v;
//     if (root == NULL)
//         return v;

//     queue<Node *> q;
//     if (root)
//         q.push(root);

//     while (!q.empty())
//     {
//         for (int i = 0; i < q.size(); i++)
//         {
//             Node *tmp = q.front();
//             q.pop();

//             if (i == 0)
//             {
//                 v.push_back(tmp->val);
//             }
//             if (tmp->left != NULL) {
//                 q.push(tmp->left);
//             }
//             if (tmp->right != NULL) {
//                 q.push(tmp->right);
//             }
//         }
//     }

//     return v;
// }

vector<int> getLeftView(Node *root) {
    vector<int> result;
    if (root == NULL) return result;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node *curr = q.front();
            q.pop();

            
            if (i == 0) {
                result.push_back(curr->val);
            }

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }

    return result;
}


int main()
{
    Node *root = input();
    print(root);
    cout << endl
         << endl;

    vector<int> leftView = getLeftView(root);
    for (int val : leftView)
    {
        cout << val << " ";
    }

    return 0;
}