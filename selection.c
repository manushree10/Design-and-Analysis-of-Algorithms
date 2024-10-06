#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int a[50000],int n)
{
    int min,i,j,temp=0;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
        
    }
    
}
int main()
{
    int a[50000],n,i;
    clock_t start,end;
    float cpu_time_taken=0;
    printf("enter num of array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     a[i]=rand()%10000;
    }
    start=clock();
    sort(a,n);
    end=clock()-start;
    printf("sorted array\n");
    
        printf("time taken%f",((double)(end)/CLOCKS_PER_SEC));
    
}