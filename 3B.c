#include <stdio.h>
#include <stdlib.h>
typedef struct Boat{
	int capacity,id,space;
	float ratio;
}Boat;

int cmp(const void *a,const void *b){
	// if ( (*(Boat*)a).ratio > (*(Boat*)b).ratio )
	// 	return  -1;
	// if ( (*(Boat*)a).ratio < (*(Boat*)b).ratio )
	// 	return  1;	
	// if ( (*(Boat*)a).ratio == (*(Boat*)b).ratio )
	// 	return (*(Boat*)a).space > (*(Boat*)b).space ?1:-1;
		
		return (*(Boat*)a).ratio > (*(Boat*)b).ratio ?-1:1;
	
	
}

Boat boat[100005];
int order[100005];  
int main(){

	int n,v,i,j,k=0,optimal=0,lastKayaks=-1,lastK,edgeKayaks=-1,edgeK,uncheckC=-1,uncheckK=-1,allcapacity=0 ;
	scanf("%d%d",&n,&v);
	for(i=0;i<n;i++){
		boat[i].id=i+1;
		scanf("%d%d",&boat[i].space,&boat[i].capacity);
		if(boat[i].space==1)
			boat[i].ratio=boat[i].capacity/1.0;	
		else
			boat[i].ratio=boat[i].capacity/2.0;
	}
	qsort(boat,i,sizeof(boat[0]),cmp);

	for(j=0;j<i;j++){
		if(v-boat[j].space==0){
			optimal+=boat[j].capacity;
			order[k++]=boat[j].id;
			v-=boat[j].space;
			if(boat[j].space == 1){
				edgeK = k-1;
				edgeKayaks = j;	
			}
		}
		else if(v-boat[j].space>0){
			optimal+=boat[j].capacity;
			order[k++]=boat[j].id;
			v-=boat[j].space;
			if(boat[j].space == 1){
				lastK = k-1;
				lastKayaks = j;	
			}
		}
		else{
				if(uncheckC==-1&&boat[j].space==2) 
					uncheckC = j;  
			}				 
	}
	if(v==0&&edgeKayaks!=-1&&uncheckC!=-1){
		 if(boat[uncheckC].capacity - boat[lastKayaks].capacity - boat[edgeKayaks].capacity  >0){
				order[lastK]=boat[uncheckC].id;
				k--;
				optimal+=boat[uncheckC].capacity - boat[lastKayaks].capacity - boat[edgeKayaks].capacity ;
			}
		
	}
	if(v==1&&lastKayaks!=-1&&uncheckC!=-1){
		 if(boat[uncheckC].capacity - boat[lastKayaks].capacity >0){
				order[lastK]=boat[uncheckC].id;
				optimal+=boat[uncheckC].capacity - boat[lastKayaks].capacity ;
			}
	}
	printf("%d\n",optimal);
	for(i=0;i<k;i++){
		printf("%d ",order[i]);
	}

}


