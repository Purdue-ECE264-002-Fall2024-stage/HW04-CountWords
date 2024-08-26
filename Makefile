# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 

TESTFLAGS = -DTEST_TOTALCOUNTWORD -DTEST_EACHCOUNTWORD # -DDEBUG

SRCS = main.c filestr.c
OBJS = $(SRCS:%.c=%.o)

# diff -w means do not care about space

hw04: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw04

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6

test1: hw04
	./hw04 inputs/input1 | sort > output1
	diff -w output1 expected/expected1

test2: hw04
	./hw04 inputs/input2 | sort > output2
	diff -w output2 expected/expected2

test3: hw04
	./hw04 inputs/input3 | sort > output3
	diff -w output3 expected/expected3

test4: hw04
	./hw04 inputs/input4 | sort > output4
	diff -w output4 expected/expected4

test5: hw04
	./hw04 inputs/input5 | sort > output5
	diff -w output5 expected/expected5

test6: hw04
	./hw04 inputs/input6 | sort > output6
	diff -w output6 expected/expected6


clean: # remove all machine generated files
	rm -f hw04 *.o output*


