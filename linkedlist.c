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

	while(1)
	{
		printf("\n\nLinkedlist Menu:\n");
		printf(" 1. Add element\n");
		printf(" 2. Print List\n");
		printf(" 3. Exit\n");
		printf("Enter your choice: ");
		int num   = 0;
		int value = 0;
		scanf("%d", &num);
		switch(num)
		{
			case 1:
			printf("Enter a value: ");
			scanf("%d", &value);
			if (head == NULL)
			{
				head = createNode(value);
				break;
			}
			append(head, value);
			break;
			
			case 2:
			printlist(head);
			break;
			
			default:
			printlist(head);
			free(head);
			exit(0);
			break;
		}
	}

	
	return 0;
}
