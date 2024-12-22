# Project of using `Clang`+`KLEE` for C++ code test generator.

## Requirements:

- `clang` and `clang++` version `13.0.1`;

```bash
$ clang --version
Ubuntu clang version 13.0.1-2ubuntu2.2
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

- `llvm` version `13.0.1`;

```bash
$ llvm-config --version
13.0.1
```

- `z3` version `4.13.1`;

```bash
$ z3 --version
Z3 version 4.13.1 - 64 bit
```

- built `klee-uclibc` library:

```bash
$ git clone https://github.com/klee/klee-uclibc.git ~/Downloads
$ cd ~/Downloads/klee-uclibc
$ ./configure --make-llvm-lib   
$ make -j2
$ cd -
```

- built `libc++` library;
- `google tests lib` version `1.11.0`.

Link to check info about `KLEE` installation: https://klee-se.org/build/build-llvm13/.
Command with which I built `KLEE`:

```bash
mkdir -p Downloads/build
cd Downloads/build
cmake -DENABLE_POSIX_RUNTIME=ON -DENABLE_SOLVERS=Z3 -DKLEE_UCLIBC_PATH=/home/alex/Downloads/klee-uclibc -DENABLE_UNIT_TESTS=ON -DGTEST_SRC_DIR=/home/alex/Downloads/gtests/googletest-release-1.11.0/ -DENABLE_KLEE_LIBCXX=ON -DKLEE_LIBCXX_DIR=/home/alex/Downloads/libc++-install-130 -DKLEE_LIBCXX_INCLUDE_PATH=/home/alex/libc++-install-130/include/c++/v1/ /home/alex/Downloads/klee
```