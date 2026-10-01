#include <stdio.h>
#include <string.h>

    char supplierID[10]; 
    char supplier_name [50];
    char email [50];
    char telephone_number [15];
    char town[50];

void addSupplier()
{
    printf("Supplier Details\n");   

    printf("Enter Supplier ID: ");
    fgets(supplierID, sizeof(supplierID), stdin);

    printf("Enter Supplier Name: ");   
    fgets(supplier_name, sizeof(supplier_name), stdin);
    supplier_name[strcspn(supplier_name, "\n")] = '\0';

    printf("Enter Supplier Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter Supplier Telephone Number: ");
    fgets(telephone_number, sizeof(telephone_number), stdin);

    printf("Enter Supplier Town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';
}

void displaySupplier()
{

    printf("\n---------------------------\n");
    printf("     SUPPLIER DETAILS\n");
    printf("--------------------------\n");

    printf("Supplier ID: %s\n", supplierID);
    printf("Supplier Name: %s\n", supplier_name);
    printf("Email: %s\n", email);
    printf("Telephone: %s\n", telephone_number);
    printf("Town: %s\n", town);

}

void searchSupplier()
{

    char searchName[50];

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);

    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(searchName, supplier_name) == 0)
    {
        printf("Supplier found!\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }
}

void showNameLength()
{
    printf("\nSupplier Name Length: %lu\n", strlen(supplier_name));
    printf("Email Length: %lu\n", strlen(email));
    printf("Town Length: %lu\n", strlen(town));
}

void copySupplierName()
{

    char copiedName[50];
    strcpy(copiedName, supplier_name);
    printf("\nCopied Supplier Name: %s\n", copiedName);

}

void combineSupplierInfo()
{

    char supplierInfo[100];

    strcpy(supplierInfo, supplier_name);
    strcat(supplierInfo, " - ");
    strcat(supplierInfo, town);

    printf("\nSupplier Information: %s\n", supplierInfo);

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
                printf("Exiting Supplier Management...\n");
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
