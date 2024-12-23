#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <klee/klee.h>


int global_arr[10]={0,1,2,3,4,5,6,7,8,9};

int test1(char* buf) {
    int i = 5;
    if (strcmp(buf, "BUG!") == 0) {
        i += 20;
    }

    return global_arr[i];
}


int main(int argc, char** argv) {
    char arr[10];
    klee_make_symbolic(arr, 10, "arr");
    klee_assume(arr[9] == '\0');
    test1(arr);
}
