#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void get_every_fifth_student(const matrix_t *matrix, long results[RESULTS_LEN]) {
    // set both the rows and columns into a veraible so it doesn't need to be called in each for loop
    int len = matrix->rows;
    int len2 = matrix->cols;
    // initialize i and j as well for efficiency
    int i, j;
    // set all the temp multiple accum variables to 0
    long temp1 = 0;
    long temp2 = 0;
    long temp3 = 0;
    long temp4 = 0;
    long temp5 = 0;
    // also set the matrix data into a variable to not call it in the for loop part of macro MGET
    const int *data = matrix->data;
    // pre-calculate this to subtract from column length in for loop condition
    int len3 = len2 % 10;
    for (i = 0; i < len; i++) {
        // this variable is from the macro MGET 
        int q = i * len2;
        for (j = 0; j < len2-len3; j+=10) {
            // set for loop to 10 (multiple of 5) and set each one to their repective columns, keep adding 
            temp1 += (data[q + (j)]);
            temp2 += (data[q + (j+1)]);
            temp3 += (data[q + (j+2)]);
            temp4 += (data[q + (j+3)]);
            temp5 += (data[q + (j+4)]);
            temp1 += (data[q + (j+5)]);
            temp2 += (data[q + (j+6)]);
            temp3 += (data[q + (j+7)]);
            temp4 += (data[q + (j+8)]);
            temp5 += (data[q + (j+9)]);
        }
        // extra loop to ctach all the missed values 
        for(; j < len2; ++j){
            // calculate mod outside of the array [] and add missed values to the results array directly 
            int k = j%5;
           results[k] += (data[q + (j)]);
        }
    }
    // add into the resuts array using += since it is more efficient than doing + + +...
    results[0] += temp1;
    results[1] += temp2;
    results[2] += temp3;
    results[3] += temp4;
    results[4] += temp5;
}

long get_every_student(const matrix_t *matrix) {
    // initialize accumulators
    long sum = 0;
    long sum1 = 0;
    long sum2 = 0;
    long sum3 = 0;
    long sum4 = 0;
    long sum5 = 0;
    long sum6 = 0;
    long sum7 = 0;
    long sum8 = 0;
    long sum9 = 0;
    // initialize variables that are used in for-loop conditions
    int i, j;
    int len = matrix->rows;
    int len2 = matrix->cols;
    // pre-compute this so no need to every time in the for-loop
    int len3 = len2 % 9;
    int flen = len2 - len3;
    for (i = 0; i < len; i++) {
        // part of the MGET function, stored it into a variable for easier usage in each loop
        int q = i * len2;
        for (j = 0; j < flen; j+=9) {
            // use every multiple accumualtor for 9 sums (found to be fastest when testing around)
            sum1 += ((matrix)->data[q + (j)]);
            sum2 += ((matrix)->data[q + (j+1)]);
            sum3 += ((matrix)->data[q + (j+2)]);
            sum4 += ((matrix)->data[q + (j+3)]);
            sum5 += ((matrix)->data[q + (j+4)]);
            sum6 += ((matrix)->data[q + (j+5)]);
            sum7 += ((matrix)->data[q + (j+6)]);
            sum8 += ((matrix)->data[q + (j+7)]);
            sum9 += ((matrix)->data[q + (j+8)]);
        // add an extra for loop for any amount of columns not easily divisible by 9 or that are missed
        } for(; j < len2; ++j){
            sum1 += ((matrix)->data[q+ (j)]);
        }
    } 
    // add all the data into the original sum variable by using += instead of + .. + .. because it is faster
    sum += sum1;
    sum += sum2;
    sum += sum3;
    sum += sum4;
    sum += sum5;
    sum += sum6;
    sum += sum7;
    sum += sum8;
    sum += sum9;

    // no need 
    return sum;
}
