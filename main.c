#include <stdio.h>
#include "library.h"

int main(){
	int choice;
	do{
		displayMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				clearScreen();
				displayBooks();
				break;
			case 2:
				clearScreen();
				addBook();
				break;
			case 3:
				clearScreen();
				editBook();
				break;
			case 4:
				clearScreen();
				deleteBook();
				break;
			case 5:
				clearScreen();
				sortBooksByPrice();
				break;
			case 6:
				clearScreen();
				searchBookByTitle();
				break;
			case 7:
				clearScreen();
				printf("\nExit the program.\n");
				break;
			default:
				clearScreen();
				printf("\nInvalid selection, please select again.\n");
			}
		}while(choice!=7);
	return 0;
}
