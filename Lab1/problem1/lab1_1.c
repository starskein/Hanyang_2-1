#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *input_file;
	FILE *output_file;

	input_file = fopen("lab1_1_input.txt","r");
	output_file = fopen("lab1_1_output.txt","wt");
	
	int input_num;
	int* num_list;
	int start,end;
	int sum = 0;
	fscanf(input_file, "%d" , &input_num);
	num_list = (int*)malloc(sizeof(int) * input_num);

	for(int i=0;i<input_num;i++){
		fscanf(input_file, "%d" , &(num_list[i]));
	}
	fscanf(input_file, "%d" , &start);
	fscanf(input_file, "%d", &end);
	for(int i=start;i<=end;i++){
		sum += num_list[i];
	}
	fprintf(output_file, "%d", sum);
	fclose(input_file);
	fclose(output_file);
	free(num_list);
	return 0;

}
