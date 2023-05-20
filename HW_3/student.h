#ifndef __STUDENT__
#define __STUDENT__

#include "stack.h"
//#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {
	char *name;
	int age;
    int id;
}*pstudent_t, student_t;
char *strdup(const char *);

/**

    @fn student_t student_clone(student_t e)
    @brief Creates a copy of a student element.
    @param e - The element to clone.
    @return A copy of the given element.
    */
elem_t student_clone(elem_t e);

/**

    @fn void destroy_t(student_t e)
    @brief Deallocates a student element.
    @param e - The element to destroy.
    */
void student_destroy(elem_t e);

/**

    @fn void print_t(student_t e)
    @brief Prints a student element.
    @param e - The element to print.
    */
void student_print(elem_t e);
#endif /* __STUDENT__ */ 
