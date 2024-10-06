#include<stdio.h>
#define max 100
#define INF 999999
typedef struct 
{
    int value;
    int weight;
    float ratio;
}item;
void swap(item *a,item *b)
{
    item temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void ratiobyitem(item items[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(items[j].ratio<items[j+1].ratio)
            {
                swap(&items[j],&items[j+1]);
            }
        }
    }
}
int knapdiscrete(int W,item items[],int n)
{
    int i,j;
    ratiobyitem(items,n);
    int curweight=0;
    int totalvalue=0;
    for(i=0;i<n;i++)
    {
        if(curweight+items[i].weight<=W)
        {
            curweight+=items[i].weight;
            totalvalue+=items[i].value;
        }
    }
    return totalvalue;
}
float knapcont(int W,item items[],int n)
{
    int i,j;
    ratiobyitem(items,n);
    int curweight=0;
    float totalvalue=0.0;
    for(i=0;i<n;i++)
    {
        if(curweight+items[i].weight<=W)
        {
            curweight+=items[i].weight;
            totalvalue+=items[i].value;
        }
        else
        {
        int remain=W-curweight;
        totalvalue+=items[i].value*((float)remain/items[i].weight);
        break;
        }
    }
    return totalvalue;
}
int main()
{
    int i,n,W,j,ch;
    item items[max];
    printf("enter num of objects");
    scanf("%d",&n);
    printf("enter weight capacity ");
    scanf("%d",&W);
    printf("enter now\n");
    for(i=0;i<n;i++)
    {
        printf("enter value and weight %d",i+1);
        scanf("%d%d",&items[i].value,&items[i].weight);
        items[i].ratio=(float)items[i].value/items[i].weight;
      
    }
    printf("enter choice\n1.discrete\n2.continues\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        int maxvalue=knapdiscrete(W,items,n);
        printf("max value%d",maxvalue);
    }
    else 
    if(ch==2)
    {
        float maxvalue=knapcont(W,items,n);
        printf("max value%.2f",maxvalue);
    }
    else
      printf("invalid\n");
}