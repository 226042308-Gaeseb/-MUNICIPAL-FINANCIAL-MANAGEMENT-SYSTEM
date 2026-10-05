
#include <stdio.h>
#include <string.h>
#include "reports.h"
#define DEPARTMENT_COUNT 10   /* budget.c has 10 departments */

/* Data that lives in the other modules (defined there, only declared here) */
extern char supplierID[][10];
extern char supplier_name[][50];
extern char email[][50];
extern char telephone_number[][15];
extern char town[][50];
extern int supplierCount;

extern char departmentName[][50];
extern float allocatedBudget[];
extern float expenditure[];


extern int assetCount;

/*Prints a single line filled with dashes to separate the parts of the report */
void printReportLine(void)
{
    printf("----------------------------------------------------------\n");
}

/*Prints a line filled with dashes to separate the parts of the report */
void printReportLines(void)
{
    printReportLine();
}

/*Prints the reports menu text (only the printing, no input) */
static void printReportsMenu(void)
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

/*---------------------------------------------------------------------
    Reports Menu
    Called from main when the user picks "Reports". It displays the menu,
    reads the number the user enters, runs the matching report, and keeps
    repeating until the user chooses 5 (Back to Main Menu).
    Only the employee data has to be passed in (main owns those arrays).
    The budget, supplier and asset data are read from their own modules.
    ---------------------------------------------------------------------*/
void displayReportsMenu(
    char names[][NAME_LEN],
    double basicSalaries[],
    double housingAlls[],
    double transportAlls[],
    char departmentName[][50],
    float allocatedBudget[],
    float expenditure[],
    char supplierID[][10],
    char supplier_name[][50],
    char email[][50],
    char telephone_number[][15],
    char towns[][50],
    Asset assets[],
    int employeeCount,
    int budgetCount,
    int supplierCount,
    int assetCount)
{
    int choice;

    do
    {
        printf("\n================================\n");
        printf("              REPORTS\n");
        printf("================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeReport(
                    names,
                    basicSalaries,
                    housingAlls,
                    transportAlls,
                    employeeCount
                );
                break;

            case 2:
                budgetReport(
                    departmentName,
                    allocatedBudget,
                    expenditure,
                    budgetCount
                );
                break;

            case 3:
                supplierReport(
                    supplierID,
                    supplier_name,
                    email,
                    telephone_number,
                    towns,
                    supplierCount
                );
                break;

            case 4:
                assetReport(
                    assets,
                    assetCount
                );
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1-5.\n");
        }

    } while (choice != 5);
}

/*----------------------------------------------------------------------
    Employee Report
    Gross salary = basic + housing + transport
    This works out the total employees, average, highest and lowest salaries
    ----------------------------------------------------------------------*/

void employeeReport(char names[][NAME_LEN], double basicSalaries[], double housingAlls[],
                    double transportAlls[], int count)
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

/*this function calculates the remaining budget and a negative will mean over the budget*/
double calculateRemaining(double allocated, double spent)
{
    return allocated - spent;
}

void budgetReport(char deptNames[][50], float allocated[], float spent[], int count)
{
    double totalAllocated = 0;
    double totalSpent = 0;
    double remaining;
    int overCount = 0;
    int entered = 0;

    printf("\nBUDGET REPORT\n");
    printReportLine();

    /*step 1 calculating the total allocated and spent,
     a department only counts once a budget above 0 is entered*/
    for (int i = 0; i < count; i++)
    {
        if (allocated[i] > 0)
        {
            totalAllocated = totalAllocated + allocated[i];
            totalSpent = totalSpent + spent[i];
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
               "Department", "Allocated", "Spent", "Remaining", "Status");
        printReportLine();

        for (int i = 0; i < count; i++)
        {
            if (allocated[i] > 0)
            {
                remaining = calculateRemaining(allocated[i], spent[i]);

                printf("%-18s %12.2f %12.2f %12.2f ", deptNames[i], allocated[i], spent[i], remaining);

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
            if (allocated[i] > 0 && spent[i] > allocated[i])
            {
                printf("  -%s (over by N$%.2f)\n", deptNames[i],
                       spent[i] - allocated[i]);
            }
        }
    }
    printReportLine();
}

/*---------------------------------------------------------
    Supplier Report
    ------------------------------------------------------*/
void supplierReport(char sIDs[][10], char sNames[][50], char sEmails[][50],
                    char sPhones[][15], char sTowns[][50], int count)
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
            printf("%-6s %-20s ", sIDs[i], sNames[i]);

            /* strlen() is used to check if the email is empty, if it is empty then "N/A" will be printed instead of an empty space*/
            if (strlen(sEmails[i]) == 0)
            {
                printf("%-24s ", "N/A");
            }
            else
            {
                printf("%-24s ", sEmails[i]);
            }

            printf("%-12s %s\n", sPhones[i], sTowns[i]);
        }
        printReportLine();
        printf("Total Suppliers: %d\n", count);
    }
    printReportLine();
}

/*---------------------------------------------------------
    Asset Report
    ------------------------------------------------------*/
void assetReport(const Asset list[], int count)
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
                   list[i].assetId, list[i].assetName, list[i].assetType,
                   list[i].purchaseValue, list[i].department, list[i].condition);

            totalValue = totalValue + list[i].purchaseValue;

            /* strcmp() == 0 will mean the two strings are the same */
            if (strcmp(list[i].condition, "Poor") == 0)
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