SRC_CPP_FILES = ${wildcard src/pattern/*.cpp} ${wildcard src/algorithm/*.cpp} ${wildcard src/structure/*.cpp} ${wildcard src/problem/*.cpp}

TEST_CPP_FILES = ${wildcard test/algorithm/*.cpp} ${wildcard test/pattern/*.cpp} ${wildcard test/structure/*.cpp}

OBJ_FILES = ${addprefix bin/objs/,${notdir ${SRC_CPP_FILES:.cpp=.o}}} ${addprefix bin/objs/,${notdir ${TEST_CPP_FILES:.cpp=.o}}}

CC_FLAGS = -g -Wall -Werror -std=c++11
LD_FLAGS = -lgtest -lgtest_main -lpthread -lgmock -lgmock_main
IN_FLAGS = -Iinclude
WN_FLAGS = -Wno-write-strings

all: bin/run

bin/run: ${OBJ_FILES} 
	g++ -o $@ $^ ${LD_FLAGS}


bin/objs/%.o: src/algorithm/%.cpp
	g++ ${CC_FLAGS} ${IN_FLAGS} ${WN_FLAGS} -c -o $@ $<

bin/objs/%.o: src/problem/%.cpp
	g++ ${CC_FLAGS} ${IN_FLAGS} ${WN_FLAGS} -c -o $@ $<


bin/objs/%.o: test/algorithm/%.cpp
	g++ ${CC_FLAGS} ${IN_FLAGS} ${WN_FLAGS} -c -o $@ $<

bin/objs/%.o: test/pattern/%.cpp
	g++ ${CC_FLAGS} ${IN_FLAGS} ${WN_FLAGS} -c -o $@ $<

bin/objs/%.o: test/structure/%.cpp
	g++ ${CC_FLAGS} ${IN_FLAGS} ${WN_FLAGS} -c -o $@ $<

bin/objs/%.o: test/%.cpp
	g++ ${CC_FLAGS} ${IN_FLAGS} ${WN_FLAGS} -c -o $@ $<


clean:
	rm bin/objs/*.o
	rm bin/run
