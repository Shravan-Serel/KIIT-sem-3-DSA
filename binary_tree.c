//program to create and display a binary tree
#include <stdio.h>

void buildtree(int t[], int index, int item){
    int ch, data;
    t[index] = item;
    printf("Add LEFT child?(1/0): ");
    scanf("%d", &ch);
    if(ch==1){
        printf("Enter value of LEFT child: ");
        scanf("%d", &data);
        buildtree(t, 2*index+1, data);
    }
    printf("Add RIGHT child?(1/0): ");
    scanf("%d", &ch);
    if(ch==1){
        printf("Enter value of RIGHT child: ");
        scanf("%d", &data);
        buildtree(t, 2*index+2, data);
    }
}

void main(){
    int t[20], item;
    for(int i=0;i<20;i++)
        t[i]= -1;
    printf("Enter root node: ");
    scanf("%d", &item);
    buildtree(t, 0, item);

    printf("Tree:");
    for(int i=0;i<20;i++){
        if(t[i] == -1)
            printf(" -");
        else printf(" %d", t[i]);
    }
}
