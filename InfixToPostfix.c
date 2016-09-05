#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ArrayStack{
	int capacity;
	int top;
	char *array;
};

int com(char a,char b){

}

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
		//printf("Stack Empty");
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

char Top(struct ArrayStack *S){

	if(!isEmptyStack(S)){
		return S->array[S->top];
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


struct ArrayStack *CreateStack(){

	struct  ArrayStack *s = malloc(sizeof(struct ArrayStack));

	s->capacity=30;
	s->top=-1;
	s->array = malloc(sizeof(int)*s->capacity);

	
	return s;
}

int infix2po(char * infix){

	struct ArrayStack *S = CreateStack();

	for(int i=0;i<strlen(infix);i++){
		if(infix[i]!='+' && infix[i] != '*' && infix[i]!='-' && infix[i] != '/' && infix[i] != '(' && infix[i] != ')'){
			printf("%c",infix[i]);
		}
		else{

			if(infix[i] != '(' && infix[i] != ')' ){
				Push(S,infix[i]);
				if(Top(S)=='*' || Top(S)=='/'){
					if(infix[i+1]!='('){
						printf("%c",infix[++i]);	
						printf("%c",Pop(S));
					}
					else{
						i=infix2po(infix+i+2);
					}
				}
			}
			else{
				if(infix[i]=='('){
					
					i=infix2po(infix+i+1);
				/*	while(1==1){
					if(infix[i]==')'){
						
						return i+1;
						break;
					}
					i++;
					}   */
				}
				else{
					return i+1;
					break;
				}

			}
		}
	}

	while(!isEmptyStack(S)){
	printf("%c",Pop(S));
	}


}


int main(){



printf("Input Infix");
printf("\n");
char infix[100];



scanf ("%[^\n]%*c", infix);
printf("\n");


infix2po(infix);




return 0;	

}
