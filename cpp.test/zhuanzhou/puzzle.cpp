#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct point
{
	int c, d;
}POINT;
int map[100][100] = { 0 };//迷宫
int visited[100][100] = { 0 };//表示是否走过
//入口固定为(1,0),出口固定为(rows-2,cols-1),即(a-2,b-1)
stack<point> road,temp;
int MOVE[4] = { -1,1,0,0 };//上下左右,行操作
int List[4] = { 0,0,-1,1 };//列操作
int a, b;//行数和列数
int flag = 1;
//int stack[10000][2];//栈
int top = 0;//栈顶指针
void fun(int c,int d)
{
		if (c == a - 2 && d == b - 1)
	{
		flag = 0;
		cout << "success" << endl;
		//for (int i = 0; i < top; i++)
			/*cout << stack[i][0] << " " << stack[i][1] << endl;*/
		while (!road.empty())
		{
			point p1 = road.top();
			road.pop();
			temp.push(p1);
		}
		while (!temp.empty())
		{
			point p1 = temp.top();
			temp.pop();
			road.push(p1);
			cout << p1.c << " " << p1.d << endl;
		}
		return;
	}
};
void STAR(int c,int d)
{
	fun(c,d);
	if (c < 0 || c >= a || d < 0 || d >= b)
		return;
		int j=0;
	while (j < 4)
	{
		int move1 = c + MOVE[j];
		int List1 = d + List[j];
		if (!map[move1][List1] && !visited[move1][List1])//下一步是0，而且没有走过,且没有超出迷宫
		{
			visited[move1][List1] = 1;
			POINT.c = move1;
			POINT.d = List1;
			road.push(POINT);
			STAR(move1, List1);
			visited[move1][List1] = 0;
			road.pop();
		}
		j++;
	}
}
int main()
{
	cin >> a >> b;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			cin >> map[i][j];//迷宫初始化
	POINT.c = 1;
	POINT.d = 0;
	road.push(POINT);
	STAR(1, 0);
	if (flag)
		cout << "fail";
		system("pause");
	return 0;
}