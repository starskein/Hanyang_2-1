#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HeapStruct{
	int Capacity;
	int Size;
	int* Element;
}Heap;

Heap* CreateHeap(int heapSize);
void Insert(Heap* heap,int value);
int Find(Heap* heap, int value);
int DeleteMax(Heap* heap);
void PrintHeap(Heap* heap);
void freeHeap(Heap* heap);
FILE* fi;
FILE* fo;

int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
	fo = fopen(argv[2],"wt");
	Heap* heap;
	while(1){
		char ip[5];	
		int num;	
		fscanf(fi,"%s",ip);
		if(feof(fi)) break;
		if(strcmp(ip,"n")==0){
			fscanf(fi,"%d",&num);
			if(feof(fi)) break;
			heap = CreateHeap(num);
		}
		else if(strcmp(ip,"i")==0){
			fscanf(fi,"%d",&num);
			if(feof(fi)) break;
			Insert(heap,num);
		}
		else if(strcmp(ip,"f")==0){
			fscanf(fi,"%d",&num);
			if(feof(fi)) break;
			int p = Find(heap,num);
			if(p==1) fprintf(fo,"%d is in the heap\n",num);
			else fprintf(fo,"%d is not in the heap\n",num);
		}
		else if(strcmp(ip,"d")==0)
			DeleteMax(heap);
		else
			PrintHeap(heap);
	}
	fclose(fi);
	fclose(fo);
	freeHeap(heap);
}

Heap* CreateHeap(int heapSize){
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->Capacity = heapSize;
	heap->Size = 0;
	heap->Element = (int*)malloc(sizeof(int)*(heapSize+1));
	return heap;
}
void Insert(Heap* heap, int value){
	if(heap->Size == heap-> Capacity){
		fprintf(fo,"Insert Error : heap is full\n");
		return;
	}
	if(Find(heap,value) == 1){
		fprintf(fo,"%d is already in the heap\n",value);
		return;
	}
	heap->Size++;
	heap->Element[heap->Size] = value;
	int child = heap->Size;
	int parent = child/2;
	while(child>1 && heap->Element[parent]<heap->Element[child]){
		int temp = heap->Element[child];
		heap->Element[child] = heap->Element[parent];
		heap->Element[parent] = temp;
		child = parent;
		parent = child/2;
	}
	fprintf(fo,"insert %d\n",value);
}
int Find(Heap* heap, int value){
	if(value>heap->Element[1])
		return 0;
	for(int i=1; i<=heap->Size; i++){
		if(value == heap->Element[i]) return 1;
	}
	return 0;
}
int DeleteMax(Heap* heap){
	if(heap->Size == 0){
		fprintf(fo,"Delete Error : heap is empty\n");
		return -1;
	}
	int deleted_max = heap->Element[1];
	heap->Element[1] = heap->Element[heap->Size];
	heap->Size--;
	int parent = 1;
	int child = 2;
	if(child+1 <= heap->Size)
		child = (heap->Element[child]>heap->Element[child+1])? child : child+1;		
	while(child <=heap->Size && heap->Element[parent]<heap->Element[child]){
		int temp = heap->Element[child];
		heap->Element[child] = heap->Element[parent];
		heap->Element[parent] = temp;
		parent = child;
		child = child*2;
		if(child+1 <= heap->Size)
			child = (heap->Element[child]>heap->Element[child+1])? child : child+1;
	}
	fprintf(fo,"Max Element: %d deleted\n",deleted_max);
	return deleted_max;
}
void PrintHeap(Heap* heap){
	if(heap->Size==0){
		fprintf(fo,"Print Error : heap is empty\n");
		return;
	}
	for(int i=1; i<=heap->Size; i++){
		fprintf(fo,"%d ",heap->Element[i]);
	}
	fprintf(fo,"\n");
}
void freeHeap(Heap* heap){
	free(heap->Element);
	free(heap);
}

