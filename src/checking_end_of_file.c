#include <stdio.h>

int main() {
    FILE *file;
    char buffer [256]; // hold each line read from file

    // Open file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("File unable to open");
        return 1;
    }

    // Read file line-by-line until end of file
    while (!feof(file)) {
        if(fgets(buffer, sizeof(buffer), file) !=NULL) {
            printf("%s", buffer);
        }
    }

    // Checkif the loop ended due to an error
    if (ferror(file)) {
        perror("Error reading file");
    }

    // Close file
    fclose(file); 
    return 0;
}