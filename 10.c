//circular queue using linkedlist
//Perform all the operations of circular queue using linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void create(){
    struct Node *new, *ptr;
    int i = 0;
    char ch;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    new->next = head;
    head = new;
    ptr = head;
    fflush(stdin);

    while (i != 1){
        printf("Do you want to add another element(Y/N): ");
        scanf("%c", &ch);
        fflush(stdin);
        if (ch == 'Y' || ch == 'y'){
            new = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter next value: ");
            scanf("%d", &new->data);
            new->next = head;
            ptr->next = new;
            ptr = new;
            fflush(stdin);
        }
        else
            i = 1;
    }
}

void traverse(){
    struct Node *ptr;
    ptr = head;
    printf("The list is:");
    do{
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void Enqueue(){
    struct Node *new, *ptr;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    new->next = head;
    ptr->next = new;
}

void Dequeue(){
    struct Node *ptr, *temp;
    ptr = head;
    if (head == NULL)
        printf("Not possible");
    else{
        while (ptr->next != head)
            ptr = ptr->next;
        temp = head;
        ptr->next = head->next;
        head = head->next;
        free(temp);
    }
}

int main(){
    int num, t = 0;
    while (t != 1){
        printf("\n\n1. Create a circular linked list.");
        printf("\n2. Display the linked list.");
        printf("\n3. Insert an element.");
        printf("\n4. Delete an element.");
        printf("\n5. Exit.");
        printf("\n\nEnter your choice: ");
        scanf("%d", &num);
        fflush(stdin);
        
        switch (num){
            case 1:
                create();
                break;
            case 2:
                traverse();
                break;
            case 3:
                Enqueue();
                traverse();
                break;
            case 4:
                Dequeue();
                traverse();
                break;
            case 5:
                t = 1;
                printf("\nExited");
                break;
            default:
                printf("Invalid input.");
        }
    }
    return 0;
}
