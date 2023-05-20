#include "student.h"
/**

    @fn student_t student_clone(student_t e)
    @brief Creates a copy of a student element.
    @param e - The element to clone.
    @return A copy of the given element.
    */
elem_t student_clone(elem_t e) {
    student_t *s = e;
    size_t len = strlen(s->name) + 1;
    struct student *copy = malloc(sizeof(struct student));
    if (!copy) {
        fprintf(stderr, "Failed to allocate memory for stack.\n");
        exit(EXIT_FAILURE);
    }
    copy->name = malloc(len);
    if (!copy->name) {
        fprintf(stderr, "Failed to allocate memory for student name.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(copy->name, s->name, len);
    copy->age = s->age;
    copy->id = s->id;
    return copy;
}

/**

    @fn void destroy_t(student_t e)
    @brief Deallocates a student element.
    @param e - The element to destroy.
    */

void student_destroy(elem_t e) {
	student_t *s = e;
	if( s->name){
		free(s->name);
	}
	if(s){
		free(s);
	}
}


/**

    @fn void print_t(student_t e)
    @brief Prints a student element.
    @param e - The element to print.
    */
void student_print(elem_t e) {
    if (!e) {
        printf("Error: null pointer passed to student_print.\n");
        return;
    }
    student_t *s = (student_t*) e;
    printf("student name: %s, age: %d, id: %d.\n", s->name, s->age, s->id);
}




