#include<stdio.h>
#include<string.h>

// Define structures for item, customer, and bill
struct item {
    char item_name[20];
    int item_id;
    int quantity;
    float price;
};

struct customer {
    int customer_id;
    char customer_name[20];
    int phone_no;
};

struct bill {
    int bill_number;
    int bill_items;
    int date;
    float total_amount;
};

// Function to add a new item to the inventory
void addItem(struct item inventory[], int *inventoryCount) {
    struct item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.item_name);
    printf("Enter item ID: ");
    scanf("%d", &newItem.item_id);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);

    inventory[*inventoryCount] = newItem;
    (*inventoryCount)++;
    printf("Item added successfully!\n");
}

// Function to generate a bill
void generateBill(struct item inventory[], int inventoryCount, struct bill *currentBill) {
    int item_id, quantity, index;
    float totalAmount = 0;

    printf("Enter item ID (-1 to end): ");
    while (scanf("%d", &item_id) == 1 && item_id != -1) {
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        for (int i = 0; i < inventoryCount; i++) {
            if (inventory[i].item_id == item_id) {
                index = i;
                totalAmount += inventory[i].price * quantity;
                break;
            }
        }

        printf("Enter next item ID (-1 to end): ");
    }

    currentBill->total_amount = totalAmount;
}

// Function to print a bill
void printBill(struct bill currentBill) {
    printf("\n------ Bill ------\n");
    printf("Bill Number: %d\n", currentBill.bill_number);
    printf("Total Amount: %.2f\n", currentBill.total_amount);
    printf("------------------\n");
}

int main(){
    printf("Welcome to the billing system\n");

    // Sample inventory
    struct item inventory[100]; // Assuming the shop can have up to 100 items
    int inventoryCount = 0;

    // Sample customer
    struct customer currentCustomer;

    // Sample bill
    struct bill currentBill;
    currentBill.bill_number = 1; // Starting bill number

    int choice;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Add Item to Inventory\n");
        printf("2. Generate Bill\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &inventoryCount);
                break;
            case 2:
                if (inventoryCount == 0) {
                    printf("No items in inventory!\n");
                } else {
                    generateBill(inventory, inventoryCount, &currentBill);
                    printf("Bill generated successfully!\n");
                }
                break;
            case 3:
                printBill(currentBill);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
