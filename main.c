#include <stdio.h>
#include "library.h"

int main(){
	if(authenticateAdmin()){
	int choice;
	do{
		displayMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				clearScreen();
				loadBooksFromFile();
				displayBooks();
				break;
			case 2:
				clearScreen();
				addBook();
				saveBooksToFile();
				break;
			case 3:
				clearScreen();
				editBook();
				saveBooksToFile();
				break;
			case 4:
				clearScreen();
				deleteBook();
				saveBooksToFile();
				break;
			case 5:
				clearScreen();
				sortBooksByPrice();
				saveBooksToFile();
				break;
			case 6:
				clearScreen();
				searchBookByTitle();
				break;
			case 7:
				clearScreen();
				printf("\n========= Thank You =========\n");
				printf("======== See You Soon =======\n");
				break;
			default:
				clearScreen();
				printf("\nInvalid selection, please select again.\n");
			}
		}while(choice!=7);
	}
	return 0;
}
