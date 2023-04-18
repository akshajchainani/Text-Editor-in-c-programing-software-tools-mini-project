#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char content[MAX_LENGTH];
    int content_length = atoi(getenv("CONTENT_LENGTH"));

    // Read input from POST request
    fgets(content, content_length + 1, stdin);

    // Open file for writing
    FILE *fp = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("Error: could not create file\n");
        return 1;
    }

    // Write input to file
    fputs(content, fp);

    fclose(fp);

    // Return HTTP response
    printf("Content-type: text/html\n\n");
    printf("<html><body>");
    printf("<h1>File saved successfully!</h1>");
    printf("</body></html>");

    return 0;
}
