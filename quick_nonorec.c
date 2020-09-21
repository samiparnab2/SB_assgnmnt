#include<stdio.h>
#define MAX_STACK_SIZE 20
struct position
{
    int start,end;
};
struct position stack[MAX_STACK_SIZE];
int top=-1;
void push(struct position p)
{
    if(++top>=MAX_STACK_SIZE)
        return;
    stack[top]=p;
}
struct position pop()
{
    struct position q;
    if(top==-1)
    {
        q.start=0;
        q.end=0;
        return q;
    }
    return stack[top--];
}
int isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
void quick_sort(int p[],int start,int end)
{
    struct position pe,pf;
    pe.start=start;
    pe.end=end;   
    push(pe);
    int i,j,temp;
    while(isEmpty()==0)
    {
        pe=pop();
        if(pe.start>=pe.end)
            continue;
        i=pe.start+1;
        j=pe.end;
        while(i<=j)
        {
            while(p[i]<p[pe.start])
            {
                if(j<i)
                    break;
                i++;
            }
            while(p[j]>=p[pe.start])
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
        temp=p[pe.start];
        p[pe.start]=p[j];
        p[j]=temp;
        pf.start=pe.start;
        pe.start=j+1;
        pf.end=j-1;
        push(pe);
        push(pf);
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
    a[n]=2147483648;
    quick_sort(a,0,n-1);
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
-4
enter 4th element:-
5
enter 5th element:-
6
enter 6th element:-
-2
enter 7th element:-
0
enter 8th element:-
3
enter 9th element:-
6
enter 10th element:-
7
sorted elements are:-
-4 -2 0 3 5 6 6 7 10 19
*/