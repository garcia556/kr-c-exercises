src=$1
out=$(basename ${src} .c)
dir=$(dirname ${src})
lib="${dir}/_flib.c"

if [ ! -f ${lib} ]; then
	lib=""
fi

cc -g -O0 -std=c99 -o ${out} ${lib} ${src}
echo "Running program:"
./${out}
rm -rf ${out} ${out}.dSYM

