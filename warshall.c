#include<stdio.h>
void warshall(int n,int a[20][20])
{
	int i,j,m1[20][20],m2[20][20],k;
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   m1[i][j]=a[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		  m2[i][j]=(m1[i][j]||(m1[i][k] && m1[k][j]));
		}
	}
  for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m1[i][j]=m2[i][j];
		}
	}
}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",m2[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int i,j,k,n,a[20][20];
	printf("enter num of vertics");
	scanf("%d",&n);
	printf("enter adj matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter edge %d,%d",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("transitive clusure\n");
	warshall(n,a);
	return 0;
}