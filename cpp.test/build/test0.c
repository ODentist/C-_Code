#include <stdio.h>
int Func(int n);
int main()
{
    int n,ret;
    printf("Input n:");
    scanf("%d",&n);
    ret = Func(n);
    if(ret == -1)printf("Input error!\n");
    else
    {
        printf("%d\n",ret);
    }
    return 0;
}

int Func(int n)
{
    int max = 100;
    if(n < 1000 || n > 1000000) return -1;
    else
    {
        for(int i = 100;i <= 999; i++)
        {
            if(n % i == 0)max = i;
        }
        return max;
    }
}