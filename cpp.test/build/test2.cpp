#include<stdio.h>
#include<stdlib.h>
int main()
{ int fun (int s[],int m, int below[]);
  int i,n,below[9];
  int s[9]={10,20,30,40,50,60,70,80,90};
  for ( i = 0; i < 9; i++)
     printf("%d ",s[i]);
  n=fun(s,9,below);
  printf("\ncount=%d\n",n);
  printf("Below the average score are:");
  for ( i = 0; i < n; i++)
    printf("%d ",below[i]);  
  system ("pause");
}
int fun (int s[],int m, int below[])
{
   int h,i,j,k=0;
    s[i]=below[i]; 
   for ( i = 0; i < 9; i++)
    k+=s[i];
   j=k/9;
   for(i=0;i<9;i++)
   {if (s[i]<j)
   {h++;  below[i]=s[i];}}
   printf("%d\n",h);
   return h;
}