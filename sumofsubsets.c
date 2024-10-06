#include<stdio.h>
#include<stdbool.h>
#define max 100
void subsetsum(int set[],int subset[],int n,int subsize,int total,int nodecount,int sum)
{
    int i,j;
    if(total==sum)
    {
        printf("subset found:{ ");
        for(i=0;i<subsize;i++)
        {
            printf("%d\t",subset[i]);
        }
        printf("}\n");
        return;
    }
    else
    {
        for(i=nodecount;i<n;i++)
        {
            subset[subsize]=set[i];
            subsetsum(set,subset,n,subsize+1,total+set[i],i+1,sum);
        }
    }
}
int main()
{
    int i,n,sum;
    int set[max];
    int subset[max];
    printf("enter num of subsets");
    scanf("%d",&n);
    printf("enter the subsets");
    for(i=0;i<n;i++)
    {
        scanf("%d",&set[i]);
    }
    printf("enter the sum to find subset");
    scanf("%d",&sum);
    printf("subset with sum %d\n",sum);
    subsetsum(set,subset,n,0,0,0,sum);
    return 0;
     
}