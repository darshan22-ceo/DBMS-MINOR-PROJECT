#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100  // Maximum size of the array 
// Function to display the elements of the array 
void display(int arr[], int size) { 
printf("Array elements: "); 
for (int i = 0; i < size; i++) { 
printf("%d ", arr[i]); 
} 
printf("\n");
} 
// Function to insert an element at a given index 
void insert(int arr[], int *size, int element, int index) { 
if (*size >= MAX_SIZE) { 
printf("Array is full, cannot insert element.\n"); 
return; 
} 
if (index < 0 || index > *size) { 
printf("Invalid index for insertion.\n"); 
return; 
} 
for (int i = *size; i > index; i--) { 
arr[i] = arr[i - 1];  // Shift elements to the right 
} 
arr[index] = element; 
(*size)++; 
printf("Element %d inserted at index %d.\n", element, index); 
} 
// Function to delete an element at a given index 
void delete(int arr[], int *size, int index) { 
if (index < 0 || index >= *size) { 
printf("Invalid index for deletion.\n"); 
return; 
} 
printf("Element %d deleted from index %d.\n", arr[index], index); 
for (int i = index; i < *size - 1; i++) { 
arr[i] = arr[i + 1];  // Shift elements to the left 
} 
(*size)--; 
} 
// Function to search for an element and return its index 
int search(int arr[], int size, int element) { 
for (int i = 0; i < size; i++) { 
if (arr[i] == element) { 
return i;  // Return index if element is found 
} 
} 
return -1;  // Return -1 if element is not found 
} 
int main() { 
int arr[MAX_SIZE];  // Array to hold elements 
int size = 0;       // Current size of the array 
int choice, element, index; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Insert element\n"); 
printf("2. Delete element\n"); 
printf("3. Search element\n"); 
printf("4. Display array\n"); 
printf("5. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1:  // Insert element
printf("Enter the element to insert: "); 
scanf("%d", &element); 
printf("Enter the index at which to insert: "); 
scanf("%d", &index); 
insert(arr, &size, element, index); 
break; 
case 2:  // Delete element 
printf("Enter the index at which to delete: "); 
scanf("%d", &index); 
delete(arr, &size, index); 
break; 
case 3:  // Search element 
printf("Enter the element to search for: "); 
scanf("%d", &element); 
index = search(arr, size, element); 
if (index != -1) { 
printf("Element %d found at index %d.\n", element, index); 
} else { 
printf("Element not found.\n"); 
} 
break; 
case 4:  // Display array 
display(arr, size); 
break; 
case 5:  // Exit 
exit(0); 
default:printf("Invalid choice. Please try again.\n"); 
} 
} 
return 0; 
} 
