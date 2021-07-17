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
void removeDuplicate(Node *head)
{
    Node *current = head;
    Node *next_next;
    if (current == NULL)
    {
        return;
    }
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {

            current = current->next;
        }
    }
}

int main()
{

    Node *head = NULL;
    push(head, 2);
    push(head, 2);
    push(head, 4);
    push(head, 5);

    display(head);
    removeDuplicate(head);
    display(head);
    return 0;
}