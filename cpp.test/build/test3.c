#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main( )
{	char words[81],message[]="您好，输入的汉字长度为：\n"; 
	int n;
	while(1)
	{   printf("输入一段汉字：");
	    gets(words);
		n=strlen(words)/2;//使用求字符串长度的函数计算
		if(strcmp(words,"结束")==0)
			break;
		else 
			printf("%s%d\n",message,n);
	}       
system("pause");    
return 0;
}
