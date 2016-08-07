#include<stdio.h>
#include<stdlib.h>


struct ArrayQueue{
	int capacity;
	int head;
	int tail;
	int *array;
	int num;
};






int isFullQueue(struct ArrayQueue *Q){

	//printf("%d %d\n",S->top,S->capacity );
	if(Q->num==Q->capacity){
		printf("Stack Full");
		return 1;
	}
	else{
		
		return 0;
	}
}

int isEmptyQueue(struct ArrayQueue *Q){

	//printf("%d %d\n",S->top,S->capacity );
	if(Q->num==0){
		printf("Stack Empty");
		return 1;
	}
	else{
		
		return 0;
	}
}


void Enqueue(struct ArrayQueue *Q, int data){

	if(!isFullQueue(Q)){
		Q->array[++Q->tail%Q->capacity]=data;
		Q->num++;
		//printf("%d \n",Q->num);
	}
}

int Dequeue(struct ArrayQueue *Q){
	
	if(isEmptyQueue(Q))
		//printf("%d",isEmptyQueue);
		return NULL;
	Q->num--;
	return Q->array[Q->head++%Q->capacity];

	
}


struct ArrayQueue *CreateQueue(){

	struct  ArrayQueue *q = malloc(sizeof(struct ArrayQueue));

	q->capacity=10;
	q->head=0;
	q->tail=-1;
	q->num=0;
	q->array = malloc(sizeof(int)*q->capacity);

	
	return q;
}

int main(){

	struct ArrayQueue *Q = CreateQueue();

	//printf("%d \n",Dequeue(Q));
	Enqueue(Q,1);
	Enqueue(Q,2);
	Enqueue(Q,3);
	Enqueue(Q,4);
	printf("%d \n",Dequeue(Q));
	printf("%d \n",Dequeue(Q));
	Enqueue(Q,5);
	Enqueue(Q,6);
	printf("%d \n",Dequeue(Q));
	printf("%d \n",Dequeue(Q));
	Enqueue(Q,7);
	Enqueue(Q,8);
	Enqueue(Q,9);
	Enqueue(Q,10);
	Enqueue(Q,20);
	Enqueue(Q,30);
	Enqueue(Q,40);

	for(int i=0;i<10;i++){
		printf("A %d \n",Q->array[i]);
	}
	
	


}

	