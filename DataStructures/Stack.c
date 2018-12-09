#include<stdio.h>
#define MAXSIZE=100

typedef struct{

	int top;
	int arr[MAXSIZE];
	void init();
	int pop();
	int push();
	int current();
}stack;

void init(stack st){

	st->top=-1;

	}

int push(stack st,int val){

	if(st->top<MAXSIZE)
		st->arr[++st->top]=val;
	else return -1;

}

int pop(stack st){

	if(st->top>=0)
		st->top--;
	else return -1;
}

int current(stack st){

	return st->arr[st->top];
}

int main(){

	stack->init;
	stack->pop(st);
	stack->push(st,3);
	stack->push(st,4);
	stack->pop(st);
	(stack->pop==-1)?printf("Stack is full\n"):printf("%d\n",stack->current);
}