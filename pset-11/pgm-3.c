#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
typedef struct Stack_s
{
    short top;
    short limit;
    short item[MAX_STACK_SIZE];

    bool (*pop)(struct Stack_s *const stack, short *const value);
    bool (*push)(struct Stack_s *const stack, const short value);
    void (*print)(const struct Stack_s *const stack);
} Stack;

bool StackPop(struct Stack_s *const stack, short *const value);
bool StackPush(struct Stack_s *const stack, const short value);
void PrintStack(const struct Stack_s *const stack);

int main()
{
    srand(time(0));
    Stack myStack =
        {
            .top = 0,
            .pop = StackPop,
            .push = StackPush,
            .print = PrintStack};

    printf("Enter the stack size:");
    scanf("%hu", &myStack.limit);

    printf("=intial=\n");
    myStack.print(&myStack);

    while (myStack.push(&myStack, rand() % 10000))
        ;
    printf("=populated=\n");
    myStack.print(&myStack);

    short value;
    int temp = myStack.top / 2;
    for (int i = 0; i < temp && myStack.pop(&myStack, &value); i++)
    {
        printf("1. Popped: %d\n", value);
    }

    printf("=midway=\n");
    myStack.print(&myStack);

    while (myStack.push(&myStack, rand() % 10000))
        ;
    printf("=repopulated=\n");
    myStack.print(&myStack);

    while (myStack.pop(&myStack, &value))
    {
        printf("2. Popped: %d\n", value);
    }
    printf("=final=\n");
    myStack.print(&myStack);

    return 0;
}

bool StackPop(struct Stack_s *const stack, short *const value)
{
    if (stack->top != 0)
    {
        *value = stack->item[stack->top];
        stack->top--;

        return true;
    }
    return false;
}
bool StackPush(struct Stack_s *const stack, const short value)
{
    // short length = sizeof(stack->item) / sizeof(stack->item[0]);
    // if (length == stack->limit)
    if (stack->top != stack->limit)
    {
        stack->item[stack->top] = value;
        stack->top++;
        return true;
    }
    return false;
}
void PrintStack(const struct Stack_s *const stack)
{
    printf("===============\n");
    printf("Stack.top=%hd limit=%hd\n\n", stack->top, stack->limit);
    if (stack->top == 0)
    {
        printf("===============\n");
        return;
    }

    for (short i = 0; i < stack->limit; i++)
    {
        if (i % 10 == 0 && i != 0)
        {

            printf("  %hd\n", stack->item[i]);
        }
        else
        {
            printf("  %hd", stack->item[i]);
        }
    }
    printf("\n\n===============\n");
}