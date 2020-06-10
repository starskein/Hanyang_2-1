#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode *Position;
typedef Position List;
typedef struct HashTbl *HashTable;

struct ListNode{
	int Element;
};

struct HashTbl{
	int TableSize;
	List* TheLists;
};

void Insert(HashTable H,int value, int solution);
void Delete(HashTable H,int value, int solution);
int Find(HashTable H, int value, int solution);
void printTable(HashTable H);
int Hash(int value, int Size, int i, int solution);

FILE* fi;
FILE* fo;
int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
	fo = fopen(argv[2],"wt");
	char solution[20];
	int sol,size;
	fscanf(fi,"%s",solution);
	if(strcmp("Linear",solution)==0) sol = 1;
	else sol =2;
	fscanf(fi,"%d",&size);
	HashTable H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize = size;
	H->TheLists = (List*)malloc(sizeof(List)*size);

	for(int i=0;i<size;i++){
		H->TheLists[i] = malloc(sizeof(struct ListNode));
		H->TheLists[i]->Element = 0;
	}	

	while(1){
		char command;
		int num;
		fscanf(fi,"%c",&command);
		if(feof(fi)) break;
		if(command == 'i'){
			fscanf(fi,"%d",&num);
			if(feof(fi)) break;
			Insert(H,num,sol);
		}
	
		else if(command == 'f'){
			fscanf(fi,"%d",&num);
			if(feof(fi)) break;
			int f = Find(H,num,sol);
			if(f == -1) fprintf(fo, "Not found\n");
			else fprintf(fo, "Hash table %d\n",f);
		}
		
		else if(command == 'd'){
			fscanf(fi,"%d",&num);
                        if(feof(fi)) break;
			Delete(H,num,sol);
		}
	
		else if(command == 'p'){
			printTable(H);
		}
	
	}

	free(H->TheLists);
	free(H);	

	fclose(fi);
	fclose(fo);		

}

void Insert(HashTable H, int value, int solution){
	int i=0;
	if(Find(H, value, solution)!=-1){
		fprintf(fo,"Already exists\n");
		return;
	}
	
	while(1){
		int h = Hash(value,H->TableSize,i,solution);
		if(H->TheLists[h]->Element == 0){
			H->TheLists[h]->Element = value;
			break;
		}
		i++;
	}

	fprintf(fo,"Inserted %d\n",value);
}

void Delete(HashTable H, int value, int solution){
	int f = Find(H,value,solution);
	if(f==-1){
		fprintf(fo,"%d not exists\n",value);
		return;
	}
	H->TheLists[f]->Element = 0;
	fprintf(fo,"Deleted %d\n",value);
}

int Find(HashTable H, int value, int solution){
	int i=0;
	int index = -1;
        while(1){
		int h = Hash(value,H->TableSize,i,solution);
		if(H->TheLists[h]->Element == value){
			index = h;
			break;
		}
                if(H->TheLists[h]->Element == 0)
                        break;
                        
                i++;
	}
   	
	return index;
}

void printTable(HashTable H){
	for(int i=0;i<H->TableSize;i++)
		fprintf(fo,"%d ",H->TheLists[i]->Element);
	fprintf(fo,"\n");
}

int Hash(int value, int Size, int i, int solution){
	int h;
	h = value % Size;
	if(solution == 1){
		h = (h + i)% Size;
		return h;
	}
	else{
		h = (h + i*i) % Size;
		return h;
	}
}
		
