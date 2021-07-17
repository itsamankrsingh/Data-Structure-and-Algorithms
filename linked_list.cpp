#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;

void inputOutput()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(Node *head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//iterative
Node *deleteNodeIterative(Node *head, int x)
{

    Node *temp = head;
    Node *prev = NULL;
    int count = 1;
    if (count == x)
    {
        head = temp->next;
        temp->next = NULL;
        return head;
    }
    while (count != x && temp != NULL)
    {
        count++;
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        prev->next = temp->next;
        temp->next = NULL;
    }
    return head;
}

//recursive
void deleteNodeRecursive(Node *&head, int x)
{
    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (head == NULL)
    {
        cout << "Element not present in the list\n";
        return;
    }

    // If current node is the node to be deleted
    if (head->data == x)
    {
        Node *t = head;
        head = head->next; // If it's start of the node head
                           // node points to second node
        delete (t);        // Else changes previous node's link to
                           // current node's link
        return;
    }
    deleteNodeRecursive(head->next, x);
}

int findLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    if (length < n)
    {
        return -1;
    }
    temp = head;
    // get the (len-n+1)th node from the beginning
    for (int i = 1; i < length - n + 1; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

int getMiddle(Node *head)
{
    // Your code here
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    int middle = length / 2;

    temp = head;

    for (int i = 0; i < middle; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

//Function to check if the linked list has a loop using hash
bool detectLoop(Node *head)
{
    // your code here
    Node *temp = head;
    unordered_set<Node *> set;
    while (temp != NULL)
    {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (set.find(temp) != set.end())
        {
            return true;
        }

        // If we are seeing the node for
        // the first time, insert it in hash
        set.insert(temp);
        temp = temp->next;
    }
    return false;
}

//Function to check if the linked list has a loop using  Floyd's Algo
bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        //loop found
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

//Function to find the length of a loop in the linked list.
/**int countNodesinLoop(struct Node *head)
{
}**/

//create a loop at give position in linked list
void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

//remove a loop from linked list
void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

// Returns count of nodes present in loop.
int countNodes(struct Node *n)
{
    int res = 1;
    struct Node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

/* This function detects and counts loop
nodes in the list. If loop is not there
in then returns 0 */
int countNodesinLoop(Node *list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p &&
           fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        /* If slow_p and fast_p meet at
        some point then there is a loop */
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }

    /* Return 0 to indeciate that
       their is no loop*/
    return 0;
}

bool isPalindrome(Node *head)
{
    Node *temp = head;
    stack<int> stack;
    while (temp != NULL)
    {
        stack.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != stack.top())
        {
            return false;
        }
        stack.pop();
        temp = temp->next;
    }
    return true;
}

int main()
{
    //inputOutput();
    /*Node *head = NULL;
    for (int i = 1; i < 10; i++)
    {
        insertAtTail(head, i);
    }
    cout << "Original List -> ";
    display(head);
    insertAtHead(head, 10);
    cout << "New List -> ";
    display(head);

    if (search(head, 11))
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not Found\n";
    }
    head = deleteNodeIterative(head, 1);
    cout << "Node Deleted Iteratively-> ";
    display(head);

    deleteNodeRecursive(head, 14);
    deleteNodeRecursive(head, 5);
    cout << "Node Deleted Recursively -> ";
    display(head);
    int length = findLength(head);
    cout << "Length-> " << length << endl;
    cout << "Value of Nth node-> " << getNthFromLast(head, 1) << endl;
    cout << "Get Middle-> " << getMiddle(head) << endl;

    makeCycle(head, 4);

    if (detectLoop(head))
    {
        cout << "Found Loop\n";
    }
    else
    {
        cout << "Loop Not Found\n";
    }

    removeCycle(head);

    if (detectCycle(head))
    {
        cout << "Found Loop\n";
    }
    else
    {
        cout << "Loop Not Found\n";
    }*/

    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    if (isPalindrome(head))
    {
        cout << "Palindrome\n";
    }
    else
    {
        cout << "Not Palindrome\n";
    }
}