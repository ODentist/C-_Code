#include<iostream>
using namespace std;
const int MaxSize=100;
void sort (int x[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (x[j]>x[j+1])
            {
                int temp =x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a[MaxSize];
        int j=0;
        int count=0;
        cin>>a[j];
        while (a[j]!=0)
        {
            j++;
            cin>>a[j];
        }
            for (int i = 0;i < j - 1;j--) {
            sort(a,j);
			a[0] = a[0] + a[1];
			count = count + a[0];
			for (int i = 1;i <j-1;i++)
            {
                a[i]=a[i+1];
            }
    }
    cout<<count<<endl;
    }
system("pause");
return 0;
}