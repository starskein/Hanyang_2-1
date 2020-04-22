#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTree* Tree;
struct BinarySearchTree{
	int value;
	Tree left;
	Tree right;
};
Tree insertNode(Tree root, int key);
Tree createNode(int key);
Tree findMinNode(Tree root);
int searchNode(Tree root, int key);
void findNode(Tree root, int key);
void printInorder(Tree root);
Tree deleteNode(Tree root,int key);
void deleteTree(Tree root);
FILE* fo;
FILE* fi;
int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
        fo = fopen(argv[2],"wt");
	Tree root=NULL;
	
	while(1){
		char ip[5];
		int val;
		fscanf(fi,"%s",ip);
		if(feof(fi)) break;
		if(strcmp(ip,"i")==0){
			fscanf(fi,"%d",&val);
			if(root == NULL){
				root = createNode(val);
				fprintf(fo,"insert %d\n",val);
			
			}
			else{
				if(searchNode(root,val))
					fprintf(fo,"error, already existing number\n");
				else{
					insertNode(root,val);
					fprintf(fo, "insert %d\n", val);
				}
				
			}
		}
		else if(strcmp(ip,"d")==0){
			fscanf(fi,"%d",&val);
			if(searchNode(root, val)){
				if(root->value == val && root->left==NULL && root->right == NULL){
					root=NULL;
					fprintf(fo,"delete %d\n",val);
				}
				else{
					deleteNode(root,val);
					fprintf(fo,"delete %d\n",val);
				}
				
				
			}
			else{
				fprintf(fo,"error, %d is not in the tree\n",val);
			
			}
			
		}
		else if(strcmp(ip,"f")==0){
                        fscanf(fi,"%d",&val);
                        findNode(root,val);
		
                }
		else if(strcmp(ip,"pi")==0){
			printInorder(root);
			fprintf(fo,"\n");
			
		}
	
	}
	fclose(fi);
	fclose(fo);
	deleteTree(root);
}
Tree createNode(int key){
	Tree newNode = (Tree)malloc(sizeof(struct BinarySearchTree));
	newNode->left =NULL;
	newNode->right =NULL;
	newNode->value =key;
	return newNode;
}
Tree insertNode(Tree root,int key){
	Tree newNode =createNode(key);
	if(root->value < key){
		if(root->right == NULL)
			root->right = newNode;
		else
			insertNode(root->right,key);
	}
	else if(root->value >key){
		if(root->left == NULL)
			root->left = newNode;
		else
			insertNode(root->left,key);
	}
	return root;
}

int searchNode(Tree root, int key){
	if(root == NULL)
		return 0;
	if(root->value < key)
		return searchNode(root->right,key);
	else if(root->value >key)
		return searchNode(root->left,key);
	else
		return 1;
}
void findNode(Tree root, int key){
	if(searchNode(root, key))
		fprintf(fo,"%d is in the tree.\n", key);
	else
		fprintf(fo,"error there is no %d in the tree\n", key);
}
void printInorder(Tree root){
	if(root != NULL){
		printInorder(root->left);
		fprintf(fo,"%d ",root->value);
		printInorder(root->right);
	}
	else
		return;
}
Tree deleteNode(Tree root,int key){
	Tree deleted = NULL;
	
	if(root == NULL)
		return NULL;
	if(root->value > key)
		root->left = deleteNode(root->left,key);
	else if(root->value <key)
		root->right = deleteNode(root->right,key);
	else{
		if(root->right != NULL && root->left != NULL){
			deleted = findMinNode(root->right);
			root->value = deleted->value;
			root->right = deleteNode(root->right,deleted -> value);
		}
		else{
			deleted = (root->left == NULL) ? root->right : root->left;
			root = NULL;
			return deleted;
		}
	}
	return root;
}
Tree findMinNode(Tree root){
	Tree tmp = root;
	while(tmp->left != NULL)
		tmp = tmp->left;
	return tmp;
} 
void deleteTree(Tree root){
	if(root!=NULL){
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}
