#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	//int *top;
	struct ListNode *next;
};

struct ListNode *CreateListNode(int data){
	struct ListNode *L= malloc(sizeof(struct ListNode));
	L->next=NULL;
	L->data=data;
	return L;
}


int getElement(struct ListNode *top, int index){


	for(int i=0;i<index;i++){
		top = top->next;
	}

	return top->data;
}


void InsertNode(struct ListNode *top, int data, int index){

	if(index==0){
		return;
	}
	for(int i=0;i<index-1;i++){
		top=top->next;
	}
	struct ListNode *node = CreateListNode(data);
	node->next=top->next;
	top->next=node;
	
}

void InsertInLinkedList(struct ListNode** head, int data, int index){
	
		struct ListNode *newNode= CreateListNode(data);
	if(index==0){
		newNode->data=data;
		newNode->next=*head;
		*head=newNode;
	}	
	else{
		struct ListNode *p;
		p=*head; 
		for(int i=0;i<index-1;i++){
			*head=(*head)->next;
		}
		struct ListNode *node = CreateListNode(data);
		node->next=(*head)->next;
		(*head)->next=node;
	}


}


void DeleteInLinkedList(struct ListNode** head,int index){
	
	
	if(index==0){
		
	}	
	else{
		struct ListNode *p;
		p=*head; 
		for(int i=0;i<index-1;i++){
			*head=(*head)->next;
		}
		(*head)->next=((*head)->next)->next;
	}


}


struct ListNode *InsertAtHead(struct ListNode *top,int data, int index){
	struct ListNode *node = CreateListNode(data);
		node->next=top;
		node->data=data;
		top=node;
		return node;
}

int Head(struct ListNode *top){
	if(!top)
			return 0;
	return top->data;
}

int ListLength(struct ListNode *head){
	if(!head)	
		return 0;
	int count = 1;
	while(head->next){
		head=head->next;
		count++;
	}
	return count;
}

void DeleteList(struct ListNode *top){
	if(top)
		while(top->next){
			struct ListNode *temp=top;
			top=top->next;
			free(temp);
		}
	}


int main(){

	struct ListNode *l=CreateListNode(3);

	InsertNode(l,2,1);
	InsertNode(l,4,2);
	InsertNode(l,28,1);
	InsertNode(l,67,1);
	printf("%d\n",getElement(l,1));
	DeleteInLinkedList(&l,1);
	printf("%d\n",getElement(l,1));
	//struct ListNode *p;
	//	p=**l;
	InsertInLinkedList(&l,23,0);
	printf("%d",getElement(l,1));
	
	return 0;
}