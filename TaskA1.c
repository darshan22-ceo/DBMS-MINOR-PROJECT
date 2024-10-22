#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> // For file control operations like open()
#include <unistd.h> // For Unix system calls like read(), write(), close()
#include <string.h> 
void demonstrateSystemCalls(); 
void demonstrateCLibraryFunctions(); 
int main()
{
printf("File Operations in Unix OS using System Calls and C Library\n");
demonstrateSystemCalls();
demonstrateCLibraryFunctions();
return 0;
}
void demonstrateSystemCalls()
{
printf("\n1. Demonstrating Unix System Calls:\n");
int fileDescriptor; 
char *fileName = "system_call_example.txt"; 
char buffer[100]; 
ssize_t bytesRead; 
// Create and open a file using 'open' system call
fileDescriptor = open(fileName, O_WRONLY | O_CREAT , 0644);
if (fileDescriptor < 0)
{ 
("Error opening file using system call");
exit(0);
}
printf("File '%s' created and opened using system call 'open'.\n", fileName);
// Write text to the file using 'write' system call
char *text = "Hello, this is a sample text written using Unix system calls.\n";
if (write(fileDescriptor, text, strlen(text)) < 0)
{ 
perror("Error writing to file using system call");
exit(0);
}
printf("Text written to file using system call 'write'.\n");
if (close(fileDescriptor) < 0)
{ 
perror("Error closing file using system call");
exit(0);
}
printf("File closed using system call 'close'.\n");
// Reopen the file in read mode using 'open' system call
fileDescriptor = open(fileName, O_RDONLY);
if (fileDescriptor < 0)
{ 
perror("Error opening file for reading using system call");
exit(0);
}
printf("File '%s' opened for reading using system call 'open'.\n", fileName);
bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);
if (bytesRead < 0)
{ 
perror("Error reading from file using system call");
exit(0);
}
buffer[bytesRead] = '\0'; // Null-terminate the string to print
printf("Text read from file: %s\n", buffer);
// Close the file again
if (close(fileDescriptor) < 0)
{ 
perror("Error closing file after reading using system call");
exit(0);
}
printf("File closed after reading using system call 'close'.\n");
}
void demonstrateCLibraryFunctions()
{
printf("\n2. Demonstrating C Library Functions:\n");
FILE *filePointer; 
char *fileName = "c_library_example.txt"; 
char buffer[100]; 
// Open the file using 'fopen' in write mode
filePointer = fopen(fileName, "w");
if (filePointer == NULL)
{ 
perror("Error opening file using C library");
exit(0);
}
printf("File '%s' created and opened using C library function 'fopen'.\n", fileName);
fprintf(filePointer, "Hello, this is a sample text written using C library functions.\n");
printf("Text written to file using C library function 'fprintf'.\n");
if (fclose(filePointer) != 0)
{ 
perror("Error closing file using C library");
exit(0);
}
printf("File closed using C library function 'fclose'.\n");
filePointer = fopen(fileName, "r");
if (filePointer == NULL)
{ 
perror("Error opening file for reading using C library");
exit(0);
}
printf("File '%s' opened for reading using C library function 'fopen'.\n", fileName);
if (fgets(buffer, sizeof(buffer), filePointer) != NULL)
{
printf("Text read from file: %s\n", buffer);
}
if (fclose(filePointer) != 0)
{ 
perror("Error closing file after reading using C library");
exit(0);
}
printf("File closed after reading using C library function 'fclose'.\n");
}
