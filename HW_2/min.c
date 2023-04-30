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
/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments which is a t file contains a grades
 * @return Non-zero value in case of an error,prints to stdout the minimum grade
 * @error if the grade is out of range we print a message to stderr
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
		int grade,mingrade,rerror=fscanf(fp," %d", &mingrade);
			if (rerror !=1){
		  		/* Error */
			fprintf(stderr, "Error: not a number\n");
	   		exit(1);
    	}
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
   	        fprintf(stderr, "Error: line %d is out of range [%d,%d]\n",
   		   		         		num_lines + 2, MIN_GRADE, MAX_GRADE);
   	        exit(1);
   		  }else{
		  mingrade=(mingrade>grade)? grade:mingrade;
		  num_lines++;
	  }

	}
	fprintf(stdout,"%d\n",mingrade);

	fclose(fp);
	return 0;
}
