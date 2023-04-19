#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char filename[100];
    char content[MAX_LENGTH];

    printf("Enter filename to create: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Error creating file!\n");
        exit(1);
    }

    printf("Enter text (max 1000 characters):\n");
    scanf(" %[^\n]s", content);

    fputs(content, fp);

    fclose(fp);

    printf("\nFile created and saved successfully!\n");

    return 0;
}
