#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {

    printf("\n----------------------------\n       BEGIN HAPPY TEST\n----------------------------\n\n");

    // Creating a new list
    list* testList = create_list();

    // Adding elements to the list
    add_to_list(testList, "One");
    add_to_list(testList, "Two");
    add_to_list(testList, "Three");
    add_to_list(testList, "Four");
    add_to_list(testList, "Five");

    // Printing the list
    printf("List after adding elements:\n");
    print_list(testList);

    // Removing the head element from the list
    char* removedItem = remove_from_list(testList);
    if (removedItem != NULL) {
        printf("\nRemoved item: %s\n", removedItem);
        free(removedItem);
    }

    // Printing the updated list
    printf("\nList after removing the head element:\n");
    print_list(testList);

    // Flushing the entire list
    flush_list(testList);

    // Printing the flushed list
    printf("\nList after flushing:\n");
    print_list(testList);

    // Freeing the list and its memory
    free_list(testList);
    
    printf("\n----------------------------\n        END HAPPY TEST\n----------------------------\n");

    printf("\n----------------------------\n       BEGIN SAD TEST\n----------------------------\n\n");

    // We won't be able to test the malloc issues without testing on a machine with an absuredly
    // small amount of resources

    list* testListTwo = create_list();

    printf("Testing add_to_list\n");
    printf("Add to list called with NULL list pointer\n");
    if (add_to_list(NULL, "TEST") == -1) {
        printf("Caught and returned -1\n");
    }
    printf("Add to list called with NULL string\n");
    if (add_to_list(testListTwo, NULL) == -1) {
        printf("Caught and returned -1\n");
    }
    printf("Add to list called with NULL list pointer and NULL string\n");
    if (add_to_list(NULL, NULL) == -1) {
        printf("Caught and returned -1\n\n");
    }

    printf("Testing remove_from_list\n");
    printf("Remove from list called with NULL list pointer\n");
    if (remove_from_list(NULL) == NULL) {
        printf("Caught and returned NULL\n");
    }
    printf("Remove from list called with empty list\n");
    if (remove_from_list(testListTwo) == NULL) {
        printf("Caught and returned NULL\n\n");
    }

    printf("Testing print_list\n");
    printf("Print list called with NULL list pointer\n");
    print_list(NULL);
    printf("Print list called with empty list\n\n");
    print_list(testListTwo);

    printf("Testing flush_list\n");
    printf("Flush list called with NULL list pointer\n");
    flush_list(NULL);
    printf("Flush list called with empty list\n\n");
    flush_list(testListTwo);

    printf("Testing free_list\n");
    printf("Free list caleld with NULL list pointer\n");
    free_list(NULL);

    flush_list(testListTwo);
    free_list(testListTwo);

    printf("\n----------------------------\n        END SAD TEST\n----------------------------\n\n");

    return 0;
}