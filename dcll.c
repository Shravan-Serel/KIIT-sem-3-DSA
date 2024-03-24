//various operations on double circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

void display(){
    struct Node *ptr = head;
    if(head == NULL)
        printf("Empty list.");
    else{
        printf("Output:");
        while(ptr->next != NULL){
            printf(" %d", ptr->data);
            ptr = ptr->next;
        }
        printf(" %d", ptr->data);
    }
}

void search(){
    struct Node *ptr = head;
    int n, flag=1, i=0;
    if(ptr == NULL)
        printf("Empty list.");
    else{
        printf("Enter element to be searched: ");
        scanf("%d", &n);
        if(head->data == n){
            printf("Data found at index %d", i+1);
            flag = 0;
        }
        else{
            while(ptr->next != NULL){
                if(ptr->data == n){
                    printf("Data found at index %d", i+1);
                    flag=0;
                    break;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if(flag == 1)
            printf("Data not in list");
    }
}

void insert_first(){
    struct Node *ptr, *new;
    int value;
    new = (struct Node *)malloc(sizeof(struct Node));
    if(new == NULL)
        printf("OVERFLOW");
    else{
        printf("Enter value: ");
        scanf("%d", &value);
        new->data = value;
        if(head == NULL){
            head = new;
            new->next = head;
            new->prev = head;
        }
        else{
            ptr = head;
            while(ptr->next != head)
                ptr = ptr->next;
            ptr->next = new;
            new->prev = ptr;
            head->prev = new;
            new->next = head;
            head = new;
        }
    }
}

void insert_last(){
    struct Node *ptr, *new;
    int value;
    new = (struct Node *)malloc(sizeof(struct Node));
    if(new == head)
        printf("OVERFLOW");
    else{
        printf("Enter value: ");
        scanf("%d", &value);
        new->data = value;
        if(head == NULL){
            head = new;
            new->next = head;
            new->prev = head;
        }
        else{
            ptr = head;
            while(ptr->next != head)
                ptr = ptr->next;
            ptr->next = new;
            new->prev = ptr;
            head->prev = new;
            new->next = head;
        }
    }
}

void del_first(){
    struct Node *ptr;
    if(head == NULL)
        printf("UNDERFLOW");
    else if(head->next == head){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = head->next;
        head->next->prev = ptr;
        free(head);
        head = ptr->next;
    }
}

void del_last(){
    struct Node *ptr;
    if(head == NULL)
        printf("OVERFLOW");
    else if(head->next == head){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        if(ptr->next != head)
            ptr = ptr->next;
        ptr->prev->next = head;
        head->prev = ptr->prev;
        free(ptr);
    }
}

int main(){
    int num, i=0;
    while(i!=1){
        printf("\n\n1. Display\n2. Search\n3. Insert at Start\n4. Insert at End\n5. Delete at Start\n6. Delete at End\n7. Exit\n\nEnter your choice: ");
        scanf("%d", &num);

        switch(num){
            case 1:
                display();
                break;
            case 2:
                search();
                break;
            case 3:
                insert_first();
                display();
                break;
            case 4:
                insert_last();
                display();
                break;
            case 5:
                del_first();
                display();
                break;
            case 6:
                del_last();
                display();
                break;
            case 7:
                i=1;
                printf("Exited");
                break;
            default:
                printf("Invalid input");
        }
    }
}
