#!/bin/bash

source ../../../config.sh

clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone -I ${MY_KLEE_INC_PATH} test3.c
klee --libc=uclibc test3.bc
