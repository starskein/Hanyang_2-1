#include <stdio.h>
#include <stdlib.h>

FILE* fi;
FILE* fo;

struct CompleteTree{
	int Size;
	int nodeNum;
	int* Element;
};
typedef struct CompleteTree* Tree;
Tree NewTree(int size);
void Insert(Tree tree,int value);
void printPreorder(Tree tree, int index);
void printInorder(Tree tree, int index);
void printPostorder(Tree tree, int index);
void FreeTree(Tree tree);

int main(int args, char *argv[]){
	fi = fopen(argv[1],"r");
        fo = fopen(argv[2],"wt");
	
	int size;
	fscanf(fi,"%d",&size);
	Tree tree = NewTree(size);
	
	while(!feof(fi)){
		if(tree->nodeNum==tree->Size){
			fprintf(fo,"error, tree is full\n");
			break;
		}
		int temp;
		fscanf(fi,"%d",&temp);
		Insert(tree,temp);
		
	}
	fprintf(fo,"Preorder: ");
	printPreorder(tree,1 );
	fprintf(fo,"\n");
	fprintf(fo,"Inorder: ");
	printInorder(tree,1 );
	fprintf(fo,"\n");
	fprintf(fo,"Postorder: ");
	printPostorder(tree,1 );
	fprintf(fo,"\n");
	FreeTree(tree);
	fclose(fi);
}
Tree NewTree(int size){
	Tree tree = (Tree)malloc(sizeof(struct CompleteTree));
	tree->Size = size;
	tree->nodeNum = 0;
	tree->Element = (int*)malloc(sizeof(int)*(size+1));
	for(int i = 0; i<=size; i++){
		tree->Element[i] = -1;
	}
	return tree;
}
void Insert(Tree tree, int value){
	tree->nodeNum++;
	tree->Element[tree->nodeNum]=value;
}
void printPreorder(Tree tree,int index){
	if(index<=tree->nodeNum && tree->Element[index+1]!= -1){
		fprintf(fo,"%d ",tree->Element[index]);
		printPreorder(tree,index*2);
		printPreorder(tree,index*2+1);
	}
}
void printInorder(Tree tree,int index){
        if(index<=tree->nodeNum && tree->Element[index+1]!= -1){
                printInorder(tree,index*2);
		fprintf(fo,"%d ",tree->Element[index]);
		printInorder(tree,index*2+1);
        }
}
void printPostorder(Tree tree,int index){
        if(index<=tree->nodeNum && tree->Element[index+1]!= -1){
                printPostorder(tree,index*2);
                printPostorder(tree,index*2+1);
                fprintf(fo,"%d ",tree->Element[index]);
        }
}
void FreeTree(Tree tree){
	free(tree->Element);
	free(tree);
}


