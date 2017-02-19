#include <stdio.h>
typedef long long int64; 
int main()
{
	
	int n,m,a;
	int64 stonesX,stonesY;
	
	while(scanf("%d %d %d",&n,&m,&a)!=EOF){		
		stonesX = n > a ? (n+a-1)/a : 1;
		stonesY = m > a ? (m+a-1)/a : 1; 
		printf("%I64d\n",stonesX*stonesY); 
		
	}
	return 0; 
}