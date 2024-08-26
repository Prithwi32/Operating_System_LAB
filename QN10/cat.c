// Write a program to simulate cat command using system calls.
// a) CAT(VIEW ONLY)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    if (argc < 2)
    {
        printf("File name not entered");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File does not exits!");
        exit(1);
    }
    while ((ch=fgetc(fp)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}

// CAT (FOR CONCATENATION)
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    FILE *f1, *f2;
    char ch;
    if(argc < 3){
        printf("Insufficient number of arguments\n");
        exit(0);
    }
    f1 = fopen(argv[1], "a");
    f2 = fopen(argv[2], "r");

    if(f2 == NULL){
        printf("File not exists!");
        exit(0);
    }

    while(ch=fgetc(f2) != EOF){
        fprintf(f1, "%c", ch);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}