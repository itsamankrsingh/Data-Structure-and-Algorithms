#include <bits/stdc++.h>
#include "bst.h"

void levelOrderHelper(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        int data = current->data;
        v.push_back(data);
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}
vector<int> levelOrder(Node *node)
{
    vector<int> v;
    levelOrderHelper(node, v);
    return v;
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

    vector<int> v;
    vector<int>::iterator it;

    v = levelOrder(root);

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}