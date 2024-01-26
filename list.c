#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Allocate space for a new list and set its head to NULL.
 * Returns the created list if succesful. NULL otherwise. */
list* create_list() {
    list* newList = (list*) malloc(sizeof(list));
    if (newList != NULL) {
        newList -> head = NULL;
    }

    // NULL if not succesfull
    return newList;
}

/* Allocates a new node and copies the string from item to this node
 * (use malloc, strlen, and strncpy; or try strdup). Adds this new node
 * to end of list ll. Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item) {
    if (ll == NULL || item == NULL) {
        // Not legal arguments
        return -1;
    }

    // Allocate space for the new node
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        // Not succesfully created
        return -1;
    }

    // Allocate space for the item string and copy it
    newNode -> item = strdup(item);
    if (newNode -> item == NULL) {
        // Not succesfully created
        free(newNode);
        return -1;
    }

    // Set next pointer to NULL
    newNode -> next = NULL;

    // Check if the list is empty
    if (ll -> head == NULL) {
        // Set the new node as the head
        ll -> head = newNode;
    } else {
        // Traverse to the end of the list and add the new node
        node* current = ll -> head;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
    }

    // Successfully added item to list
    return 0;
}

/* Removes the had of the list ll, extracts the string stored in the head,
 * and returns a pointer to this string. Also frees the removed head node. */
char* remove_from_list(list* ll) {
    if (ll == NULL || ll -> head == NULL) {
        // Not legal arguments
        return NULL;
    }

    // Extract the string from the head node
    char* removedItem = ll -> head -> item;

    // Remove the head node
    node* temp = ll -> head;
    ll -> head = ll -> head -> next;
    free(temp);

    // Successfully removed item
    return removedItem;
}

/* Prints every string in each node of the list ll, with a new line
 * character at the end of each string */
void print_list(list* ll) {
    if (ll == NULL) {
        // Not legal argument
        return;
    }

    // Traverse the list and print each item
    node* current = ll -> head;
    while (current != NULL) {
        printf("%s\n", current -> item);
        current = current -> next;
    }
}

/* Flushes (clears) the entire list and re-initializes the list. The passed
 * pointer ll should still point to a valid, empty list when this function
 * returns. Any memory allocated to store nodes in the list should be freed. */
void flush_list(list* ll) {
    if (ll == NULL) {
        // Not legal argument
        return;
    }

    // Traverse the list and free each node and its item
    node* current = ll -> head;
    while (current != NULL) {
        node* temp = current;
        current = current -> next;
        free(temp -> item);
        free(temp);
    }

    // Reset the head pointer to NULL
    ll -> head = NULL;
}

/* De-allocates all data for the list. Ensure all memory allocated for list
 * ll is freed, including any allocated strings and list ll itself. */
void free_list(list* ll) {
    if (ll == NULL) {
        // Not legal argument
        return;
    }

    // Flush the list to free all memory
    flush_list(ll);

    // Free the list structure
    free(ll);
}