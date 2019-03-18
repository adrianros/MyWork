
#include <stdio.h>
#include <stdlib.h>
typedef struct arbore
{
    int bal,info;
    struct arbore *left;
    struct arbore *right;
    struct arbore *tata;

}nod;
int i,n,x;
nod *p,*t=NULL;
int min(int a,int b)
{
    if(a>b)
        return b;
    else return a;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
void rotatie_dr(nod *p)
{
    nod *k=p->left;
    p->left=k->right;
    k->right=p;
    p->bal=p->bal+(1-min(k->bal,0));
    k->bal=k->bal+(1+max(p->bal,0));
    p=k;
}
void rotatie_st(nod *p)
{
    nod *k=p->right;
    p->right=k->left;
    k->left=p;
    p->bal=p->bal-(1+max(k->bal,0));
    k->bal=k->bal-(1-min(p->bal,0));
    p=k;
}
void rotatie_st_dr(nod *p)
{
    rotatie_st(p->left);
    rotatie_dr(p);
}
void rotatie_dr_st(nod *p)
{
    rotatie_dr(p->right);
    rotatie_st(p);
}

int inserare(nod *p,int val)
{
    if(t==NULL)
    {
        nod *nou=calloc(1,sizeof(nod));
        nou->right=NULL;
        nou->left=NULL;
        nou->info=val;
        t=nou;
        nou->tata=NULL;
        return 1;
    }
    else
    {





            if(p->info>val)
            {if(p->left!=NULL&&p->left->info<val)



                p->bal--;
                nod *nou=calloc(1,sizeof(nod));
                nou->right=NULL;
                nou->left=p->left;
                nou->tata=p;
                p->left=nou;
                nou->info=val;
                p=nou;
                return 1;
            }






                if(p->info<val&&p->right->info>val);
            {


                p->bal++;
                nod *nou=calloc(1,sizeof(nod));
                nou->left=NULL;
                nou->tata=p;
                nou->right=p->right;
                p->right=nou;
                nou->info=val;
                p=nou;
                return 1;
            }









            if(p->info>val)
                return inserare(p->right,val);
            else
                return inserare(p->left,val);

    }


}
int verificare(nod *t)
{
    if(t->bal==0||t->bal==1||t->bal==-1)
        return 1;
    else
        return 0;

}
void echil(nod *p)
{   if(p!=NULL)
{


    if(p->bal==-2)
    {
        if(p->left->bal==1)
            rotatie_st_dr(p);
        else
            rotatie_dr(p);
    }
    else if(p->bal==2)

    {
        if(p->right->bal==-1)
            rotatie_dr_st(p);
        else
            rotatie_st(p);
    }


    }
    echil(p->tata);

}

void echil_avl()
{   int xx;
    for(i=1; i<=n; ++i)
    {


        scanf("%d",&x);
        xx=inserare(t,x);
        nod *aux1=p;
        //echil(aux1);



    }
    afisare(t);
    printf("\n");

}
int cauta(nod *t,int x)
{
    if(t->info>x)
        return (t->left,x);
    else
        if(t->info<x)
        return (t->right,x);
    else
   {
       if(t->info==x)
       return 1;
       else
        return 0;
   }
}
int maxim(nod *t)
{
    while(t->right!=NULL)
        t->right=t;
    return t->info;
}
void stergere(nod *t,int x)
{
    if(t->info>x)
        t->left=t;
    else
        if(t->right<x)
        t->right=t;
    else
    {   nod *aux=t;
        if(aux->right!=NULL)
        {

            aux->right=aux;
            while(aux->left!=NULL)
                    aux->left=aux;
                    aux->left=t->left;
                    echil(aux);
                    t->tata->right=t->right;
                    free(aux);



                    }
                    else
                        aux->tata->left=aux->left;
                    t->tata=t;
                    free(aux);



                            echil(t);



    }
}
int minim(nod *k)
{
    while(k->left!=NULL)
        k->left=k;
    return k;
}
void stergeree(nod *t,int x)
{   nod *aux;
    if(t->info>x)
        t->left=t;
    if(t->info<x)
        t->right=t;
    else
    {   if(t->left==NULL||t->right==NULL)
        {
            if(t->left!=NULL)
            {


                aux=t->left;
                t->info=t->left->info;
                t->left=t->left->left;
            }
                else
                {


                    aux=t->right;
                    t->info=t->right->info;
                    t->right=t->right->right;
                }
            free(aux);
        }
        else
        {
             nod *y=minim(t->right);
             t->info=y->info;
             free(y);
        }


    }
}
void afisare(nod *t)
{   if(t!=NULL)
{


    printf("%d",t->info);
    afisare(t->left);
    afisare(t->right);
}
}


int main()
{
    scanf("%d",&n);
    echil_avl();
    return 0;
}

