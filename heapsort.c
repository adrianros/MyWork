#include <stdio.h>
#include <stdlib.h>
int i,a[20];
typedef struct arbore{
int val,index;
struct arbore*s;
struct arbore*d;
struct arbore*t;}arb;
arb *rad,*p;

void insertie()
{int k;
    int v[50],m=4;
    for(i=0; i<m; ++i)
    {


        scanf("%d",v[i]);
        inserare_max(a,i,v[i]);
    }

}
void inserare_max(int a[20],int *n,int x)
{   *n++;
    if(rad==NULL)
    {
        rad->s=NULL;
        rad->d=NULL;
        rad->t=NULL;
        rad->val=x;
    }
    else
    {

    }
}
void delelem_max(int a[20],int *n)
{
    int first=a[0];
    int last=a[n];
    int p=1,l=2,r=3;
    *n--;
    while(r<=n)
    {
        if(last>=a[l]&&last>=a[r])
        {


            last=a[p];
        printf("%d",a[p]);
        return
        }
        else
        {
            if(last<=a[l])
            {


                a[p]=a[l];
                p=l;
            }
            else if(last<=a[r])
            {


                a[p]=a[r];
                p=r;
                l=2*p,r=l+1;
            }
        }
    }
    if(l==n&&a[l]>last)
    {


        a[p]=a[l];
        p=l;


    }
}
void heapsort(int n,int v[2000])
{   m=0;
scanf("%d",n);
    for(i=1;i<=n;++i)
    {


        scanf("%d",&v[i]);
        inserare_max(v,m,v[i]);
    }

    while(n>1)
        delelem_max(v,m);

}

int main()
{
    heapsort(n,v);
    return 0;
}
