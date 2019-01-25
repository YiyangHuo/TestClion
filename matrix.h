//
// Created by THINKPAD on 2019/1/19.
//

#ifndef HW1_3_MATRIX_H
#define HW1_3_MATRIX_H
#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"
#include<string.h>
   typedef struct matrix{
        int c;
        int r;
        double **values;
    } matrix;
    double *makeline(FILE* fp);
    matrix getmatrix(double **);
    double getdetermine(matrix* thema);
    matrix getlowmatrix(matrix* thema, int indc, int indr);
    void Freematrix(matrix* thema);
#endif //HW1_3_MATRIX_H
