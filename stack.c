#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stk[SIZE];
int sp = -1;

void push(int);
int pop(void);
void display(void);

int main(void)
{
    int opt, item;

    do
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\n\nEnter your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter an item: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item = pop();

                if (item != -1)
                    printf("Popped = %d\n", item);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option\n");
        }

    } while (1);

    return 0;
}

/* Function to push an item */
void push(int x)
{
    if (sp == SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }

    stk[++sp] = x;
}

/* Function to pop an item */
int pop(void)
{
    if (sp == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    else
    {
        return stk[sp--];
    }
}

/* Function to display the stack */
void display(void)
{
    int i;

    if (sp == -1)
    {
        printf("Empty stack\n");
    }
    else
    {
        printf("Stack elements:\n");

        for (i = sp; i >= 0; i--)
        {
            printf("%d\n", stk[i]);
        }
    }
}

