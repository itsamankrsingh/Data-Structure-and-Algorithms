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

/*naive approach*/
void reverseUsingStack(Node *&head)
{

    stack<int> s;
    Node *temp = head;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    head = NULL;
    while (!s.empty())
    {
        push(head, s.top());
        s.pop();
    }
}

Node *reverseIterative(Node *head)
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main()
{

    Node *head = NULL;
    push(head, 1);
    push(head, 3);
    push(head, 5);
    push(head, 2);
    push(head, 9);
    display(head);
    //reverseUsingStack(head);
    head = reverseIterative(head);
    display(head);
    return 0;
}