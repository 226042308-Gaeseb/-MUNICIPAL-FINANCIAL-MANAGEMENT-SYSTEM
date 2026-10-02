#include <stdio.h>
#include "employeemanagement.c"
int main(){
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

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1){
        printf("\nWelcome to Employee Management.\n");
        printf("---------------------------------\n");
        displayEmployeeManagementMenu();
    }
    else if (choice == 2 ){
        printf("\nWelcome to Budget Management.\n");
        printf("-------------------------------\n");
        //budgetManagement();
    }
    else if (choice == 3 ){
        printf("\nWelcome to Asset Management.\n");
        printf("-------------------------------\n");
        //assetManagement();
    }
    else if (choice == 4 ){
        printf("\nWelcome to Supplier Management.\n");
        printf("---------------------------------\n");
        //supplierManagement();
    }
    else if (choice == 5 ){
        printf("\nWelcome to Reports.\n");
        printf("--------------------\n");
        //reports();
    }
    else if (choice == 6 ){
        printf("\nExiting the system\n");
        return 0;
    }
    else{
        printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}