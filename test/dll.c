#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *prev;
	struct node *next;

};

struct node *start = NULL;
struct node *end = NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
void insert_pos();
struct node *insert_end();
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
void delete_pos();
int count();

int main(){

	int option;
	
	do{

		printf("\n\n*******MENU*********");
		printf("\n\n1. CREATE LINKED LIST");
		printf("\n\n2. DISPLAY LINKED LIST");
		printf("\n\n3. INSERT AT BEGINNING(from left to right)");
		printf("\n\n4. INSERT AT END(from left to right)");
		printf("\n\n5. INSERT AT POSITION(from left to right)");
		printf("\n\n6. DELETE FROM BEGINNING(from left to right)");
		printf("\n\n7. DELETE FROM END(from left to right)");
		printf("\n\n8. DELETE FROM A POSITION(from left to right)");
		printf("\n\n9. EXIT");
		printf("\n\nEnter your option : ");
		scanf("%d", &option);
		
		switch (option){
			
			case 1: start = create(start);
					break;

			case 2 : start = display(start);
				 break;

			case 3 : start = insert_beg(start);
				 break;

			case 4 : start = insert_end();
				 break;

			case 5 : insert_pos();
				 break;

			case 6 : start = delete_beg(start);
				 break;

			case 7 : start = delete_end(start);
				 break;

			case 8 : delete_pos();
				 break;

			case 9 : exit(0);
		}

	}while(option < 10);

	return 0;
}

struct node *create(struct node *start){

	struct node *ptr, *newnode;
	int num;
	printf("Enter -1 to end\n");
	printf("\nEnter the data : ");
	scanf("%d", &num);
	while (num != -1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = num;
		newnode->next = NULL;
		newnode->prev = NULL;
		if (start == NULL)
		{
			start = newnode;
			end = newnode;
		}
		else
		{
			ptr = start;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = newnode;
			newnode->prev = ptr;
			end = newnode;
		}
		printf("\nEnter the data : ");
		scanf("%d", &num);
	}
	return start;

}

struct node *display(struct node *start){

	struct node *ptr;

	if (start == NULL)
	{
		printf("\n\nLINKED LIST IS EMPTY");
	}
	else
	{
		ptr = start;
		printf("\n\n\t*****LINKED LIST from left to right*****\n\n");
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}

		ptr = end;
		printf("\n\n\t*****LINKED LIST from right to left*****\n\n");
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->prev;
		}
		
	}
	return start;

}

struct node *insert_beg(struct node *start){

	int num;
	struct node *newnode;
	printf("Enter data to insert at begining : ");
	scanf("%d", &num);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
	start->prev = newnode;
	newnode->next = start;
	start = newnode;
	newnode->prev = NULL;
	return start;

}


struct node *insert_end()
{
	int num;
	struct node *newnode;
	printf("Enter data to insert at end : ");
	scanf("%d", &num);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
	end->next = newnode;
	newnode->next = NULL;
	newnode->prev = end;
	end = newnode;
	return start;
}

void insert_pos()
{
	int cnt, pos, i = 1, data;
	struct node *ptr, *preptr, *newnode;
	ptr = start;
	cnt = count();
	
	printf("Total number of elements in linked list : %d. You can insert new elements based on this count. Position should be from left to right.", cnt);
	printf("\nEnter the position : ");
	scanf("%d", &pos);
	ptr = start;
	if ((cnt >= pos || pos == cnt + 1) && pos != 0)
	{

		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d", &data);
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;

		while (i < pos)
		{
			preptr = ptr;
			ptr = ptr->next;
			i++;
		}

		if (start == ptr)
		{
			newnode->next = ptr;
			start = newnode;
		}
		else
		{
			preptr->next = newnode;
			newnode->prev = preptr;
			newnode->next = ptr;
			ptr->prev = newnode;
		}
	}

	else
	{
		printf("invalid");
	}
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start->next;
	start->prev = NULL;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr = end;
	end = end->prev;
	end->next = NULL;
	free(ptr);
	return start;
}
void delete_pos()
{

	struct node *ptr, *preptr;
	int pos, i = 1, cnt;
	cnt = count();
	printf("\n\nTotal number of elements in linked list is %d. You can delete element based on this count. Position should be from left to right.", cnt);
	printf("\n\nEnter the position : ");
	scanf("%d", &pos);
	ptr = start;

	if ((cnt >= pos && pos != 0))
	{
		while (i<pos)
		{
			preptr = ptr;
			ptr = ptr->next;
			i++;
		}

		if(start == ptr){
			start = ptr -> next;
			start->prev = NULL;
			free(ptr);
		}
		else{
			preptr -> next = ptr -> next;
			ptr->next->prev = preptr;
			free(ptr);
		}
	}

	else{
		printf("Not Possible");
	}
}

int count()
{
	int count = 0;
	struct node *ptr;
	ptr = start;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}
