#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

#define LARGE_SET_SIZE 30000
#define SMALL_SET_SIZE 1000

typedef struct timespec timespec_t;

double get_elapsed_time_sec(const timespec_t *start, const timespec_t *end) {
    long start_nanos = (long)1e9 * start->tv_sec + start->tv_nsec;
    long end_nanos = (long)1e9 * end->tv_sec + end->tv_nsec;
    return (double)(end_nanos - start_nanos) / 1e9;
}

int main() {
    // TODO: Declare whatever variables you need to time functions
    timespec_t start;             // Variables for timing
    timespec_t end;
    double cpu_time;

    int results_small[SMALL_SET_SIZE * 2];
    int *results_large = malloc(sizeof(int) * LARGE_SET_SIZE * 2);

    // set up list for testing control list search vs your list search
    list_t list;
    list_init(&list);
    for (int i = 0; i < SMALL_SET_SIZE; i++){
        list_add(&list, i * 2);
    }

    // TODO: Use "clock_gettime" to get the time before the loop starts
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < 2 * SMALL_SET_SIZE; i++) {
        results_small[i] = list_find(&list, i);
    }

    // TODO: Use "clock_gettime" to get the time after the loop finishes
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // TODO: Calculate the time it took for the loop to run
    cpu_time = get_elapsed_time_sec(&start, &end);

    if (validate_results(results_small, SMALL_SET_SIZE * 2)) {
        printf("Indices correct.\n");
    }
    else {
        printf("One or more indices incorrect.\n");
    }

    // TODO: Replace the "????" with an argument for the time and uncomment the print statement
    printf("Time for control implementation: %f\n\n", cpu_time);

    // TODO: Use "clock_gettime" to get the time before the loop starts
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < 2 * SMALL_SET_SIZE; i++) {
        results_small[i] = list_find_student(&list, i);
    }

    // TODO: Use "clock_gettime" to get the time after the loop runs
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // TODO: Calculate the time it took the loop to run
    cpu_time = get_elapsed_time_sec(&start, &end);

    if (validate_results(results_small, SMALL_SET_SIZE * 2)) {
        printf("Indices correct.\n");
    }
    else {
        printf("One or more indices incorrect.\n");
    }

    // TODO: Replace the "????" with an argument for the time and uncomment the print statement
    printf("Time for student implementation: %.3f sec.\n\n", cpu_time);


    // Set up list and array for testing your list search vs searching an array
    list_free(&list);
    int *arr = malloc(sizeof(int) * LARGE_SET_SIZE);
    for (int i = 0; i < LARGE_SET_SIZE; i++) {
        list_add(&list, i * 2);
        arr[i] = 2 * i;
    }

    // TODO: Use "clock_gettime" to get the time before the loop runs
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < LARGE_SET_SIZE * 2; i++) {
        results_large[i] = list_find_student(&list, i);
    }

    // TODO: Use "clock_gettime" to get the time after the loop runs
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // TODO: Calculate the time it took the loop to run
    cpu_time = get_elapsed_time_sec(&start, &end);

    if (validate_results(results_large, LARGE_SET_SIZE * 2)) {
        printf("Indices correct.\n");
    }
    else {
        printf("One or more indices incorrect.\n");
    }

    // TODO: Replace the "????" with an argument for the time and uncomment the print statement
    printf("Time for list linear search: %.3f sec.\n\n", cpu_time);

    // TODO: Use "clock_gettime" to get the time before the loop runs
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < LARGE_SET_SIZE * 2; i++) {
        results_large[i] = array_find(arr, LARGE_SET_SIZE, i);
    }

    // TODO: Use "clock_gettime" to get the time after the loop runs
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // TODO: Calculate the time it took the loop to run
    cpu_time = get_elapsed_time_sec(&start, &end);

    if (validate_results(results_large, LARGE_SET_SIZE * 2)) {
        printf("Indices correct.\n");
    }
    else {
        printf("One or more indices incorrect.\n");
    }

    // TODO: Replace the "????" with an argument for the time and uncomment the print statement
    printf("Time for array linear search: %.3f sec.\n", cpu_time);

    // Cleaning up memory
    list_free(&list);
    free(arr);
}
