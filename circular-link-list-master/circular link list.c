#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
}*head;
void createList(int n);
void displayList();
void insertAtN(int data, int position);
void deleter(struct node ** head, int key);
int main()
{
    int n, data, choice=1,key;
    head = NULL;
    while(choice != 0)
    {

        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Insert at any position\n");
        printf("4. delete any node\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter node position: ");
                scanf("%d", &n);
                printf("Enter data you want to insert at %d position: ", n);
                scanf("%d", &data);
                insertAtN(data, n);
                break;
            case 4:
                printf("enter the node value to be deleted: ");
                scanf("%d",&key);
                deleter(&head,key);
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-4");
        }
    }
    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;
    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        prevNode = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = NULL;
            prevNode->next = newNode;
            prevNode = newNode;
        }
        prevNode->next = head;
        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}
void insertAtN(int data, int position)
{
    struct node *newNode, *current;
    int i;
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void deleter(struct node ** head, int key)
{
    int i, count;
    struct node *prev, *cur;
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    count = 0;
    cur   = *head;
    prev  = cur;
    while (prev->next != *head)
    {
        prev = prev->next;
        count++;
    }
    i = 0;
    while (i <= count)
    {
        if (cur->data == key)
        {
            if (cur->next != cur)
                prev->next = cur->next;
            else
                prev->next = NULL;
            if (cur == *head)
                *head = prev->next;
            free(cur);
            if (prev != NULL)
                cur = prev->next;
            else
                cur = NULL;
        }
        else
        {
            prev = cur;
            cur  = cur->next;
        }
        i++;
    }
}

