
//WAP that inputs two arrays and saves sum of corresponding elements of these arrays in a third array and prints them.
#include <stdio.h>

int main(){
    int n, arr1[20], arr2[20], arr3[20];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Array 1\n");
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &arr1[i]);
    }

    printf("\nArray 2\n");
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &arr2[i]);
        arr3[i] = arr1[i]+arr2[i];
    }

    printf("\nSum of arrays:");
    for(int i=0;i<n;i++){
        printf(" %d", arr3[i]);
    }

    return 0;
}
