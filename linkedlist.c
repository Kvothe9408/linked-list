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

void delete_node(linkedlist *list, int position) { // going into the linkedlist and deleting a specified node
    if (list->head == NULL) { // check is the list is empty first
        return;
    }
    Node *current = list->head; // declaring 'current' node pointer as a variable
    if (position == 0) { // looking at when we want to delete the first node
        list->head = current->next; // reassinging list->head as the pointer of the next node after the deleted node
        free(current); // free the node memory
        return;
    }
    int count = 0; // declaring count here befoe the loop
    while (count < position -1) { // condition continues as long as the statement is true, so it stops the first time its false, unliek in math when you would put the correct number from one postion before
        current = current->next; // walk down the list by switching the current pointer to the pointer of the next node
        count++; // increments count by +1
    }
    Node *delete = current->next; // assigns another pointer to the point at the node to be deleted, we need to do this since we need 'current' to be assigned to the node after the deletion node
    current->next = delete->next; // reassings the pointer to fromt eh node to be deleted to the node after the to be deleted node
    free(delete); // frees the memory of the node to be deleted
} // if the last pointer is re-assigned to NULL the list terminates, so we don't need to add this edge case separately to the function.

int get(linkedlist *list, int position) { // get (in this case the integer data stored in a specified node)
    if (list->head == NULL) { // check is the list is empty first
        return -1; // -1 shows that an error has occured and needs to be there as I promised an interger return at the start
    }
    Node *current = list->head; // creating and assigning walk through node pointer
    int count = 0; // declaring count
    while (count < position) { // loop that walks the current pointer to the relevant node to be deleted
        current = current->next; // walk through routine
        count++; // increment count by +1
        if (current == NULL) { // checks is the the list terminates before the specified position is reached by checking if the current pointer now points to NULL instead of the address of the next node
            return -1; // -1 error indication for the required int return
        }
    }
    return current->data; // returns the data in the specified node we asked for
}
void print(linkedlist *list) { // print the entire list
    if (list->head == NULL) { // check if the list is empty
        return;
    }
    Node *current = list->head;
    while (current != NULL) { // run this loop as long as the current node pointer isn't pointing at NULL, so the end of the list
        printf("%d\n", current->data); // print the date in the current node
        current = current->next; // walk the current pointer down one node
    }
    return; // since this is a void function, no return is specified
}
void free_list(linkedlist *list) { //freeing up the memory of the linked list
    Node *current = list->head; // assigns a variable to the list->head pointer
    while (current != NULL) { // a loop that runs while current doesn't point at NULL
        Node *delete = current; // creates a temp value for in the loop for the node that will be deleted
        current = current->next; // moves current forward one each step
        free(delete); // do not need to increment delete, as it will always create a new version of it as the loop runs, frees the memory of that node
    }
    free(list); // frees the memory of the list
    return;
}

int main() {
    return 0;
}