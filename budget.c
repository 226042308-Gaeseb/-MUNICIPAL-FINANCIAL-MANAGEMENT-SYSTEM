#include <stdio.h>
#include <string.h>
#include "budget.h"

char departmentName[10][50] = {"Finance", "Health", "Water", "Electricity", "Roads", "Housing", "Planning", "Waste", "IT", "HR"};
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
            printf("remain: N$%.2f\n", remainBudget[i]);
            printf("status: %s\n", status[i]);
        }
    }
}

void showOverspent(){
    for(i = 0; i < 10; i++){
        if(remainBudget[i]< 0){
            printf("%s has exceeded their allocated budget\n", departmentName[i]);
        }
    }
}

void enterdepartment(){
    for(i = 0; i < 10; i++){
        printf("%d. %s\n", i +1, departmentName[i]); //it printd the number of choice and the department name
}

printf("pick number from 1 to 10: ");
scanf("%d", &choice);

printf("%s\n", departmentName[choice - 1]);//open the locker one less than the number the user typed, because lockers start at 0

printf("Enter the budget amount:");
scanf("%f", &allocatedBudget[choice - 1]);

if(allocatedBudget[choice - 1] < 0){
    printf("allocatedBudget cannot be negative\n");
    return;
}

printf("Enter the expenditure amount: ");
scanf("%f", &expenditure[choice - 1]);


if(expenditure[choice - 1] < 0){
    printf("exependiture cannot be negative\n");
        return;
    }

    remainBudget[choice - 1] = calculateremainBudget(allocatedBudget[choice - 1], expenditure[choice - 1]);
    if(remainBudget[choice - 1] < 0){
      strcpy(status[choice - 1], "over the budget"); //Copy thr words over the budget in the department's statuss's locks
        
    }else{
        strcpy(status[choice - 1], "Within the budget");

    }


    printf("%.2f\n", remainBudget[choice - 1]);
    printf("%s\n", status[choice - 1]);
}

void budgetsMenu() {
    int choice = 0;

    do {
        printf("\n===================================\n");
        printf("      BUDGET MANAGEMENT MENU       \n");
        printf("===================================\n");
        printf("1. Enter Department Budget\n");
        printf("2. Display Budget Information\n");
        printf("3. Show Overspent Departments\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterdepartment();
                break;
            case 2:
                displayBudget();
                break;
            case 3:
                showOverspent();
                break;
            case 4:
                printf("\nReturning to main menu...\n");
                break;
            default:
                printf("\nInvalid Option: Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
}
