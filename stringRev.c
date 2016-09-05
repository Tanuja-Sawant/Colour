#include<stdio.h>
#include<stdlib.h>


struct ArrayStack{
	int capacity;
	int top;
	char *array;
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


void Push(struct ArrayStack *S, char data){

	if(!isFullStack(S)){
		S->array[++S->top]=data;
	}

}

char Pop(struct ArrayStack *S){

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

	s->capacity=40;
	s->top=-1;
	s->array = malloc(sizeof(int)*s->capacity);

	
	return s;
}
int main(){
printf("Enter size of input, soldier!\n");
int n;
scanf("%d", &n);

printf("Enter the string, DARLINNNNNG \n");
char s[n];

//scanf("%s", &s);
//printf("%s", s);

for (int i=0; i<=n;i++){
	scanf("%c",&s[i]);
}

struct ArrayStack *S = CreateStack();


for (int i=0; i<=n;i++){
	Push(S,s[i]);

}

for(int i=0;i<=n;i++){
	printf("%c",Pop(S));
}


return 0;	

}
