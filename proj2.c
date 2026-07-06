#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    char category[30];
    float price;
    int quantity;
    float totalValue;
};

void initializeInventory(struct Product inventory[], int *size) {
    *size = 0;
    printf("Inventory initialized with 0 products.\n");
}

void addProduct(struct Product inventory[], int *size) {
    if (*size >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    struct Product newProduct;
    
    printf("\n--- Add New Product ---\n");
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    
    // Check if ID already exists
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == newProduct.id) {
            printf("Product with ID %d already exists!\n", newProduct.id);
            return;
        }
    }
    
    printf("Enter Product Name: ");
    scanf(" %s", newProduct.name);
    
    printf("Enter Category: ");
    scanf(" %s", newProduct.category);
    
    printf("Enter Price: ₹");
    scanf("%f", &newProduct.price);
    
    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    
    newProduct.totalValue = newProduct.price * newProduct.quantity;
    
    inventory[*size] = newProduct;
    (*size)++;
    
    printf("\nProduct added successfully!\n");
    printf("Product ID: %d\n", newProduct.id);
    printf("Name: %s\n", newProduct.name);
    printf("Category: %s\n", newProduct.category);
    printf("Price: ₹%.2f\n", newProduct.price);
    printf("Quantity: %d\n", newProduct.quantity);
    printf("Total Value: ₹%.2f\n", newProduct.totalValue);
}

void displayInventory(struct Product inventory[], int size) {
    if (size == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    
    printf("\n=== INVENTORY REPORT ===\n");
    printf("ID\tName\t\tCategory\tPrice\tQuantity\tTotal Value\n");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        printf("%d\t%-15s\t%-10s\t₹%.2f\t%d\t\t₹%.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].category,
               inventory[i].price,
               inventory[i].quantity,
               inventory[i].totalValue);
    }
}

void searchProduct(struct Product inventory[], int size) {
    int searchId;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);
    
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == searchId) {
            printf("\nProduct Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Category: %s\n", inventory[i].category);
            printf("Price: ₹%.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Total Value: ₹%.2f\n", inventory[i].totalValue);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product not found!\n");
    }
}

void updateQuantity(struct Product inventory[], int size) {
    int searchId, newQuantity;
    printf("\nEnter Product ID to update quantity: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == searchId) {
            printf("Current Quantity: %d\n", inventory[i].quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &newQuantity);
            
            inventory[i].quantity = newQuantity;
            inventory[i].totalValue = inventory[i].price * newQuantity;
            
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    
    printf("Product not found!\n");
}

void displayByCategory(struct Product inventory[], int size) {
    char category[30];
    printf("\nEnter Category to display: ");
    scanf(" %s", category);
    
    int found = 0;
    printf("\n=== Products in Category: %s ===\n", category);
    printf("ID\tName\t\tPrice\tQuantity\tTotal Value\n");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].category, category) == 0) {
            printf("%d\t%-15s\t₹%.2f\t%d\t\t₹%.2f\n",
                   inventory[i].id,
                   inventory[i].name,
                   inventory[i].price,
                   inventory[i].quantity,
                   inventory[i].totalValue);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No products found in category '%s'\n", category);
    }
}

void displayLowStock(struct Product inventory[], int size) {
    int threshold;
    printf("\nEnter stock threshold level: ");
    scanf("%d", &threshold);
    
    printf("\n=== LOW STOCK ALERT ===\n");
    printf("ID\tName\t\tCategory\tQuantity\tPrice\n");
    printf("----------------------------------------------------------------\n");
    
    int lowStockCount = 0;
    for (int i = 0; i < size; i++) {
        if (inventory[i].quantity < threshold) {
            printf("%d\t%-15s\t%-10s\t%d\t\t₹%.2f\n",
                   inventory[i].id,
                   inventory[i].name,
                   inventory[i].category,
                   inventory[i].quantity,
                   inventory[i].price);
            lowStockCount++;
        }
    }
    
    if (lowStockCount == 0) {
        printf("All products have sufficient stock.\n");
    } else {
        printf("\nTotal products needing restock: %d\n", lowStockCount);
    }
}

void generateInventoryReport(struct Product inventory[], int size) {
    float totalValue = 0, totalQuantity = 0;
    int categoryCount[10][2] = {{0}}; // [category][0]=count, [category][1]=totalValue
    char categoryNames[10][30];
    int categoryIndex = 0;
    
    printf("\n=== INVENTORY ANALYSIS REPORT ===\n");
    
    // Calculate totals
    for (int i = 0; i < size; i++) {
        totalValue += inventory[i].totalValue;
        totalQuantity += inventory[i].quantity;
    }
    
    printf("Total Products: %d\n", size);
    printf("Total Quantity: %.0f units\n", totalQuantity);
    printf("Total Inventory Value: ₹%.2f\n", totalValue);
    printf("Average Product Value: ₹%.2f\n", totalValue / size);
    
    // Category-wise analysis
    printf("\n=== CATEGORY-WISE ANALYSIS ===\n");
    printf("Category\tCount\tAvg Value\tTotal Value\n");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < categoryIndex; j++) {
            if (strcmp(categoryNames[j], inventory[i].category) == 0) {
                categoryCount[j][0]++;
                categoryCount[j][1] += inventory[i].totalValue;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            strcpy(categoryNames[categoryIndex], inventory[i].category);
            categoryCount[categoryIndex][0] = 1;
            categoryCount[categoryIndex][1] = inventory[i].totalValue;
            categoryIndex++;
        }
    }
    
    for (int i = 0; i < categoryIndex; i++) {
        float avgValue = categoryCount[i][1] / categoryCount[i][0];
        printf("%-15s\t%d\t₹%.2f\t\t₹%.2f\n",
               categoryNames[i],
               categoryCount[i][0],
               avgValue,
               categoryCount[i][1]);
    }
}

void inventoryManagementSystem() {
    struct Product inventory[MAX_PRODUCTS];
    int size;
    int choice;
    
    initializeInventory(inventory, &size);
    
    do {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product\n");
        printf("4. Update Quantity\n");
        printf("5. Display by Category\n");
        printf("6. Low Stock Alert\n");
        printf("7. Generate Report\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct(inventory, &size);
                break;
            case 2:
                displayInventory(inventory, size);
                break;
            case 3:
                searchProduct(inventory, size);
                break;
            case 4:
                updateQuantity(inventory, size);
                break;
            case 5:
                displayByCategory(inventory, size);
                break;
            case 6:
                displayLowStock(inventory, size);
                break;
            case 7:
                generateInventoryReport(inventory, size);
                break;
            case 8:
                printf("Exiting Inventory Management System...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 8);
}

int main() {
    inventoryManagementSystem();
    return 0;
}
