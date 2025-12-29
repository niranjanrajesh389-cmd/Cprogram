 #include <stdio.h>
 #include<stdlib.h>
#define MAX 2

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &value);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
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

}