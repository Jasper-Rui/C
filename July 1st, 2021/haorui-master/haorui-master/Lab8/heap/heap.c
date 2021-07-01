#include "heap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Heap* heap_initialize(int typeSize, char* typeName, int (* number)(void*, void*), void (* ptr)(void*)){
	Heap* heap = malloc(sizeof(Heap));
	
	if(heap!=NULL){
		heap->list = alist_initialize(99,typeSize,typeName);
		heap->compare = number;
		heap->print = ptr;
		return heap;

	}
	return NULL;

}


bool heap_insert(Heap* heap, void* ptr){
	if(heap != NULL && ptr != NULL){
		if(heap->list->size == 0){
			return alist_add(heap->list, ptr);
		}
		else{
			alist_add(heap->list,ptr);
			return _heapify_up(heap,heap->list->size-1);
		}

	}
	return false;
}

void* heap_remove(Heap* heap){
	if(heap != NULL){
		if(heap->list->size == 1){
			return alist_remove(heap->list,0);
		}
		else if(heap->list->size == 2){
			void* rootptr = alist_get(heap->list,0);
			void* leftptr = alist_get(heap->list,1);
			if(heap->compare(leftptr,rootptr) > 0 ){
				heap->list->arr[0] = leftptr;
				heap->list->arr[1] = rootptr;
			}
			return alist_remove(heap->list,0);
		}
		else{
			void* temp = alist_get(heap->list,0);
			int lastptr = heap->list->size-1;
			heap->list->arr[0] = alist_get(heap->list,lastptr);
			alist_remove(heap->list,lastptr);
			_heapify(heap,0);
			return temp;

		}


	}
	return NULL;

}

void* heap_peek(Heap* heap){
	if(heap != NULL){
		return alist_get(heap->list,0);

	}
	return NULL;
}

int heap_size(Heap* heap){
	return heap->list->size;
}

bool heap_contains(Heap* heap,void* ptr){
	if(heap != NULL && ptr != NULL){
		return alist_index_of(heap->list,ptr) != -1;

	}
	return false;
}

bool _heapify(Heap* heap,int index){

	if(heap != NULL && index >= 0 && index < heap->list->size ){

	int lefti = index*2 +1;
	int righti = (index+1)*2;
	int end = heap->list->size -1;
	void* temp = alist_get(heap->list,index);
	void* left = alist_get(heap->list,lefti);
	void* right = alist_get(heap->list,righti);
	if(end < index || end < lefti || end < righti){
		return true;
	}
	
	if(heap->compare(left,temp)>0 && heap->compare(left,right)>=0){
		
		heap->list->arr[lefti] = temp;
		heap->list->arr[index] = left;
		return _heapify(heap,lefti);
	}
	else if(heap->compare(right,temp)>0 && heap->compare(right,left)>=0){

		heap->list->arr[righti] = temp;
                heap->list->arr[index] = right;
                return _heapify(heap,righti);

	}
	else{
		return true;
	}
}
	return false;
}

bool _heapify_up(Heap* heap,int index){
	if(heap != NULL && index >= 0 && index < heap->list->size ){
		void* temp = alist_get(heap->list,index);
		void* root = NULL;
		int rooti = -1;

		void* nextroot = NULL;
		int nrooti = -1;
		if(index == 0){
			return true;
		}
		if(heap->list->size == 2){
			rooti = 0;
			root=alist_get(heap->list,0);
		}
		
		if(index % 2 != 0){
			rooti = (index-1)/2;
			root = alist_get(heap->list,rooti);
			nrooti = (rooti + 1)*2;
			nextroot = alist_get(heap->list,nrooti);
		}
		else{

			rooti = (index/2)-1;
			root = alist_get(heap->list,rooti);
			nrooti = rooti*2+1;
			nextroot = alist_get(heap->list,nrooti);
		}

		if(heap->compare(root,temp)<0){

			heap->list->arr[index] = root;
			heap->list->arr[rooti] = temp;
			return _heapify_up(heap,rooti);


		}
		else{
			return true;
		}
			
	}
	return false;
}



