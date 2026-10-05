#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "Assets.h"

/* Report formatting */
void printReportLine(void);
void printReportLines(void);

/* Reports menu */
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
    int assetCount
);

/* Individual reports */
void employeeReport(
    char names[][NAME_LEN],
    double basicSalaries[],
    double housingAlls[],
    double transportAlls[],
    int count
);

double calculateRemaining(double allocated, double spent);

void budgetReport(
    char deptNames[][50],
    float allocated[],
    float spent[],
    int count
);

void supplierReport(
    char sIDs[][10],
    char sNames[][50],
    char sEmails[][50],
    char sPhones[][15],
    char sTowns[][50],
    int count
);

void assetReport(
    const Asset list[],
    int count
);

#endif