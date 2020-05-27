#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Queue* Queue;
struct _Queue{
	int* key;
	int first;
	int rear;
	int qsize;
	int max_queue_size;
};

typedef struct _Graph* Graph;
struct _Graph{
	int* node;
	int size;
	int** matrix;
};
Graph CreateGraph(int* nodes);
void InsertEdge(Graph G,int a,int b);
void TopSort(Graph G);
Queue MakeNewQueue(int X);
void Enqueue(Queue Q, int X);
int Dequeue(Queue Q);
void PrintMatrix(Graph G);
FILE* fi;
FILE* fo;

int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
	fo = fopen(argv[2],"wt");
	int cnt = 0;
	int nodes[100] = {0};
	char str[100];
	fgets(str, 100, fi);
	char* ptr = strtok(str," ");
	nodes[cnt] = atoi(ptr);

	while(ptr != NULL){
		nodes[cnt] = atoi(ptr);
		ptr = strtok(NULL, " ");
		cnt++;
	}
	Graph G = CreateGraph(nodes);
	char str2[100];
	fgets(str2,100,fi);
	char* edge = strtok(str2," ");
	int a,b;
	
	while(edge != NULL){
		a = edge[0]-'0';
		b = edge[2]-'0';
		InsertEdge(G,a,b);
		edge = strtok(NULL," ");
	}
	PrintMatrix(G);
	
	fprintf(fo,"\n");
	
	TopSort(G);
	
}

Graph CreateGraph(int* nodes){
	Graph G = (Graph)malloc(sizeof(struct _Graph));
	int cnt=0;
	while(nodes[cnt]!=0){
		cnt++;
	}
	G->node = (int*)malloc(sizeof(int)*cnt);
	memcpy(G->node,nodes,sizeof(int)*cnt);
	G->size = cnt;
	G->matrix = malloc(sizeof(int*)*cnt);
	for(int i=0; i<cnt;i++){
		G->matrix[i] = malloc(sizeof(int)*cnt);
	} 
	for(int i=0; i<cnt;i++){
		for(int j=0; j<cnt;j++)
			G->matrix[i][j] = 0;
	}
	return G;
}

void InsertEdge(Graph G, int a, int b){
	int i=0,j=0;
	while(G->node[i]!=a)
		i++;
	while(G->node[j]!=b)
		j++;
	G->matrix[i][j] = 1;
}

void TopSort(Graph G){
	Queue Q = MakeNewQueue(G->size);
	int num_left = G->size;
	while(num_left!=0){
		int cnt=0;

		for(int i=(G->size)-1;i>=0;i--){
			
			int flag = 0;
			for(int j=0;j<G->size;j++){
				if(G->matrix[j][i]==1){
					flag = 1;
				}
			}
			if(flag == 0){
				cnt++;
				Enqueue(Q,G->node[i]);
				G->matrix[i][i] = 1;
			}
		}
		for(int i=0;i<G->size;i++){
			if(G->matrix[i][i] == 1){
				for(int k=0;k<G->size;k++)
                                	G->matrix[i][k] = 0;
				G->matrix[i][i] = 1;
			}
		}
		
		num_left = num_left - cnt;
		for(int i=0;i<cnt;i++){
			int dequeue = Dequeue(Q);
			fprintf(fo,"%d ",dequeue);
		}
		
	}
	free(Q->key);
	free(Q);
}

Queue MakeNewQueue(int X){
	Queue Q = (Queue)malloc(sizeof(struct _Queue));
	Q->key = (int*)malloc(sizeof(int)*X);
	Q->qsize = 0;
	Q->max_queue_size = X;
	return Q;
}

void Enqueue(Queue Q, int X){
	for(int i=Q->qsize;i>0;i--)
		Q->key[i] = Q->key[i-1];
	Q->key[0] = X;
	Q->first = X;
	Q->rear = Q->key[Q->qsize];
	Q->qsize++;
}
int Dequeue(Queue Q){
	int pop = Q->first;
	for(int i=0;i<Q->qsize;i++)
		Q->key[i] = Q->key[i+1];
	Q->qsize--;
	Q->first = Q->key[0];
	Q->rear = Q->key[Q->qsize];
	return pop;
}
void PrintMatrix(Graph G){
	for(int i=-1;i<G->size;i++){
		for(int j=-1;j<G->size;j++){
			if(i==-1 && j==-1)
				fprintf(fo,"  ");
			else if(i==-1)
				fprintf(fo,"%d ",G->node[j]);
			else if(j==-1)
				fprintf(fo,"%d ",G->node[i]);
			else
				fprintf(fo,"%d ",G->matrix[i][j]);
		}
		fprintf(fo,"\n");
	}
}
