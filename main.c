#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"

char ids[MAX_EMPLOYEES][ID_LEN];
char names[MAX_EMPLOYEES][NAME_LEN];
char depts[MAX_EMPLOYEES][DEPT_LEN];

double basicSalaries[MAX_EMPLOYEES];
double housingAlls[MAX_EMPLOYEES];
double transportAlls[MAX_EMPLOYEES];

int count = 0;

int displayMenu(){
    int choice;
    printf("=================================================\n");
    printf("===== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM =====\n");
    printf("=================================================\n");

    printf("\n Welcome. Please select type of service \n");
    printf("==========================================\n");

    printf("\n1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Asset Management\n");
    printf("4. Supplier Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("==========================================\n");

    printf("Enter your choice from (1-6): ");
    scanf("%d", &choice);

    if (choice == 1){
        printf("\nYou have selected Employee Management.\n");
        printf("==========================================\n");
        employeeMenu(ids, names, depts, basicSalaries, housingAlls, transportAlls, &count);
    }
    else if (choice == 2){
        printf("\nYou have selected Budget Management.\n");
        printf("==========================================\n");
        budgetMenu();
    }
    else if (choice == 3){
        printf("\nYou have selected Asset Management.\n");
        printf("==========================================\n");
        // Call asset management function here
    }
    else if (choice == 4){
        printf("\nYou have selected Supplier Management.\n");
        printf("==========================================\n");
        supplierMenu();
    }
    else if (choice == 5){
        printf("\nYou have selected Reports.\n");
        printf("==========================================\n");
        // Call reports function here
    }
    else if (choice == 6){
        printf("\nExiting the program. Goodbye!\n");
        return 0;
    }
    else{
        printf("\nInvalid choice. Please select a valid option from the menu.\n");
    }
}

int main(){
    displayMenu();
    return 0;
}