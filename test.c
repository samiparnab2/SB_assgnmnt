#include<stdio.h>
void prin(int p[][10],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",p[i][j]);
        printf("\n");
    }
}
void main()
{
    int a[10][10],n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    prin(&a[1][1],2);
}