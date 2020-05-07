#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _DisjointSet{
	int size_maze;
	int* ptr_arr;
}DisjointSets;

void init(DisjointSets* sets,DisjointSets* maze_print,int num);
void Union(DisjointSets* sets,int i, int j);
int find(DisjointSets* sets, int i);
void createMaze(DisjointSets* sets,DisjointSets* maze_print,int num);
void printMaze(DisjointSets* sets, int num);
void freeMaze(DisjointSets* sets,DisjointSets* maze_print);

FILE* fi;
FILE* fo;

int main(int args, char* argv[]){
	fi = fopen(argv[1],"r");
	fo = fopen(argv[2],"wt");
	DisjointSets* sets=(DisjointSets*)malloc(sizeof(DisjointSets));
	DisjointSets* maze_print=(DisjointSets*)malloc(sizeof(DisjointSets));
	int num;
	fscanf(fi,"%d", &num);
	init(sets,maze_print,num);
	srand((unsigned int)time(NULL));
	//printf("%d %d \n",find(sets,1),find(sets,num*num));
	createMaze(sets,maze_print,num);
	printMaze(sets,num);
	//for(int i=1;i<=num*num;i++) printf("%d = %d\n",i,sets->ptr_arr[i]);
//	printf("%d\n",find(sets,num*num));
	//freeMaze(sets,maze_print);
	fclose(fi);
	fclose(fo);
}
void init(DisjointSets* sets,DisjointSets* maze_print,int num){
	sets->size_maze = num*num+1;
	sets->ptr_arr = (int*)malloc(sizeof(int)*(sets->size_maze));
	for(int k=0;k<num*num+1;k++)
		sets->ptr_arr[k] = k;
	maze_print->size_maze = 2*num*(num-1)+1;
	maze_print->ptr_arr = (int*)malloc(sizeof(int)*(maze_print->size_maze));
	for(int k=0;k<2*num*(num-1)+1;k++)
		maze_print->ptr_arr[k] = -1;
}
void Union(DisjointSets* sets, int i, int j){
	//printf("Union of %d %d\n",i,j);
	
	if(sets->ptr_arr[j] == sets->ptr_arr[i])
		sets->ptr_arr[i]--;
	sets->ptr_arr[j] = i;
}
int find(DisjointSets* sets,int i){
	if(sets->ptr_arr[i] == i)
		return i;
	else
		return find(sets,sets->ptr_arr[i]);
}
void createMaze(DisjointSets* sets, DisjointSets* maze_print,int num){
	while(find(sets,num*num) != find(sets,1)){
		int k = (rand()%(2*num*(num-1)))+1;
		int line = 0;
		//printf("%d\n",k);
		if(maze_print->ptr_arr[k] == 0) continue;
		maze_print->ptr_arr[k] = 0;
		//printf("ok\n");
		while(1){
			if(k>num-1){
				k = k -(num-1);
				line++;
			}
			if(k<=num) break;
			if(k>num){
				k = k - num;
				line++;
			}
			if(k<=num-1) break;
		}
		//printf("%d %d\n",k,line);
		if(line%2==0)
			Union(sets,((line/2)*num)+k,((line/2)*num)+k+1);
		else
			Union(sets,((line/2)*num)+k,((line/2)*num)+k+num);
	}
}
void printMaze(DisjointSets* sets,int num){
	for(int i=0;i<2*num+1;i++){
		for(int j=0;j<2*num+1;j++){
			if(i==1 && j==0) fprintf(fo," ");
			else if(i==2*num-1 && j==2*num) fprintf(fo," ");
			else if(i%2==0 && j%2==0) fprintf(fo,"+");
			else if(i%2==1 && j%2==1) fprintf(fo," ");
			else if(i==0 || i==2*num || j==0 || j==2*num){
				if(i%2==0) fprintf(fo,"-");
				else fprintf(fo,"|");
			}
			else if(i%2==1){
				if((sets->ptr_arr[((i-1)/2*num)+j/2+1])==(((i-1)/2*num)+j/2)) fprintf(fo," ");
				else fprintf(fo,"|");
			}
			else{
				if((sets->ptr_arr[((i-1)/2*num)+j/2+num+1])==(((i-1)/2*num)+j/2+1)) fprintf(fo," ");
				else fprintf(fo,"-");
			}
		}
		fprintf(fo,"\n");
	}
}
void freeMaze(DisjointSets* sets, DisjointSets* maze_print){
	free(sets->ptr_arr);
	free(maze_print->ptr_arr);
	free(sets);
	free(maze_print);
}
				
