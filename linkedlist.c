// Standard Libaries
#include <stdio.h> // standard input/outpu. printf, scanf, fgets
#include <stdlib.h> // standard library. malloc, realloc, free, exit

// My defitions
typedef struct Node Node; // declares that "struct Node" as "Node" will be defined
typedef struct Node{ // Defining "gitNode" as a struct
    int data; //a pointer pointing to the data in this node
    struct Node *next; // a pointer pointing to the next node head. using struct node as that is the general form and Node isn't defined yet at this stage
} Node; // name of struct
typedef struct{
    Node *head; //a pointer pointing to the first node head in the linked list
} linkedlist; // name of struct

// functions
linkedlist *create() { // promising a return of 'linkedlist' and create doesn't need any paramters as linkedlist can start empty except for the designation of memory for the head pointer.
    linkedlist *list = (linkedlist*)malloc(sizeof(linkedlist)); // linkedlist pointer variable 'list' assigned a memory allocation of the size of linkedlist, so in this case the pointer to the node head
    if (list == NULL) { // checking if the memory allocation for the linkedlist (list) succeeded
        printf("linkedlist creation failed"); // prints in case of failure
        return NULL; // NUll return when successful
    }
    list -> head = NULL; // this just says that the head of the linked list doesn't exist yet since there is no data yet and thus no first Node
    return list; // since there is no data, once the linkedlist pointer is created the function can return the linkedlist
}
void push_front(linkedlist *list, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("memory allocation failed");
        return;
    }
    node->data = value;
    node->next = list->head;
    list->head = node;
    return;
}
        
push_back()
delete_node()
get()
print()
free_list()
