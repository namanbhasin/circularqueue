#include<stdio.h>
#include<stdlib.h>
#define maxq 5
typedef struct que{
	int data[maxq];
	int front,rear;
}que;
void addq(que *,int);
int delq(que *);
void display(que);
int main()
{
	que q1;
	q1.front=q1.rear=-1;
	int ch,item;
	do
	{
		printf("1. ADDQ\n2. DELQ\n3. DISPLAY\n4. EXIT\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter item you want to add\n");
				scanf("%d",&item);
				addq(&q1,item);
				break;
			case 2:
				item=delq(&q1);
				if(item!=0)
					printf("The deleted item is %d\n",item);
				break;
			case 3:
				display(q1);
				break;
		}
	}while(ch!=4);
	return 0;
}
void addq(que *q1,int item)
{
	if(q1->rear==maxq-1 && q1->front==0 || q1->rear+1==q1->front)
	{
		printf("Overflow\n");
		return;
	}
	if(q1->front==-1)
	{
		q1->front=q1->rear=0;
	}
	else if(q1->front!=0 && q1->rear==maxq-1)
	{
		q1->rear=0;
	}
	else
	{
		q1->rear++;
	}
	q1->data[q1->rear]=item;
}
int delq(que *q1)
{
	int item;
	if(q1->front==-1)
	{
		printf("Underflow\n");
		return 0;
	}
	item=q1->data[q1->front];
	if(q1->front==q1->rear)
	{
		q1->front=q1->rear=-1;
	}
	else if(q1->front==maxq-1)
	{
		q1->front=0;
	}
	else
	{
		q1->front++;	
	}
	return item;
}
void display(que q1)
{
	int i;
	printf("Queue is ");
	if(q1.front==-1)
	{
		printf("empty\n");
		return;
	}
	else 
	{
		if(q1.front<=q1.rear)
		{
			for(i=q1.front;i<=q1.rear;i++)
			{
				printf("%d\t",q1.data[i]);
			}	
		}
		else
		{
			for(i=q1.front;i<maxq;i++)
				printf("%d\t",q1.data[i]);
			for(i=0;i<=q1.rear;i++)
				printf("%d\t",q1.data[i]);
		}
	}
	printf("\n");
}
