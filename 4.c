//Q4



#include <stdio.h>

void push(int stack[], int *top, int maxSize){
	if ((*top) == (maxSize-1)){
		printf("Overflow!\n");
	} else{
		(*top)++;
		int item;
		printf("Enter the element to Push: ");
		scanf("%d",&item);
		stack[(*top)] = item;
	}
}

int pop(int stack[], int *top){
	if ((*top) == -1){
		printf("Underflow!\n");
		return -1; //Returns -1 to indicate underflow
	} else{
		printf("Popped element: %d\n",stack[(*top)]);
		(*top)--;
		return (stack[((*top)+1)]);
	}
}

void peek(int stack[], int *top){
	if ((*top) == -1){
		printf("Stack is empty!\n");
	} else{
		printf("Top element: %d", stack[(*top)]);
	}
}

void display(int stack[], int *top){
	if ((*top) == -1){
		printf("Stack is empty!\n");
	} else{
		printf("Top pointer = %d\n",(*top));
		int i;
		printf("======STACK======\n");
		for (i=(*top); i>=0; i--){
			printf("Index %d:\t%d\n",i,stack[i]);
		}
	}
}

int main(){
	int i, stackSize, userChoice, topPointer=-1, poppedElement;
	
	printf("Enter the size you want to set for stack: ");
	scanf("%d",&stackSize);
	
	int myStack[stackSize];
	
	do {
		printf("\n");
		
		printf("Choose an option:\n");
		printf("1) PUSH (insert an element into stack)\n");
		printf("2) POP (remove an element from stack)\n");
		printf("3) PEEK (display top element without removal)\n");
		printf("4) DISPLAY (display all elements without removal)\n");
		printf("5) EXIT\n");
		
		scanf("%d",&userChoice);
		printf("\n");
		
		switch(userChoice){
			case 1:
				push(myStack,&topPointer,stackSize);
				break;
			case 2:
				poppedElement = pop(myStack,&topPointer);
				break;
			case 3:
				peek(myStack,&topPointer);
				break;
			case 4:
				display(myStack,&topPointer);
				break;
			case 5:
				printf("Exiting...");
				break;
			default:
				printf("Choose a valid option!\n");
		}
		printf("\n");
	}while(userChoice!=5);
	
	return 0;
}