dependencies:
	mkdir -p lib
	wget -O lib/assert.h https://raw.githubusercontent.com/ss-c-cpp-projects/assert/master/src/assert.h
	wget -O lib/assert.c https://raw.githubusercontent.com/ss-c-cpp-projects/assert/master/src/assert.c
	wget -O lib/stack.h https://raw.githubusercontent.com/ss-c-cpp-projects/stack/master/src/stack.h
	wget -O lib/stack.c https://raw.githubusercontent.com/ss-c-cpp-projects/stack/master/src/stack.c

test: 
	mkdir -p bin
	gcc -o bin/test.bin test/postfix-evaluator-test.o lib/assert.o lib/stack.o src/evaluator.c