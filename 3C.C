#include <stdio.h>
int i;
char a[9];
bool t(char c,int i){
	
	if(a[3*i]==c&&a[3*i+1]==c&&a[3*i+2]==c
				||a[i]==c&&a[i+3]==c&&a[i+6]==c
						||a[0]==c&&a[4]==c&&a[8]==c
							||a[2]==c&&a[4]==c&&a[6]==c)
		return true;		
	else 
			return false;	
			
}


int main(){
	
	int wo=0,wx=0,co=0,cx=0;

	for(i=0;i<9;i++){
 		scanf("%c",&a[i]);
		if(a[i]=='\n'){
			i--;
			continue;
		}
		if(a[i]=='0')
			co++;
		if(a[i]=='X')
			cx++;
	}
	for(i=0;i<3;i++){
		if(t('0',i))
		wo=1;
		if(t('X',i))
		wx=1;
	}
	if((wx&&cx!=co+1)||(wo&&cx!=co)||(cx!=co+1&&cx!=co))
		printf("illegal");
	else if(wx)		
		printf("the first player won");
	else if(wo) 
		printf("the second player won");
	else if(cx+co==9) 
		printf("draw");	
	else if(cx==co)	
		printf("first");
	else 
		printf("second");
			
	return 0;
	
}