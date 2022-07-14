#include<iostream>
using namespace std;

int main()
{
	int a[50][50] = { 0 };

	int num;
	cin >> num;
	while (num)
	{
		if (num % 2 == 0)
		{
			num = num - 1;

			int x = num / 2, y = num / 2;
			int n = 0;
			int N = 1;
			int i = x;
			int j = y + 1;

			a[x][y] = N++;

			while (1)
			{
				n++;

				if (n + x > num - 1)
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

			num++;

			for (int i = 0; i < num; i++)
			{
				a[i][num - 1] = N++;
			}

			for (int j = num - 2; j >= 0; j--)
			{
				a[num - 1][j] = N++;
			}
		}
		else
		{
			int x = num / 2, y = num / 2;
			int n = 0;
			int N = 1;
			int i = x;
			int j = y + 1;

			a[x][y] = N++;

			while (1)
			{
				n++;

				if (n + x > num - 1)
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

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
		cout<<endl;
		cin >> num;
	}
system("pause");
	return 0;
}
