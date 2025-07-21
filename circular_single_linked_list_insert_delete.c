#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;  
};
// Delete at Beginning
void delete_at_beg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = *head, *last = *head;

    // Only one node
    if (temp->next == temp) {
        free(temp);
        *head = NULL;
        return;
    }

    // Find last node
    while (last->next != *head)
        last = last->next;

    last->next = temp->next;
    *head = temp->next;
    free(temp);
}

// Delete at End
void delete_at_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = *head, *prev = NULL;

    // Only one node
    if (temp->next == temp) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Delete at a Specific Position
void delete_at_position(struct node **head, int pos) {
    if (*head == NULL || pos <= 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (pos == 1) {
        delete_at_beg(head);
        return;
    }

    struct node *temp = *head;
    int count = 1;

    // Traverse to (pos-1) node
    while (count < pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    // If position is out of range
    if (temp->next == *head || count != pos - 1) {
        printf("Position out of range.\n");
        return;
    }

    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}
void insert_at_beg(struct node**head,int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;


    if(*head==NULL)
    {
        newnode->next=newnode;
        *head=newnode;
    }
    else
    {
        struct node *temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        newnode->next=*head;
        temp->next=newnode;
        *head=newnode;
    }

}
void insert_at_end(struct node**head,int value){
      struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL) {
        newnode->next = newnode;
        *head = newnode;
    } else {
        struct node *temp = *head;

        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = *head;
    }


}
void insert_at_n_position(struct node **head,int value,int position){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    // Insert at beginning if position is 1
    if (position == 1) {
        insert_at_beg(head,value);
    }

    // Insert at position > 1
    struct node *temp = *head;
    int i = 1;
    while (i < position - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    // If position is greater than the number of nodes + 1
    if (i != position - 1) {
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;


}
void display(struct node *head)

{
    struct node *temp;
    if(head==NULL)
    {
       
        printf("Circular single linked list is empty\n");
        return ;
    }
    temp=head;
    printf("Circular single linked list\n");
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("--Back to head node \n");
}
int main()
{
    struct node *head=NULL;
    insert_at_beg(&head,1);
    insert_at_end(&head,2);
    insert_at_end(&head,3);
    insert_at_end(&head,4);

    insert_at_end(&head,5);
    insert_at_n_position(&head,6,6);
    insert_at_end(&head,7);
    insert_at_end(&head,8);
    insert_at_end(&head,9);

/////////////////////////////


    display(head);

}