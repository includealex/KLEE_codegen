#!/bin/bash

source ../../../config.sh

clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone -I ${MY_KLEE_INC_PATH} test6.c
klee -posix-runtime test6.bc -sym-arg 10 

clang -I ${MY_KLEE_INC_PATH} test6.c
t_name=$( ls "klee-last" | grep "err" | cut -d "." -f 1 )

for cur_name in ${t_name[@]}; do klee-replay a.out "klee-last/${cur_name}.ktest"; done

