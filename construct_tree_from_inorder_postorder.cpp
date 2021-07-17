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
static int postIndex;
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

Node *buildTreeHelper(int postorder[], int inorder[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }

    int current = postorder[postIndex];
    postIndex--;

    Node *node = new Node(current);

    if (start == end)
    {
        return node;
    }

    int inIndex = search(inorder, start, end, current);
    node->right = buildTreeHelper(postorder, inorder, inIndex + 1, end);

    node->left = buildTreeHelper(postorder, inorder, start, inIndex - 1);

    return node;
}

Node *buildTree(int in[], int post[], int n)
{
    postIndex = n - 1;
    Node *root = buildTreeHelper(post, in, 0, n - 1);
    return root;
}

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

int main()
{
    int postorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(postorder, inorder, 5);

    vector<int> res = preorder(root);
    vector<int>::iterator it;
    for (it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}