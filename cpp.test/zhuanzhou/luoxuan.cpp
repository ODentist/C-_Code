#include<iostream>
using namespace std;
void print(int k,int a[50][50]);
void luoxuan(int k,int a[50][50])
{	
    while (k)
	{
		if (k % 2 == 0)
		{
			k = k - 1;

			int x = k / 2, y = k / 2;
			int n = 0;
			int N = 1;
			int i = x;
			int j = y + 1;

			a[x][y] = N++;

			while (1)
			{
				n++;

				if (n + x > k- 1)
					break;

				for (; i <= x + n; i++)
					a[i][j] = N++;
				i--;
				j--;

				for (; j >= y - n; j--)
					a[i][j] = N++;
				j++;
				i--;

				for (; i >= x - n; i--)
					a[i][j] = N++;
				i++;
				j++;

				for (; j <= y + n; j++)
					a[i][j] = N++;
			}

			k++;

			for (int i = 0; i < k; i++)
			{
				a[i][k - 1] = N++;
			}

			for (int j = k - 2; j >= 0; j--)
			{
				a[k - 1][j] = N++;
			}
		}
		else
		{
			int x = k / 2, y = k / 2;
			int n = 0;
			int N = 1;
			int i = x;
			int j = y + 1;

			a[x][y] = N++;

			while (1)
			{
				n++;

				if (n + x > k - 1)
					break;

				for (; i <= x + n; i++)
					a[i][j] = N++;
				i--;
				j--;

				for (; j >= y - n; j--)
					a[i][j] = N++;
				j++;
				i--;

				for (; i >= x - n; i--)
					a[i][j] = N++;
				i++;
				j++;

				for (; j <= y + n; j++)
					a[i][j] = N++;
			}
		}
        print(k,a);
		cin >> k;
	}
}
void print(int k,int a[50][50])
{
    		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
				cout << a[i][j] << "   ";
			cout << endl;
		}
}
int main()
{
	int k;
    int a[50][50] = { 0 };
	cin >> k;
luoxuan(k,a);

	return 0;
}
