#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int x)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

int main()
{
    struct node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    struct node* q[100];
    int f=-1, r=-1;
    q[++r]=root;
    printf("The level order is\n");
    while(f<r)
    {
        struct node* t = q[++f];
        printf("%d ", t->data);
        if(t->left) q[++r]=t->left;
        if(t->right) q[++r]=t->right;
    }
    return 0;
}