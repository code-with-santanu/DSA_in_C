#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
    int value;
    struct BinaryTree *left, *right;
} BT;

BT *create_node(int );
void Insert(BT **,int);
void inorder(BT *);
void postorder(BT *);
void preorder(BT *);

int main()
{
    int i, no, n;
    BT *root = NULL;

    printf("\nEnter the no of values: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter the no: ");
        scanf("%d", &no);

        Insert(&root, no);
    }

    printf("\nINORDER TRAVERSAL: ");
    inorder(root);
    printf("\nPREORDER TRAVERSAL: ");
    preorder(root);
    printf("\nPOSTORDER TRAVERSAL: ");
    postorder(root);

    return 0;
}

BT *create_node(int n)
{
    BT *temp;
    temp = (BT *)malloc(sizeof(BT));
    temp->left = NULL;
    temp->right = NULL;
    temp->value = n;

    return temp;
}

void Insert(BT **root, int num)
{
    BT *temp=NULL;
    if (*root == NULL)
    {
        temp=create_node(num);
        *root = temp;
        return;
    }
    else
    {
        if((*root)->left==NULL)
        {
            Insert(&((*root)->left),num);
        }
        else
        {
            if((*root)->right==NULL)
            {
                Insert(&((*root)->right),num);
            }
            else
            {
                Insert(&((*root)->left),num);
            }
        }
    }

    // while (cur->left != NULL || cur->right != NULL)
    // {
    //     if (cur->right == NULL)
    //     {
    //         cur->right = temp;
    //         return;
    //     }
    //     cur = cur->left;
    // }
    // cur->left = temp;
}

void preorder(BT *T)
{
    if(T!=NULL)
    {
        printf("%d\t",T->value);
        preorder(T->left);
        preorder(T->right);
    }
    else
        return;
}    
    
void inorder(BT *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d\t",T->value);
        inorder(T->right);
    }
    else
        return;
}

void postorder(BT *T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d\t",T->value);
    }
    else
        return;
}