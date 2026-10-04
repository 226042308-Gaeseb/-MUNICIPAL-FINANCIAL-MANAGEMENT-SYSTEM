/* reports.c - reports module for the Municipal FInancial Management System Group
The reports read their data from the other modules:
     - Employees : arrays that main owns, passed into displayReportsMenu()
     - Budget    : global arrays in budget.c
     - Suppliers : global arrays in suppliers.c
     - Assets    : global array in Assets.c*/
#include <stdio.h>
#include <string.h>
#include "reports.h"

/*Prints a single line filled with dashes to separate the parts of the report */
void printReportLine()
{
    printf("----------------------------------------------------------\n");
}

/*Prints a line filled with dashes to separate the parts of the report */
void printReportLines()
{
    printReportLine();
}
/*Reads the number the user types for the menu.
  Blank lines are skipped (a leftover newline from an earlier scanf would
  otherwise count as an empty choice). Returns -1 if the input is not a
  number, and 5 (Back) if the input has ended.*/
static int readMenuChoice(void)
{
    char line[64];
    int choice;

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        if (sscanf(line, "%d", &choice) == 1)
        {
            return choice;
        }

        if (line[strspn(line, " \t\r\n")] != '\0')
        {
            return -1;
        }
    }

    return 5;
}

/*Waits for the user to press Enter so the report stays on screen*/
static void waitForEnter(void)
{
    char line[64];

    printf("\nPress Enter to return to the Reports menu...");
    fgets(line, sizeof(line), stdin);
}

