#include<stdio.h>
#include<malloc.h>
#include<limits.h>
struct node
{
	int data;
	struct node *next;
};
int linear_search_linked_list(struct node *head,int to_search)
{
	struct node *temp;
	temp=head;
	int flag=0;
	int pos=1;
	while(temp!=NULL)
	{
		if(temp->data==to_search)
			{flag=1;
				break;
			}
			temp=temp->next;
			pos++;
	}
	//free (temp); implicit
	if(flag==1)
	return pos;
	else
	return flag;	
}
main()
{
	
	struct node *head;
	head=(struct node*)malloc(sizeof(struct node));
	
	head->next=NULL;
	//printf("\nEnter the linked list elements(%d to exit and enter atleat one element): ",INT_MAX);
	
	printf("\nEnter the linked list elements(-9999 to exit and enter atleat one element): ");
	
	struct node *temp;
	int flag=0;
	while(1)
	{
		int entered_data;
		scanf("%d",&entered_data);
		if(entered_data==-9999)
			break;
		if(flag==0)
		{
			head->data=entered_data;
			temp=head;
			flag=1;
		}
		else
		{
			struct node* j=(struct node*)malloc(sizeof(struct node));
			j->data=entered_data;
			j->next=NULL;
			temp->next=j;
			temp=j;
			//free (j); implicit
		}
	}
	printf("Enter the number to search : ");
	
	int to_search;
	scanf("%d",&to_search);
	
	int pos=linear_search_linked_list(head,to_search);
	if(pos>=1)
		printf("Given number is present in the linked list at pos: %d\n",pos);
	else printf("Given number is not in the linked list\n");
	
	
}
