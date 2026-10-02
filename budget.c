#include <stdio.h>
#include <string.h>

char departmentName[10][50] = {"Finance", "Health", "Water", "Electricty", "Roads", "Housing", "Planning", "Waste", "IT", "HR"};
float allocatedBudget[10] = {0};
float expenditure[10] = {0};
float remainBudget[10] = {0};
char status[10][30];
int i = 0;
int choice;

float calculateremainBudget(float allocated, float used){
    return allocated - used;
}

void displayBudget(){
    printf("\nDisplay budget information\n");
    for(i = 0; i < 10; i++){
        if(allocatedBudget[i] > 0){
            printf("name: %s\n", departmentName[i]);
            printf("Budget: N$%.2f\n", allocatedBudget[i]);
            printf("expenditure: N$%.2f\n", expenditure[i]);
            printf("remain: N$%.2f\n", remainingBudget[i]);
            printf("status: %s\n", status[i]);
        }
    }
}

void showOverspent(){
    for(i = 0; i < 10; i++){
        if(remainBudget[i] < 0){
            printf("%s has execced their budget\n", departmentName[i]);
        }
    }
}
