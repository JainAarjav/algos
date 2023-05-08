#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *lchild;
    int data;
     struct node *rchild;
}*t=NULL;

struct node* create()
{
    struct node *t =malloc(sizeof(struct node));
    int x;
    printf("ENTER THE DATA\n");
    scanf("%d",&t->data);
    if(t->data==-1)
    {
        return NULL;
    }
        printf("ENTER THE DATA OF LCHILD OF %d\n",t->data);
         t->lchild=create();
        printf("ENTER THE DATA OF LCHILD OF %d\n",t->data);
        t->rchild=create();
        return t;
}

struct node * BST(struct node *p,int key)
{
    struct node *temp;
    if(p==NULL)
    {
                temp=malloc(sizeof(struct node));
        temp->rchild=temp->lchild=NULL;
        temp->data=key;
        return temp;
    }
    else if(p->data<key)
    {
        p->lchild=BST(p->lchild,key);
    }
    else if(p->data>key)
    {
                p->rchild=BST(p->rchild,key);
    }
    return p;
}







int main()
{
    t=create();
}