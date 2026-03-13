# First Linked List (C)

## Description
A linked list implemented in C.

## Overview
A linked list is a way to store data in memory in a non contiguous way through the use of pointers. So, each data point in memory includes a pointer pointing to the next data point, thus linking these points of data together in a list. The advantage of this design is that no memory needs to be allocated upfront as data can live anywhere in memory. However, the disadvantage is that the CPU must follow the list from the beginning everytime and cannot jump directly to a specific point in the list.

## API / Functions
- `linkedlist *create();` 
    - creates the first pointer of the list, intially pointing at NULL as the list itself if empty
- `void push_front(linkedlist *list, int value);`
    - pushes an integer "value" to the front of the list
- `void push_back(linkedlist *list, int value);`
    - pushes an integer "value" to the back of the list
- `void delete_node(linkedlist *list, int position);`
    - finds a node at a specific position and deletes it    
- `int get(linkedlist *list, int position);` 
    - finds the value at the "position" slot in the linkedlist
- `void print(linkedlist *list);`
    - prints the entire list
- `void free_list(linkedlist *list);`
    - frees up both the memory allocated to all the nodes in the list and to the pointer struct of the linked list

## Design Decisions
At this stage, I wasn't making any design decisions, since it's so early in the learning process, but there were a few parts that were more involved than the dynamic array.
- I need to create temporary variables in my functions. For example, when I want to save a node to reference later, I need to assign a temporary variable to it before walking my pointer forward, otherwise I will lose access to the reference node.
- First encounter with loops. Only used while loops for this entire program. Two things to keep in mind. 1. The while loop continues until the condition specified is FALSE, or in other words, as long as the condition holds. 2. No return needs to be specified as the loop terminates automatically once the condition no longer holds.

## How to compile and run
```
gcc -Wall -Wextra -fsanitize=address -o linked-list linkedlist.c
./linked-list
```
## Next Steps
I am moving on to a Hash map now as my next smallest building block on the way to building a mini computer.