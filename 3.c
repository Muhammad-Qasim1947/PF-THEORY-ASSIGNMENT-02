#include <stdio.h>

void update(int array[20][20]){
    int row, column, flagNumber, operation;

    printf("Enter the sector coordinates:\n");
    printf("  Row: ");
    scanf("%d", &row);
    printf("  Column: ");
    scanf("%d", &column);

    printf("Which field do you want to update?\n");
    printf(" 1) Power\n 2) Overload Warning\n 3) Maintenance Required\n");
    scanf("%d", &flagNumber);

    printf("Choose an operation:\n");
    printf(" 1) Set\n 2) Clear\n");
    scanf("%d", &operation);

    switch (flagNumber){
    case 1:
        switch (operation){
        case 1:
			array[row][column] = array[row][column] | 1; //OR with 010 sets Bit 0
				break;
		case 2:
			array[row][column] = array[row][column] & 6; //AND with 101 clears Bit 0
				break;
		default:
			printf("Invalid operation!\n");
        } 
    break;

    case 2:
        switch (operation){
        case 1 :	
            array[row][column] = array[row][column] | 2; //OR with 001 sets Bit 1
				break;
		case 2:
			array[row][column] = array[row][column] & 5; //AND with 110 clears Bit 1
				break;
        default:
            printf("Invalid Operation!\n");    
        }
    break;
    
    case 3:
        switch (operation){
        case 1 :	
            array[row][column] = array[row][column] | 4; //OR with 100 sets Bit 2
				break;
		case 2:
			array[row][column] = array[row][column] & 3; //AND with 011 clears Bit 2
				break;
        default:
            printf("Invalid Operation!\n");    
        }
    break;

    default:
    printf("Invalie Field!\n");
    }
}

void query(int array[20][20]){
	int row, column, bit0, bit1, bit2;
	printf("Enter the sector coordinates:\n");
	printf("  Row: ");
	scanf("%d",&row);
	printf("  Column: ");
	scanf("%d",&column);
	bit0 = array[row][column] & 1; //AND with 001 gives Bit 0
	bit1 = array[row][column] & 2; //AND with 010 gives Bit 1
	bit2 = array[row][column] & 4; //AND with 100 gives Bit 2
	printf("QUERY REPORT\n");
	if (bit0 == 0){
		printf("-> Sector's Power is OFF\n");
	} else{
		printf("-> Sector's Power is ON\n");
	}
	if (bit1 == 0){
		printf("-> Sector IS NOT Overloaded\n");
	} else{
		printf("-> Sector IS Overloaded\n");
	}
	if (bit2 == 0){
		printf("-> Sector DOES NOT Require Maintenance\n");
	} else{
		printf("-> Sector DOES Require Maintenance\n");
	}
}



int main(){
    
}