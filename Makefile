dependencies:
	mkdir -p lib
	wget -O lib/assert.h https://raw.githubusercontent.com/ss-c-cpp-projects/assert/master/src/assert.h
	wget -O lib/assert.c https://raw.githubusercontent.com/ss-c-cpp-projects/assert/master/src/assert.c
	wget -O lib/stack.h https://raw.githubusercontent.com/ss-c-cpp-projects/stack/master/src/stack.h
	wget -O lib/stack.c https://raw.githubusercontent.com/ss-c-cpp-projects/stack/master/src/stack.c

test: test/evaluator-test.o src/evaluator.o
	mkdir -p bin
	gcc -g -o bin/test.bin test/evaluator-test.o lib/assert.o lib/stack.o src/evaluator.o
	./bin/test.bin
