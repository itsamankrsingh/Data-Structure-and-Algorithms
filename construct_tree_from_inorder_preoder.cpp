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

int search(int inorder[], int start, int end, int curr)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int index = 0;

    if (start > end)
    {
        return NULL;
    }

    int current = preorder[index];
    index++;

    Node *node = new Node(current);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, current);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
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
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(preorder, inorder, 0, 4);

    vector<int> res = postorder(root);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}