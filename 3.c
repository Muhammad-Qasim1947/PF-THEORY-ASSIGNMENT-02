// Q3



#include <stdio.h>

void update(int array[20][20]){
	int row, column, flagNumber, operation;
	printf("Enter the sector coordinates:\n");
	printf("  Row: ");
	scanf("%d",&row);
	printf("  Column: ");
	scanf("%d",&column);
	printf("Which field do you want to update?\n");
	printf(" 1) Power,\n 2) Overload Warning,\n 3) Maintenance Required.\n");
	scanf("%d",&flagNumber);
	printf("Choose an operation:\n");
	printf(" 1) Set,\n 2) Clear.\n");
	scanf("%d",&operation);
	switch (flagNumber){
		case 1:
			switch(operation){
				case 1:
					array[row][column] = array[row][column] | 1; //OR with 001 sets Bit 0
					break;
				case 2:
					array[row][column] = array[row][column] & 6; //AND with 110 clears Bit 0
					break;
				default:
					printf("Invalid operation!\n");
			}
			break;
		case 2:
			switch(operation){
				case 1:
					array[row][column] = array[row][column] | 2; //OR with 010 sets Bit 1
					break;
				case 2:
					array[row][column] = array[row][column] & 5; //AND with 101 clears Bit 1
					break;
				default:
					printf("Invalid operation!\n");
			}
			break;
		case 3:
			switch(operation){
				case 1:
					array[row][column] = array[row][column] | 4; //OR with 100 sets Bit 2
					break;
				case 2:
					array[row][column] = array[row][column] & 3; //AND with 011 clears Bit 2
					break;
				default:
					printf("Invalid operation!\n");
			}
			break;
		default:
			printf("Ivalid field!\n");
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

int diagnostic(int array[20][20]){
	int faultySectors = 0, i, j;
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			if ((array[i][j]&6)!=0){
				faultySectors += 1;
			}
		}
	}
	return faultySectors;
}

int main(){
	printf("=== IESCO Power Grid Monitoring System ===\n\n\n");
	
	int grid[20][20]; //Assuming that there are total 400 sectors in a 20 X 20 layout
	
	int choice;
	
	do {
		printf("Select an option:\n");
		printf(" 1) Update Sector Status,\n");
		printf(" 2) Query Sector Status,\n");
		printf(" 3) Run System Diagnostic,\n");
		printf(" 4) Exit System.\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				update(grid);
				break;
			case 2:
				query(grid);
				break;
			case 3:
				printf("There are %d sectors that are overloaded or require maintenance!\n",diagnostic(grid));
				break;
			case 4:
				printf("Exiting...");
				break;
			default:
				printf("Choose a Valid Option!!\n");
		}
		printf("\n\n");
	} while (choice != 4);
	
	return 0;
}