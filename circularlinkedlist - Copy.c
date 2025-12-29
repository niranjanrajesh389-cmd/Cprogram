#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

void insert_end(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;

    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void delete_begin()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (last->next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

int main()
{
    int ch, value;

    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;

        case 2:
            delete_begin();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }
}