#include "draw_shape.h"
#include <iostream>
#include <stdio.h>
#define roottwo 1.412
using namespace std;

Shape::Shape(){}
Shape::Shape(int x,int y,int width,int height,char p_){
	x_=x;
	y_=y;
	w=width;
	h=height;
	p=p_;
}
int Shape::GetPerimeter(){
	return w*h;
}
double Shape::GetArea(){
	return 2*(w+h);
}
void Shape::Draw(int canvas_width, int canvas_height){
	for(int i= -1;i<canvas_height;i++){
		for(int j = -1;j<canvas_width;j++){
			if(i==-1 && j == -1) cout << " ";
			else if(i==-1 && j!= -1) cout << j;
			else if(i!=-1 && j==-1) cout << i;
			else if(i>=x_ && i<x_+w && j>= y_ && j<y_+h) cout << p;
			else cout <<".";
		}
		cout << endl;
	}
	return;
}

Square::Square(int x,int y,int width,char p):Shape(x,y,width,width,p){
};

Rectangle::Rectangle(int x,int y,int width,int height,char p):Shape(x,y,width,height,p){
};

Diamond::Diamond(int x,int y,int width,char p_):Shape(x,y,width,width,p_){
};
double Diamond::GetPerimeter(){
	return 4*w*roottwo;
}
double Diamond::GetArea(){
       	return 2*w*w;
}
void Diamond::Draw(int canvas_width, int canvas_height){
       	for(int i=-1;i<canvas_height;i++){
             	for(int j=-1;j<canvas_width;j++){
                     	if(i==-1 && j== -1) cout << " ";
			else if(i==-1 && j!=-1) cout << j;
			else if(i!=-1 && j==-1) cout << i;
			else if(i+j>=(x_+y_) && i+j <= (x_+y_+w*2) && i-j>=(y_-x_) && i-j<=(y_-x_+w*2)) cout << p;
			else cout << ".";
		}
	cout << "\n";
   	}
	return;
}

