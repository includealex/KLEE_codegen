#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <klee/klee.h>

void check_string(char* buf, int len) {
    unsigned int sum = 1;
    for (int i = 0; i < len; i++) {
        sum *= (unsigned char)buf[i];
    }
    if (sum == 257) {
        assert(0);
    }

    return;
}

int main(int argc, char** argv) {
#define SIZE 3
    char buf[SIZE];
    klee_make_symbolic(buf, sizeof(buf), "buf");
    check_string(buf, SIZE);
    return 0;
}