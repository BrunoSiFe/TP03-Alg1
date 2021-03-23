CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp03
TMPOUT=tp03.testresult

$(EXEC): main.cpp stopover.o utils.o
	$(CC) $(CFLAGS) main.cpp stopover.o utils.o -o $(EXEC)

utils.o: implementation/utils.cpp
	$(CC) $(CFLAGS) -c implementation/utils.cpp -o utils.o

stopover.o: implementation/stopover.cpp
	$(CC) $(CFLAGS) -c implementation/stopover.cpp -o stopover.o

test: $(EXEC)
	@bash run_test.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf stopover.o