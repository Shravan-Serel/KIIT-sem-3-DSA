#include <stdio.h>
#include <string.h>

struct date{
    int day;
    int month;
    int year;
};

struct employee{
    char name[20];
    struct date dob;
    struct date doj;
    int salary;
};

void sortByName(struct employee emp[], int numOfEmployees){
    struct employee temp;
    for(int i=0; i<numOfEmployees-1; i++){
        for(int j=i+1; j<numOfEmployees; j++){
            if(strcmp(emp[i].name, emp[j].name)){
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

void sortByDOB(struct employee emp[], int numOfEmployees){
    struct employee temp;
    for(int i=0; i<numOfEmployees; i++){
        for(int j=i+i; j<numOfEmployees; j++){
            if(emp[i].dob.year > emp[j].dob.year || emp[i].dob.month > emp[j].dob.month || emp[i].dob.day > emp[j].dob.day){
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

void sortByDOJ(struct employee emp[], int numOfEmployees){
    struct employee temp;
    for(int i=0; i<numOfEmployees; i++){
        for(int j=i+i; j<numOfEmployees; j++){
            if(emp[i].doj.year > emp[j].doj.year || emp[i].doj.month > emp[j].doj.month || emp[i].doj.day > emp[j].doj.day){
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

void sortBySalary(struct employee emp[], int numOfEmployees){
    struct employee temp;
    for(int i=0; i<numOfEmployees-1; i++){
        for(int j=i+1; j<numOfEmployees; j++){
            if(emp[i].salary > emp[j].salary){
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

int main(){
    struct employee emp[3];
    int numofEmployees;
    
    printf("Enter number of employees: ");
    scanf("%d", &numOfEmployees);
    
    for(int i=0; i<numofEmployees; i++){
        fflush(stdin);
        printf("\nEnter Details of Employee %d", i+1);
        printf("\nEnter name: ");
        gets(emp[i].name);
        printf("Enter Date of Birth(DD MM YY): ");
        scanf("%d %d %d", emp[i].dob.day, emp[i].dob.month, emp[i].dob.year);
        printf("Enter Date of Job(DD MM YY): ");
        scanf("%d %d %d", emp[i].doj.day, emp[i].doj.month, emp[i].doj.year);
        printf("\nEnter salary: ");
        scanf("%d", emp[i].salary);
    }

    sortByName(emp, numofEmployees);        //sorts by Name

    sortByDOB(emp, numofEmployees);         //sorts by Date of Birth

    sortByDOJ(emp, numofEmployees);         //sorts by Date of Joining

    sortBySalary(emp, numofEmployees);      //sorts by Salary

    return 0;
}
