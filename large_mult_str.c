#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void pad(char p[],char q[])
{
    int n1=strlen(p);
    int n2=strlen(q);
    char tmp[10];
    tmp[0]='\0';
    if(n1>n2)
    {
        for(int i=1;i<=n1-n2;i++)
        {
            strcat(tmp,"0");
        }
        strcat(tmp,q);
        strcpy(q,tmp);
    }   
    else if(n2>n1)
    {
        for(int i=1;i<=n2-n1;i++)
        {
            strcat(tmp,"0");
        }
        strcat(tmp,p);
        strcpy(p,tmp);
    }  
}
int len(long x)
{
    int length=0;
    if(x==0)
        return 1;
    while(x>0)
    {
        x=x/10;
        length++;
    }
    return length;
}

void itoa(char p[],int x)
{
    int i=len(x);
    char res[20];
    res[i]='\0';
    i--;
    if(x==0)
    {
        p[0]='0';
        p[1]='\0';
        return ;
    }   
    while(x>0)
    {
        res[i]=(x%10)+48;
        x=x/10;
        i--;
    }
    strcpy(p,res);
}
void stradd(char x[],char y[])
{
    int c=0,d=0,lx=strlen(x),ly=strlen(y),length;
    char result[20],temp[20];
    lx--;
    ly--;
    if(lx>=ly)
        length=lx;
    else
        length=ly;
    result[length+1]='\0';
    while(lx>=0 && ly>=0)
    {
        c=(x[lx]-48)+(y[ly]-48)+d;
        lx--;
        ly--;
        d=0;
        if(c>9)
        {
            d=1;
            c=c-10;
        }
        result[length]=48+c;
        length--;
    }
    while(lx>=0)
    {
        c=(x[lx]-48)+d;
        lx--;
        d=0;
        if(c>9)
        {
            d=1;
            c=c-10;
        }
        result[length]=48+c;
        length--;
    }
    while(ly>=0)
    {
        c=(y[ly]-48)+d;
        ly--;
        d=0;
        if(c>9)
        {
            d=1;
            c=c-10;
        }
        result[length]=48+c;
        length--;
    }
    if(d!=0)
    {
        x[0]='1';
        strcpy(&x[1],result);
        return ;
    }
    strcpy(x,result);
    return ;
}


void strsub(char x[],char y[])
{
    int c=0,d=0,lx=strlen(x),ly=strlen(y),length;
    char result[20],temp[20];
    
    lx--;
    ly--;
    length=ly;
    if(lx>ly)
        length=lx;
    else if(ly>lx)
        length=ly;
    result[length+1]='\0';
    while(lx>=0 && ly>=0)
    {
        c=(x[lx]-48)-(y[ly]-48)-d;
        lx--;
        ly--;
        d=0;
        if(c<0)
        {
            d=1;
            c=c+10;
        }
        result[length]=48+c;
        length--;
    }
    while(lx>=0)
    {
        c=(x[lx]-48)-d;
        lx--;
        d=0;
        if(c<0)
        {
            d=1;
            c=c+10;
        }
        result[length]=48+c;
        length--;
    }
   /* while(ly>=0)
    {
        c=(y[ly]-48)+d;
        ly--;
        d=0;
        if(c<0)
        {
            d=1;
            c=c+10;
        }
        result[length]=48+c;
        length--;
    }*/
    lx=0;
    while(result[lx]=='0')
    lx++;
    if(d!=0)
    {
        x[0]='1';
        strcpy(&x[1],result);
        return ;
    }
    strcpy(x,&result[lx]);
    return ;
}

void large_mult(char p[],char q[],char res[])
{
    pad(p,q); 
    int length=strlen(p),lb2,fill,i;
    char c0[20],c1[20],c2[20],px[20],py[20],qx[20],qy[20];
    lb2=length/2;
    if(strlen(p)==1 && strlen(q)==1)
    {
         itoa(res,atoi(p)*atoi(q));
         return;
    }
    strncpy(px,p,lb2);
    px[lb2]='\0';
    strncpy(py,&p[lb2],length-lb2);
    py[length-lb2]='\0';
    strncpy(qx,q,lb2);
    qx[lb2]='\0';
    strncpy(qy,&q[lb2],length-lb2);
    qy[length-lb2]='\0';
    large_mult(px,qx,c0);
    large_mult(py,qy,c2);
    stradd(px,py);
    stradd(qx,qy);
    large_mult(px,qx,c1);
    //printf("\n%s %s %s",c0,c1,c2);
    strsub(c1,c0);
    strsub(c1,c2);
    if(length&1==1)
        strcat(c1,"0");
    while(length--)
    {
        strcat(c0,"0");
    }
    while(lb2--)
    {
        strcat(c1,"0");
    }
    //printf("\n%s %s %s",c0,c1,c2);
    stradd(c0,c1);
    stradd(c0,c2);
    strcpy(res,c0);
    i=0;
    while (res[i]=='0')
        i++;
    strcpy(res,&res[i]);
    return ;
}
void main()
{
    char a[20],b[20],c[20];
    for(int i=0;i<20;i++)
    {
        a[i]='\0';
        b[i]='\0';
        c[i]='\0';
    }
    printf("enter 1st no. ");
    scanf("%s",a);
    printf("enter 2nd no. ");
    scanf("%s",b);
    large_mult(a,b,c);
    printf("result=%s",c);
}