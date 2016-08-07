#include<stdio.h>
#include<stdlib.h>


struct ArrayStack{
	int capacity;
	int top;
	int *array;
};


int isFullStack(struct ArrayStack *S){

	//printf("%d %d\n",S->top,S->capacity );
	if(S->capacity-1<=S->top){
		printf("Stack Full");
		return 1;
	}
	else{
		
		return 0;
	}
}

int isEmptyStack(struct ArrayStack *S){

	//printf("%d %d\n",S->top,S->capacity );
	if(S->top<=-1){
		printf("Stack Empty");
		return 1;
	}
	else{
		
		return 0;
	}
}


void Push(struct ArrayStack *S, int data){

	if(!isFullStack(S)){
		S->array[++S->top]=data;
	}

}

int Pop(struct ArrayStack *S){

	if(!isEmptyStack(S)){
		return S->array[S->top--];
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
	s->top=-1;
	s->array = malloc(sizeof(int)*s->capacity);

	
	return s;
}
int main(){

struct ArrayStack *S = CreateStack();
	
Push(S,20);

printf("%d\n",Pop(S));
printf("%d\n",Pop(S));

DeleteStack(S);

Push(S,21);
printf("%d\n",Pop(S));
return 0;	

}
