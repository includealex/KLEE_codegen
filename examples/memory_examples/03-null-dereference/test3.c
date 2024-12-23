#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <klee/klee.h>

char* global_string[] = {"string1", "string2", "string3", NULL};

int test3(char* buf) {
    int i = 1;
    if (strcmp(buf, "BUG!") == 0) {
        i = 3;
    }

    char c = *(global_string[i]);
    if (c == 's') {
        return 0;
    }

    return 1;
}


int main(int argc, char** argv) {
    char arr[10];
    klee_make_symbolic(arr, 10, "arr");
    klee_assume(arr[9] == '\0');
    test3(arr);
}
