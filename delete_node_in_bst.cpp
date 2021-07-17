/* Deleting a node from Binary search tree */
#include <iostream>
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

//Function to visit nodes in Inorder
void Preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data); //Print data
    Preorder(root->left);      //Visit left subtree
    Preorder(root->right);     // Visit right subtree
}

// Function to Insert Node in a Binary Search Tree
Node *Insert(Node *root, char data)
{
    if (root == NULL)
    {
        root = new Node(data);
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

//Function to find minimum in a tree.
Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        //Case1:no child
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        } //case2: one child
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        } //case3: Two Child
        else
        {
            Node *min = findMin(root->right);
            root->data = min->data;
            root->right = deleteNode(root->right, min->data);
        }
    }
    return root;
}

int main()
{
    /*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
    Node *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);

    //Print Nodes in Inorder
    cout << "Inorder: ";
    Preorder(root);
    cout << "\n";

    // Deleting node with value 5, change this value to test other cases
    root = deleteNode(root, 5);
    Preorder(root);
    cout << "\n";
}