#include <bits/stdc++.h>
#include "bst.h"

bool isBSTUtil(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->data > min) && (root->data < max) && isBSTUtil(root->left, min, root->data) && (isBSTUtil(root->right, root->data, max)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBST(Node *root)
{
    if (isBSTUtil(root, INT_MIN, INT_MAX))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = new Node(5);
    insert(root, 4);
    insert(root, 6);
    insert(root, 7);
    insert(root, 3);
    insert(root, 1);
    preorder(root);
    cout << endl;

    if (isBST(root))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}