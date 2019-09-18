#include <stdio.h>

void square(double* var);

int main(){
	double dvar;
	double* pdvar=&dvar;
	scanf("%lf",pdvar);
	square(&dvar);
	printf("%lf",dvar);
}

void square(double* var){
	*var =(*var)*(*var);
}
	
	
