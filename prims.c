#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,k,a,b,n,u,v,ne=1;
   int min,mincost=0,cost[20][20],vis[20]={0};
   printf("enter num of vertices");
   scanf("%d",&n);
   printf("enter vertices");
   for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
            cost[i][j]=999;
    }
   }
   vis[1]=1;
   while(ne<n)
   {
    for(i=1,min=999;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                if(vis[i]!=0)
                {
                 min=cost[i][j];
                 a=u=i;
                 b=v=j;
                }
            }

        }
    }
    if(vis[u]==0||vis[v]==0)
    {
        printf("%d edges(%d,%d)=%d\n",ne++,a,b,min);
        vis[b]=1;
        mincost+=min;
    }
    cost[b][a]=cost[a][b]=999;
   }
   printf("min spanning tree=%d\t",mincost);
}