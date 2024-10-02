#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    // Open the file for writing (creates if it doesn't exist)
    file = fopen("Example.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write to the file
    fprintf(file, "DBMS MINOR WORK HERE .\n");

    // Close the file after writing
    fclose(file);

    // Open the file for reading
    file = fopen("Example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // Read from the file
    fgets(buffer, sizeof(buffer), file);
    printf("Content read from file: %s", buffer);

    // Close the file after reading
    fclose(file);

    return 0;
}