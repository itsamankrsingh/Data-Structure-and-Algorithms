#include <iostream>
#include "linked_list_basic.h"
using namespace std;

void divide(int N, Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
    odd->next = evenStart;
}

int main()
{

    Node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    //push(head, 5);

    display(head);

    divide(7, head);
    display(head);
}