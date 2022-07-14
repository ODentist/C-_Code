#include<iostream>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n;//输入n阶幻方的阶数
    
    while(n!=0)
    {
        int i,j;
        int a[101][101];
        cin>>x>>y;
        if((x==n-1)&&(y==n/2))
    {

    for ( i = 0; i <= n+1; i++)
    {
        for ( j = 0; j <=1+ n; j++)
        {
            if(0<=i&&i<n&&0<=j&&j<n)
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=1;
            }   
        }
    }
    a[x][y]=1;
for ( int i = 2; i <= n*n; i++)
{
    if (x==1&&y==n)x=2;
    else
    {
        x++,y++;
        if (x==n&&y==n)
        {
              x-=2;
            y--;
        }
        
        if(x>=n&&y!=n) x=0;
        if(y>=n) y=0;
        if (a[x][y]>0)
        {
            x-=2;
            y--;
        }
    }
    a[x][y]=i;
}
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
    else
    {
        x++;
    for ( i = 1; i <= n+1; i++)
    {
        for ( j = 0; j <1+ n; j++)
        {
            if(1<=i&&i<=n&&0<=j&&j<n)
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=1;
            }   
        }
    }
    a[x][y]=1;
for ( int i = 2; i <= n*n; i++)
{
    if (x==1&&y==n)x=2;
    else
    {
        x--,y++;
        if (x==0&&y==n)
        {
              x++;
            y-=2;
        }
        
        if(x<1&&y!=n) x=n;
        if(y>=n) y=0;
        if (a[x][y]>0)
        {
            x++;
            y-=2;
        }
    }
    a[x][y]=i;
}
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <n; j++){
            cout<<a[i][j]<<" ";
        }
        printf("\n");
    }


    }
      x=0,y=0,i=0,j=0;
        cin>>n;//输入n阶幻方的阶数
    
}
   system("pause");
    return 0;
}