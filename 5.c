#include <stdio.h>

void encodeMessage(char message[])
{
    // Calculate length
    int length = 0;
    while (message[length] != '\0')
    {
        length++;
    }

    // Reverse the message
    for (int i = 0; i < length / 2; i++)
    {
        char temp = message[i];
        message[i] = message[length - i - 1];
        message[length - i - 1] = temp;
    }

    // Bitwise XOR encoding
    for (int i = 0; i < length; i++)
    {
        message[i] = message[i] ^ 18; // XOR with 00010010
    }

    printf("\nEncoded Message: %s\n", message);
}

void decodeMessage(char message[])
{
    int length = 0;
    while (message[length] != '\0')
    {
        length++;
    }

    // Bitwise XOR decoding
    for (int i = 0; i < length; i++)
    {
        message[i] = message[i] ^ 18; // XOR with 00010010
    }

    // Reverse the message
    for (int i = 0; i < length / 2; i++)
    {
        char temp = message[i];
        message[i] = message[length - i - 1];
        message[length - i - 1] = temp;
    }

    printf("\nDecoded Message: %s\n", message);
}

int main()
{
    printf("===TCS ENCODING / DECODING SYSTEM===\n\n");
    char inputMessage[100];
    int choice;

    do
    {
        printf("Choose an Option:\n");
        printf(" 1) Encode a Message,\n");
        printf(" 2) Decode a Message,\n");
        printf(" 3) Exit.\n");
        scanf("%d", &choice);
        getchar(); // consume leftover newline

        switch (choice)
        {
            case 1:
                printf("Enter the Message to Encode:\n");
                scanf(" %[^\n]", inputMessage);
                encodeMessage(inputMessage);
                break;
            case 2:
                printf("Enter the Message to Decode:\n");
                scanf(" %[^\n]", inputMessage);
                decodeMessage(inputMessage);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Choose a Valid Option!\n");
        }

        printf("\n");

    } while (choice != 3);

    return 0;
}
