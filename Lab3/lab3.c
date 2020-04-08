#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* fi;
FILE* fo;
typedef struct Stack{
	int* key;
	int top;
	int max_stack_size;
}Stack;

void Push(Stack* S,int X);
int Pop(Stack *S);
int Postfix(Stack* S, char input_str);
void DeleteStack(Stack* S);

Stack* CreateStack(int max){
	Stack* S = NULL;
	S = (Stack*)malloc(sizeof(struct Stack));
	S->key = (int*)malloc(sizeof(int)*max);
	S->top = -1;
	return S;
}

void main(int argc, char* argv[]){
	fi = fopen(argv[1],"r");
	fo = fopen(argv[2],"wt");
	Stack* stack;
	char input_str[101];
	int max,i=0,a,b,result;

	fgets(input_str,101,fi);
	max = 10;
	stack = CreateStack(max);
	
	fprintf(fo, "Top numbers : ");

	for(i=0;i<strlen(input_str)&&input_str[i]!='#';i++){
		result = Postfix(stack, input_str[i]);
	}

	fprintf(fo, "\nevaluation result : %d\n",result);
	fclose(fi);
	DeleteStack(stack);
}
void Push(Stack* S,int X){
	if(S->top > 8){
		fprintf(fo,"error, stack is full\n");
		return;
	}
	(S->top)++;
	S->key[S->top]=X;
	return;
}
int Pop(Stack* S){
	if(S->top < 0){
		fprintf(fo,"error, there is nothing in stack\n");
		return -1;
	}
	return S->key[S->top--];
	
}
int Postfix(Stack* S,char input_str){
	if(input_str=='+'){
		int a = Pop(S);
		int b = Pop(S);
		Push(S,b+a);
		fprintf(fo,"%d ",S->key[S->top]);
		return S->key[S->top];
	}
	else if(input_str=='-'){             
                int a = Pop(S);
                int b = Pop(S);
                Push(S,b-a);    
		fprintf(fo,"%d ",S->key[S->top]);
		return S->key[S->top];
        }
	else if(input_str=='*'){
                int a = Pop(S);
                int b = Pop(S);
                Push(S,b*a);
		fprintf(fo,"%d ",S->key[S->top]);
		return S->key[S->top];
        }
	else if(input_str=='/'){
                int a = Pop(S);
                int b = Pop(S);
                Push(S,b/a);
		fprintf(fo,"%d ",S->key[S->top]);
                return S->key[S->top];
        }
	else if(input_str=='%'){
                int a = Pop(S);
                int b = Pop(S);
                Push(S,b%a);
		fprintf(fo,"%d ",S->key[S->top]);
                return S->key[S->top];
        }
	else{
		int a = input_str-'0';
		Push(S,a);
		fprintf(fo,"%d ",S->key[S->top]);
		return S->key[S->top];
	}
	
}
void DeleteStack(Stack* S){
	S->top=-1;
	free(S->key);
	free(S);
}
