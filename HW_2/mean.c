/* Welcome to Mamat, 044101
 *
 * Use this project as a template for other C/C++ projects.
 * To copy this project, right-click on the project name "hello-world"
 * in the "project explorer" tab (left), then "copy" and finally "paste".
 *
 * To compile the project use "gcc" within the terminal.
 * To debug the project use "gdb" within the terminal.
 *
 * The red vertical line (right) represents the code width limit (80 chars).
 * Make sure not to cross it. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_GRADE 0
#define MAX_GRADE 100
void mean_op(FILE *fp);
/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments which is a t file contains a grades
 * @return Non-zero value in case of an error
 */
int main(int argc, char **argv) {
	FILE *fp;
	if(argc==1|| !strcmp("-",argv[1])){
		fp=stdin;
	} else{
		fp=fopen(argv[1],"r");
	}
	if(fp==NULL){
		// File not found
        fprintf(stderr, "Error: file not found: \"%s\"\n", argv[1]);
		return 1;
	}
	 mean_op(fp);

	fclose(fp);
	return 0;
}
/**
 * @brief  we receive file of grades the calculate and print the GPA
 * @param fp Pointer to argument which is a t file contains a grades
 * @error  if the grade is out of range we print a message to stderr
 */
void  mean_op(FILE *fp){
	int grade, rerror;
	double avg=0;
	int num_bad_grades = 0;
	int num_lines = 0;
	while (1){

		rerror=fscanf(fp," %d", &grade);
		if(rerror==EOF){
			break; // finished!!
		} else if (rerror !=1){
			/* Error */
			fprintf(stderr, "Error: not a number\n");
			exit(1);
		}
		if (grade < MIN_GRADE || grade > MAX_GRADE) {
		            // Grade is out of range
		            num_bad_grades++;
		            fprintf(stderr, "Error: line %d is out of range [%d,%d]\n",
		            		num_lines + 1, MIN_GRADE, MAX_GRADE);
		            exit(1);
		        }

			avg+= grade;
			num_lines++;
		}
	    int num_students = num_lines - num_bad_grades;
		fprintf(stdout,"%.2lf\n",avg/num_students);
}