/*this prints and displays the reports sub menue*/
void displayReportsMenu()
{
    printf("\n================================\n");
    printf("              Reports\n");
    printf("================================\n");
    printf("1. Employee Report\n");
    printf("2. Budget Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
    printf("5. Back to Main Menu\n");
    printf("Enter your choice: ");
}

void displayReportsMenu(char names[][NAME_LEN], double basicSalaries[],
                        double housingAlls[], double transportAlls[],
                        int employeeCount)
{
    int choice;

    do
    {
        printReportsMenu();
        choice = readMenuChoice();

        switch (choice)
        {
            case 1:
                employeeReport(names, basicSalaries, housingAlls, transportAlls,
                               employeeCount);
                waitForEnter();
                break;
            case 2:
                budgetReport(departmentName, allocatedBudget, expenditure,
                             DEPARTMENT_COUNT);
                waitForEnter();
                break;
            case 3:
                supplierReport(supplierID, supplier_name, email, telephone_number,
                               town, supplierCount);
                waitForEnter();
                break;
            case 4:
                assetReport(assets, assetCount);
                waitForEnter();
                break;
            case 5:
                printf("\nReturning to the main menu...\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 5.\n");
                break;
        }
    } while (choice != 5);
}
/*----------------------------------------------------------------------
    Employee Report
    Gross salary = basic + housing + transport
    This works out the total employees, average, highest and lowest salaries
    ----------------------------------------------------------------------*/

void employeeReport(char names[][50], double basicSalaries[], double housingAlls[],
                    double transportAlls[],int count)
{
    double gross;
    double total = 0;
    double highest = 0;
    double lowest = 0;
    double average;
    int highestIndex = 0;
    int lowestIndex = 0;

    printf("\nEMPLOYEE REPORT\n");
    printReportLines();
    
    if (count <= 0)
    {
       printf("None of the employees have been registered yet.\n");
    }
    else
    {
            for (int i = 0; i < count; i++)
            {
                gross = basicSalaries[i] + housingAlls[i] + transportAlls[i];
                total = total + gross;

                /* the very first employee will start as both the highest and lowest*/
                if (i == 0)
                {
                    highest = gross;
                    lowest = gross;
                }
                
                if (gross > highest)
                { 
                    highest = gross;
                    highestIndex = i;
                }

                if (gross < lowest)
                {
                    lowest = gross;
                    lowestIndex = i;
                }
             }
   
             average = total / count;

             printf("Total Employees : %d\n", count);
             printf("Average Salary  : N$%.2f\n", average);
             printf("Highest Salary  : N$%.2f (%s)\n", highest, names[highestIndex]);
             printf("Lowest Salary   : N$%.2f (%s)\n", lowest, names[lowestIndex]);
        }
        printReportLine();
}

/*---------------------------------------------------------
    Budget Report
    ------------------------------------------------------*/

/*this function calculates the remaining budget and a negetive will mean over the budget*/
double calculateRemaining(double allocated, double spent)
{
    return allocated - spent;
}

void budgetReport(char departmentName[][50], float allocatedBudget[], float expenditure[], int count)

{
    double totalAllocated = 0;
    double totalSpent = 0;
    double remaining;
    int overCount = 0;
    int entered = 0;

    printf("\nBUDGET REPORT\n");
    printReportLine();

    /*step 1 calculating the total allicated and spent ,
     a department only counts once a budget above 0 is entered*/
    for (int i = 0; i < count; i++)
    {
        if (allocatedBudget[i] > 0)
        {
            totalAllocated = totalAllocated + allocatedBudget[i];
            totalSpent = totalSpent + expenditure[i];
            entered++;
        }
    }
    if (entered == 0)
    {
        printf("None of the departments have been entered yet.\n");
    }
    else
    {
        printf("Total Allocated Budget   : N$%.2f\n", totalAllocated);
        printf("Total Expenditure        : N$%.2f\n", totalSpent);
        printf("Total Remaining Budget   : N$%.2f\n", calculateRemaining(totalAllocated, totalSpent));


        /*step 2; this will show the status of every budget*/
        printf("%-18s %12s %12s %12s %s\n",
               "Department", "Allocated", "spent", "Remaining", "status");
        printReportLine();

        for (int i = 0; i < count; i++)
        {
            if(allocatedBudget[i] > 0)
            {
                remaining = calculateRemaining(allocatedBudget[i], expenditure[i]);
            
                printf("%-18s %12.2f %12.2f %12.2f ", departmentName[i], allocatedBudget[i], expenditure[i], remaining);
    
                if (remaining < 0)
                {
                    printf("%s\n", "Over Budget");
                    overCount++;
                }      
                else
                {
                    printf("%s\n", "Within Budget");
                }   
            }
        }
        printReportLine();
        
        /*step 3: display the number of departments exceeding the budget*/
        printf("Departments exceeding budget: %d\n", overCount);

        for (int i = 0; i < count; i++)
        {
            if (allocatedBudget[i] >0 && expenditure[i] > allocatedBudget[i])
            {
                printf("  -%s (over by N$%.2f)\n", departmentName[i], 
                        expenditure[i] - allocatedBudget[i]);
            }
        }
    }
    printReportLine();
}

/*---------------------------------------------------------
    Supplier Report
    ------------------------------------------------------*/
void supplierReport(char supplierID[][10], char supplier_name[][50], char email[][50], 
                    char telephone_number[][15],char towns[][50], int count)
{
    printf("\nSUPPLIER REPORT\n");
    printReportLine();

    if (count <= 0)
    {
        printf("None of the suppliers have been registered yet.\n");
    }
    else
    {
        printf("%-6s %-20s %-24s %-12s %s\n", "ID", "Name", "Email", "Phone", "Town");
        
        printReportLine();

        for (int i = 0; i < count; i++)
        {
            printf("%-6s %-20s ", supplierID[i], supplier_name[i]);
            
            /* strlen() is used to check if the email is empty, if it is empty then "N/A" will be printed instead of an empty space*/
            if (strlen(email[i]) == 0)
            {
                printf("%-24s ","N/A");
            }
            else
            {
                printf("%-24s ", email[i]);
            }

            printf("%-12s %s\n", telephone_number[i], towns[i]);
        }
        printReportLine();
        printf("Total Suppliers: %d\n", count);
    }
    printReportLine();
}

/*---------------------------------------------------------
    Asset Report
    ------------------------------------------------------*/
void assetReport(char ids[][50], char names[][50], char types[][50], 
                 double values[], char departments[][50], 
                 char conditions[][20], int count)
{
    double totalValue = 0;
    int poorCount = 0;

    printf("\nASSET REPORT\n");
    printReportLine();

    if (count <= 0)
    {
        printf("None of the assets have been registered yet.\n");
    }
    else
    {
        printf("%-7s %-16s %-10s %11s %-11s %s\n",
               "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
        printReportLine();

        for (int i = 0; i < count; i++)
        {
            printf("%-7s %-16s %-10s %11.2f %-11s %s\n", 
                   ids[i], names[i], types[i], values[i],
                    departments[i], conditions[i]);
            
            totalValue =  totalValue + values[i];

            /* strcmp() ==0 will mean the two strings are the same */
            if (strcmp(conditions[i], "Poor") == 0)
            {
                poorCount++;
            }
        }
        printReportLine();
        printf("Total Assets            : %d\n", count);
        printf("Total purchase Value    : N$%.2f\n", totalValue);
        printf("Assets in Poor Condition: %d\n", poorCount);    
    }
    printReportLine();
}
