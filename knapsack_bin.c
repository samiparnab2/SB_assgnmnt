#include<stdio.h>
void knapsack_bin(int totalWeight,int profit[],int weight[],int noOfItem)
{
    int row=noOfItem+1,col=totalWeight+1,mat[row][col],new,i,j,x[row];
    printf("the matrix is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==0 || j==0)
            {
                mat[i][j]=0;
            }
            else
            {
                if(weight[i]<=j)
                {
                    new=profit[i]+mat[i-1][j-weight[i]];
                    if(new>mat[i-1][j])
                    {
                        mat[i][j]=new;
                        new=0;
                    }
                    else
                        mat[i][j]=mat[i-1][j];
                }
                else
                    mat[i][j]=mat[i-1][j];
            }
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("selection array is:\n");
    j=col-1;
    for(i=row-1;i>0;i--)
    {
        if(mat[i][j]>mat[i-1][j])
        {
            x[i]=1;
            j-=weight[i];
        }
        else
            x[i]=0;
        printf("%d ",x[i]);
    }
    printf("\b\b\b\nand the total profit will be %d",mat[noOfItem][totalWeight]);
}

void main()
{
    int i,j,n;
    int weight[20],profit[20],totalWeight;
    printf("enter no of elements");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("enter weight for element %d ",i);
        scanf("%d",&weight[i]);
        printf("enter profit for element %d ",i);
        scanf("%d",&profit[i]);
    }
    printf("eneter maximum weight that can be carried");
    scanf("%d",&totalWeight);
    knapsack_bin(totalWeight,profit,weight,n);
}

/*
4
3
2
4
3
6
1
5
4
8
*/