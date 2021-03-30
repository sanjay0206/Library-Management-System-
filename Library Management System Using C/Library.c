#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lastindex = 0;
struct Book
{
     char item_name[50];
     char author_name[50];
     char published_year[50];
}books[100];

typedef Book book;

void addBooks(int size){
int count = lastindex + size;
for(int i=lastindex;i<count;i++)
     {
          printf("\\nEnter book-%d Details",i+1);
          printf("\n--------------------------\n");
          printf("Enter item_name     : ");
          scanf("%s",books[i].item_name);
          printf("Enter author_name        : ");
          scanf("%s",books[i].author_name);
          printf("Enter published_year       : ");
          scanf("%s",books[i].published_year);
          lastindex ++;
     }
}
void addExtraItems(){
     int n;
     printf("How many book records you want to enter?");
     printf("\nEnter Limit : ");
     scanf("%d",&n);
     addBooks(n);
}

void sort_book_by_item(){
  book temp;
  for(int i=0;i<lastindex;i++)
     {
          for(int j=0;j<lastindex-i-1;j++)
          {
               if(strcmp(books[j].item_name,books[j+1].item_name) > 0)
               {
                    temp = books[j];
                    books[j] = books[j+1];
                    books[j+1] = temp;
               }
          }
     }
}
void sort_book_by_author(){
  book temp;
  for(int i=0;i<lastindex;i++)
     {
          for(int j=0;j<lastindex-i-1;j++)
          {
               if(strcmp(books[j].author_name,books[j+1].author_name) > 0)
               {
                    temp = books[j];
                    books[j] = books[j+1];
                    books[j+1] = temp;
               }
          }
     }
}

void sort_book_by_published_year(){
  book temp;
  for(int i=0;i<lastindex;i++)
     {
          for(int j=0;j<lastindex-i-1;j++)
          {
               if(strcmp(books[j].published_year, books[j+1].published_year) > 0)
               {
                    temp = books[j];
                    books[j] = books[j+1];
                    books[j+1] = temp;
               }
          }
     }
}
void displayBooks(){
 printf("\n\tBooks available in Mysore Library");
     printf("\n------------------------------------------\n");
     printf("book name\tAuthor\t published_year\n");
     printf("--------------------------------------------\n\n");
     for(int i=0;i<lastindex;i++)
     {
          printf("%s\t\t%s\t%s\n\n",books[i].item_name,books[i].author_name,books[i].published_year);
     }
}
void showMenu(){
    printf("1. Add new Book/Books\n"); 
    printf("2. Display Books in Library\n"); 
    printf("3. Sort by item Name\n"); 
    printf("4. Sort by Author Name\n"); 
    printf("5. Sort by Published year\n"); 
    printf("6. To Exit\n"); 
    printf("Enter your choice:\n");
}
int main()
{
 char c,q = 1;
    while (q){
        showMenu();
        scanf(" %c", &c);;
        switch (c){
            case '1':{addExtraItems();} break;
            case '2':{displayBooks();} break;
            case '3':{sort_book_by_item();} break;
            case '4':{sort_book_by_author();} break;
            case '5':{sort_book_by_published_year();} break;
            case '6':{q =0;} break;
            break;
        }
    }
}