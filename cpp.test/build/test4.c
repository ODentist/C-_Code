#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,o=0,e=0;
    printf("Please enter the number:\n");
    scanf("%d",&a);
    if (a==-1)
    {
         printf("over\n");
         printf("The total number of odd is %d\n",o);
         printf("The total number of even is %d\n",e);
         system("pause");
         return 0;
    }
    else
    {
    while (scanf("%d",&a))
    {
             if(a%2==0)
             {
             e=e+1;
             printf("%d:even\n",a);
             }
             else
             {
                o=o+1;
                printf("%d:odd\n",a);
             
            }
            
            }
         }
         }
    
