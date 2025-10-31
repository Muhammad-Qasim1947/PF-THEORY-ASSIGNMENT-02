#include <stdio.h>
#include <string.h>

char customername[50], customercnic[50];

int productcode[4] = {1, 2, 3, 4};
int stock[4] = {50, 10, 20, 8};
int priceperprod[4] = {100, 200, 300, 150};

int cartcode[10];
int cartqty[10];
int cartcount = 0;

float totalbill = 0;
float discountedbill = 0;
float promoapplied = 0;

void customerinfo() {
    printf("\n--------------------------------------\n");
    printf("Please Enter Your Name: ");
    scanf("%s", customername);
    printf("\nHi %s! Please Enter Your CNIC Number: ", customername);
    scanf("%s", customercnic);
    printf("--------------------------------------\n");
}

void displayinventory() {
    printf("\n------------- Inventory -------------\n");
    printf("Code\tQuantity\tPrice\n");
    for (int i = 0; i < 4; i++) {
        printf("00%d\t%d\t\t%d\n", productcode[i], stock[i], priceperprod[i]);
    }
    printf("--------------------------------------\n");
}

void additem() {
    int code, qty, found = 0;
    displayinventory();

    printf("\nEnter The Product Code: ");
    scanf("%d", &code);
    printf("Enter The Quantity: ");
    scanf("%d", &qty);

    for (int i = 0; i < 4; i++) {
        if (productcode[i] == code) {
            found = 1;
            if (qty > stock[i]) {
                printf("\nNot Enough Stock Available. Sorry :(\n");
                return;
            }
            cartcode[cartcount] = code;
            cartqty[cartcount] = qty;
            cartcount++;
            printf("\n%d of Product 00%d added to cart.\n", qty, code);
            return;
        }
    }
    if (!found)
        printf("\n Invalid Product Code.\n");
}

void updateinventory() {
    for (int i = 0; i < cartcount; i++) {
        for (int j = 0; j < 4; j++) {
            if (cartcode[i] == productcode[j]) {
                stock[j] -= cartqty[i];
            }
        }
    }
}

void displaytotalbill() {
    totalbill = 0;
    for (int i = 0; i < cartcount; i++) {
        for (int j = 0; j < 4; j++) {
            if (cartcode[i] == productcode[j]) {
                totalbill += priceperprod[j] * cartqty[i];
            }
        }
    }

    printf("\n--------------------------------------\n");
    printf("Total Bill Without Discount: %.2f\n", totalbill);

    char promocode[20];
    printf("Enter Promo Code If Any: ");
    scanf("%s", promocode);

    if (strcmp(promocode, "QASIM123") == 0) {
        discountedbill = 0.75 * totalbill;
        promoapplied = 1;
        printf("\nYou Have Availed A Discount Of 25%%!\n");
    } else {
        discountedbill = totalbill;
        promoapplied = 0;
        printf("\nNo Promo Applied.\n");
    }
    printf("--------------------------------------\n");

    updateinventory();
}

void invoice() {
    printf("\n=========== CUSTOMER INVOICE ===========\n");
    printf("Customer Name : %s\n", customername);
    printf("Customer CNIC : %s\n", customercnic);
    printf("----------------------------------------\n");
    printf("Code\tQty\tPrice\tTotal\n");

    for (int i = 0; i < cartcount; i++) {
        for (int j = 0; j < 4; j++) {
            if (cartcode[i] == productcode[j]) {
                printf("00%d\t%d\t%d\t%.2f\n", productcode[j], cartqty[i], priceperprod[j],
                       (float)priceperprod[j] * cartqty[i]);
            }
        }
    }

    printf("----------------------------------------\n");
    printf("Bill without discount: %.2f\n", totalbill);
    if (promoapplied)
        printf("Bill with discount: %.2f\n", discountedbill);
    else
        printf("No discount applied. Total: %.2f\n", discountedbill);
    printf("========================================\n");
}

int main() {
    int choice;
    printf("\n--- Supermarket Management System ---\n");

    do {
        printf("\n1. Enter Customer Info");
        printf("\n2. Display Inventory");
        printf("\n3. Add Item to Cart");
        printf("\n4. Display Total Bill");
        printf("\n5. Show Invoice");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerinfo();
                break;
            case 2:
                displayinventory();
                break;
            case 3:
                additem();
                break;
            case 4:
                displaytotalbill();
                break;
            case 5:
                invoice();
                break;
            case 6:
                printf("\nExiting system... Thank you for shopping!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
