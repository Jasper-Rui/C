COMPILER = gcc

CSTD = --std=c18

threads: threads.c safe.c unsafe.c
	$(COMPILER) $(CSTD) ../../CI/objects/threads/threadsM.o threads.c -o threads -lpthread
	$(COMPILER) $(CSTD) ../../CI/objects/threads/safeM.o safe.c -o safe -lpthread
	$(COMPILER) $(CSTD) ../../CI/objects/threads/unsafeM.o unsafe.c -o unsafe -lpthread

clean:
	rm -f threads unsafe safe *.o