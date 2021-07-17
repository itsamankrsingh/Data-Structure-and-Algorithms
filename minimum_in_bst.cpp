#include <bits/stdc++.h>
#include "bst.h"

using namespace std;

int minValue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
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
    cout << endl
         << minValue(root);
}