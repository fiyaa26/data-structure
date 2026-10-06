#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};
struct node *sp=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *,int *);
void display(struct node *);
int search(struct node *,int);
int main()
{
int opt,data,found;
for(;;)
{
printf("\n1.Push\n2.Pop\n3.display\n4.Search\n5.Exit\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
  case 1:
       printf("Enter element to insert:");
       scanf("%d",&data);
       sp=push(sp,data);
       break;
  case 2:
       if(sp==NULL)
       {
       printf("stack is empty!\n");
       }
       else
       {
       sp=pop(sp,&data);
       printf("popped element is %d\n",data);
       }
       break;
  case 3:
        display(sp);
        break;
  case 4:
       printf("Enter the element to be searched :");
       scanf("%d",&data);
       found=search(sp,data);
       
       if(found !=0)
       printf("The element in found at position %d\n",found);
       else
       printf("Not found\n");
       break;
  case 5:
      exit(0);
}
}
return 0;
}
//function to insert an element in singly linked list struct node * push(struct node *,p,int data)
struct node *push(struct node *sp,int data)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=sp;
sp=temp;
return sp;
}
//Function to remove an element from singly linked list struct node *pop9struct node 8 sp,int* x)
struct node *pop(struct node *sp, int *x)
{
struct node *temp;
if(sp != NULL)
{
temp=sp;
*x=sp->data;
sp=sp->next;
free(temp);
}
return sp;
}
//Function to display element of singly linked list void display(struct node * sp)
void display(struct node *sp)
{
if(sp==NULL)
{
printf("stack is empty\n");
return;
}
printf("stack element are :\n");
while(sp !=NULL)
{
printf("%d\n",sp->data);
sp=sp->next;
}
}
//Function to search elements in singly linked list int search (struct node * sp,int data)
int search(struct node *sp,int  data)
{
int position =1;
while(sp !=NULL)
{
if(sp->data==data)
{
return position;
}
sp=sp->next;
position++;
}
return 0;
}


       
       
