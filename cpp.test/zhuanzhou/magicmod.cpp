#include<iostream>
using namespace std;
const int MaxSize=100;
int a[MaxSize][MaxSize];
void get_magicsquares(int n)
{

    if(n % 2 == 0) return; //如果是偶数，终止函数
    int i,j;
cin>>i>>j;
i++;
j++;
    a[i][j] = 1;
    for(int value = 2; value <= (n)*(n); value++)
	{
		if(a[n][n/2+1]==1)
		{
        i += 1;     //当前元素，放在之前元素的xia一行，you侧一列，有如下几种特殊情况
        j += 1;
        if(i < 1 && j > n)
		{ //如果当前元素在you xia角则，存放在前一元素tong一lie shang一列
            j -= 1;
            i -= 2;
        }
		else
		{
            if(i > n)
			{     // 如果当前元素是第n行，则将其放在di一行，前一元素右侧一列
                i = 1;
            }
            if(j > n)
			{      //如果当前元素是最右的一列，则放在第一列，前一元素上一行
                j = 1;
            }
        }
        if(a[i][j] == 0)
		{   //如果在原来的位置上有值则放在前一元素shang一行，同一列
            a[i][j] = value;
        }
		else
		{ 
			a[i][j] = value;
           i-=2;
		   j-=1;
	      a[i][j] = value;
        }
    
	}
    for(int i = 1; i <= n; i++)
	{
        for(int j = 1; j <= n; j++)
		{  cout<<a[i][j]<<" ";
			if (j==n+1)
			{
				cout<<endl;
			}
		}
        printf("\n");
    }


}
}

int main()
{
    int n;
    cin>>n;
    get_magicsquares(n);
	system("pause");
	return 0;
}