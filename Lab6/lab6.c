#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a)>(b)) ? (a) : (b))

typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;
struct AVLNode{
	ElementType Element;
	AVLTree left;
	AVLTree right;
	int Height;
};
AVLTree Insert(ElementType X, AVLTree T);
Position SingleRotateWithLeft(Position node);
Position SingleRotateWithReft(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
int Height(Position node);
int getBalance(Position node);
Position Balance(AVLTree T);
void ResetHeight(AVLTree T);
void printInorder(AVLTree T);
void deleteTree(AVLTree T);

FILE* fi;
FILE* fo;
int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
        fo = fopen(argv[2],"wt");
	AVLTree root = NULL;
	while(1){
		ElementType temp;
		fscanf(fi,"%d" ,&temp);
		if(feof(fi)) break;
		root = Insert(temp,root);
		printInorder(root);
		fprintf(fo,"\n");
	}
	
	deleteTree(root);
	fclose(fi);
	fclose(fo);
}
AVLTree Insert(ElementType X, AVLTree T){
	if(T == NULL){
		T =malloc(sizeof(struct AVLNode));
		T->Element = X;
		T->left = NULL;
		T->right = NULL;
		T->Height = 0;
	}
	else if (T->Element>X){
		T->left = Insert(X, T->left);
		T = Balance(T);
	}
	else if(T->Element<X){
		T->right = Insert(X, T->right);
		T = Balance(T);
	}
	else{
		fprintf(fo,"error, already existing\n");
	}
	ResetHeight(T);
	return T;
}

Position SingleRotateWithLeft(Position node){
	Position next = node->left;
	node->left = next ->right;
	next->right = node;
	return next;
}
Position SingleRotateWithRight(Position node){
	Position next = node->right;
	node->right = next->left;
	next->left = node;
	return next;
}
Position DoubleRotateWithLeft(Position node){
	Position next = node->left;
	node->left = SingleRotateWithRight(next);
	return SingleRotateWithLeft(node);
}
Position DoubleRotateWithRight(Position node){
	Position next = node->right;
	node->right = SingleRotateWithLeft(next);
	return SingleRotateWithRight(node);
}
int Height(Position node){
	if(node == NULL)
		return -1;
	else
		return max(Height(node->left),Height(node->right)) + 1;
}
int getBalance(Position node){
	return Height(node->left) - Height(node->right);
}
void ResetHeight(AVLTree T){
	if(T!=NULL){
		ResetHeight(T->left);
		ResetHeight(T->right);
		T->Height = Height(T);
	}
}
Position Balance(AVLTree T){
	int bal = getBalance(T);
	if(bal >1){
		if(getBalance(T->left)>0)
			T = SingleRotateWithLeft(T);
		else
			T = DoubleRotateWithLeft(T);
	}
	else if(bal < -1){
		if(getBalance(T->right)<0)
			T = SingleRotateWithRight(T);
		else 
			T = DoubleRotateWithRight(T);
	}
	return T;
}
void printInorder(AVLTree T){
	if(T!= NULL){
	printInorder(T->left);
	fprintf(fo,"%d(%d) ",T->Element,T->Height);
	printInorder(T->right);
	}
	else{
		return;
	}
}
void deleteTree(AVLTree T){
	if(T!=NULL){
		deleteTree(T->left);
		deleteTree(T->right);
		free(T);
	}
}
