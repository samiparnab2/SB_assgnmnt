#include<stdlib.h>
#include<stdio.h>
struct node
{
char ch;
int fr;
struct node *lchild,*rchild;
};
struct node *stack[27]={NULL};
int freq[26]={0},m=0;
char code[26]={'\0'},c;
void swap(struct node **p,struct node **q)
{
struct node *t;
t=*p;
*p=*q;
*q=t;
}
void readfreq(FILE *f)
{
while((c=fgetc(f))!=EOF)
if(c>=97 && c<=122)
freq[c%97]++;
}
void freq_to_stack()
{
char d=96;
int i;
for(i=0;i<26;i++)
{
d++;
if(freq[i]!=0)
{
m++;
stack[m]=(struct node *)malloc(sizeof(struct node));
stack[m]->ch=d;
stack[m]->fr=freq[i];
}
}
}
void minheapinsert(struct node *key)
{
int i,p;
m++;
stack[m]=key;i=m;
while(i>1)
{
p=i/2;
if(stack[i]->fr<stack[p]->fr)
{
swap(&stack[i],&stack[p]);
i=p;
}
else
return;
}
}
void heapify(int i)
{
int l,r,small;
l=2*i;
if(l<=m && stack[l]->fr<stack[i]->fr)
small=l;
else
small=i;
r=l+1;
if(r<=m && stack[r]->fr<stack[small]->fr)
small=r;
if(i!=small)
{
swap(&stack[small],&stack[i]);
heapify(small);
}
}
void buildheap()
{
int i;
for(i=m/2;i>=1;i--)
heapify(i);
}
struct node *build_huffman_tree()
{
struct node *root,*t,*p,*q;
buildheap();
while(m>1)
{
root=(struct node *)malloc(sizeof(struct node));
swap(&stack[1],&stack[m]);
p=stack[m--];
heapify(1);
swap(&stack[1],&stack[m]);
q=stack[m--];
heapify(1);
root->fr=(p->fr)+(q->fr);
root->lchild=p;
root->rchild=q;minheapinsert(root);
}
return root;
}
void traversal(struct node *rt,int i)
{
if(rt->lchild==NULL && rt->rchild==NULL)
{
printf("\n%c- %d- %s",rt->ch,rt->fr,code);
i=0;
return;
}
else
{
code[i]='0';
code[i+1]='\0';
traversal(rt->lchild,i+1);
code[i]='1';
code[i+1]='\0';
traversal(rt->rchild,i+1);
}
}
int main(int argc,char *argv[])
{
FILE *fp;
int i;
struct node *root;
fp=fopen(argv[1],"r+");
readfreq(fp);
freq_to_stack();
printf("the frequency of each character and corresponding huufman code\n");
root=build_huffman_tree();
traversal(root,0);
}