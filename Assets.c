#include <stdio.h>
#include <string.h>
#include "Assets.h"

Asset assets[MAX_ASSETS];

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) {
        printf("\n[ERROR] Asset register is full. Cannot add more assets.\n");
        return;
    }

    Asset newAsset;

    printf("\n=== ADD NEW MUNICIPAL ASSET ===\n");
    
    printf("Enter Asset ID: ");
    scanf(" %[^\n]", newAsset.assetId);

    printf("Enter Asset Name: ");
    scanf(" %[^\n]", newAsset.assetName);
    if (strlen(newAsset.assetName) == 0) {
        printf("[ERROR] Asset name cannot be empty.\n");
        return;
    }

    printf("Enter Asset Type (e.g., Vehicle, Computer, Furniture): ");
    scanf(" %[^\n]", newAsset.assetType);

    printf("Enter Purchase Value (N$): ");
    if (scanf("%lf", &newAsset.purchaseValue) != 1 || newAsset.purchaseValue < 0) {
        printf("[ERROR] Invalid value. Purchase value cannot be negative.\n");
    
        while (getchar() != '\n');
        return;
    }

    printf("Enter Department: ");
    fgets(newAsset.department, sizeof(newAsset.department), stdin);
    newAsset.department[strcspn(newAsset.department, "\n")] = '\0';

    printf("Enter Condition (Good/Fair/Poor): ");
    fgets(newAsset.condition, sizeof(newAsset.condition), stdin);
    newAsset.condition[strcspn(newAsset.condition, "\n")] = '\0';

    assets[*count] = newAsset;
    (*count)++;

    printf("\n[SUCCESS] Asset successfully added to the register!\n");
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) {
        printf("\n[INFO] No municipal assets registered yet.\n");
        return;
    }

    printf("\n=================================================================\n");
    printf("                       MUNICIPAL ASSET REGISTER                  \n");
    printf("=================================================================\n");
    printf("%-10s | %-15s | %-15s | %-12s | %-15s\n", "ID", "Name", "Type", "Value (N$)", "Department");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10s | %-15s | %-15s | N$%-10.2f | %-15s\n",
               assets[i].assetId,
               assets[i].assetName,
               assets[i].assetType,
               assets[i].purchaseValue,
               assets[i].department);
    }
    printf("=================================================================\n");
}

void searchAsset(const Asset assets[], int count) {
    if (count == 0) {
        printf("\n[INFO] No assets available to search.\n");
        return;
    }

    char searchQuery[50];
    int found = 0;

    printf("\n=== SEARCH MUNICIPAL ASSET ===\n");
    printf("Enter Asset ID or Name to search: ");
    scanf(" %[^\n]", searchQuery);

    printf("\nSearch Results:\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(assets[i].assetId, searchQuery) == 0 || strcmp(assets[i].assetName, searchQuery) == 0) {
            printf("Asset ID   : %s\n", assets[i].assetId);
            printf("Name       : %s\n", assets[i].assetName);
            printf("Type       : %s\n", assets[i].assetType);
            printf("Value      : N$%.2f\n", assets[i].purchaseValue);
            printf("Department : %s\n", assets[i].department);
            printf("Condition  : %s\n", assets[i].condition);
            printf("----------------------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("[INFO] No matching asset found for '%s'.\n", searchQuery);
    }
}

/* shared with the reports module (report.c) */
Asset assets[MAX_ASSETS];
int assetCount = 0;

void assetsMenu(){
    int choice;

    do {
        printf("\n=== MUNICIPAL ASSET MANAGEMENT MENU ===\n");
        printf("1. Add New Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search for an Asset\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAsset(assets, &assetCount);
                break;
            case 2:
                displayAssets(assets, assetCount);
                break;
            case 3:
                searchAsset(assets, assetCount);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("[ERROR] Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);
}