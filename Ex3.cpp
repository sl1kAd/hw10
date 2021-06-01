#include <iostream>

Node tmp;
*c = NULL;
if (a == NULL) 
{
    *c = b;
    return;
}
if (b == NULL) 
{
    *c = a;
    return;
}

if (a->value < b->value) 
{
    *c = a;
    a = a->next;
}
else 
{
    *c = b;
    b = b->next;
}

while (a && b) 
{
    if (a->value < b->value) 
    {
        (*c)->next = a;
        a = a->next;
    }
    else 
    {
        (*c)->next = b;
        b = b->next;
    }
    (*c) = (*c)->next;
}

if (a) 
{
    while (a) {
        (*c)->next = a;
        (*c) = (*c)->next;
        a = a->next;
    }
}
if (b) 
{
    while (b) 
    {
        (*c)->next = b;
        (*c) = (*c)->next;
        b = b->next;
    }
}


void merge(Node * a, Node * b, Node * *c) 
{
    Node tmp;
    *c = NULL;
    if (a == NULL) 
    {
        *c = b;
        return;
    }
    if (b == NULL) 
    {
        *c = a;
        return;
    }
    if (a->value < b->value)
    {
        *c = a;
        a = a->next;
    }
    else
    {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) 
    {
        if (a->value < b->value) 
        {
            (*c)->next = a;
            a = a->next;
        }
        else 
        {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) 
    {
        while (a) 
        {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) 
    {
        while (b) 
        {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

void split(Node * src, Node * *low, Node * *high) 
{
    Node* fast = NULL;
    Node* slow = NULL;

    if (src == NULL || src->next == NULL) 
    {
        (*low) = src;
        (*high) = NULL;
        return;
    }

    slow = src;
    fast = src->next;

    while (fast != NULL) 
    {
        fast = fast->next;
        if (fast != NULL) 
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    (*low) = src;
    (*high) = slow->next;
    slow->next = NULL;
}

void mergeSort(Node * *head) 
{
    Node* low = NULL;
    Node* high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL)) 
    {
        return;
    }

    split(*head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    merge(low, high, head);
}