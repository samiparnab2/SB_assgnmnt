#include<stdio.h>
void merge(double p[][2],int start,int mid,int end)
{
    double a[end-start+1][2];
    int i,j,k=0;
    i=start;
    j=mid+1;
    while(i<=mid && j<=end)
    {
        if(p[i][0]<=p[j][0])
        {
            a[k][0]=p[i][0];
            a[k][1]=p[i][1];
            i++;
            k++;
        }
        else
        {
            a[k][0]=p[j][0];
            a[k][1]=p[j][1];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k][0]=p[i][0];
        a[k][1]=p[i][1];
        i++;
        k++;
    }
    while(j<=end)
    {
        a[k][0]=p[j][0];
        a[k][1]=p[j][1];
        j++;
        k++;
    }
    k=0;
    for(i=start;i<=end;i++)
    {
        p[i][0]=a[k][0];
        p[i][1]=a[k][1];
        k++;
    }
}
void merge_sort(double p[][2],int start,int end)
{
    int mid;
    if(start>=end)
        return;
    mid=(start+end)/2;
    merge_sort(p,start,mid);
    merge_sort(p,mid+1,end);
    merge(p,start,mid,end);
}

void knapsack(double totalWeight,double profit[],double weight[],int noOfItem)
{
    int i,j;
    double pbw[20][2],x[20],totalProfit=0;
    for(i=0;i<noOfItem;i++)
    {
        pbw[i][0]=profit[i]/weight[i];
        pbw[i][1]=i;
        x[i]=0;
    }
    merge_sort(pbw,0,noOfItem-1);
    i=noOfItem-1;
    while(totalWeight>0 && noOfItem>i)
    {
        if(weight[(int)pbw[i][1]]<=totalWeight)
        {
            x[(int)pbw[i][1]]=1;
            totalWeight-=weight[(int)pbw[i][1]];
        }
        else
        {
            x[(int)pbw[i][1]]=(double)totalWeight/weight[(int)pbw[i][1]];
            totalWeight=0;
        }
        i--;
    }
    printf("portions of weights of items are:-");
    for(i=0;i<noOfItem;i++)
    {
        totalProfit+=profit[i]*x[i];
        printf("(%g*%g)",weight[i],x[i]);
    }
    printf("total profit made %lf",totalProfit);
}
void main()
{
    int i,j,n;
    double weight[20],profit[20],totalWeight;
    printf("enter no of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter weight for element %d ",i+1);
        scanf("%lf",&weight[i]);
        printf("enter profit for element %d ",i+1);
        scanf("%lf",&profit[i]);
    }
    printf("eneter maximum weight that can be carried");
    scanf("%lf",&totalWeight);
    knapsack(totalWeight,profit,weight,n);
}



/*
7
2
10
3
5
5
15
7
7
1
6
4
18
1
3
15
*/