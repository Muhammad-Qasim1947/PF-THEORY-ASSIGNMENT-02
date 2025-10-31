#include <stdio.h>

int isbns[100];
char titles[100][50];
float prices[100];
int quantities[100];
int numberOfTitles = 0;

void addnewbook() {
    int isbn, quantity;
    float price;
    char title[50];

    printf("Enter The Book ISBN Number: ");
    scanf("%d", &isbn);

    printf("\nEnter The Book Quantity: ");
    scanf("%d", &quantity);

    printf("\nEnter The Book Price: ");
    scanf("%f", &price);

    printf("\nEnter The Book Title: ");
    scanf(" %[^\n]", title);

    int i = 0;
    while (i < numberOfTitles) {
        if (isbns[i] == isbn) {
            break;
        } else {
            i++;
        }
    }

    if (i < numberOfTitles) {
        // If ISBN already exists, just update quantity
        quantities[i] += quantity;
    } else {
        // If it's a new book, add new data
        isbns[i] = isbn;
        prices[i] = price;
        quantities[i] = quantity;

        int j = 0;
        while (title[j] != '\0') {
            titles[numberOfTitles][j] = title[j];
            j++;
        }
        titles[numberOfTitles][j] = '\0';

        numberOfTitles++;
    }

    printf("Book Added Successfully!\n");
}

void processSale() {
    int isbn, numbersold;
    printf("Enter Book ISBN Number: ");
    scanf("%d", &isbn);
    printf("Enter Number Of Books Sold: ");
    scanf("%d", &numbersold);

    int i = 0;
    while (i < numberOfTitles) {
        if (isbns[i] == isbn) {
            break;
        } else {
            i++;
        }
    }

    if (i == numberOfTitles) {
        printf("Error! Book not found.\n");
    } else {
        if (quantities[i] == 0) {
            printf("The Book Is Out Of Stock.\n");
        } else if (quantities[i] < numbersold) {
            printf("Error! Only %d books left.\n", quantities[i]);
            printf("Do you want to sell all remaining? (1=Yes, 2=No): ");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                quantities[i] = 0;
                printf("Sale Processed!\n");
            } else {
                printf("Sale Not Processed!\n");
            }
        } else {
            quantities[i] -= numbersold;
            printf("Sale Processed!\n");
        }
    }
}

void lowstockreport() {
    if (numberOfTitles == 0) {
        printf("Error! No books found!\n");
    } else {
        printf("===LOW STOCK REPORT===\n");
        for (int i = 0; i < numberOfTitles; i++) {
            if (quantities[i] < 5) {
                printf("ISBN: %d, Title: %s, Price: %.2f, Quantity: %d\n",
                       isbns[i], titles[i], prices[i], quantities[i]);
            }
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n1) Add a New Book\n");
        printf("2) Process a Sale\n");
        printf("3) Low Stock Report\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addnewbook();
                break;
            case 2:
                processSale();
                break;
            case 3:
                lowstockreport();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option!\n");
        }
    } while (choice != 4);

    return 0;
}
