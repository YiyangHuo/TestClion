//
// Created by THINKPAD on 2019/1/19.
//

#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"
#include<string.h>




double *makeline(FILE* fp){
    int stri = 0;
    int linei = 0;
    double *line = (double*)malloc(sizeof(double));
    char *str = (char*)malloc(sizeof(char));
    str[0]='\0';
    char temp;
    while(fscanf(fp, "%c",  &temp)!=EOF){
        //char* test = "-12345.67"; it works
        if(((temp == ' ')||(temp == '\n')||(temp == '\0')||(temp == '\r'))&&(str[0]!='\0')){
            str[stri] = '\0';
            sscanf(str, "%lf",&line[linei]);
            stri = 0;
            str = (char*)malloc(sizeof(char));
            str[0] = '\0';
            linei++;
            line = (double*) realloc(line, (linei+1) * sizeof(double));
        }
        else if((temp != ' ')&&(temp != '\n')&&(temp != '\0')&&(temp != '\r')){
            str[stri] = temp;
            stri++;
            str = (char*)realloc(str,(stri+1)*sizeof(char));
        }

    }
    return line;

}
matrix getmatrix(double **theline) {
    matrix pmatrix;
    int num = 2;
    pmatrix.c = (int)(*theline)[0];
    pmatrix.r = (int)(*theline)[1];
    pmatrix.values= (double**)malloc((pmatrix.c)*(sizeof(double*)));
    for(int i=0;i<pmatrix.c;i++){
        pmatrix.values[i]= (double*)malloc((pmatrix.r)*(sizeof(double)));
    }
    for(int i=0;i<pmatrix.c;i++){
        for(int j=0;j<pmatrix.r;j++){
            pmatrix.values[i][j] = (*theline)[num];
            num++;
        }
    }
    free(*theline);
    return pmatrix;
}

matrix getlowmatrix(matrix* thema, int indc, int indr){
    int mnum = 2;
    double* lline = (double*)malloc((mnum+1)*sizeof(double));
    lline[0] = (*thema).c-1;
    lline[1] = (*thema).r-1;
    for (int i = 0;i<(*thema).c;i++){
        for(int j=0;j<(*thema).r;j++){
            if((i!=indc)&&(j!=indr)){
                lline[mnum] = (*thema).values[i][j];
                mnum++;
                lline = (double*)realloc(lline,(mnum+1)*sizeof(double));

            }
        }
    }
    matrix lmatrix = getmatrix(&lline);
    return lmatrix;

}

double getdetermine(matrix* thema) {
    double answer = 0;
    if ((*thema).c>2){
        for (int i=0; i<(*thema).r;i++){
            matrix lmatrix = getlowmatrix(thema,0,i);
            answer+=pow(-1,i)*(*thema).values[0][i]*getdetermine(&lmatrix);
        }
        Freematrix(thema);
    }
    else{
        answer = ((*thema).values[0][0])*((*thema).values[1][1]) - (*thema).values[0][1]*(*thema).values[1][0];
        Freematrix(thema);
        return answer;
    }
    return answer;
}

void Freematrix(matrix* thema){
    //free((*thema).values[6]);
    for(int i=0; i<(*thema).r;i++){
        free((*thema).values[i]);
        }
    //if ((*thema).values == NULL){
        free((*thema).values);
    //}

}
