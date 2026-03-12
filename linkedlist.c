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
    list->head = NULL; // this just says that the head of the linked list doesn't exist yet since there is no data yet and thus no first Node
    return list; // since there is no data, once the linkedlist pointer is created the function can return the linkedlist
}
void push_front(linkedlist *list, int value) { //linkedlist * list, is in teh paramater as teh function needs to access the list and create 'list' as a variable
    Node *node = (Node *)malloc(sizeof(Node)); // defines node as the Node pointer and allocates memory in the size of a Node as defined earlier
    if (node == NULL) { // checks if the memory allocation succeeded
        printf("memory allocation failed");
        return; // nothing is returned as this is a void function
    }
    node->data = value; // sets the data in 'node' to the value specified
    node->next = list->head; // sets the the 'next' pointer in 'node to the current list head pointer since this function pushes data to the front of the list
    list->head = node; // sets the new list head pointer as to the pointer of the new Node
    return; // nothing is returned as this is a void function
}

void push_back(linkedlist *list, int value) { // function to push data to the back of the list
    Node *node = (Node *)malloc(sizeof(Node)); // allocting memory for the Node struct
    if (node == NULL) { // check if memory was allocated successfully
        printf("memory allocation failed");
        return; // no return value as this is a void function
    }
    if (list->head == NULL) { // checking if the list is empty when pushing this function, so that no error occurs during the loop later
        list->head = node; // if the list is empty, then we assign list->head to the new node, which would be the first
        return;
    }
    Node *current = list->head; // need to declare the new pointer name to be used in the subsequent loop. current is the new pointer in this case and start by pointing at list->head
    while (current->next != NULL) { // loop that keeps running as long as current->next doesn't equal NULL
        current = current->next; // says that the pointer to current gets reassign to current->next (thus pointing at the next node)
    } // no return is included here as it it were then the loop would terminate after one round instead of when current->next == NULL
    current->next = node; // now that the loop as walked current to the end of the list, we are assiging current->next (so the previously last node) to point at the newly created node
    node->next = NULL; // setting the newly created node's node->next to NULL
    node->data = value; // inputing the data into the node
    return;
    }

void delete_node(linkedlist *list, int position) {
    if (list->head == NULL) {
        return;
    }
    Node *current = list->head; // declaring current nod pointer as a variable
    if (position == 0) { // looking at when we want to delete the first node
        list->head = current->next; // reassinging list->head as the pointer of the next node after the delection node
        free(current); // free the node memory
        return;
    }
    int count = 0; // declaring count here befoe the loop
    while (count < position -1) { // condition continues as long as the statement is true, so it stops the first time its false, unliek in math when you would put the correct number from one postion before

    }
}
// get()
// print()
// free_list()
int main() {
    return 0;
}