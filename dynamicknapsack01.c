#include<stdio.h>
int w[20],p[20],n;
int max(int a,int b)
{
	return a>b?a:b;
}
int knap(int i,int m)
{
	if(i==n)
	return w[i]>m?0:p[i];
	if(w[i]>m)
	 return knap(i+1,m);
	  return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}
int main()
{
	int i,m,max;
	printf("enter num of objects\n");
	scanf("%d",&n);
	printf("enter capcity\n");
	scanf("%d",&m);
	printf("enter value n weight\n");
	for(i=1;i<=n;i++){
	scanf("%d%d",&p[i],&w[i]);
	}
	printf("output\n");
	max=knap(1,m);
	printf("max value=%d",max);

}