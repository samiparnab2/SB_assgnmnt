#include<stdio.h>

int bin_search_rec(int a[],int start,int end,int key)
{
    if(start>end)
        return -1;
    int mid=(start+end)/2;
    if(a[mid]==key)
        return mid;
    else if(key<a[mid])
        bin_search_rec(a,start,mid-1,key);
    else
        bin_search_rec(a,mid+1,end,key);
}
void main()
{
    int a[20],n,key,pos,i;
    printf("enter no of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter %dth element\n",i+1);
        scanf("%d",&a[i]);
    }
    printf("enter element to search");
    scanf("%d",&key);
    pos=bin_search_rec(a,0,n-1,key);
    if(pos!=-1)
        printf("%d is in %dth position",key,pos);
    else
    printf("%d is not found",key);
    
}


/*
enter no of elements: 4
enter 1th element
1
enter 2th element
2
enter 3th element
3
enter 4th element
4
enter element to search1
1 is in 0th position


enter no of elements: 4
enter 1th element
1
enter 2th element
2
enter 3th element
3
enter 4th element
4
enter element to search5
5 is not found
*/

