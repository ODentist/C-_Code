#include<iostream>
#include<ctime>
using namespace std;
const int MaxSize = 100;
class TextArry {
private: int length;
		 int a[MaxSize];
public:
    TextArry()
	{
		length=0;
	}
	TextArry(int x[MaxSize],int n)
{
	for (int i = 0; i < n;i++)
	{
		a[i] = x[i];
		length++;
	}
}
  void print()
  {
	  for (int i = 0; i < length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "the line of the length is "<<length<<endl;
  }
  int Find(int s)
	{
		for (int i = 0; i < length; i++)
		{
			if (a[i]==s)
			{
				cout<<"the number is NO."<<i+1<<endl;
				return 1;
					}
	}
	return 0;
	}
	void Insert(int i, int x)
	{
		if (length==MaxSize)throw"up full out ";
		if (i<1 || i>length+1) throw"inserter the wrong side";
		for ( int j = length; j >= i; j--)
			a[j]=a[j-1];
			a[i-1]=x;
			length++;		
	}
	void Delete(int i)
	{
		if(length==0)throw"down full out";
		if(i<1 ||i>length)throw "delete wrong side";
		int x=a[i-1];
		for ( int j = i; j < length; j++)
		{
			a[j-1]=a[j];
		}
		length--;
		cout<<"deleted"<<x<<endl;
	}
};
void Found(int x[], int n) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) 
	{
		x[i] = rand() % 101;
		cout <<  x[i] <<" ";
	}
	cout<<endl;
    cout<< "find the number"<<endl;
}
int main()
{
	int x[MaxSize], s, n=10;
    int a,b,c;
	cout<<"the length of the number"<<endl;
	cin>>n;//自己输入x数组的个数
	Found(x ,n);
	TextArry R(x,n);//调用数组x与x数组的个数
	while(1)
	{
		cin>>s;
		if(R.Find(s))
		{
			cout<<"the number has been found"<<endl;
			break;
		}
		else
		{
			cout<<"the number is not in the line , please search agin "<<endl; 
		}
	}
	cout<<"inserter the side and the number"<<endl;
	cin>>a>>b;
	R.Insert(a,b);
	R.print();
	cout<<"select the delete the side of the number"<<endl;
	cin>>c;
	R.Delete(c);
	R.print();
	system("pause");
	return 0;
}