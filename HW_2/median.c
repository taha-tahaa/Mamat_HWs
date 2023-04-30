#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_GRADE 0
#define MAX_GRADE 100

void calculate_median(FILE* file) {
    int hist[MAX_GRADE] = {0};
    int num_bad_grades = 0;
    int num_lines = 0;
    int num_students = 0;
    int median_grade = 0;
    int median_index = 0;
    int grade = 0;
    int scanf_result = 0;
    
    while (1) {
        scanf_result = fscanf(file, "%d", &grade);
        if (scanf_result == EOF) {
            break;
        }
        else if (scanf_result != 1) {
            // Invalid input (not a number)
            num_bad_grades++;
            fprintf(stderr, "Error: not a number\n");
            exit(1);
        }
        else if (grade < MIN_GRADE || grade > MAX_GRADE) {
            // Grade is out of range
            num_bad_grades++;
            fprintf(stderr, "Error: line %d is out of range [%d,%d]\n",
            		num_lines +1, MIN_GRADE, MAX_GRADE);
            exit(1);
        }
        hist[grade]++;
        num_lines++;
    }
    num_students = num_lines - num_bad_grades;
    median_index = (num_students + 1) / 2;
    for (int i = 0, count = 0; i < MAX_GRADE; i++) {
        count += hist[i];
        if (count >= median_index) {
            median_grade = i;
            break;
        }
    }
    fprintf(stdout, "%d\n", median_grade);
}

int main(int argc, char** argv) {
    FILE* file = NULL;
    if (argc == 1 || !strcmp(argv[1], "-")) {
        file = stdin;
    }
    else {
        file = fopen(argv[1], "r");
    }
    if (!file) {
        // File not found
        fprintf(stderr, "Error: file not found: \"%s\"\n", argv[1]);
        return 1;
    }
    calculate_median(file);
    fclose(file);
    return 0;
}
