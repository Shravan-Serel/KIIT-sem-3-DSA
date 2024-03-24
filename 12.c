#include <stdio.h>

int front = -1, rear = -1;

void cqInsert(int items[], int size,int element){
  if ((front == rear + 1) || (front == 0 && rear == size - 1))
    printf("\nOVERFLOW\n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    items[rear] = element;
  }
}

int cqDelete(int items[], int size){
  int element;
  if(front == -1){
    printf("\nUNDERFLOW\n");
    return (-1);
  }
  else{
    element = items[front];
    if(front == rear){
      front = -1;
      rear = -1;
    } 
    else{
      front = (front + 1) % size;
    }
    printf("\nDeleted element: %d \n", element);
    return (element);
  }
}

void Traverse(int items[], int size){
  int i;
  if(front == -1)
    printf(" \nUNDERFLOW\n");
  else{
    printf("Circular Queue:");
    for(i = front; i != rear; i = (i + 1) % size){
      printf(" %d", items[i]);
    }
    printf(" %d ", items[i]);
  }
}

int main(){
    int size, n=0;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    int items[size];

    while(n!=1){
        int num, value;
        printf("\n\n1. Insert\n2. Delete\n3. Taverse\n4. Exit\nEnter your choice: ");
        scanf("%d", &num);

        switch(num){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                cqInsert(items, size, value);
                Traverse(items, size);
                break;
            case 2:
                cqDelete(items, size);
                Traverse(items, size);
                break;
            case 3:
                Traverse(items, size);
                break;
            case 4:
                printf("Exited.");
                n++;
                break;
            default:
                printf("Invalid Value.");
        }
    }
    return 0;
}
