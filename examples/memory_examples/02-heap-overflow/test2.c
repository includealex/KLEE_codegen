#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <klee/klee.h>

int test2(char* buf) {
    int* dyn_mem_arr = malloc(sizeof(int) * 10);
    dyn_mem_arr[0] = 0;
    dyn_mem_arr[1] = 1;
    dyn_mem_arr[2] = 2;
    dyn_mem_arr[3] = 3;
    dyn_mem_arr[4] = 4;
    dyn_mem_arr[5] = 5;
    dyn_mem_arr[6] = 6;
    dyn_mem_arr[7] = 7;
    dyn_mem_arr[8] = 8;
    dyn_mem_arr[9] = 9;

    int i = 5;
    if (strcmp(buf, "BUG!") == 0) {
        i += 20;
    }

    int return_value = dyn_mem_arr[i];
    free(dyn_mem_arr);

    return return_value;
}


int main(int argc, char** argv) {
    char arr[10];
    klee_make_symbolic(arr, 10, "arr");
    klee_assume(arr[9] == '\0');
    test2(arr);
}
