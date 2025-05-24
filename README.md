# Simple Singly Linked List in C

## Description

This program implements a basic singly linked list in C with the following operations:

- Insert a node at the head of the list
- Insert a node at the tail of the list (recursive)
- Insert a new node after a node with a specific value (recursive)
- Delete a node by value (recursive)
- Traverse and print the list
- Free all allocated memory safely

## Build Instructions

To compile the program, run this command in your terminal:

gcc -Wall -Wextra -Werror -o linkedlist main.c

This will produce an executable named `linkedlist`.

## Usage

Run the executable:

./linkedlist

The program demonstrates:

- Inserting nodes at the head and tail
- Inserting a node after a given value
- Deleting a node by value
- Traversing and printing the list after each operation

## Example Output

After inserting 30, 20, 10 at head:
30 -> 20 -> 10 -> NULL

After inserting 40, 50 at tail:
30 -> 20 -> 10 -> 40 -> 50 -> NULL

After inserting 25 after 10:
30 -> 20 -> 10 -> 25 -> 40 -> 50 -> NULL

After deleting node with value 20:
30 -> 10 -> 25 -> 40 -> 50 -> NULL

## Author

Your Name
