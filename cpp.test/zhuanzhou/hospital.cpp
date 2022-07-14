#include<limits.h>
#include<string.h>
#include<iostream>
using namespace std;
const int MaxSize= 200;
void The_Shortest_Road(int b[MaxSize][MaxSize],int Leave_center[MaxSize], int n)
{
	int i=0,j ,k=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (b[j][i] + b[i][k] < b[j][k])
				{
					b[j][k] = b[j][i] + b[i][k];
				}
			}
		}
	}
int m=0;
	while ( m < n)
	{
		Leave_center[j] = b[0][m];
		int i=1;
		while ( i < n)
		{
			if (Leave_center[m] < b[i][m])
				Leave_center[m] = b[i][m];
				i++;
		}
		m++;
	}
	return;
}
void REMAKE(int b[MaxSize][MaxSize],int n)
{
		for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <n; j++)
		{
			 b[i][j];
		}
	}
}

void LEAVE_CENTER(int Leave_center[MaxSize], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (Leave_center[i] == 10000)
		{
			Leave_center[i] = -1;
		}
		cout << Leave_center[i] << ' ';
	}
}
int main()
{
	int n;//村庄数量
	cin >> n;
	int a[MaxSize][MaxSize], b[MaxSize][MaxSize], Leave_center[MaxSize];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == -1)
			{
				b[i][j] = 10000;
			}
			else b[i][j] = a[i][j];
		}
	}
    REMAKE(b,n);
	The_Shortest_Road(b, Leave_center,n);
    REMAKE(b,n);
	LEAVE_CENTER(Leave_center, n);
    system("pause");
	return 0;
}
