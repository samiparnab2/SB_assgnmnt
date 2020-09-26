#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
void lcs(char s1[],char s2[])
{
    int i,j,n1=strlen(s1),n2=strlen(s2),mat[n1][n2],x[n2];
    printf("length matrix is:\n");
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(i==0 || j==0)
                mat[i][j]=0;
            else
            {
                if(s1[i]==s2[j])
                    mat[i][j]=mat[i-1][j-1]+1;
                else
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    j=n2-1;
    i=n1-1;
    while(mat[i][j]!=0)
    {
        if(s1[i]==s2[j] && mat[i][j]>mat[i-1][j-1])
        {
            x[j]=1;
            j--;
            i--;
        }
        else
        {
            x[j]=0;
            if(mat[i-1][j]>mat[i][j-1])
                i--;
            else
                j--;
        }   
    }
    printf("\nselection matrix is ");
    for(i=1;i<n2;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\nlength of the largest substr is %d",mat[n1-1][n2-1]);
    printf("\nthe substring is : ");
    for(i=1;i<n2;i++)
    {
        if(x[i]==1)
            printf("%c ",s2[i]);
    }
}
void main()
{
    char s1[30],s2[30];
    int n;
    s1[0]='0';
    s2[0]='0';
    printf("enter 1st string ");
    gets(&s1[1]);
    printf("enter 2nd string ");
    gets(&s2[1]);
    lcs(s1,s2);
}
/*
stone
longest
*/