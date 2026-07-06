#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50

struct Address {
    char street[50];
    char city[30];
    char state[30];
    char pinCode[10];
};

struct Item {
    int code;
    char description[50];
    int quantity;
    float unitPrice;
    float totalAmount;
};

struct Invoice {
    int invoiceNumber;
    char date[12];
    char customerName[50];
    struct Address customerAddress;
    struct Item items[MAX_ITEMS];
    int itemCount;
    float subTotal;
    float gst;
    float totalAmount;
    char paymentMode[20];
    time_t timestamp;
};

void getCurrentDate(char *dateStr) {
    time_t now = time(NULL);
    struct tm *localTime = localtime(&now);
    strftime(dateStr, 12, "%d-%m-%Y", localTime);
}

void generateInvoiceNumber(int *invoiceNumber) {
    static int counter = 1000;
    *invoiceNumber = counter++;
}

void initializeInvoice(struct Invoice *invoice) {
    generateInvoiceNumber(&invoice->invoiceNumber);
    getCurrentDate(invoice->date);
    invoice->itemCount = 0;
    invoice->subTotal = 0;
    invoice->gst = 0;
    invoice->totalAmount = 0;
    invoice->timestamp = time(NULL);
}

void addItemToInvoice(struct Invoice *invoice) {
    if (invoice->itemCount >= MAX_ITEMS) {
        printf("Maximum items limit reached!\n");
        return;
    }
    
    struct Item newItem;
    
    printf("\n--- Add Item to Invoice ---\n");
    printf("Enter Item Code: ");
    scanf("%d", &newItem.code);
    
    printf("Enter Item Description: ");
    scanf(" %s", newItem.description);
    
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter Unit Price (₹): ");
    scanf("%f", &newItem.unitPrice);
    
    newItem.totalAmount = newItem.quantity * newItem.unitPrice;
    
    // Check if item already exists
    for (int i = 0; i < invoice->itemCount; i++) {
        if (invoice->items[i].code == newItem.code) {
            invoice->items[i].quantity += newItem.quantity;
            invoice->items[i].totalAmount = invoice->items[i].quantity * invoice->items[i].unitPrice;
            printf("Item quantity updated!\n");
            return;
        }
    }
    
    invoice->items[invoice->itemCount] = newItem;
    invoice->itemCount++;
    invoice->subTotal += newItem.totalAmount;
    
    printf("\nItem added successfully!\n");
    printf("Code: %d | Description: %s | Qty: %d | Price: ₹%.2f | Total: ₹%.2f\n",
           newItem.code, newItem.description, newItem.quantity, 
           newItem.unitPrice, newItem.totalAmount);
}

void enterCustomerDetails(struct Invoice *invoice) {
    printf("\n--- Customer Details ---\n");
    printf("Enter Customer Name: ");
    scanf(" %s", invoice->customerName);
    
    printf("Enter Street Address: ");
    scanf(" %s", invoice->customerAddress.street);
    
    printf("Enter City: ");
    scanf(" %s", invoice->customerAddress.city);
    
    printf("Enter State: ");
    scanf(" %s", invoice->customerAddress.state);
    
    printf("Enter Pin Code: ");
    scanf(" %s", invoice->customerAddress.pinCode);
}

float calculateGST(float amount, int itemCount) {
    // Higher GST for more items, different tax rates
    if (itemCount <= 3) return amount * 0.05;
    if (itemCount <= 6) return amount * 0.12;
    return amount * 0.18;
}

void generateInvoice(struct Invoice invoice) {
    printf("\n=================================================\n");
    printf("                    INVOICE\n");
    printf("=================================================\n");
    printf("INVOICE NO: %06d\n", invoice.invoiceNumber);
    printf("DATE: %s\n", invoice.date);
    printf("TIME: %s", ctime(&invoice.timestamp));
    
    printf("\n-------------------------------------------------\n");
    printf("BILL TO:\n");
    printf("Name: %s\n", invoice.customerName);
    printf("Address: %s, %s\n", 
           invoice.customerAddress.street,
           invoice.customerAddress.city);
    printf("State: %s | Pin: %s\n", 
           invoice.customerAddress.state,
           invoice.customerAddress.pinCode);
    
    printf("\n-------------------------------------------------\n");
    printf("ITEM DETAILS\n");
    printf("-------------------------------------------------\n");
    printf("S.No\tCode\tDescription\tQuantity\tUnit Price\tTotal Amount\n");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < invoice.itemCount; i++) {
        printf("%d\t%d\t%-15s\t%d\t\t₹%.2f
