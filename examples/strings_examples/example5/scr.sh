#!/bin/bash

source ../../../config.sh

clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone -I ${MY_KLEE_INC_PATH} test5.c
klee --libc=uclibc test5.bc