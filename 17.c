//sparse matrix using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int row;
    int col;
    struct Node *next;
};

void create(struct Node **head, int value, int row, int col){
    struct Node *new, *ptr;
    ptr = *head;
    if(ptr == NULL){
        new = (struct Node *)malloc(sizeof(struct Node));
        new->data = value;
        new->row = row;
        new->col = col;
        new->next = NULL;
        *head = new;
    }
    else{
        while(ptr->next != NULL)
            ptr = ptr->next;
        new = (struct Node *)malloc(sizeof(struct Node));
        new->data = value;
        new->row = row;
        new->col = col;
        new->next = NULL;
        ptr->next = new;
    }
}

void display(struct Node *head){
    struct Node *ptr=head;

    while(ptr != NULL){
        printf("%d\t%d\t%d\n", ptr->row, ptr->col, ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    int row, col, a[20][20];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    struct Node *head = NULL;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter value [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0)
                create(&head, a[i][j], i, j);
        }
    }
    display(head);

    return 0;
}
