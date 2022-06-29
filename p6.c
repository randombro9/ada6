#include <string.h>
#include <stdio.h>
char str[100],ptn[20];
int res,m,n,len,len1,i,j,k,table[1000];
void main()
{
printf("Enter text \n");
gets(str);
printf("Enter pattern to be found \n");
gets(ptn);
res=horspool(ptn,str);
if(res==-1)
printf("\nPattern was not found\n");
else
printf("Pattern is found at %d position \n",res+1);
}
void shift(char p[])
{
len=strlen(p);
for(i=0;i<1000;i++)
table[i]=len;
for(j=0;j<=len-2;j++)
table[p[j]]=len-1-j;
}
int horspool(char p[], char t[])
{
shift(p);
m=strlen(p);
n=strlen(t);
i=m-1;
while(i<=n-1)
{
k=0;
while(k<=m-1 && (p[m-1-k]==t[i-k]))
k++;
if(k==m)
return i-m+1;
else
i=i+table[t[i]];
}
return -1;
}
