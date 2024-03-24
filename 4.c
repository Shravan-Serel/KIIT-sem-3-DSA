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

    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i]%2==0){
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    printf("\nResultant array:");
    for(int i=0;i<n;i++)
        printf(" %d", arr[i]);

    return 0;
}
