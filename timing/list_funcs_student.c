#include <stdlib.h>
#include "linked_list.h"

int list_find_student(list_t *list, int value) {
    // set index and current node we are looking at to 0 and head
    int index = 0;
    node_t *current = list->head;
    // set while condition so that it still goes while there is a current node
   while(current != NULL){
       // check the current value of node and compare it
       if (current -> value == value){
           return index;
       } else {
           // if not equal, update the index we are looking at and the next node
           current = current->next;
           index++;
       }
   }
    return -1;
}
