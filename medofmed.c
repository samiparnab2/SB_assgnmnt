#include<stdio.h>
#define N 30
void merge(int p[],int start,int mid,int end)
{
    int a[end-start+1],i,j,k=0;
    i=start;
    j=mid+1;
    while(i<=mid && j<=end)
    {
        if(p[i]<=p[j])
        {
            a[k]=p[i];
            i++;
            k++;
        }
        else
        {
            a[k]=p[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k]=p[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        a[k]=p[j];
        j++;
        k++;
    }
    k=0;
    for(i=start;i<=end;i++)
    {
        p[i]=a[k];
        k++;
    }
}
void merge_sort(int p[],int start,int end)
{
    int mid;
    if(start>=end)
        return;
    mid=(start+end)/2;
    merge_sort(p,start,mid);
    merge_sort(p,mid+1,end);
    merge(p,start,mid,end);
}
int medofmed(int a[],int start,int end,int n)
{
    int i,j,med[N/5],l[N],r[N],k=0,x,inc=0,mom;
    for(i=start;i<=end;i+=5)
    {   
        if(i+4<=end)
            x=i+4;
        else
            x=end;
        merge_sort(a,i,x);
        med[k]=a[(i+x)/2];
        k++;
    }
    merge_sort(med,0,k-1);
    mom=med[k/2];
    j=0;
    x=0;
    for(i=start;i<=end;i++)
    {
        if(a[i]<mom)
        {
            l[j]=a[i];
            j++;
        }
        else if(a[i]>mom)
        {
            r[x]=a[i];
            x++;
        }
    }
    if(n==j)
        return mom;
    else if(n>j)
        return medofmed(r,0,(end-start)-j-1,((end-start)-j)/2);
    else
        return medofmed(l,0,j-1,(j-1)/2);
    
}
void main()
{
    int a[N],i,j,n;
    printf("enter no of elemenets: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter %dth element: ",i);
        scanf("%d",&a[i]);
    }
    printf("the median is %d ",medofmed(a,0,n-1,n/2));
}
/*
24
25
21
98
100
76
22
43
60
89
87
1
10
9
8
7
6
5
4
3
2
31
38
37
35
*/