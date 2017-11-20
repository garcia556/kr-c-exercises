#!/bin/bash

src=$1
out=$(basename ${src} .c)
dir=$(dirname ${src})
lib="${dir}/_flib.c"

if [ ! -f ${lib} ]; then
	lib=""
fi

cc -g -O0 -std=c99 -o ${out} ${lib} ${src} 
echo "Running program:"

set -f
shift
args=""
for var in "$@"; do
	args="${args} ${var}"
done

./${out} ${args}
rm -rf ${out} ${out}.dSYM

