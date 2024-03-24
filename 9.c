//swap pair of elements in a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(){
    struct Node *ptr, *New;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->next = NULL;
    head = New;
    ptr = New;
    printf("Enter data: ");
    scanf("%d", &New->data);

    int num, n=0;
    while(n!=1){
        printf("Do you want to add another node?(1/0): " );
        scanf("%d", &num);
        if(num==1){
            New = (struct Node *)malloc(sizeof(struct Node));
            New->next = NULL;
            printf("Enter data: ");
            scanf("%d", &New->data);
            ptr->next = New;
        }
        else{
            n++;
        }        
    }
}

void display(){
    struct Node *ptr=head;
    printf("Output:");
    while(ptr!=NULL){
        printf(" %d", ptr->data);
        ptr=ptr->next;
    }
}

void swap_alt(){
    struct Node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = ptr1->next;
    while(ptr1->next!=NULL){
        struct Node *temp;
        temp->data = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp->data;

        ptr1 =  ptr1->next;
        ptr2 = ptr1->next;
    }
}

int main(){
    create();
    swap_alt();
    display();
    return 0;
}
