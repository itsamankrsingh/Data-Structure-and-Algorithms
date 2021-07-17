#include <iostream>
#include "linked_list_basic.h"
using namespace std;

int length(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int diff = 0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    if (l1 > l2)
    {
        diff = l1 - l2;
        temp1 = head1;
        temp2 = head2;
    }
    else
    {
        diff = l2 - l1;
        temp1 = head2;
        temp2 = head1;
    }

    while (diff)
    {
        if (temp1 == NULL)
        {
            return -1;
        }
        temp1 = temp1->next;

        diff--;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp2->data;
        }
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return -1;
}

int main()
{
    //inputOutput();
    Node *head1 = NULL;
    push(head1, 3);
    push(head1, 6);
    push(head1, 9);
    push(head1, 15);
    push(head1, 30);

    Node *head2 = NULL;
    push(head2, 10);
    push(head2, 15);
    push(head2, 30);

    display(head1);
    display(head2);

    cout << intersectPoint(head1, head2) << endl;
}