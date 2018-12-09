#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int array[100];
}Stack;

Stack *init()
{
    Stack *stack = (Stack *) malloc(sizeof(struct Stack));
 
    if (!stack) 
        return NULL;
 
    stack->top = -1;

    if (!stack->array)
        return NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1 ;
}
char top(Stack *stack)
{
    return stack->array[stack->top];
}
char pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int operand(char ch)
{
    return (ch >= '1' && ch <= '9');
}

int importance(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    }
    return -1;
}

int convert(char expression[])
{
    int i, k=-1;

    Stack *stack = init();

    for (i = 0; expression[i]!= '\0'; ++i)
    {

         if (operand(expression[i]))
            expression[++k] = expression[i];  

        else if (expression[i] == '(')
            push(stack, expression[i]);

        else if (expression[i] == ')')
        {        
            while (!isEmpty(stack) && top(stack) != '(')
                expression[++k] = pop(stack);
            pop(stack); 
        }
        
        else
        {
            while (!isEmpty(stack) && importance(expression[i]) <= importance(top(stack)))
                expression[++k] = pop(stack);
            push(stack, expression[i]);
        }

    }

    while (!isEmpty(stack))
        expression[++k] = pop(stack );
 
    expression[++k] = '\0';
    printf( "%s\n", expression );

}

int calculate(char exp[])
{
   
    Stack *stack = init();
    int i;
    
    for (i = 0; exp[i]!='\0'; ++i)
    {

        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
 
        else
        {
            int x = pop(stack);
            int y = pop(stack);

            switch (exp[i])
            {
             case '+': push(stack, y + x); break;
             case '-': push(stack, y - x); break;
             case '*': push(stack, y * x); break;
             case '/': push(stack, y/x);   break;
            }
        }
    }
    return pop(stack);
}

int main(){

	int n;
	char expression[100];

	printf("Enter the expression\n");
	scanf("%s",expression);

	convert(expression);
	int result = calculate(expression);

	printf("%d\n",result);
	return 0;

}