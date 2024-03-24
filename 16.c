//WAP to implement queue using stack
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
    int data[MAX];
    int top;
}STACK;

int PUSH(STACK* T, int v){
    if(T->top == (MAX-1)){
        printf("Overflow!\n");
        return 1;
    }
    else{
        T->top++;
        T->data[T->top] = v;
        return 0;
    }
}
void POP(STACK* T1, STACK* T2){
    while(T1->top != 0){
        PUSH(T2,T1->data[T1->top]);
        T1->top--;
    }
    T1->top = -1;
    while(T2->top != -1){
        PUSH(T1,T2->data[T2->top]);
        T2->top--;
    }
}
void init(STACK* T1){
    T1->top = -1;
}
void display(STACK T){
    if(T.top == -1){
        printf("Stack empty!\n");
        return;
    }
    else{
        for(int i = 0 ; i <= T.top ; i++)
            printf("%d ",T.data[i]);
        return;
    }
}

int main(){
    STACK s1, s2;

    init(&s1);
    init(&s2);
    PUSH(&s1,10);
    PUSH(&s1,20);
    PUSH(&s1,30);
    PUSH(&s1,40);
    PUSH(&s1,50);
    printf("\nThe data present in the queue is: ");
    display(s1);
    POP(&s1,&s2);
    printf("\nAfter first deletion, the queue is: ");
    display(s1);
    printf("\n");

    return 0;
}
