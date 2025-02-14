#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void clearScreen(){
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
};

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
	int valid=0;
	
	while(!valid){
		valid=1; // Gia dinh du lieu hop le la 1, neu co loi thi dat thanh 0
		
		printf("\nEnter the book ID: ");
		scanf("%s", newBook.bookId);
		
		//Kiem tra ID khong bi trung
		for(int i=0; i<book_count; i++){
			if(strcmp(library[i].bookId, newBook.bookId)==0){
				printf("Error: Book ID already exists! Please re-enter.\n");
				valid=0;
				break;
			}
		}
		
		//Kiem tra do dai ID
		if(strlen(newBook.bookId)<1 || strlen(newBook.bookId)>9){
			printf("Error: Invalid book ID (1-9 characters)!\n");
			valid=0;
		}
		
		printf("Enter the title of the book: ");
		getchar(); // xoa bo dem
		fgets(newBook.title, sizeof(newBook.title), stdin);
		newBook.title[strcspn(newBook.title, "\n")] = 0; // bo ki tu xuong dong cua fgets
		
		//Kiem tra ten sach khong bi trung
		for(int i=0;i<book_count; i++){
			if(strcmp(library[i].title, newBook.title)==0){
				printf("Error: Book title already exists! Please re-enter.\n");
				valid=0;
				return;
			}
		}
		
		//Kiem tra do dai tieu de
		if(strlen(newBook.title)<1 || strlen(newBook.title)>29){
			printf("Error: Invalid book title (1-29 characters)!\n");
			valid=0;
		}
		
		printf("Enter the author of the book: ");
		fgets(newBook.author, sizeof(newBook.author), stdin);
		newBook.author[strcspn(newBook.author, "\n")] = 0; // bo ki tu xuong dong cua fgets
		
		//Kiem tra khong duoc bo trong
		if(strlen(newBook.author)<1){
			printf("Error: Author name cannot be blank!\n");
			valid=0;
		}
		
		printf("Enter the amount: ");
		if(scanf("%d",&newBook.quantity)!=1 || newBook.quantity<=0){
			printf("Error: Quantity must be a positive integer!\n");
			valid=0;
		}
		
		printf("Enter price: ");
		if(scanf("%d",&newBook.price)!=1 || newBook.price<=0){
			printf("Error: Price must be a positive integer!\n");
			valid=0;
		}
		
		printf("Enter the publication date(dd mm yyyy): ");
		if(scanf("%d %d %d", &newBook.publication.day, &newBook.publication.month, &newBook.publication.year) != 3 || newBook.publication.day < 1 || newBook.publication.day > 31 || newBook.publication.month < 1 || newBook.publication.month > 12 || newBook.publication.year < 1000 || newBook.publication.year > 9999){
			printf("Error: Invalid publication date!\n");
			valid=0;
		}
		
		getchar();
		
		if(!valid){
			printf("\nPlease re-enter book information.\n");
		}
	}
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

void deleteBook(){
	char bookId[10];
	printf("\n%28s\n","***Delete A Book***");
	printf("=====================================");
	printf("\nEnter the bookID to delete: ");
	scanf("%s",&bookId);
	for(int i=0; i<book_count; i++){
		if(strcmp(library[i].bookId, bookId)==0){
			char confirm[10];
			printf("\nAre you sure you want to delete this book? (y/n): ");
			getchar();
			fgets(confirm, sizeof(confirm), stdin);
			
			if(confirm[0]=='y' || confirm[0]=='Y'){
				for(int j=i; j<book_count-1; j++){
					library[j]=library[j+1];
				}
				book_count--;
				printf("\nThe book has been successfully deleted!\n");
			}else{
				printf("\nCancel deletion of books!\n");
			}
			returnToMenu();
			return;
		}
	}
	printf("\nNo books found.\n");
	returnToMenu();
}

void sortBooksByPrice(){
	if(book_count==0){
		printf("\nThere are no books to sort.\n");
		returnToMenu();
		return;
	}
	int choice;
	printf("\n%28s\n","***Sort the book list***");
	printf("================================");
	printf("\nSelect sort order:\n");
	printf("1. Gradually increase\n");
	printf("2. Gradually decreasing\n");
	printf("Enter selection: ");
	scanf("%d",&choice);

	for(int i=0; i<book_count-1; i++){
		for(int j=i+1; j<book_count; j++){
			if(choice==1 && library[i].price > library[j].price || (choice==2 && library[i].price < library[j].price)){
				Book temp=library[i];
				library[i]=library[j];
				library[j]=temp;
			}
		}
	}
	printf("\nList of books after sorting:\n");
	displayBooks();
}

void searchBookByTitle(){
	char searchTitle[30];
	printf("\n%25s\n","***Search for books***");
	printf("============================");
	printf("\nEnter the title of the book you want to search for: ");
	getchar();
	fgets(searchTitle,sizeof(searchTitle),stdin);
	searchTitle[strcspn(searchTitle,"\n")]=0;

	int found=0;
	printf("\nSearch results:\n");
	printf("\n|===========================================================================================|\n");
	printf("|%-10s|%-30s|%-20s|%-8s|%-8s|%-10s|\n","Book ID","Title","Author","Quantity","Price","Publish");
	printf("|===========================================================================================|\n");

	for(int i=0; i<book_count; i++){
		if(strstr(library[i].title, searchTitle)!=NULL){
			printf("|%-10s|%-30s|%-20s|%-8d|%-8d|%2d/%2d/%4d|",library[i].bookId, library[i].title, library[i].author,library[i].quantity, library[i].price, library[i].publication.day, library[i].publication.month, library[i].publication.year);	
			found=1;
		}
	}
	printf("\n|===========================================================================================|\n");
	if(!found){
		printf("\nNo books found with that title.\n");
	}
	returnToMenu();
}

void returnToMenu(){
	int choice;
	printf("\nExit(0): ");
	scanf("%d",&choice);
	clearScreen();
}
