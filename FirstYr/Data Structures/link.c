#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} node;


void insert(node* head)
{
	int n,pos,i;
	printf("Enter no. to be inserted and what its position should be: ");
	scanf("%d%d",&n,&pos);
	
	node *ins, *prev;
	ins=(node*)malloc(sizeof(node));
	ins->data=n;

	if(pos==0)
	{
		ins->next=head;
		head=ins;
	}
	else
	{
		prev=head;
		for(i=0; i<pos-1; i++) prev=prev->next;

		node *next;
		next=prev->next;
		prev->next=ins;
		ins->next=next;
	}
}

int main()
{
	int num,i;
	printf("Enter num of entries: ");
	scanf("%d",&num);
	node *temp,*head,*last;

	//Scanning and creating list
	for(i=0; i<num; i++)
	{
		temp=(node*)malloc(sizeof(node));
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(i>0) last->next=temp;
		if(i==0) head=temp;	
		last=temp;	
	}
	insert(head);
	//Printing
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		printf("%d",temp->data);
	}
	printf("%d\n",temp->data);

	return 0;
}
