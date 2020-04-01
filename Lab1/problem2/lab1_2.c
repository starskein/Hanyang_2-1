#include <stdio.h>
#include <stdlib.h>

int main(){
        FILE *input_file;
        FILE *output_file;

        input_file = fopen("lab1_2_input.txt","r");
        output_file = fopen("lab1_2_output.txt","wt");
	
	int input_num;
	int* num_list;
	
	fscanf(input_file, "%d" , &input_num);
	num_list = (int*)malloc(sizeof(int)*input_num);
	for(int i=0; i<input_num; i++){
		fscanf(input_file, "%d" , &num_list[i]);
	}
	for(int i = 0;i<input_num-1;i++){
		for(int j = i+1; j<input_num; j++){
			if(num_list[i] < num_list[j]){
				int temp = num_list[j];
				num_list[j] = num_list[i];
				num_list[i] = temp;
			}
		}
	}
	for(int i=0; i<input_num;i++){
		fprintf(output_file, "%d " , num_list[i]);
	}
	fclose(input_file);
	fclose(output_file);
	free(num_list);
	return 0;
}
