#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}Node;


Node *create_node(int );
void insert(struct node **,int);
void inorder(struct node *);
void postorder(struct node *);
void preorder(struct node *);

int main()
{

    Node *head=NULL;
    int no,i,num;
    printf("\nProgram for Tree Traversal\n");
    printf("Enter the number of nodes to add to the tree:<BR>\n");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
    printf("Enter the item:\n");
    scanf("%d",&num);
    insert(&head,num);
    }

    //getch();
    printf("\nINORDER TRAVERSAL\n");
    inorder(head);
    printf("\nPREORDER TRAVERSAL\n");
    preorder(head);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(head);
    
    return 0;
}

Node *create_node(int n)
{
    Node *temp=NULL;
    temp=(Node*)malloc(sizeof(Node));

    temp->data=n;
    temp->left=temp->right=NULL;

    return temp;
}

void insert(Node **p,int num)
{
    if((*p)==NULL)
    {
        Node *temp=NULL;
        printf("Leaf node created.");
        temp=create_node(num);
        (*p)=temp;
        return;
    }
    else
    {
        if(num==(*p)->data)
        {
            printf("\nREPEATED ENTRY ERROR VALUE REJECTED\n");
            return;
        }
        if(num<(*p)->data)
        {
            printf("\nDirected to left link.\n");
            insert(&((*p)->left),num);
        }
        else
        {
            printf("Directed to right link.\n");
            insert(&((*p)->right),num);
        }
    }
    return;
}


void preorder(Node *p)
{
    if(p!=NULL)
    {
        printf("\nData :%d",p->data);
        preorder(p->left);
        preorder(p->right);
    }
    else
        return;
}    
    
void inorder(Node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("\nData :%d",p->data);
        inorder(p->right);
    }
    else
        return;
}

void postorder(Node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("\nData :%d",p->data);
    }
    else
        return;
}