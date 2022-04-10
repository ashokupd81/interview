#include<stdio.h>
#include<stdlib.h>

 struct node{
	int data;
	struct node *next;
};


struct node * get_new_node(int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = NULL;

	return temp;

}

/* This function add node at the end of the linklist */
void add_node_list(struct node **head, int data){
	static struct node *prev = NULL;
	/* If list has already some nodes */
	if(*head != NULL){
		/*move prev pointer as node increase*/
		prev->next = get_new_node(data);
		prev = prev->next;
	}
	else{
		*head = get_new_node(data);
		prev = *head;
	}
}

/* This function print the linklist */

void print_list(struct node *head){
	while(head != NULL){
		printf("%d\t",head->data);
		head = head->next;
	}

}

void sumoflist(struct node *head){
	struct node *temp = head;
	struct node *cur = head;
	int sum  = 0 ;
	while(cur != NULL)
	{
		if(cur->data != 0){
			sum = sum  + cur->data;
			cur = cur->next;
		}
		else{
			temp->data = sum;
			/* Before free the node make the link from head node to  -> next node of aftre first 0
			 * that might 0 again no problem.
			 */
			temp->next = cur->next;
			/* cur point to next node after 0*/
			cur = temp->next;
			/* make next node as first node now*/
		       	temp = temp->next;
	       		sum = 0;
		}
	}
}



int main (){
	struct node *head = NULL;
	char ch;
	int num;
	do {
		printf("Enter the new node value\n");
		scanf("%d",&num);
		add_node_list(&head, num);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');
	print_list(head);
	sumoflist(head);
	printf("\n");
	print_list(head);
}
