#include<stdio.h>
#include<stdlib.h>
const int max=100;
void topo(int a[max][max],int n)
{
   int in[max],out[max],stack[max],top=-1;
   int i,j,k=0;
   for(i=0;i<n;i++)
   {
      in[i]=0;
      for(j=0;j<n;j++)
      {
        if(a[j][i]==1)
         in[i]++;
      }
   }
  while(1)
  {
    for(i=0;i<n;i++)
    {
      if(in[i]==0)
      {
        stack[++top]=i;
        in[i]=-1;
      }
    }
    if(top==-1)
     break;
     out[k]=stack[top--];
     for(i=0;i<n;i++)
     {
      if(a[out[k]][i]==1)
        in[i]--;
     }
     k++;
  }
  printf("topology sort\n");
  for(i=0;i<k;i++)
  {
    printf("%d",out[i]+1);
  }
}
int main()
{
  int i,j,a[max][max],n;
  printf("enter num of vertices");
  scanf("%d",&n);
  printf("enter adj matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  topo(a,n);
  printf("\n");
  return 0;
}

