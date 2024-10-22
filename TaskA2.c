#include <stdio.h>
#include <stdlib.h>
void insertValue(int *array, int index, int value);
int getValue(int *array, int index);
void displayArray(int *array, int size);
int main() {
int size; 
int *array; 
printf("Enter the size of the array: ");
scanf("%d", &size);
// Allocate memory for the array
array = (int *)malloc(size * sizeof(int));
if (array == NULL) {
printf("Memory allocation failed!\n");
return 1; 
}
// Initialize the array with zeros
for (int i = 0; i < size; i++) {
array[i] = 0;
}
// Demonstrate insertion of values
insertValue(array, 0, 10); 
insertValue(array, 1, 20); 
insertValue(array, 2, 30); 
insertValue(array, 3, 40); 
insertValue(array, 4, 50); 
 printf("Array contents after insertion:\n");
displayArray(array, size);
// Demonstrate retrieval of values
for (int i = 0; i < size; i++) {
printf("Value at index %d: %d\n", i, getValue(array, i));
}
free(array);
return 0; 
}
// Function to insert a value at a specific index
void insertValue(int *array, int index, int value) {
// Check for valid index
if (index < 0) {
printf("Error: Index cannot be negative.\n");
return;
}
array[index] = value; 
}
// Function to retrieve a value from a specific index
int getValue(int *array, int index) {
// Check for valid index
if (index < 0) {
printf("Error: Index cannot be negative.\n");
return -1; 
}
return array[index]; 
}
void displayArray(int *array, int size) {
for (int i = 0; i < size; i++) {
printf("Index %d: %d\n", i, array[i]);
}
}