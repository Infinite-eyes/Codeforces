#include "stdio.h"
void PrintColumn(int y){
	//列数为0，除尽
	if(y){
		//递归打印  
		PrintColumn((y-1)/26);
		putchar(65+(y-1)%26);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n,x,y;
	char s[64],*p;
	scanf("%d ",&n);
	while(n--){
		gets(s);
		if(sscanf(s,"%*c%d%*c%d",&x,&y)==2)
		{
				//为RXCY计数系统
				//打印字母列
				PrintColumn(y);
				//打印数字行
				printf("%d\n",x);
		}
		else{
				//	C    R
				// 字母  数字 计数系统
				for(x=0,p=s;*p>64;++p)
					//列字母转化成数字
					x=x*26 + *p - 64;
				
				printf("R%sC%d\n",p,x);
			}	
	}
	return 0;
}