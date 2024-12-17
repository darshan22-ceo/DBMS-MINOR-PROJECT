#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h>    // for open, O_RDONLY, O_WRONLY, O_CREAT, O_APPEND 
#include <unistd.h>   // for close, read, write, unlink 
#include <string.h>   // for strlen 
#include <errno.h>    // for error handling 
int main() { 
int file_desc; 
ssize_t bytes_written, bytes_read; 
char buffer[100]; 
 
// 1. Creating and opening a file using 'open' system call 
file_desc = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 
if (file_desc < 0) { 
perror("Error opening file"); 
exit(EXIT_FAILURE);} 
printf("File created and opened successfully.\n"); 
// 2. Writing to the file using 'write' system call 
const char *data = "Hello, this is a test for file operations in Unix using system calls.\n"; 
bytes_written = write(file_desc, data, strlen(data)); 
if (bytes_written < 0) { 
perror("Error writing to file"); 
close(file_desc); 
exit(EXIT_FAILURE);
} 
printf("%ld bytes written to file.\n", bytes_written); 
 
// 3. Closing the file using 'close' system call 
if (close(file_desc) < 0) { 
perror("Error closing file"); 
exit(EXIT_FAILURE); 
} 
printf("File closed successfully.\n"); 
 
// 4. Re-opening the file in read mode 
file_desc = open("testfile.txt", O_RDONLY); 
if (file_desc < 0) { 
perror("Error reopening file"); 
exit(EXIT_FAILURE); 
} 
printf("File reopened in read mode.\n"); 
 
// 5. Reading the contents of the file using 'read' system call 
bytes_read = read(file_desc, buffer, sizeof(buffer) - 1); 
if (bytes_read < 0) { 
perror("Error reading file"); 
close(file_desc); 
exit(EXIT_FAILURE); 
} 
buffer[bytes_read] = '\0'; // Null terminate the string 
printf("File content:\n%s\n", buffer);
// 6. Closing the file again 
if (close(file_desc) < 0) { 
perror("Error closing file"); 
exit(EXIT_FAILURE); 
} 
printf("File closed after reading.\n"); 
 
// 7. Deleting the file using 'unlink' system call 
if (unlink("testfile.txt") < 0) { 
perror("Error deleting file"); 
exit(EXIT_FAILURE); 
} 
printf("File deleted successfully.\n"); 
return 0; 
} 
