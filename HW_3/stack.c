#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include "student.h"

typedef void *elem_t;
typedef elem_t (*clone_t) (elem_t);
typedef void (*destroy_t) (elem_t);
typedef void (*print_t) (elem_t);

// Function to create a new stack with the given capacity
stack stack_create(int capacity, clone_t clone_elemnt, destroy_t destroy_elemnt,
		print_t print_elemnt) {
    // Allocate memory for the stack
    stack pstack = malloc(sizeof(struct stack_t));
    if (pstack == NULL) {
        // Return NULL if memory allocation fails
        return NULL;
    }

    // Initialize the properties of the stack
    pstack->capacity = capacity;
    pstack->top = -1;  // -1 means the stack is empty
    pstack->elements = malloc(capacity * sizeof(elem_t));
    if (pstack->elements == NULL) {
        // Free the stack and return NULL if memory allocation fails
    	if(pstack){
    	   	free(pstack);
    	}
        return NULL;
    }

    // Set the clone, destroy, and print functions
    pstack->clone_elemnt = clone_elemnt;
    pstack->destroy_elemnt = destroy_elemnt;
    pstack->print_elemnt = print_elemnt;

    // Return the newly created stack
    return pstack;
}

// Function to deallocate a stack
Result stack_destroy(stack pstack) {

    if (pstack) {
        // Free the elements array

    	 for (int i = pstack->top; i >=0; i--) {
    			pstack->destroy_elemnt(pstack->elements[i]);
    		}
        // Free the stack itself
    	if(pstack){
    		free(pstack);
    	}
        return SUCCESS;
    }
    return FAIL;
}
/**
 * @fn void stack_push(stack pstack, elem_t element)
 * @brief pushes an element onto the top of the stack
 * @param pstack - pointer to the stack
 * @param element - the element to push onto the stack
 * @return void
 */
Result stack_push(stack pstack_t, elem_t elem) {
    if (pstack_t == NULL || elem == NULL) {
        return FAIL;
    }
    if ((pstack_t)->top == pstack_t->capacity - 1) {
        return FAIL;
    }
    (pstack_t)->top++;
    pstack_t->elements[pstack_t->top] = pstack_t->clone_elemnt(elem);
    return SUCCESS;
}


/**
 * @fn void stack_pop(stack pstack)
 * @brief removes the top element from the stack
 * @param pstack - pointer to the stack
 * @return void
 */
void stack_pop(stack pstack) {
    // Check if pstack is a valid pointer
    if (!pstack) {
        fprintf(stderr, "Error: null pointer passed to stack_pop.\n");
        exit(EXIT_FAILURE);
    }
    // Check if the stack is empty
    if (pstack->top < 0) {
        fprintf(stderr, "Error: stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    pstack->top--;
}

/**
 * @fn elem_t stack_peek(stack pstack)
 * @brief returns a pointer to the top element of the stack
 * @param pstack - pointer to the stack
 * @return a pointer to the top element of the stack
 */

elem_t stack_peek(stack pstack) {
    // Return a copy of the top element of the stack
    if (pstack->top == -1) {
        printf("Error: stack is empty.\n");
        return NULL;
    }

    return (pstack->elements[pstack->top]);
}
/**
 * @fn int stack_size(stack pstack)
 * @brief returns the number of elements in the stack
 * @param pstack - pointer to the stack
 * @return the number of elements in the stack, or 0 if an error occurs
 */
int stack_size(stack pstack) {
   // If the stack is not initialized properly or the top index is out of bounds
    if (!pstack || pstack->top < 0 || pstack->top >= pstack->capacity) {
        // Return 0 to indicate an error
        return 0;
    }
    // Return the size of the stack
    return pstack->top + 1;
}

/**
 * @fn int stack_capacity(stack pstack)
 * @brief returns the capacity of the stack
 * @param pstack - pointer to the stack
 * @return the remaining capacity of the stack, or 0 if an error occurs
 */
int stack_capacity(stack pstack) {
   // If the stack is not initialized properly or the top index is out of bounds
    if (!pstack || pstack->top < 0 || pstack->top >= pstack->capacity) {
        // Return 0 to indicate an error
        return 0;
    }
    // Return the remaining capacity of the stack
    return pstack->capacity - pstack->top - 1;
}

/**

    @fn bool stack_is_empty(stack pstack)
    @brief Checks whether the stack is empty or not
    @param pstack - Pointer to the stack to check
    @return true if the stack is empty, false otherwise
    */
bool stack_is_empty(stack pstack_t) {
    // Check if the stack is initialized properly
    if (!pstack_t) {
    fprintf(stderr, "Error: null pointer passed to stack_is_empty.\n");
    exit(EXIT_FAILURE);
    }
    	// If the top index is less than 0, the stack is empty
    	return (pstack_t->top ==-1);
    }
/**

    @fn void stack_print(stack pstack)

    @brief Prints the elements of the stack

    @param pstack - Pointer to the stack to print
    */
void stack_print(stack pstack_t) {
   		// If the stack is empty, return immediately
	 if (pstack_t == NULL || pstack_t->elements == NULL || pstack_t->top < 0) {
      return;
      }

    // Iterate through the elements of the stack, starting from the top
   	for (int i = pstack_t->top; i >=0; i--) {
  		// Print the current element
    	pstack_t->print_elemnt(pstack_t->elements[i]);
    }

}
