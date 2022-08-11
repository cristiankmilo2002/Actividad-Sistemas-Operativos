CC=gcc

%.o: %.c
	$(CC) -c -o $@ $<

linkedListOpt: linkedListOpt.o
	gcc -o linkedListOpt linkedListOpt.o

clean:
	rm -f *.o linkedListOpts