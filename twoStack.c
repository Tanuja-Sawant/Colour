#include<stdio.h>
#include<stdlib.h>


struct ArrayStack{
	int capacity;
	int top1;
	int top2;
	int *array;
};


int isFullStack(struct ArrayStack *S){

	//printf("%d %d\n",S->top,S->capacity );
	if(S->top1 +1 >=S->top2){
		printf("Stack Full");
		return 1;
	}
	else{
		
		return 0;
	}
}

int isEmptyStack1(struct ArrayStack *S){

	//printf("%d %d\n",S->top,S->capacity );
	if(S->top1<=-1){
		printf("Stack Empty");
		return 1;
	}
	else{
		
		return 0;
	}
}
int isEmptyStack2(struct ArrayStack *S){

	//printf("%d %d\n",S->top,S->capacity );
	if(S->top2>=S->capacity){
		printf("Stack Empty");
		return 1;
	}
	else{
		
		return 0;
	}
}


void Push1(struct ArrayStack *S, int data){

	if(!isFullStack(S)){
		S->array[++S->top1]=data;
	}

}

int Pop1(struct ArrayStack *S){

	if(!isEmptyStack1(S)){
		return S->array[S->top1--];
	}
	return NULL;

}

void Push2(struct ArrayStack *S, int data){

	if(!isFullStack(S)){
		S->array[--S->top2]=data;
	}

}

int Pop2(struct ArrayStack *S){

	if(!isEmptyStack2(S)){
		return S->array[S->top2++];
	}
	return NULL;

}

void DeleteStack(struct ArrayStack *S){
	if(S){
		if(S->array){
			free(S->array);
		}
		free(S);
	}
	
}
/*
Pop

Push

isEmptyStack()

isFullStack()

void DeleteStack(struct ArrayStack *S){
	if
}

*/


struct ArrayStack *CreateStack(){

	struct  ArrayStack *s = malloc(sizeof(struct ArrayStack));

	s->capacity=3;
	s->top1=-1;
	s->top2=s->capacity;

	s->array = malloc(sizeof(int)*s->capacity);

	
	return s;
}
int main(){

struct ArrayStack *S = CreateStack();
Push1(S,0);
Push2(S,2);
Push1(S,1);
	printf("%d \n", Pop1(S));

	printf("%d \n", Pop1(S));
	printf("%d \n", Pop2(S));
return 0;	

}
