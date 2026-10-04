/* reports.h - function declarations (prototypes) for the reports module */
#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"   /* NAME_LEN */
#include "Assets.h"      /* Asset type */

/* helpers */
void printReportLine(void);
void printReportLines(void);
double calculateRemaining(double allocated, double spent);

/* Displays the reports menu, reads the user's number, runs that report,
   and repeats until the user picks 5 (Back). */
void displayReportsMenu(char names[][NAME_LEN], double basicSalaries[],
                        double housingAlls[], double transportAlls[],
                        int employeeCount);

/* ARRAY SIZES -  every group member within the group will use the same size
         employee : names[][50], double basicSalaries[], housingAlls[], transportAlls[] - these are the arrays used in the employeeReport function
         budget : departmentName[][50], float allocatedBudget[], expenditure[] - these are the arrays used in the budgetReport function
         suppliers : supplierID[][10], supplier_name[][50], email[][50], telephone_number[][15], towns[][50] - these are the arrays used in the supplierReport function
         assets : ids[50], names[50], types[50], values[], departments[50], conditions[20] - these are the arrays used in the assetReport function
        for the arrays in their code to avoid any issues with the reports module */

void displayReportsMenu();

void employeeReport(char names[][50], double basicSalaries[], double housingAlls[], 
                    double transportAlls[], int count);

double calculateRemaining(double allocated, double spent);

void budgetReport(char departmentName[][50], float allocatedBudget[],
                  float expenditure[], int count);

void supplierReport(char supplierID[][10], char supplier_name[][50], char email[][50],
                    char telephone_number[][15], char towns[][50], int count);

void assetReport(char ids[][50], char names[][50], char types[][50],
                 double values[], char departments[][50],
                 char conditions[][20], int count);

#endif  
