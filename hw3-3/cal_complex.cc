#include <stdio.h>

typedef struct{
	double real;
	double imag;
}Complex;

void printComplex(Complex a){
	printf("%lf + %lfi\n",a.real,a.imag);
	return;
}
void printAddComp(Complex a, Complex b){
	printf("%lf + %lfi\n",a.real+b.real,a.imag+b.imag);
	return;
}
void printMulComp(Complex a, Complex b){
	printf("%lf + %lfi\n",a.real*b.real-a.imag*b.imag,a.real*b.imag+a.imag*b.real);
	return;
}

int main(void){
	Complex a,b;
	scanf("%lf %lf %lf %lf",&a.real,&a.imag,&b.real,&b.imag);
	printf("Complex 1:\n");
	printComplex(a);
	printf("Complex 2:\n");
	printComplex(b);
	printf("Sum of two complex:\n");
	printAddComp(a,b);
	printf("Mul of two complex:\n");
	printMulComp(a,b);
	return 0;
}

