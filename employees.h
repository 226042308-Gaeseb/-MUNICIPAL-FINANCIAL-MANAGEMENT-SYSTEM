#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50
#define ID_LEN 20
#define NAME_LEN 50
#define DEPT_LEN 30

void addEmployee(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                 double basicSalaries[], double housingAlls[], double transportAlls[], int *count);

void displayEmployees(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                     double basicSalaries[], double housingAlls[], double transportAlls[], int count);

void searchEmployee(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                    double basicSalaries[], double housingAlls[], double transportAlls[], int count);

void calculateSalaryInfo(double basic, double housing, double transport, double *gross, double *net);

void employeeMenu(char ids[][ID_LEN], char names[][NAME_LEN], char depts[][DEPT_LEN], 
                  double basicSalaries[], double housingAlls[], double transportAlls[], int *count);

#endif
