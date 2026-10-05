#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "Assets.h"
#include "reports.h"

char ids[MAX_EMPLOYEES][ID_LEN];
char names[MAX_EMPLOYEES][NAME_LEN];
char depts[MAX_EMPLOYEES][DEPT_LEN];

double basicSalaries[MAX_EMPLOYEES];
double housingAlls[MAX_EMPLOYEES];
double transportAlls[MAX_EMPLOYEES];

int count = 0;
extern Asset assets[];
extern char departmentName[][50];
extern float allocatedBudget[];
extern float expenditure[];

extern char supplierID[][10];
extern char supplier_name[][50];
extern char email[][50];
extern char telephone_number[][15];
extern char town[][50];
extern int supplierCount;

extern int assetCount;

int budgetCount = 0;

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
        budgetsMenu();
    }
    else if (choice == 3){
        printf("\nYou have selected Asset Management.\n");
        printf("==========================================\n");
        assetsMenu();
    }
    else if (choice == 4){
        printf("\nYou have selected Supplier Management.\n");
        printf("==========================================\n");
        supplierMenu();
    }
    else if (choice == 5){
        printf("\nYou have selected Reports.\n");
        printf("==========================================\n");
        displayReportsMenu(
            names,
            basicSalaries,
            housingAlls,
            transportAlls,
            departmentName,
            allocatedBudget,
            expenditure,
            supplierID,
            supplier_name,
            email,
            telephone_number,
            town,
            assets,
            budgetCount,
            supplierCount,
            assetCount,
            count
        );
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