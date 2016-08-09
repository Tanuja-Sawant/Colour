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

void InsertNode(struct Node **head,int data,int index){
	if(index==0)	
	{

	}

	struct Node *L=CreateNode(data);
	int i=0;
	for(i=0;i<index-1;i++){
		*head=(*head)->next;
		printf("%d",index);
	}
	L->next=(*head)->next;
	(*head)->next=L;

}

int get(struct Node **head,int index){

	int i=0;
	for(;i<index;i++){
		*head=(*head)->next;
	}
	return (*head)->data;

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
	
	InsertNode(&L,3,1);
	InsertNode(&L,30,1);
	InsertNode(&L,30,1);
	
	
	
	printf("%d",lsize(L));


	return 0;
}