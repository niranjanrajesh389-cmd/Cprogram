#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *queue[20];
int front = -1, rear = -1;

void enqueue(struct node *x)
{
    if (rear == 19)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

struct node* dequeue()
{
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

struct node* create()
{
    int x;
    struct node *root, *temp, *p;

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->left = root->right = NULL;

    enqueue(root);

    while (front <= rear)
    {
        p = dequeue();

        printf("Enter left child of %d (0 for no node): ", p->data);
        scanf("%d", &x);
        if (x != 0)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->left = temp;
            enqueue(temp);
        }

        printf("Enter right child of %d (0 for no node): ", p->data);
        scanf("%d", &x);
        if (x != 0)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = x;
            temp->left = temp->right = NULL;
            p->right = temp;
            enqueue(temp);
        }
    }

    return root;
}

void display(struct node *root)
{
    if (root == NULL)
        return;

    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main()
{
    struct node *root;
    root = create();

    printf("Tree elements: ");
    display(root);

    return 0;
}