#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void implementPreorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {

        return;
    }
    v.push_back(root->data);
    implementPreorder(root->left, v);
    implementPreorder(root->right, v);
}

vector<int> preorder(Node *root)
{
    vector<int> v;
    implementPreorder(root, v);
    return v;
}

void implementInorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {

        return;
    }

    implementInorder(root->left, v);
    v.push_back(root->data);
    implementInorder(root->right, v);
}

vector<int> inorder(Node *root)
{
    vector<int> v;
    implementInorder(root, v);
    return v;
}

void implementPostorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {

        return;
    }

    implementPostorder(root->left, v);
    implementPostorder(root->right, v);
    v.push_back(root->data);
}

vector<int> postorder(Node *root)
{
    vector<int> v;

    implementPostorder(root, v);
    return v;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);*/

    /*vector<int> res = preorder(root);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }*/

    /*vector<int> res = postorder(root);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }*/

    vector<int> res = inorder(root);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}