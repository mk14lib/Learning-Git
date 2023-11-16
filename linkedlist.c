#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* createNode(int);
void append(struct node*, int);
void printlist(struct node*);

struct node* createNode(int value)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void append(struct node* head, int value)
{
	struct node* newNode = createNode(value);
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		struct node* temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next; 
		}
		temp->next = newNode;
	}
}

void printlist(struct node* head)
{
	struct node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

int main()
{
	struct node* head = NULL;
	head = createNode(10);
	append(head, 16);
	append(head, 18);
	printlist(head);
	return 0;
}
