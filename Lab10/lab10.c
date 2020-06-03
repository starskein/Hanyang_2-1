#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 9999

typedef struct Node{
	int vertex;
	int dist;
	int prev;
}Node;

typedef struct Graph{
        int size;
        int** vertices;
        Node* nodes;
}Graph;

typedef struct Heap{
	int Capacity;
	int Size;
	Node* Element;
}Heap;

Graph* CreateGraph(int size);
void insertEdge(Graph* G, int s, int e, int c);
void Dijkstra(Graph* G);
void printShortestPath(Graph* g);
Heap* createMinHeap(int heapSize);
void insertToMinHeap(Heap* minHeap, int vertex, int distance);
Node deleteMin(Heap* minHeap);
FILE* fi;
FILE* fo;

int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
	fo = fopen(argv[2],"wt");
	int num;
	fscanf(fi,"%d",&num);
	Graph* G;
	G = CreateGraph(num);
	while(1){
		char edge[10];
		fscanf(fi,"%s",edge);
		if(feof(fi)) break;
		int a = edge[0]-'0';
                int b = edge[2]-'0';
                int c = edge[4]-'0';
		insertEdge(G, a, b, c);
	}
/*
	char str2[1000];
	fgets(str2,1000,fi);
	char* edge = strtok(str2," ");
	int a,b,c;
	
	while(edge != NULL){
		a = edge[0]-'0';
		b = edge[2]-'0';
		c = edge[4]-'0';
		insertEdge(G,a,b,c);
		edge = strtok(NULL," ");
	}
*/

	Dijkstra(G);
	printShortestPath(G);
	fclose(fi);
	fclose(fo);


}

Graph* CreateGraph(int size){
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->size = size;
	G->vertices = malloc(sizeof(int*)*size);
	for(int i=0; i<size;i++){
		G->vertices[i] = malloc(sizeof(int)*size);
	} 
	for(int i=0; i<size;i++){
		for(int j=0; j<size;j++)
			G->vertices[i][j] = 0;
	}
	G->nodes = (Node*)malloc(sizeof(Node)*size);
	for(int i=0; i<size;i++){
		G->nodes[i].vertex = i+1;
		if(i==0) G->nodes[i].dist = 0;
		else G->nodes[i].dist = INF;
		G->nodes[i].prev = 0;
	}
	return G;
}
void insertEdge(Graph* G, int s, int e, int c){
	int i=0,j=0;
	while(G->nodes[i].vertex!=s)
		i++;
	while(G->nodes[j].vertex!=e)
		j++;
	G->vertices[i][j] = c;
}
void Dijkstra(Graph* G){
	Node SP[10];
	Heap* H = createMinHeap(G->size*G->size);
	for(int i=0;i<G->size;i++){
		if(G->vertices[0][i] != 0){
			G->nodes[i].dist = G->vertices[0][i];
			G->nodes[i].prev = 1;
		}
	}
	for(int i=1;i<G->size;i++)
		insertToMinHeap(H, i+1, G->nodes[i].dist);
	int cnt=0;
	while(H->Size != 0){
		Node u = deleteMin(H);
		SP[cnt++] = u;
		int k = u.vertex - 1;
		for(int i=0;i<G->size;i++){
			if(G->vertices[k][i] != 0){
				if(u.dist + G->vertices[k][i] < G->nodes[i].dist){
					G->nodes[i].dist = u.dist + G->vertices[k][i];
					G->nodes[i].prev = k+1;
					insertToMinHeap(H, i+1, G->nodes[i].dist);
				}
			}
		}
	}

}  
		
		
void printShortestPath(Graph* g){
	for(int i=1;i<g->size;i++){
		if(g->nodes[i].dist == INF)
			fprintf(fo,"Cannot reach to node %d.\n",i+1);
	
		else{
			int route[100];
			int cnt = 0;
			Node temp = g->nodes[i];
			while(1){
				route[cnt] = temp.prev;
				temp = g->nodes[route[cnt]-1];
				if(route[cnt] == 1) break;
				cnt++;
			}
	
			for(int j=cnt;j>=0; j--)
				fprintf(fo,"%d->",route[j]);
			fprintf(fo,"%d (cost: %d)\n",i+1,g->nodes[i].dist);
		}
		
	}
}
			
				
Heap* createMinHeap(int heapSize){
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->Capacity = heapSize;
	heap->Size = 0;
	heap->Element = (Node*)malloc(sizeof(Node)*(heapSize+1));
	return heap;
}
void insertToMinHeap(Heap* minHeap, int vertex, int distance){
	minHeap->Size++;
	minHeap->Element[minHeap->Size].vertex = vertex;
	minHeap->Element[minHeap->Size].dist = distance;
	int child = minHeap->Size;
	int parent = child/2;
	while(child>1 && minHeap->Element[parent].vertex>=minHeap->Element[child].vertex){
		/*Node temp = minHeap->Element[child];
		minHeap->Element[child] = minHeap->Element[parent];
		minHeap->Element[parent] = temp;
		*/
		int temp = minHeap->Element[child].vertex;
		minHeap->Element[child].vertex = minHeap->Element[parent].vertex;
                minHeap->Element[parent].vertex = temp;
		temp = minHeap->Element[child].dist;
                minHeap->Element[child].dist = minHeap->Element[parent].dist;
                minHeap->Element[parent].dist = temp;
		temp = minHeap->Element[child].prev;
                minHeap->Element[child].prev = minHeap->Element[parent].prev;
                minHeap->Element[parent].prev = temp;

		child = parent;
		parent = child/2;
	}
}
Node deleteMin(Heap* minHeap){
	Node deleted_min = minHeap->Element[1];
	minHeap->Element[1] = minHeap->Element[minHeap->Size];
	minHeap->Size--;
	int parent = 1;
	int child = 2;
	// error caution line
	if(child+1 <= minHeap->Size)
		child = (minHeap->Element[child].vertex>minHeap->Element[child+1].vertex)? child : child+1;		
	while(child <=minHeap->Size && minHeap->Element[parent].vertex>=minHeap->Element[child].vertex){
		int temp = minHeap->Element[child].vertex;
                minHeap->Element[child].vertex = minHeap->Element[parent].vertex;
                minHeap->Element[parent].vertex = temp;
                temp = minHeap->Element[child].dist;
                minHeap->Element[child].dist = minHeap->Element[parent].dist;
                minHeap->Element[parent].dist = temp;
                temp = minHeap->Element[child].prev;
                minHeap->Element[child].prev = minHeap->Element[parent].prev;
                minHeap->Element[parent].prev = temp;

		parent = child;
		child = child*2;
		if(child+1 <= minHeap->Size)
			child = (minHeap->Element[child].vertex>minHeap->Element[child+1].vertex)? child : child+1;
	}
	return deleted_min;
}
