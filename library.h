#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100

typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct{
	int bookId[10];
	char title[30];
	char author[20];
	int quantity;
	int price;
	Date publication;
}Book;

extern Book library[MAX_BOOKS];
extern int book_count;

void displayMenu();
void displayBooks();
void addBook();
void editBook();
void deleteBook();
void sortBooksByPrice();
void searchBookByTitle();
void returnToMenu();
void clearScreen();

#endif // Dong lai pham vi cua #ifndef
