#include <stdio.h>
#include <string.h>
#include "employees.h"

void calculateSalaryInfo(double basic, double housing, double transport, double *gross, double *net) {
    *gross = basic + housing + transport;
    double tax = *gross * 0.15;
    *net = *gross - tax;
}

void addEmployee(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                 double basicSalaries[], double housingAlls[], double transportAlls[], int *count) {
    
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Maximum employee limit reached!\n");
        return;
    }

    int current = *count;

    printf("\n=== ADD NEW EMPLOYEE ===\n");
    
    printf("Enter Employee ID: ");
    getchar();
    fgets(ids[current], ID_LEN, stdin);
    ids[current][strcspn(ids[current], "\n")] = '\0';

    printf("Enter Full Name: ");
    fgets(names[current], NAME_LEN, stdin);
    names[current][strcspn(names[current], "\n")] = '\0';

    if (strlen(names[current]) == 0) {
        printf("Error: Employee name cannot be empty!\n");
        return;
    }

    printf("Enter Department: ");
    fgets(depts[current], DEPT_LEN, stdin);
    depts[current][strcspn(depts[current], "\n")] = '\0';

    do {
        printf("Enter Basic Salary (N$): ");
        scanf("%lf", &basicSalaries[current]);
        if (basicSalaries[current] < 0) {
            printf("[Invalid] Salary cannot be negative. Try again.\n");
        }
    } while (basicSalaries[current] < 0);

    do {
        printf("Enter Housing Allowance (N$): ");
        scanf("%lf", &housingAlls[current]);
        if (housingAlls[current] < 0) {
            printf("Invalid: Housing allowance cannot be negative. Try again.\n");
        }
    } while (housingAlls[current] < 0);

    do {
        printf("Enter Transport Allowance (N$): ");
        scanf("%lf", &transportAlls[current]);
        if (transportAlls[current] < 0) {
            printf("Invalid: Transport allowance cannot be negative. Try again.\n");
        }
    } while (transportAlls[current] < 0);

    (*count)++;
    printf("\n>>> Employee added successfully! Total employees: %d <<<\n", *count);
}

void displayEmployees(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                     double basicSalaries[], double housingAlls[], double transportAlls[], int count) {
    
    if (count == 0) {
        printf("\nNo employees registered in the system yet.\n");
        return;
    }

    printf("\n===================================================================================================\n");
    printf("%-15s | %-20s | %-15s | %-10s | %-10s | %-10s\n", 
           "ID", "Name", "Department", "Basic", "Gross", "Net");
    printf("===================================================================================================\n");

    for (int i = 0; i < count; i++) {
        double gross = 0.0, net = 0.0;
        calculateSalaryInfo(basicSalaries[i], housingAlls[i], transportAlls[i], &gross, &net);

        printf("%-15s | %-20s | %-15s | N$%-8.2f | N$%-8.2f | N$%-8.2f\n",
               ids[i], names[i], depts[i], basicSalaries[i], gross, net);
    }
    printf("===================================================================================================\n");
}

void searchEmployee(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                    double basicSalaries[], double housingAlls[], double transportAlls[], int count) {
    
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    char searchName[NAME_LEN];
    printf("\nEnter Employee Name to Search: ");
    getchar(); 
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], searchName) == 0) {
            double gross = 0.0, net = 0.0;
            calculateSalaryInfo(basicSalaries[i], housingAlls[i], transportAlls[i], &gross, &net);

            printf("\n--- Employee Details ---\n");
            printf("ID: %s\n", ids[i]);
            printf("Name: %s\n", names[i]);
            printf("Department: %s\n", depts[i]);
            printf("Basic Salary: N$%.2f\n", basicSalaries[i]);
            printf("Housing Allowance: N$%.2f\n", housingAlls[i]);
            printf("Transport Allowance: N$%.2f\n", transportAlls[i]);
            printf("Gross Salary: N$%.2f\n", gross);
            printf("Net Salary (after tax): N$%.2f\n", net);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo employee matching '%s' was found.\n", searchName);
    }
}

void employeeMenu(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                  double basicSalaries[], double housingAlls[], double transportAlls[], int *count) {
    
    int choice = 0;
    
    do {
        printf("\n===================================\n");
        printf("    EMPLOYEE RECORDS MANAGEMENT    \n");
        printf("===================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by Name\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(ids, names, depts, basicSalaries, housingAlls, transportAlls, count);
                break;
            case 2:
                displayEmployees(ids, names, depts, basicSalaries, housingAlls, transportAlls, *count);
                break;
            case 3:
                searchEmployee(ids, names, depts, basicSalaries, housingAlls, transportAlls, *count);
                break;
            case 4:
                printf("\nReturning to main menu...\n");
                break;
            default:
                printf("\nInvalid Option: Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
}