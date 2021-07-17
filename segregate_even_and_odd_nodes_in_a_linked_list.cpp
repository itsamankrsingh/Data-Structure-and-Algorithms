#include <iostream>
#include "linked_list_basic.h"
using namespace std;

Node *divide(int N, Node *head)
{
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    Node *temp = head;
    while (temp)
    {

        if ((temp->data) & 1)
        {
            if (!oddStart)
            {
                oddStart = temp;
                oddEnd = temp;
            }
            else
            {
                oddEnd->next = temp;
                oddEnd = oddEnd->next;
            }
        }
        else
        {

            if (!evenStart)
            {
                evenStart = temp;
                evenEnd = temp;
            }
            else
            {
                evenEnd->next = temp;
                evenEnd = evenEnd->next;
            }
        }
        temp = temp->next;
    }
    if (evenStart == NULL || oddStart == NULL)
    {
        return head;
    }
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}

int main()
{

    Node *head = NULL;
    push(head, 17);
    push(head, 15);
    push(head, 8);
    push(head, 9);
    push(head, 2);
    push(head, 4);
    push(head, 6);

    display(head);

    Node *divideNode = divide(7, head);
    display(divideNode);
}