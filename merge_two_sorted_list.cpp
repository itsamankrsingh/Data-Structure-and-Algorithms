#include <iostream>
#include "linked_list_basic.h"
using namespace std;

Node *sortedMerge(struct Node *head1, struct Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *dummyNone = new Node(-1);
    Node *p3 = dummyNone;

    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummyNone->next;
}

Node *sortedMergeRecursive(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *result;

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = sortedMergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = sortedMergeRecursive(head1, head2->next);
    }

    return result;
}

int main()
{
    //inputOutput();
    Node *head1 = NULL;
    push(head1, 5);
    push(head1, 10);
    push(head1, 15);
    push(head1, 40);

    Node *head2 = NULL;
    push(head2, 2);
    push(head2, 3);
    push(head2, 20);

    display(head1);
    display(head2);

    Node *head = sortedMerge(head1, head2);

    display(head);

    Node *headRecursive = sortedMergeRecursive(head1, head2);
    display(headRecursive);
}