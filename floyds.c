#include<stdio.h>
#include<stdlib.h>
void printmat(int dist[20][20],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==j)
      dist[i][j]=0;
    }
  }
  printf("output\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d\t",dist[i][j]);
    }
    printf("\n");
}
}

void floyd(int n,int com[20][20])
{
  int dist[20][20],i,j,k;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      dist[i][j]=com[i][j];
    }
  }
  for(k=0;k<n;k++)
  {
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(dist[i][j]>dist[i][k]+dist[k][j])
      dist[i][j]=dist[i][k]+dist[k][j];
    }
  }
  }
  printmat(dist,n);
}
void readmat()
{
  int i,j,n;
  int com[20][20];
  printf("enter num vertice");
  scanf("%d",&n);
  printf("enter adj matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&com[i][j]);
    }
  }
  floyd(n,com);
}
void main()
{
  readmat();
}