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

bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key <= root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

Node *insertHelper(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
    }
    else if (data <= root->data)
    {
        root->left = insertHelper(root->left, data);
    }
    else
    {
        root->right = insertHelper(root->right, data);
    }
    return root;
}

Node *insert(Node *root, int key)
{
    if (search(root, key))
    {
        return root;
    }
    else
    {
        return insertHelper(root, key);
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int k = 4;
    int arr[] = {1, 2, 3, 6};
    Node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    preorder(root);
    cout<<endl;
}