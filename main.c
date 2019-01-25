#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"
#include<string.h>

FILE* validate_input(int argc, char* argv[]){

    FILE* fp = NULL;

    if(argc < 2){
        printf("Not enough arguments entered.\nEnding program.\n");
        exit(0);
    }

    else if(argc > 2){
        printf("Too many arguments entered.\nEnding program.\n");
        exit(0);
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Unable to open file: %s\nEnding program.\n", argv[1]);
        exit(0);
    }

    return fp;

}

int main(int argc, char* argv[]) {
    FILE* fp = validate_input(argc, argv);
    double *line = makeline(fp);
    struct matrix purposematrix = getmatrix(&line);
    double determine = getdetermine(&purposematrix);
    printf("The determinant is ");
    printf("%.2lf", determine);
    printf(".");
    fclose(fp);
    return 0;
}