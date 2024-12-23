#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <klee/klee.h>

void check_string(char* buf, int len) {
    if (buf[0] == 'T' && buf[1] == 'E' && buf[2] == 'S' && buf[3] == 'T') {
        assert(0);
    }
    
    return;
}


int main(int argc, char** argv) {
    check_string(argv[1], 10);
    return 0;
}
