#include<stdio.h>
#include<math.h>
int len(long x)
{
    int length=0;
    while(x!=0)
    {
        x=x/10;
        length++;
    }
    return length;
}

long large_mult(long p,long q)
{
    int length=len(p);
    long px,py,qx,qy,c0,c1,c2;
    if(len(p)==1 && len(q)==1)
        return p*q;
    px=p/pow(10,length/2);
    py=p%(int)pow(10,length/2);
    qx=q/pow(10,length/2);
    qy=q%(int)pow(10,length/2);
    c0=large_mult(px,qx);
    c2=large_mult(py,qy);
    c1=large_mult((px+py),(qx+qy));
    c1=c1-c0-c2;
    return((c0*pow(10,length))+(c1*pow(10,length/2))+c2);
}
void main()
{
    long a,b;
    printf("enter 1st no. ");
    scanf("%ld",&a);
    printf("enter 2nd no. ");
    scanf("%ld",&b);
    printf("%ld * %ld = %ld",a,b,large_mult(a,b));
}