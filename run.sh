src=$1
out=$(basename ${src} .c)

cc -g -O0 -std=c99 -o ${out} ${src}
echo "Running program:"
./${out}
rm -rf ${out} ${out}.dSYM

