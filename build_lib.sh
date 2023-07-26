#!/bin/sh

mkdir -p bin/include
mkdir -p bin/lib

cp cose.h cose.c
gcc -Wall -Wextra -c cose.c -O2 -o bin/cose.o
rm cose.c
ar -crs bin/lib/libcose.a bin/*.o
cp src/*.h bin/include
sed '/".*\.c"/d' cose.h > bin/include/cose.h
