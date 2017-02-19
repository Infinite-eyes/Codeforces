#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//使用链表统计
typedef struct History
{
	int score;
	int round;
	struct History *next;
}History;

struct History *create_history(int score,int round){
	
	struct History *history =malloc(sizeof(struct History));
	history->score=score;
	history->round=round;
	return history;
}


void destory_history(struct History *history){
	if(history->next!=NULL)
		destory_history(history->next);
	free(history);
}


typedef struct Element{
	char name[33];
	int score;
	struct Element *next;
	struct History *history_curr;
	struct History *history_first;
}Element;

struct Element *create_element(char *name, int score)
{
	struct Element *element =malloc(sizeof(struct  Element));
	strncpy(element->name,name, 33);
	element->score=score;
	element->history_curr=NULL;
	element->history_first=NULL;
	return element;
}
void destory_element(struct Element *element){
	if(element->next!=NULL)
		destory_element(element->next);
	free(element);
}
typedef struct Node{
	char c;
	struct Element *element;
	struct Node **next;
}Node;

struct Node *create_node(char c){
	struct Node *node =malloc(sizeof(struct Node));
	node->c=c;
	node->next=calloc(26,sizeof(struct Node));
	node->element=NULL;
	return node;
}

void destroy_node(struct Node *node)
{
	int i;
	if(node == NULL)
		return ;
	for(i=0;i<26;i++)
	destroy_node(node->next[i]);
	
	free(node->next);
	free(node);
	return ;
};

int main()
{
	/* code */
	int n;
	scanf("%d",&n);
	//过滤回车
	getchar();

	struct Node *root = create_node('!');

	Element *first = NULL;
	Element *curr = NULL;
	Element *last = NULL;

	int round=0;

	while(n--){

		struct Node *elem=root;
		int c;
		int score;
		char name[33];
		int i=0;

		while((c=getchar())!=' '){
			if(c=='\n') continue;
			name[i]=c;
			c-='a';
			if(elem->next[c]==NULL){
				elem->next[c]=create_node(c);
			}
			elem=elem->next[c];
			i++;
		}
		name[i]='\0';
		scanf("%d",&score);
		getchar();

		if(elem->element==NULL){
			elem->element=create_element(name, 0);
			if(first==NULL){
				first=elem->element;
				last=elem->element;
			}else{
				last->next=elem->element;
				last=last->next;	 
			}
		}
		curr=elem->element;
		curr->score+=score;

		History *ne=create_history(curr->score,round);
		if(curr->history_first==NULL){
			curr->history_first=ne;
		}else{
			curr->history_curr->next=ne;
		}
		curr->history_curr=ne;

		round++;
	}


	curr=first->next;
	Element *winner=first;

	int max_score=winner->score;
	while(curr!=NULL){
		if(winner->score < curr->score){
			winner=curr;
			max_score=winner->score;
		}else{
				if(winner->score == curr->score)
				{
					int w_round=round ;
					int c_round=round ;

					History *hcurr = winner->history_first;
					while(hcurr!=NULL){
						if(hcurr->score>=max_score){
							w_round=hcurr->round;
							break;
						}
						hcurr = hcurr->next;
					}
					hcurr=hcurr->next;
				

					hcurr=curr->history_first;
					while(hcurr!=NULL)
					 {
						if(hcurr->score>=max_score){
							c_round=hcurr->round;
							break;
						 }
						 hcurr=hcurr->next;
					  }

					  if(c_round<w_round)
					  	winner=curr;
					}
			}
			curr=curr->next;
		}

		printf("%s", winner->name);

//		destory_history(first->history_first);
		destory_element(first);
		destroy_node(root);

	return 0;
}