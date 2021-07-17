#include <bits/stdc++.h>
#include "bst.h"

using namespace std;

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = new Node(1);
    insert(root, 2);
    insert(root, 3);
    preorder(root);
    cout << endl
         << height(root) << endl;
}