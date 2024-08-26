#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;

    if(argc < 2){
        printf("directory name not entered\n");
        exit(1);
    }
    if((dp=opendir(argv[1])) == NULL){
        printf("directory does not exits!\n");
        exit(0);
    }

    while((dirp=readdir(dp)) != NULL){
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    return 0;
}