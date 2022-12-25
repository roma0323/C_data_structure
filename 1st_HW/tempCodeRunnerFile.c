#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct StackMode
{
	int top;
	unsigned size;
	float *stackdata;
};

struct StackMode *createStackMode(unsigned size)
{
	struct StackMode *stack = (struct StackMode *)malloc(sizeof(struct StackMode));

	if (!stack)
		return NULL;

	stack->top = -1;												 //初始位置設-1
	stack->size = size;												 //設定大小
	stack->stackdata = (float *)malloc(stack->size * sizeof(float)); //設定資料空間

	if (!stack->stackdata)
		return NULL;

	return stack;
}

int isEmpty(struct StackMode *stack)
{
	return stack->top == -1;
}

// char peek(struct StackMode *stack)
// {
// 	return stack->stackdata[stack->top];
// }

float pop(struct StackMode *stack)
{
	if (!isEmpty(stack))
	{
		return stack->stackdata[stack->top--];
	}
	return 0;
}

// it can also be char op
void push(struct StackMode *stack, float op)
{
	//先++再放入 原本位置是0
	
	stack->stackdata[++stack->top] = op;
}

float CalculuatePostfix(char *exp)
{
	struct StackMode *stack = createStackMode(strlen(exp));
	int i;

	if (!stack)
		return -1;

	for (i = 0; exp[i]; ++i)
	{

		if (isdigit(exp[i]))
		{
			push(stack, exp[i] - '0');
			// ascii code 讓他與原本數字一樣
		}

		else
		{
			float val1 = pop(stack);
			float val2 = pop(stack);
			
			switch (exp[i])
			{
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack);
}

int main()
{
	char exp[40] ;
	printf("input number\n");
	scanf("%s", exp);	
	printf("%.2f", CalculuatePostfix(exp));
	return 0;
}
