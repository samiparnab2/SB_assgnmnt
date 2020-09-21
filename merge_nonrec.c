#include<stdio.h>
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
void merge_sort(int p[],int len)
{
    int lim,i,mid,end,start;
    for(i=1;i<len;i*=2)
    {
        start=0;
        while (start<len)
        {
            mid=start+i-1;
            end=mid+i;
            if(end>=len)
                end=len-1;
            merge(p,start,mid,end);
            start=end+1;
        }
    
    }
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
    merge_sort(a,n);
    printf("sorted elements are:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

/*
enter no of elements:- 10
enter 1th element:-
10
enter 2th element:-
19
enter 3th element:-
4
enter 4th element:-
6
enter 5th element:-
8
enter 6th element:-
0
enter 7th element:-
5
enter 8th element:-
-1
enter 9th element:-
0
enter 10th element:-
-3
sorted elements are:-
-3 -1 0 0 4 5 6 8 10 19 
*/