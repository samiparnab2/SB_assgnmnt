#include<stdio.h>
int *mat_add(int x[][8],int y[][8],int z[][8],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            z[i][j]=x[i][j]+y[i][j];
        }
            
    }
    return z;
}
int *mat_sub(int x[][8],int y[][8],int z[][8],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            z[i][j]=x[i][j]-y[i][j];
        }
            
    }
    return z;
}

void stressen_mat_mult(int x[][8],int y[][8],int res[][8],int n)
{
    int i,j,p,q,r,s,t,u,v,t1[8][8],t2[8][8],t3[8][8],nb2=n/2;
    int pm[8][8],qm[8][8],rm[8][8],sm[8][8],tm[8][8],um[8][8],vm[8][8];
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
        return ;
    }
    stressen_mat_mult(mat_add(x,x[nb2]+nb2,t1,nb2),mat_add(y,y[nb2]+nb2,t2,nb2),pm,nb2);
    stressen_mat_mult(mat_add(x[nb2],x[nb2]+nb2,t1,nb2),y,qm,nb2);
    stressen_mat_mult(x,mat_sub(y+nb2,y[nb2]+nb2,t2,nb2),rm,nb2);
    stressen_mat_mult(x[nb2]+nb2,mat_sub(y[nb2],y,t2,nb2),sm,nb2);    
    stressen_mat_mult(mat_add(x,x+nb2,t1,nb2),y[nb2]+nb2,tm,nb2);
    stressen_mat_mult(mat_sub(x[nb2],x,t1,nb2),mat_add(y,y+nb2,t2,nb2),um,nb2);
    stressen_mat_mult(mat_sub(x+nb2,x[nb2]+nb2,t1,nb2),mat_add(y[nb2],y[nb2]+nb2,t2,nb2),vm,nb2);
    mat_add(mat_sub(mat_add(pm,sm,res,nb2),tm,res,nb2),vm,res,nb2);
    mat_add(rm,tm,res+nb2,nb2);
    mat_add(qm,sm,res[nb2],nb2);
    mat_add(mat_sub(mat_add(pm,rm,res[nb2]+nb2,nb2),qm,res[nb2]+nb2,nb2),um,res[nb2]+nb2,nb2);
    return ;
}

void main()
{
    int a[8][8],b[8][8],c[8][8],i,j,m,n;
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
/*
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/