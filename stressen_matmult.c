#include<stdio.h>
void mat_add(int x[][10],int y[][10],int z[][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            z[i][j]=x[i][j]+y[i][j];
            printf("%d+%d=%d\n",x[i][j],y[i][j],z[i][j]);
        }
            
    }
}
int stressen_mat_mult(int x[][10],int y[][10],int res[][10],int n)
{
    int i,j,p,q,r,s,t,u,v,t1[10][10],t2[10][10],t3[10][10];
    if(n==2)
    {
        p=(x[0][0]+x[1][1])*(y[0][0]+y[1][1]);
        q=(x[1][0]+x[1][1])*y[0][0];
        r=x[0][0]*(y[0][1]-y[1][1]);
        s=x[1][1]*(y[1][0]-y[0][0]);
        t=(x[0][0]+x[0][1])*y[1][1];
        u=(x[1][0]-x[0][0])*(y[0][0]+y[0][1]);
        v=(x[0][1]-x[1][1])*(y[1][0]+y[1][1]);
        res[0][0]=p+s-t+v;
        res[0][1]=r+t;
        res[1][0]=q+s;
        res[1][1]=p+r-q+u;
        return 1;
    }
    mat_add(x,(x+((n/2)*10)+(n/2)),t1,n/2);
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        printf("%d ",t1[i][j]);
        printf("\n");
    }
}

void main()
{
    int a[10][10],b[10][10],c[10][10],i,j,m,n;
    printf("enter size of the matrix(row coloumn)");
    scanf("%d %d",&m,&n);
    printf("enter 1st matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("b[%d][%d]= ",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    stressen_mat_mult(a,b,c,n);
    printf("result:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
