COMPILER = gcc

CSTD = --std=c18

LIBRARY = -Ilib

pool: linked_list.o array_list.o heap.o queue.o pool.c 
	$(COMPILER) $(CSTD) $(LIBRARY) pool.c ../../CI/objects/pool/poolM.o linked_list.o heap.o array_list.o queue.o -o pool -lpthread

linked_list.o: ../lib/linked_list.c ../lib/linked_list.h
	$(COMPILER) $(CSTD) $(LIBRARY) -c ../lib/linked_list.c

queue.o: ../lib/queue.c ../lib/queue.h
	$(COMPILER) $(CSTD) $(LIBRARY) -c ../lib/queue.c

array_list.o: ../lib/array_list.c ../lib/array_list.h
	$(COMPILER) $(CSTD) $(LIBRARY) -c ../lib/array_list.c

heap.o: ../lib/heap.c ../lib/heap.h
	$(COMPILER) $(CSTD) $(LIBRARY) -c ../lib/heap.c

clean:
	rm -f *.o pool





