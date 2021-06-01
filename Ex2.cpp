#include <iostream>

typedef struct Node 
{
    int value;
    struct Node* next;
} Node;

void push(Node** head, int data) 
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node** head) 
{
    Node* prev = NULL;
    int val;
    if (head == NULL) 
    {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

Node* getNth(Node* head, int n) 
{
    int counter = 0;
    while (counter < n && head) 
    {
        head = head->next;
        counter++;
    }
    return head;
}


Node* getLast(Node* head) 
{
    if (head == NULL) 
    {
        return NULL;
    }
    while (head->next) 
    {
        head = head->next;
    }
    return head;
}

void pushBack(Node* head, int value) 
{
    Node* last = getLast(head);
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}

Node * getLastButOne(Node * head) 
{
    if (head == NULL) 
    {
        exit(-2);
    }
    if (head->next == NULL) 
    {
        return NULL;
    }
    while (head->next->next) 
    {
        head = head->next;
    }
    return head;
}

void popBack(Node * *head) 
{
    Node* lastbn = NULL;
    //Получили NULL
    if (!head) 
    {
        exit(-1);
    }
  
    if (!(*head)) 
    {
        exit(-1);
    }
    lastbn = getLastButOne(*head);
    
    if (lastbn == NULL) 
    {
        free(*head);
        *head = NULL;
    }
    else 
    {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}

int popBack(Node * *head) 
{
    Node* pFwd = NULL;  
    Node* pBwd = NULL;  
   
    if (!head) 
    {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) 
    {
        exit(-1);
    }

    pFwd = *head;
    while (pFwd->next) 
    {
        pBwd = pFwd;
        pFwd = pFwd->next;
    }

    if (pBwd == NULL) 
    {
        free(*head);
        *head = NULL;
    }
    else {
        free(pFwd->next);
        pBwd->next = NULL;
    }
}

void insert(Node * head, unsigned n, int val) 
{
    unsigned i = 0;
    Node* tmp = NULL;

    while (i < n && head->next) 
    {
        head = head->next;
        i++;
    }
    tmp = (Node*)malloc(sizeof(Node));
    tmp->value = val;
   
    if (head->next) {
        tmp->next = head->next;
        //иначе на NULL
    }
    else 
    {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(Node** head, int n) 
{
    if (n == 0) 
    {
        return pop(head);
    }
    else 
    {
        Node* prev = getNth(*head, n - 1);
        Node* elm = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}


void deleteList(Node** head) 
{
    while ((*head)->next) 
    {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

void deleteList(Node * *head) 
{
    Node* prev = NULL;
    while ((*head)->next) 
    {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}

void fromArray(Node * *head, int* arr, size_t size) 
{
    size_t i = size - 1;
    if (arr == NULL || size == 0) 
    {
        return;
    }
    do 
    {
        push(head, arr[i]);
    } while (i-- != 0);
}

int* toArray(const Node * head) 
{
    int leng = length(head);
    int* values = (int*)malloc(leng * sizeof(int));
    while (head) 
    {
        values[--leng] = head->value;
        head = head->next;
    }
    return values;
}

void printLinkedList(const Node * head) 
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void main()
{
    Node* head = NULL;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    
    fromArray(&head, arr, 10);

    printLinkedList(head);

    insert(head, 4, 333);
    printLinkedList(head);

    pushBack(head, 11);
    pushBack(head, 12);
    pushBack(head, 13);
    pushBack(head, 14);
    printLinkedList(head);

    printf("%d\n", pop(&head));
    printf("%d\n", popBack(&head));

    printLinkedList(head);
  
    deleteNth(&head, 4);
    printLinkedList(head);
    deleteList(&head);

    getch();
}
