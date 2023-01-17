#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}BST;


BST *create_node(int );
void insert(BST **,int);
void inorder(BST *);
void postorder(BST *);
void preorder(BST *);

int main()
{
    BST *Tree=NULL;
    int no,i,num;

    printf("\nProgram for Tree Traversal\n");

    printf("\nEnter the number of nodes to add to the tree: ");
    scanf("%d",&no);

    for(i=0;i<no;i++)
    {
        printf("\nEnter the item: ");
        scanf("%d",&num);
        insert(&Tree,num);
    }

    printf("\nINORDER TRAVERSAL: ");
    inorder(Tree);
    printf("\nPREORDER TRAVERSAL: ");
    preorder(Tree);
    printf("\nPOSTORDER TRAVERSAL: ");
    postorder(Tree);
    
    return 0;
}

BST *create_node(int n)
{
    BST *temp=NULL;
    temp=(BST*)malloc(sizeof(BST));

    temp->data=n;
    temp->left=temp->right=NULL;

    return temp;
}

void insert(BST **T,int num)
{
    if((*T)==NULL)
    {
        BST *temp=NULL;
        printf("Leaf node created.");
        temp=create_node(num);
        (*T)=temp;

        return;
    }
    else
    {
        if(num==(*T)->data)
        {
            printf("\nREPEATED ENTRY ERROR VALUE REJECTED!!!\n");
            return;
        }
        if(num<(*T)->data)
        {
            printf("\nDirected to left link.\n");
            insert(&((*T)->left),num);
        }
        else
        {
            printf("\nDirected to right link.\n");
            insert(&((*T)->right),num);
        }
    }
    return;
}


void preorder(BST *T)
{
    if(T!=NULL)
    {
        printf("%d\t",T->data);
        preorder(T->left);
        preorder(T->right);
    }
    else
        return;
}    
    
void inorder(BST *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d\t",T->data);
        inorder(T->right);
    }
    else
        return;
}

void postorder(BST *T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d\t",T->data);
    }
    else
        return;
}