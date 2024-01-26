#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    printf("\n------------------------\n       BEGIN TEST\n------------------------\n\n");

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
    
    printf("\n------------------------\n        END TEST\n------------------------\n\n");
    return 0;
}