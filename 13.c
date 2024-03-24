#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create(){
    int n;
    printf("Enter the No. of Nodes: ");
    scanf("%d", &n);
    struct node *temp = NULL;
    for (int i = 0; i < n; i++){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    temp->next = head;
    head->prev = temp;
    printf("\n");
}

void insert(){
    struct node * temp;
    struct node * new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &new->data);
    while (temp -> next != head)
        temp = temp -> next;
    temp -> next = new;
    new -> prev = temp;
    temp -> next -> next = head;
    temp -> next -> next -> prev = temp -> next;
}


void forwarddisplay(){
    struct node *ptr = head;
    while (ptr->next != head){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
}

void backwarddisplay(){
    struct node * ptr = head;
    while (ptr-> prev != head){
        ptr = ptr->prev;
        printf("%d ", ptr->data);
    }
    printf("%d", ptr->prev->data);
}


int main(){
    create();

    forwarddisplay();
    printf("\n");
    backwarddisplay();
    
    insert();

    forwarddisplay();
    printf("\n");
    backwarddisplay();

    return 0;
}
