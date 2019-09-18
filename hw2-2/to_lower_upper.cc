#include <stdio.h>

void change(char* arr,int size){
	for(int i = 0; i<size;i++){
		if(*(arr+i)>95)
			*(arr+i) = *(arr+i)-32;
		else
			*(arr+i) = *(arr+i)+32;
	}
	return;
}

int main(){
	char input_text[10];
	scanf("%s",input_text);
	int size = 0;
	for(int i=0;*(input_text+i)!='\0';i++)
		size++;
	change(input_text,size);
	printf("%s",input_text);
	return 0;
}
