// Standard Libaries
#include <stdio.h> // standard input/outpu. printf, scanf, fgets
#include <stdlib.h> // standard library. malloc, realloc, free, exit

// My defitions
typedef struct Node Node; // declares that "struct Node" as "Node" will be defined
typedef struct Node{ // Defining "gitNode" as a struct
    int data; //a pointer pointing to the data in this node
    struct Node *next; //a pointer pointing to the next node head. using struct node as that is the general form and Node isn't defined yet at this stage
} Node; // name of struct
typedef struct{
    Node *head; //a pointer pointing to the first node head in the linked list
} linkedlist; // name of struct


// functions
create()
push_front()
push_back()
delete_node()
get()
print()
free_list()
