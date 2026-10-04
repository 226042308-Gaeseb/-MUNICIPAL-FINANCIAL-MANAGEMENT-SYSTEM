#include <stdio.h>
#include <string.h>
#include "assets.h"

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
    scanf(" %[^\n]", newAsset.department);

    printf("Enter Condition (Good/Fair/Poor): ");
    scanf(" %[^\n]", newAsset.condition);

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