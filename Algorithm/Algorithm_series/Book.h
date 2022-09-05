#pragma once

#define MAX_TIT_LEN 200
#define MAX_AUT_LEN 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Book{
    char title[MAX_TIT_LEN+1];
    char author[MAX_AUT_LEN+1];
    int num;
}Book;

Book *New_Nook(const char *title, const char *author, int num);
void Delete_Book(Book *book);
void Book_View(Book *book);
int Book_CompareTitle(Book *book,const char *title);
int Book_CompareAuthor(Book *book,const char *author);
int Book_CompareNum(Book *book,int num);


Book *New_Nook(const char *title, const char *author, int num){
    Book *book = (Book *)malloc(sizeof(Book));
    B
}