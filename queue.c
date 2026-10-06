#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int Q[SIZE];
int front = 0, rear = 0;

void enqueue(int);
int dequeue(void);
void display(void);

int main(void) printf("\n1. enqueue\n2.dequeue\n3.display\n4.exit\n");
{
    int opt, item;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Deleted value = %d\n", item);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option!\n");
        }

    } while (1);

    return 0;
}

/* Function to insert an item into a circular queue */
void enqueue(int x)
{
    int temp;

    temp = (rear + 1) % SIZE;

    if (temp == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = temp;
        Q[rear] = x;
    }
}

/* Function to delete an item from a circular queue */
int dequeue(void)
{
    if (front == rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        front = (front + 1) % SIZE;
        return Q[front];
    }
}

/* Function to display the queue */
void display(void)
{
    int i;

    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The queue elements are:\n");

        i = (front + 1) % SIZE;

        while (i != (rear + 1) % SIZE)
        {
            printf("%d\n", Q[i]);
            i = (i + 1) % SIZE;
        }
    }
}

