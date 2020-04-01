#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
struct Node{
	ElementType element;
	Position next;
};
List MakeEmpty(List L);
int isEmpty(List L);
int isLast(Position P, List L);
void DeleteList(List L);

void Insert(ElementType X, List L, Position P);
void PrintList(List L);
void Delete(ElementType X, List L);
Position Find(ElementType X, List L);
FILE *output;


int main(int argc,char *argv[]){
	char command;
	int key1,key2;
	FILE *input;

	Position header;
	Position tmp;
	input = fopen(argv[1],"r");
	output = fopen(argv[2],"w");
	header = MakeEmpty(header);
	while(1){
		command = fgetc(input);
		if(feof(input)) break;
		switch(command){
		case 'i':
			fscanf(input,"%d %d",&key1,&key2);
			if(key2 == -1) Insert(key1,header,header);
			else{
				Position P = Find(key2,header);
				P = P->next;
				if(P==NULL){
					fprintf(output,"Insertion(%d) Failed: cannot find location\n",key1);
					break;
				}
				Insert(key1,header, P);
			}
			break;
		case 'd':
			fscanf(input,"%d",&key1);
			Delete(key1,header);
			break;
		case 'f':
			fscanf(input,"%d",&key1);
			Position P = Find(key1,header);
			if(P->next ==NULL){
				fprintf(output,"Finding(%d) Failed: element %d is not in list\n",key1,key1);
				break;
			}
			else if(P == header) fprintf(output,"key of previous node of %d is head\n",key1);
			else fprintf(output,"key of previous node of %d is %d\n",key1,P->element);
			break;
		case 'p':
			PrintList(header);	
		}
		
	}
	free(header);
}

int isEmpty(List L){
	return L->next==NULL;
}
int isLast(Position P, List L){
	return P->next==NULL;
}
List MakeEmpty(List L){
	if(isEmpty(L)) return L;
	List new = malloc(sizeof(struct Node));
	new->next =NULL;
	return new;
}
void Insert(ElementType X, List L, Position P){
	Position temp;
	temp = malloc(sizeof(struct Node));
	temp->element = X;
	temp->next = P->next;
	P->next = temp;
}
void PrintList(List L){
	Position P;
	P = L->next;
	while(P!=NULL){
		fprintf(output,"key: %d    ",P->element);
		P = P->next;
	}
	fprintf(output,"\n");
}
void Delete(ElementType X,List L){
	Position P1,P2;
	P1 = Find(X,L);
        if(P1->next==NULL){
        	fprintf(output,"Deletion(%d) Failed: element %d is not in list\n",X,X);
		return;
	}
	if(!isLast(P1,L)){
		P2 = P1->next;
		P1->next = P2->next;
		free(P2);
	}
}
Position Find(ElementType X,List L){
	Position P;
	P = L;
	if(P->next==NULL) return P;
	while(P->next->element!=X){
		P=P->next;
		if(P->next==NULL) break;
	}
	return P;
}
