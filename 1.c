#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[100];

    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int max =  arr[0];
    int min = arr[0];
    
    for(int i=0; i<n; i++){
        if(arr[i]>max)
            max = arr[i];
        else if(arr[i]<min)
            min = arr[i];
        else
            continue;
    }
    
    printf("\nLargest element: %d", max);
    printf("\nSmallest element: %d", min);

    return 0;
}
