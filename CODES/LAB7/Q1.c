#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *lchild;
    int data; 
    int height;
    struct node *rchild;
};

int nodeheight(struct node *p)
{
    int hl,hr;
    hl= p && p->lchild?p->lchild->height:0;
    hr= p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}



int balancefactor(struct node *p)
{
        int hl,hr;
    hl= p && p->lchild?p->lchild->height:0;
    hr= p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

struct node *llrotation(struct node *p )
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=nodeheight(p);
    pl->height=nodeheight(pl);
}

struct node*lrrotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);
}
struct node * BST(struct node *p,int key)
{
    struct node *temp;
    if(p==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->rchild=temp->lchild=NULL;
        temp->height=0;
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
    p->height=nodeheight(p);
    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
    return llrotation;
        if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
    return lrrotation;
        if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
    return rrrotation;
        if(balancefactor(p)==-2 && balancefactor(p->lchild)==-1)
    return rlrotation;
    return p;
}