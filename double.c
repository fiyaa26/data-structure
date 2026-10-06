#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *sp = NULL;

struct node *insert(struct node *, int);
struct node *deleted(struct node *, int *);
void display(struct node *);
int search(struct node *, int);

int main()
{
    int opt, data, found;

    for (;;)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);

                sp = insert(sp, data);
                break;

            case 2:
                if (sp == NULL)
                {
                    printf("Stack is empty!\n");
                }
                else
                {
                    sp = deleted(sp, &data);
                    printf("Deleted element is %d\n", data);
                }
                break;

            case 3:
                display(sp);
                break;

            case 4:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);

                found = search(sp, data);

                if (found != 0)
                    printf("The element is found at position %d\n", found);
                else
                    printf("Not found\n");

                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* Function to insert an element */
struct node *insert(struct node *sp, int data)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return sp;
    }

    temp->data = data;
    temp->prev = NULL;
    temp->next = sp;

    if (sp != NULL)
    {
        sp->prev = temp;
    }

    sp = temp;

    return sp;
}

/* Function to delete an element */
struct node *deleted(struct node *sp, int *x)
{
    struct node *temp;

    if (sp != NULL)
    {
        temp = sp;
        *x = sp->data;

        sp = sp->next;

        if (sp != NULL)
        {
            sp->prev = NULL;
        }

        free(temp);
    }

    return sp;
}

/* Function to display elements */
void display(struct node *sp)
{
    if (sp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    while (sp != NULL)
    {
        printf("%d\n", sp->data);
        sp = sp->next;
    }
}

/* Function to search an element */
int search(struct node *sp, int data)
{
    int position = 1;

    while (sp != NULL)
    {
        if (sp->data == data)
        {
            return position;
        }

        sp = sp->next;
        position++;
    }

    return 0;
}

