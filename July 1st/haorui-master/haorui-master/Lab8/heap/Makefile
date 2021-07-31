COMPILER = gcc

CSTD = --std=c18

heaps: heap.o array_list.o
	$(COMPILER) $(CSTD) ../../CI/objects/heap/heapM.o heap.o array_list.o -o heap
	$(COMPILER) $(CSTD) ../../CI/objects/heap/rheapM.o heap.o array_list.o -o rheap

heap.o: heap.c heap.h
	$(COMPILER) $(CSTD) -c heap.c


array_list.o: ../array_list/array_list.c ../array_list/array_list.h
	$(COMPILER) $(CSTD) -c ../array_list/array_list.c

clean:
	rm -f *.o heap
