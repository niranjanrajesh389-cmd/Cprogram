#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* createNode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL) return createNode(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct node* minValueNode(struct node* root)
{
    while(root->left != NULL) root = root->left;
    return root;
}

struct node* deleteNode(struct node* root, int val)
{
    if(root == NULL) return root;
    if(val < root->data) root->left = deleteNode(root->left, val);
    else if(val > root->data) root->right = deleteNode(root->right, val);
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
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
    int n, val, del;
    printf("The number of nodes\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {   printf("The node %d value\n",i+1);
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("The tree contents are\n");
    inorder(root);
    printf("\nThe node to be deleted\n");
    scanf("%d", &del);
    root = deleteNode(root, del);
    inorder(root);
    return 0;
}