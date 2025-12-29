 #include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int x)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));

    t->data = x;
    t->left = NULL;
    t->right = NULL;

    return t;
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

    root = create(1);
    root->left = create(2);
    root->right = create(3);

    display(root);
    return 0;
}