#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
   int top;
   char items[20];
} Stack;

int main()
{

   char input[20];
   scanf("%s", input);
   reverse(input);
   Prefix(input);
   reverse(input);

   for (int i = 0; i < strlen(input); i++)
   {
      printf("%c", input[i]);
   }
   return 0;
}

int priority(char n)
{
   switch (n)
   {
   case '+':
      return 1;
      break;
   case '-':
      return 1;
      break;
   case '*':
      return 2;
      break;
   case '/':
      return 2;
      break;
   default:
      return 0;
   }
}

void reverse(char input[])
{
   char temp[40];
   
   strcpy(temp, input);

   for (int i = 0; i < strlen(input); i++)
   {
      input[i] = temp[strlen(input) - i - 1];
   }
}

void Prefix(char input[])
{

   Stack *stack = (Stack *)malloc(sizeof(Stack));
   stack->top = -1;

   char ans[20];
   for (int i = 0; i < 20; i++)
   {
      ans[i] = NULL;
   }

   int i = 0;
   int index = 0;

   while (input[i] != '\0')
   {
      if ('0' <= input[i] && input[i] <= '9')
      { // number
         ans[index] = input[i];
         index++;
      }
      else
      { // operand
         while (1)
         {

            if (stack->top == -1)
            {
               push(stack, input[i]);
               break;
            }

            char popout_number = pop(stack);
            int oper_string = priority(popout_number);
            int oper_input = priority(input[i]);

            if (oper_string > oper_input)
            {
               ans[index] = popout_number;
               index++;
               continue;
            }
            else
            {
               push(stack, popout_number);
               push(stack, input[i]);
               break;
            }
         }
      }
      i++;
   }

   while (stack->top != -1)
   {
      ans[index] = pop(stack);
      index++;
   }

   for (int i = 0; i < strlen(input); i++)
   {
      input[i] = ans[i];
   }
   free(stack);
}

void push(Stack *stack, char stackdata)
{
   if (isFull(stack) == 1)
   { // full
      return;
   }

   stack->items[++stack->top] = stackdata;
}

int pop(Stack *stack)
{
   if (isEmpty(stack) == 1)
   { // empty
      return 0;
   }

   return stack->items[stack->top--];
}

int isEmpty(Stack *stack)
{
   if (stack->top == -1)
   {
      return 1;
   }
   return 0;
}

int isFull(Stack *stack)
{
   if (stack->top == MAX - 1)
   {
      return 1;
   }
   return 0;
}
