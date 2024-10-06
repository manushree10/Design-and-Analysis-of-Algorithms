#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[20],count;
int main()
{
    int n;
    void queen(int row,int n);
    printf("enter num of queen\n");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}
void print(int n)
{
    int i,j;
    printf("\nsolution %d\n",++count);
    for(i=1;i<=n;++i)
        printf("\t%d",i);
    for(i=1;i<=n;++i)
    {
      printf("\n\n%d",i);
      for(j=1;j<=n;++j)
      {
        if(board[i]==j)
        {
            printf("\tQ");

        }
        else
          printf("\t-");
      }
   }
}
int place(int row,int col)
{
    int i,j;
    for(i=1;i<=row-1;++i)
    {
        if(board[i]==col)
         return 0;
         else 
         if(abs(board[i]-col)==abs(i-row))
           return 0;

    }
    return 1;
}
void queen(int row,int n)
{
    int col;
    for(col=1;col<=n;++col)
    {
        if(place(row,col))
        {
            board[row]=col;
         if(row==n)
         print(n);
         else
          queen(row+1,n);
    }
}
}