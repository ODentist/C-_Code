#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxsize = 100;
struct BigNumber
{
    int d[maxsize];
    int length;
BigNumber()
{
    memset(d,0,sizeof(d));
    length=0;
}
};
void Numbermutilp(string x,string y)
{
	int i=0;
	int j=0;
		int a[maxsize] = { 0 };
		int b[maxsize] = { 0 };
		int c[2 * maxsize] = { 0 };
			for (i = x.length() - 1, j = 0; i >= 0; i--, j++)
		{
			a[j] = x[i] - '0';
		}
		for (i = y.length() - 1, j = 0; i >= 0; i--, j++)
		{
			b[j] = y[i] - '0';
		}

		for (i = 0; i < x.length(); i++)//计算结果储存
		{
			for (j = 0; j < y.length(); j++)
			{
				c[i + j] += a[i] * b[j];
			}
		}
		i = 0;
		while (i < (x.length() + y.length()))//进位
		{
			if (c[i] > 9)
			{
				c[i + 1] += c[i] / 10;
				c[i] %= 10;
			}
			i++;
		}
		i = x.length() + y.length();
		while (i >= 0 && c[i] == 0)//找出长度
		{
			i--;
		}
				while( i >= 0)//输出
			{cout <<c[i];
				i--;}
};
int main()
{
	string x, y;
	int num;
	cin >> num;
	while (num != 0)
	{
		cin >> x >> y;
		int i = 0;
	 Numbermutilp(x,y);
		cout << endl;
		num--;
		i--;
	}
system("pause");
	return 0;
}