#include<stdio.h>
#include<stdlib.h>
Charf(char ch,int x,int y);
int main()
{ 
  int a,b;
  char c,t;
  printf("input a charicter:");
  printf("input tow number:");
  scanf("%c%d%d",&c,&a,&b);
  t=Charf(c,a,b);
  printf("%c",t);
  system("pause");
  return 0;
}
Charf(char ch,int x,int y)
{
int n=1,m=1;
for(n=1;n<=x;n++)
{
for(m=1;m<=y;m++)         
{
   if(n==1||n==x||m==1||m==y)         
   printf("%c",ch);
   else
   printf(" ");
}
printf("\n"); 
}
return 0;
}