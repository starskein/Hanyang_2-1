#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char name[30];
	int id;
}student;

int main(){
        FILE *input_file;
        FILE *output_file;

        input_file = fopen("lab1_3_input.txt","r");
        output_file = fopen("lab1_3_output.txt","wt");
	
	int input_num;
	student* person_list;
	fscanf(input_file, "%d" , &input_num);
	person_list = (student*)malloc(sizeof(student)*input_num);
	for(int i=0;i<input_num;i++){
		fscanf(input_file, "%s %d",person_list[i].name,&(person_list[i].id));
	}
	for(int i=0;i<input_num;i++){
		for(int j=i+1;j<input_num;j++){
			if(person_list[i].id>person_list[j].id){
				student temp = person_list[j];
				person_list[j] = person_list[i];
				person_list[i] = temp;
			}
		}
	}
	for(int i=0;i<input_num;i++){
		fprintf(output_file, "%s %d\n",person_list[i].name,person_list[i].id);
	}
	free(person_list);
	fclose(input_file);
	fclose(output_file);
	return 0;
}
			
