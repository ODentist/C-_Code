#include<stdio.h>
#include<stdlib.h>
void BS(int score[],int n);
void K(int score[],int n);
int main ()
{
    int n , sum=0,i;
    int a[80];
    printf("input the number of the numbers(<80)\n");
    scanf("%d",&n);
    for ( i = 0; i <n ; i++)
    {  
    scanf("%d",&a[i]);
    }
     BS(a, n);
     K(a, n);
     system("pause");
}
void BS(int score[], int n)
{
    int flag=0,i=0,j=0,tem=0;
    for ( i = 0; i < n; ++i) 
    {
        flag=0;
    for ( j = 0; j < n-1-i; ++j)
    {
        if (score[j+1]>score[j])
        {   flag=1;
            tem=score[j];
            score[j]=score[j+1];
            score[j+1]=tem;
        }
}
if (flag==0) 
 break;
        } 
 }
void K(int score[],int n)
{
    int i = 0;
	for (i = 0; i < n; ++i) {
		printf("%d ", score[i]);
        printf("\n");  
	}
}