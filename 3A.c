#include <stdio.h>
main(){

	int x,y;
	char x1,y1,x2,y2,h,v;

	scanf("%c%c",&x1,&y1);
 	getchar();
	scanf("%c%c",&x2,&y2);

	x=x2-x1;
	y=y2-y1;

	h=((x<0)?x=-x,'L':'R');//确定方向
	v=((y<0)?y=-y,'D':'U');
	printf("%d\n",x>y?x:y);
	while(x|y){
		if(x)x--,putchar(h);
		if(y)y--,putchar(v);
		printf("\n");
	}
}