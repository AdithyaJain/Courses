#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int n;
	struct node* prev;
	struct node* next;
} node;

void makeLinkList(node** head, node** tail, int first);
void push(node** head, node** tail, int n);

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++) scanf("%d",&a[i]);

	node* head=(node*)malloc(sizeof(node*));
	node* tail=(node*)malloc(sizeof(node*));
	makeLinkList(&head, &tail, a[0]);
	
	for(i=1; i<n; i++)
		push(&head, &tail, a[i]);
	
	node* temp=(node*)malloc(sizeof(node*));
	for(temp=head; (temp->next)!=NULL; temp=temp->next)
		printf("%d ",temp->n);
	printf("%d\n",tail->n);
	return 0;
}

void makeLinkList(node** head, node** tail,  int first)
{
	(*head)->n=first;
	(*head)->prev=NULL;
	(*head)->next=NULL;
	(*tail)=(*head);
}
void push(node** head, node** tail, int n)
{
	node* temp=(node*)malloc(sizeof(node*));
	(*tail)->next=temp;
	temp->prev=(*tail);
	temp->n=n;
	temp->next=NULL;
	(*tail)=temp;
	if((*head)->next==NULL) (*head)->next=temp;
	if((*tail)->prev==NULL) (*tail)->prev=(*head);
}
