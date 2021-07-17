#include <iostream>
using namespace std;

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

int middle(Node *head)
{
    Node *slowptr = head;
    Node *fastptr = head;

    while (fastptr->next != NULL && fastptr != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    cout << slowptr->data << endl;
    return slowptr->data;
}

int main()
{
    Node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    display(head);
    cout << middle(head) << endl;
}