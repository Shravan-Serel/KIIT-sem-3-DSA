#include <stdio.h>

struct population
{
    char name[50];
    int age;
    char city[50];
};

int main()
{
    struct population p[5];
    int m = 0;

    for(int i=0; i<5; i++){
        fflush(stdin);
        printf("\nEnter details of Person %d: ", i+1);
        printf("Enter name: ");
        gets(p[i].name);
        printf("Enter city: ");
        gets(p[i].city);
        printf("Enter age: ");
        scanf("%d", &p[i].age);
        
        if(p[i].age > m){
            m = p[i].age;
        }
    }

    for(int i=0; i<5; i++){
        if(p[i].age == m){
            printf("\nName of the eldest one: %s", p[i].name);
            printf("\nCity of the eldest one: %s", p[i].city);
        }
    }

    return 0;
}
