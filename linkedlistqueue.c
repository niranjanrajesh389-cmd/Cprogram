#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void delete()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted\n");
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } 

    return 0;
}