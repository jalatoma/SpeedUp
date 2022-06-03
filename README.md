# Optimization
Project 4 in CSCI 2021 completed Fall 2021. Focuses on optimizing and speeding up code. 

## Part 1 - Timing Folder
The purpose of the "Timing" assignment was to optimize the function list_find

list_find_student will take a list and a value, and see if any of the nodes in that list contain the value. If there is a node in the list that contains the value, then the index of that node should be returned (indexes start at 0 for the head of the list). If the value is not found, list_find_student should return -1. Again, the function should be faster than list_find, but this time the provided function is inefficient because of the algorithm it uses.

**I only modified and wrote list_find_student**

## Part 2 - Optimization Folder
The purpose of the "optimization" assignment was to optimize two functions by a speedup ratio of at least 4.0 and 2.0.

 - get_every_fifth_student: In this function, you will be finding the sums of integers based on their location in the matrix, color-coded in the diagram below. Elements in column 0, 5, 10, etc. go into the first element of the results array. Elements in column 1, 6, 11, etc. go into the second column of the array. This pattern continues for the remaining columns. To summarize, the numbers in column i go into element i % 5 of the results array.

This function should return the exact same results as get_every_fifth, our control function found in matrix_funcs.c. In the following picture, the elements of a sample matrix are color coded along with which sum in the results array they should contribute to.

 - get_every_student: This function is much simpler to understand. Sum all of the elements in the matrix and return the result. The only difficult part is, you have to do it quickly.

**I only edited matrix_funcs_student, the other one is the function it's comparing itself to**
