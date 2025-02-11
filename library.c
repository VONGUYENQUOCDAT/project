#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

Book library[MAX_BOOKS];
int book_count=0;

void displayBooks(){
	if(book_count == 0){
		printf("\nThere are no books in the reception.\n");
	}else{
		printf("\n%53s","****ALL BOOKS****");
		printf("\n|===========================================================================================|\n");
		printf("|%-10s|%-30s|%-20s|%-8s|%-8s|%-10s|\n","Book ID","Title","Author","Quantity","Price","Publish");
		printf("|===========================================================================================|\n");
		for(int i=0; i<book_count; i++){
			printf("|%-10s|%-30s|%-20s|%-8d|%-8d|%2d/%2d/%4d|",library[i].bookId, library[i].title, library[i].author,library[i].quantity, library[i].price, library[i].publication.day, library[i].publication.month, library[i].publication.year);
			printf("\n|-------------------------------------------------------------------------------------------|\n");
		}
	}
	returnToMenu();
}

void addBook(){
	if(book_count>=MAX_BOOKS){
		printf("\nThe staff is full, can't add any more books");
		return;
	}
	printf("\n%30s\n","***Add A New Book***");
	printf("========================================");
	Book newBook;
	
	printf("\nEnter the book ID: ");
	scanf("%s", newBook.bookId);
	
	printf("Enter the title of the book: ");
	getchar(); // xoa bo dem
	fgets(newBook.title, sizeof(newBook.title), stdin);
	newBook.title[strcspn(newBook.title, "\n")] = 0; // bo ki tu xuong dong cua fgets
	
	printf("Enter the author of the book: ");
	fgets(newBook.author, sizeof(newBook.author), stdin);
	newBook.author[strcspn(newBook.author, "\n")] = 0; // bo ki tu xuong dong cua fgets
	
	printf("Enter the amount: ");
	scanf("%d",&newBook.quantity);
	
	printf("Enter price: ");
	scanf("%d",&newBook.price);
	
	printf("Enter the publication date(dd mm yyyy): ");
	scanf("%d %d %d",&newBook.publication.day,&newBook.publication.month,&newBook.publication.year);
	
	library[book_count++] = newBook;// Them sach moi vao mang library tai vi tri book_count va tang bien dem len 1.
	printf("\nBook Added successfully!\n");
	returnToMenu();
}

void editBook(){
	char bookId[10];
	printf("\n%28s\n","***Edit A Book***");
	printf("=======================================");
	printf("\nEnter the book code to be edited: ");
	scanf("%s", &bookId);
	for(int i=0; i<book_count; i++){
		if(strcmp(library[i].bookId, bookId)==0){ //so sanh ma sach trong bang va ma sach vua nhap
			printf("\n***Current book information***\n");
			printf("------------------------------\n");
			printf("Title: %s\n",library[i].title);
			printf("Author: %s\n",library[i].author);
			printf("Quantity: %d\n",library[i].quantity);
			printf("Price: %d\n",library[i].price);
			printf("Publication date: %2d/%2d/%4d\n",library[i].publication.day,library[i].publication.month,library[i].publication.year);
			
			printf("\n%35s\n","***Update A New Book***");
			printf("Enter the title of the book: ");
			getchar(); // xoa bo dem
			fgets(library[i].title, sizeof(library[i].title), stdin);
			library[i].title[strcspn(library[i].title, "\n")] = 0; // bo ki tu xuong dong cua fgets
			
			printf("Enter the price of the book: ");
			fgets(library[i].author, sizeof(library[i].author), stdin);
			library[i].author[strcspn(library[i].author, "\n")] = 0; // bo ki tu xuong dong cua fgets
			
			printf("Enter the amount: ");
			scanf("%d",&library[i].quantity);
			
			printf("Enter price: ");
			scanf("%d",&library[i].price);
			
			printf("Enter the publication date(dd mm yyyy): ");
			scanf("%d %d %d",&library[i].publication.day, &library[i].publication.month, &library[i].publication.year);
			
			printf("\nBook Updated Successfully!\n");
			returnToMenu();
			return;
		}
	}
	printf("\nNo books found.\n");
	returnToMenu();
}

void returnToMenu(){
	int choice;
	printf("\nExit(0): ");
	scanf("%d",&choice);
}
