#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL)
        return createNode(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(struct node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct node* root = NULL;
    int n, val;
    printf("Enter the nodes\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {printf("Enter node %d values\n",i+1);
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("The root contents are\n");
    inorder(root);
    return 0;
}