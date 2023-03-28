#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int data)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 30; i++)
    {
        int rand_num = rand() % 100 + 1;
        push(rand_num);

        if(rand_num % 2 == 1)
        {
            int popped_value = pop();
            if (popped_value != -1)
            {
                printf("Pop: %d\n", popped_value);
            }
        }

        printf("Push: %d\n", rand_num);
    }

    return 0;
}