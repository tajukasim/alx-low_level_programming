// C program to implement
// the above approach
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    FILE* ptr;
    char ch;
 
    // Opening file in reading mode
    ptr = fopen(*filename, "r");
 
    if (NULL == ptr) {
        _putchar("file can't be opened \n");
    }
 
    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        _putchar(ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);
 
    // Closing the file
    fclose(ptr);
    return 0;
}


