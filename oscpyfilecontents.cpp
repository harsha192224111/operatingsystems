#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1 = NULL, *fptr2 = NULL;
    char ch;

    // Open source file for reading
    fptr1 = fopen("source.txt", "r");
    if (fptr1 == NULL) {
        printf("Unable to open source.txt for reading.\n");
        exit(1);
    }

    // Open destination file for writing
    fptr2 = fopen("dest.txt", "w");
    if (fptr2 == NULL) {
        printf("Unable to open dest.txt for writing.\n");
        fclose(fptr1);  // Close the first file before exiting
        exit(1);
    }

    // Copy contents from source to destination
    while ((ch = fgetc(fptr1)) != EOF) {
        fputc(ch, fptr2);
    }

    // Close both files
    fclose(fptr1);
    fclose(fptr2);

    printf("Successfully copied contents from source.txt to dest.txt\n");

    return 0;
}

