#include <stdio.h>
#include "library.h"

int main(){
	int choice;
	do{
		displayMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				displayBooks();
				break;
			case 2:
				addBook();
				break;
			case 3:
				editBook();
				break;
			case 4:
				printf("\nExit the program.\n");
				break;
			default:
				printf("\nInvalid selection, please select again.\n");
			}
		}while(choice!=4);
	return 0;
}
