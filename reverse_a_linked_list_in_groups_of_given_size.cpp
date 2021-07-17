#include <iostream>
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

void push(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

Node *reverse(Node *head, int k)
{

    int count = 0;
    Node *prevptr = NULL;
    Node *currentptr = head;
    Node *nextptr;
    while (currentptr != NULL && count < k)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverse(nextptr, k);
    }

    return prevptr;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = NULL;
    push(head, 4);
    push(head, 2);
    push(head, 2);
    push(head, 1);
    push(head, 8);
    push(head, 7);
    push(head, 6);
    push(head, 5);

    display(head);
    head = reverse(head, 4);
    display(head);
    return 0;
}