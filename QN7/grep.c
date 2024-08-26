// a) Write a program to simulate grep command using system calls
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char fn[10], pat[10], temp[100];
    FILE *fp;
    printf("Enter file name:\n");
    scanf("%s", fn);
    printf("Enter pattern:\n");
    scanf("%s", pat);

    fp = fopen(fn, "r");
    while (!feof(fp))
    {
        fgets(temp, 100, fp);
        if (strstr(temp, pat))
        {
            printf("%s\n", temp);
        }
    }
    // if(temp == NULL)
    // printf("Pattern not found");
    fclose(fp);
    return 0;
}