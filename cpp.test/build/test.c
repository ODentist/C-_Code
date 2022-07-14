#include <stdio.h>
#include<stdlib.h>
#include <math.h>
void printArray(int a[], int n) {
	int i = 0;
	for (i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void bubbleSort1(int a[], int n) {
	int i = 0;
	int j = 0;
	int tmp = 0;
	int flag = 0; 
	for (i = 0; i < n; ++i)
{		flag = 0;
		for (j = 0; j < n - 1 - i; ++j)
        {
			if (a[j] < a[j + 1]) 
            {
				flag = 1;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
                }
		}
		if (flag == 0) 
        {break;}
	}	
}
int main() {
	int n,i;
    int a[n];
    printf("input the number of the numbers");
    scanf("%d",&n);
    for ( i = 1; i <=n ; i++)
    {
        scanf("%d",&a[i]);
    }
	printArray(a, n);
	bubbleSort1(a, n);
	printArray(a, n);
	system("pause");
    return 0;
}
    












