#include<stdio.h>
void quick_sort(int p[],int start,int end)
{
    if(start>=end)
        return;
    int i,j,temp;
    i=start+1;
    j=end;
    while(i<=j)
    {
        while(p[i]<p[start])
        {
            if(j<i)
                break;
             i++;
        }
        while(p[j]>=p[start])
        {
            if(j<i)
                break;
            j--;
        }
        if(i<j)
        {
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    temp=p[start];
    p[start]=p[j];
    p[j]=temp;
    quick_sort(p,start,j-1);
    quick_sort(p,j+1,end);
    
}
void main()
{
    int a[20],n;
    printf("enter no of elements:- ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter %dth element:-\n",i+1);
        scanf("%d",&a[i]);
    }
    a[n]=2147483648;
    quick_sort(a,0,n-1);
    printf("sorted elements are:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}