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
            printf("remain: N$%.2f\n", remainBudget[i]);
            printf("status: %s\n", status[i]);
        }
    }
}

void showOverspent(){
    for(i = 0; i < 10; i++){
        if(remainBudget[i] < 0){
            printf("%s has exceeded their allocated budget\n", departmentName[i]);
        }
    }
}

void enterdepartment(){
    for(i = 0; i < 10; i++){
        printf("%d. %s\n", i +1, departmentName[i]); //it printd the number of choice and the department name
}

printf("[Pick a number from 1 to 10: ]");
scanf("%d", &choice);

printf("%s\n", departmentName[choice - 1]);//open the locker one less than the number the user typed, because lockers start at 0

printf("Enter the budget amount:");
scanf("%f", &allocatedBudget);

if(allocatedBudget[choice - 1]){
    printf("allocatedBudget cannot be negative\n");
}

printf("Enter the expenditure amount: ");
scanf("%f", &expenditure);


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



