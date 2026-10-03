#include <stdio.h>
#include <string.h>
#include "suppliers.h"

#define MAX_SUPPLIERS 5

char supplierID[MAX_SUPPLIERS][10];
char supplier_name[MAX_SUPPLIERS][50];
char email[MAX_SUPPLIERS][50];
char telephone_number[MAX_SUPPLIERS][15];
char town[MAX_SUPPLIERS][50];

int supplierCount = 0;

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier limit reached.\n");
        return;
    }

    printf("\nSupplier Details\n");

    printf("Enter Supplier ID: ");
    fgets(supplierID[supplierCount], sizeof(supplierID[supplierCount]), stdin);
    supplierID[supplierCount][strcspn(supplierID[supplierCount], "\n")] = '\0';

    printf("Enter Supplier Name: ");
    fgets(supplier_name[supplierCount], sizeof(supplier_name[supplierCount]), stdin);
    supplier_name[supplierCount][strcspn(supplier_name[supplierCount], "\n")] = '\0';

    printf("Enter Supplier Email: ");
    fgets(email[supplierCount], sizeof(email[supplierCount]), stdin);
    email[supplierCount][strcspn(email[supplierCount], "\n")] = '\0';

    printf("Enter Supplier Telephone Number: ");
    fgets(telephone_number[supplierCount], sizeof(telephone_number[supplierCount]), stdin);
    telephone_number[supplierCount][strcspn(telephone_number[supplierCount], "\n")] = '\0';

    printf("Enter Supplier Town: ");
    fgets(town[supplierCount], sizeof(town[supplierCount]), stdin);
    town[supplierCount][strcspn(town[supplierCount], "\n")] = '\0';

    supplierCount++;

    printf("Supplier added successfully!\n");
}

void displaySupplier()
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n---------------------------\n");
    printf("     SUPPLIER DETAILS\n");
    printf("---------------------------\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %s\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplier_name[i]);
        printf("Email: %s\n", email[i]);
        printf("Telephone: %s\n", telephone_number[i]);
        printf("Town: %s\n", town[i]);
    }
}

void searchSupplier()
{
    char searchName[50];

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);

    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(searchName, supplier_name[i]) == 0)
        {
            printf("Supplier found!\n");
            printf("Supplier ID: %s\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplier_name[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone: %s\n", telephone_number[i]);
            printf("Town: %s\n", town[i]);
            return;
        }
    }

    printf("Supplier not found.\n");
}

void showNameLength()
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
    printf("Supplier Name Length: %zu\n", strlen(supplier_name[i]));
    printf("Email Length: %zu\n", strlen(email[i]));
    printf("Town Length: %zu\n", strlen(town[i]));
    }
}

void copySupplierName()
{
    char copiedName[50];

    strcpy(copiedName, supplier_name[0]);

    printf("Copied Supplier Name: %s\n", copiedName);
}

void combineSupplierInfo()
{
    char supplierInfo[100];

    strcpy(supplierInfo, supplier_name[0]);
    strcat(supplierInfo, " - ");
    strcat(supplierInfo, town[0]);

    printf("Supplier Information: %s\n", supplierInfo);
}

void supplierMenu()
{
    int choice;

    do
    {
        printf("\n---------------------------\n");
        printf("     SUPPLIER MANAGEMENT\n");
        printf("---------------------------\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySupplier();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                showNameLength();
                break;

            case 5:
                printf("Exiting Supplier Management.\n Thank You!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);
}

int main()
{
   
    supplierMenu();

    return 0;
}