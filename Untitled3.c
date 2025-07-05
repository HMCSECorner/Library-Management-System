#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct book{
    int id;
    char bookname[50];
    char authorName[50];
    char data[12];
}b;

struct student{
    int id[50];
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName;
    char date[12];
}s;

FILE*fp;

int main(){
    int ch;

    while(1){
        system("cls");
        printf("<==Library Management System==>\n");
        printf("1. Add Book\n");
        printf("2. Book List\n");
        printf("3. Remove Book\n");
        printf("4. Issue Book\n");
        printf("5. Issued Book List\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
    case 0:
        exit(0);
    case 1:
        addBook();
        break;
    case 2:
        bookList();
        break;
    case 3:
        del();
        break;
    case 4:
        issueBook();
        break;
    case 5:
        issueList();
        break;
    default:
        printf("Invalid Choice...");
        }
        printf("Press any key to continue...");
        getch();
    }
    return 0;

}

void addBook(){
    char myData[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myData, "%0.2d/%0.2d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900);
    strcpy(b.date,myDate);

    fp = fopen("books.txt","ab");

    printf("Enter book id: ");
    scanf("%d",&b.id);

    printf("Enter Book Name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("Enter Author Name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("Book Added Successfully");

    fwrite(&b, sizeof(b),1,fp);
    fclose(fp);

}

void bookList(){
    system("cls");
    printf("<== Available Books ==>\n\n");
    printf("%-10s %-30s %-20s %s\n\n","Book id","Book Name","Author","Date");

    fp = fopen("books.txt","rb");
    while(fread(&b,sizeof(b),1,fp)==1){
        printf("%-10 %-30s %-20s %s\n\n",b.id,b.bookName,b.authorName,b.date);
    }
    fclose(fp);
}


/*void password();
void heading();

int main()
{
    password();
}
void heading(){
    system("cls");
    printf("\n\n\t\t\t\t************ Library Project ************\n");

    fflush( stdin );
    getchar();
}
void password(){
    heading();

    char pwd1[10] = ["admin"];
    char pwd2[10] ;

    printf("\n\t\tEnter Password: ");
    scanf("%s",pwd2);
    if(strcmp(pwd1,pwd2)==0)
    {
        printf("\n\n\t\t Match Password!\n")
        printf("\n\t\t Press any key...");
    }
    else{
        printf("\n\n \t\t Wrong Password\n");
        printf("\n\n \t\t Try Again\n");

        fflush(stdin);
        getchar();

        password();
    }

    fflush(stdin);
    getchar();

    //mainMenu();
}
*/
