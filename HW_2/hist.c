#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_GRADE 0
#define MAX_GRADE 100
static FILE *f;
static int nbins =20;
void operate(int *nibs);
void parse_arg(int argc,char **argv){
    f=stdout;
    for (int i = 1; i <argc; ++i) {
        if(!strcmp(argv[i],"-")){
            f=stdin;
        }else if (!strcmp(argv[i],"-n_bins")){
            nbins=i<argc-1 ? atoi(argv[i+1]) :10;
            i++;
        } else{
            f= fopen(argv[i],"r");
        }
    }
}
int main(int argc ,char **argv) {
    parse_arg(argc,argv);
    /* Must Check for errors */
    if(!f){
        fprintf(stderr,"File not found: \"%s\"\n",argv[1]);
        return 1;
    }
    /* Intiate array */
    int *bins =(int*) malloc(sizeof (int)*nbins);
    for (int i = 0; i < nbins; ++i) {
        bins[i]=0;
    }
    operate(bins);
    free(bins);
}
void operate (int *bins){
    int grade;
    int retval;
    double pace;
    int num_lines=0;
    while (1) {

        retval = fscanf(f, "%d", &grade);
        if (retval == EOF) {
            break;
        } else if (retval != 1) {
            fprintf(stderr, "Error: not a number\n");
            exit(1);
        }
        if (grade < MIN_GRADE || grade > MAX_GRADE) {
           	          // Grade is out of range
            fprintf(stderr, "Error: line %d is out of range [%d,%d]\n",
           	   		         		num_lines + 1, MIN_GRADE, MAX_GRADE);
            exit(1);
        }
        num_lines++;
        if(grade ==100)
        	bins[nbins-1]++;
        int n = grade / (100 / nbins);
        bins[n]++;
    }
    /* print */
    pace=100.0/nbins;
    for(int i=0;i<nbins;++i) {
        printf("%.0lf-%.0lf\t%d\n", i * pace,
               (i < nbins - 1) ? ((i + 1) * pace - 1) : 100,
               bins[i]);
    }






}
