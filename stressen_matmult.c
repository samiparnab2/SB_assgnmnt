#include<stdio.h>
void mat_add(int x[][8],int y[][8],int z[][8],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            z[i][j]=x[i][j]+y[i][j];
        }
            
    }
}
void mat_sub(int x[][8],int y[][8],int z[][8],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            z[i][j]=x[i][j]-y[i][j];
        }
            
    }
}

void stressen_mat_mult(int *x,int *y,int *res,int n)
{
    int i,j,p,q,r,s,t,u,v,t1[8][8],t2[8][8],t3[8][8],nb2=n/2;
    int pm[8][8],qm[8][8],rm[8][8],sm[8][8],tm[8][8],um[8][8],vm[8][8];
    int inc=8;
    
    if(n==2)
    {
        p=(x[0]+x[inc+1])*(y[0]+y[inc+1]);
        q=(x[inc]+x[inc+1])*y[0];
        r=x[0]*(y[1]-y[inc+1]);
        s=x[inc+1]*(y[inc]-y[0]);
        t=(x[0]+x[1])*y[inc+1];
        u=(x[inc]-x[0])*(y[0]+y[1]);
        v=(x[1]-x[inc+1])*(y[inc]+y[inc+1]);
        res[0]=p+s-t+v;
        res[1]=r+t;
        res[inc]=q+s;
        res[inc+1]=p+r-q+u;
        return ;
    }
    mat_add(x,&x[(nb2*inc)+nb2],t1,nb2);
    mat_add(y,&y[(nb2*inc)+nb2],t2,nb2);
    stressen_mat_mult((int *)t1,(int *)t2,pm,nb2);
    mat_add(&x[(nb2*inc)],&x[(nb2*inc)+nb2],t1,nb2);
    stressen_mat_mult((int *)t1,y,(int *)qm,nb2);
    mat_sub(&y[nb2],&y[(nb2*inc)+nb2],t2,nb2);
    stressen_mat_mult(x,(int *)t2,(int *)rm,nb2);
    mat_sub(&y[(nb2*inc)],y,t2,nb2);
    stressen_mat_mult(&x[(nb2*inc)+nb2],(int *)t2,(int *)sm,nb2);    
    mat_add(x,&x[nb2],t1,nb2);
    stressen_mat_mult(t1,&y[(nb2*inc)+nb2],(int *)tm,nb2);
    mat_sub(&x[(nb2*inc)],x,t1,nb2);
    mat_add(y,&y[nb2],t2,nb2);
    stressen_mat_mult((int *)t1,(int *)t2,um,nb2);
    mat_sub(&x[nb2],&x[(nb2*inc)+nb2],t1,nb2);
    mat_add(&y[(nb2*inc)],&y[(nb2*inc)+nb2],t2,nb2);
    stressen_mat_mult((int *)t1,(int *)t2,vm,nb2);
    mat_add(pm,sm,res,nb2);
    mat_sub(res,tm,res,nb2);
    mat_add(res,vm,res,nb2);
    mat_add(rm,tm,&res[nb2],nb2);
    mat_add(qm,sm,&res[(nb2*inc)],nb2);
    mat_add(pm,rm,&res[(nb2*inc)+nb2],nb2);
    mat_sub(&res[(nb2*inc)+nb2],qm,&res[(nb2*inc)+nb2],nb2);
    mat_add(&res[(nb2*inc)+nb2],um,&res[(nb2*inc)+nb2],nb2);
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
    stressen_mat_mult((int *)a,(int *)b,(int *)c,n);
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