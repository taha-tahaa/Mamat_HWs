#ifndef __STACK__
#define __STACK__

#include <stddef.h>  /* size_t */
#include <stdbool.h> /* bool   */ 
#include "stdlib.h"
#include "stdio.h"
//hiiii
typedef enum { SUCCESS = 0, FAIL } Result; 
typedef void *elem_t;
typedef elem_t (*clone_t) (elem_t);
typedef void (*destroy_t) (elem_t);
typedef void (*print_t) (elem_t);
typedef struct stack_t {
    int capacity;
    int top;
    elem_t *elements;
    destroy_t destroy_elemnt;
    print_t print_elemnt;
    clone_t clone_elemnt;
} *stack;
typedef stack* pstack_t;




/* ------------------------------------------ */
/* Add here declarations of function pointers */
/* ------------------------------------------ */
/**

    @fn stack stack_create(int capacity, clone_t clone_elemnt,
    destroy_t destroy_elemnt, print_t print_elemnt);
    @brief creates a new stack with the given capacity
    @param capacity - the maximum number of elements that can be stored
    in the stack
    @param clone_elemnt - a function that creates a copy of an element
    @param destroy_elemnt - a function that deallocates an element
    @param print_elemnt - a function that prints an element
    @return pointer to the newly created stack or NULL if memory
    allocation fails
    */
stack stack_create(int capacity, clone_t clone_elemnt, destroy_t destroy_elemnt,
		print_t print_elemnt);

/**

    @fn Result stack_destroy(stack pstack);
    @brief destroys the stack and frees all the memory of the elements in the
    stack. The stack must be a stack created by stack_create otherwise
    undefined behavior
    @param pstack - pointer to the stack to destroy
    @return SUCCESS if the stack is destroyed successfully, FAIL otherwise
    */
Result stack_destroy(stack pstack);
/**

    @fn Result stack_push(stack pstack, elem_t elem);
    @brief adds an element to the top of the stack
    @param pstack - pointer to the stack
    @param elem - pointer to the element to add to the stack
    @return SUCCESS if the element is added successfully, FAIL otherwise
    */
Result stack_push(stack pstack_t, elem_t elem);

/**

    @fn void stack_pop(stack pstack_t);
    @brief removes the top element from the stack
    @param pstack_t - pointer to the stack
    @return none
    */
void stack_pop(stack pstack) ;

/**

    @fn elem_t stack_peek(stack pstack_t);
    @brief gets a pointer to the top element of the stack without removing it
    @param pstack_t - pointer to the stack
    @return pointer to the top element of the stack or NULL if the stack is empty
    */


elem_t stack_peek(stack pstack);

/**

    @fn int stack_size(stack pstack_t);
    @brief gets the number of elements in the stack
    @param pstack_t - pointer to the stack
    @return the number of elements in the stack
    */
int stack_size(stack pstack);

/**

    @fn int stack_capacity(stack pstack_t);
    @brief gets the remaining capacity of the stack
    @param pstack_t - pointer to the stack
    @return the remaining capacity of the stack
    */
int stack_capacity(stack pstack);

/**

    @fn bool stack_is_empty(stack pstack_t);
    @brief checks whether the stack is empty or not
    @param pstack_t - pointer to the stack
    @return true if the stack is empty, false otherwise
    */
bool stack_is_empty(stack pstack_t);

/**

    @fn void stack_print(stack pstack_t);
    @brief prints the elements of the stack
    @param pstack_t - pointer to the stack
    @return none
    */
void stack_print(stack pstack_t);



#endif /* __STACK__ */
