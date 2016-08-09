#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *CreateNode(int data){
	struct Node *L=malloc(sizeof(struct Node));
	if(!L)
		return NULL;
	L->data= data;
	L->next=NULL;
	return L;
}

struct Node *CircularLL(int data){
	struct Node *L = CreateNode(data);
	L->next=L;
}

void DeleteNode(struct Node **head,int index){

	if(index==0)	
	{

	}
	int i;
	struct Node *temp = *head;
	for(i=0;i<index-1;i++){
		temp=temp->next;	
	}

	struct Node * temp2 = (temp)->next;
	(temp)->next=(temp)->next->next;
	free(temp2);


}

void InsertNode(struct Node **head,int data,int index){
	if(index==0)	
	{

	}

	int i;
	struct Node *L=CreateNode(data);
	struct Node *temp = *head;
	for(i=0;i<index-1;i++){
		temp=temp->next;	
	}
	L->next=temp->next;
	temp->next=L;

}

int get(struct Node *head,int index){

	int i=0;
	for(;i<index;i++){
		head=(head)->next;
	}
	return (head)->data;

}

int lsize(struct Node *head){

	struct Node *temp= head;
	int i=0;
	while(head->next!=temp){
		i++;
		head=head->next;
	}
	return i+1;
}

int main(){
	struct Node *L=CircularLL(10);

	int i=0;
	

	
	InsertNode(&L,3,1);
	InsertNode(&L,4,1);
	InsertNode(&L,5,3);
	InsertNode(&L,6,3);
	DeleteNode(&L,3);
	
	for(i=0;i<lsize(L);i++){
		printf("%d %d\n",get(L,i),i);
	}


	return 0;
}