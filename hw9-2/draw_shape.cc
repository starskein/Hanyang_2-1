#include <iostream>
#include <string>
#include "draw_shape.h"
	
using namespace std;

Canvas::Canvas(int row,int col){
	r= row;
	c = col;
	for(int i=0; i<c; i++){
                for(int j=0; j<r; j++){
                arr[i][j] = '.';
                }
        }

}
Canvas::~Canvas(){}

void Canvas::Resize(int w, int h){
	r = w;
	c = h;
}

bool Canvas::DrawPixel(int x,int y,char brush){
	if(x>r || y>c) return false;
	arr[y][x] = brush;
	return true;
}
void Canvas::Print(){
	for(int i= -1;i<c;i++){
                for(int j = -1;j<r;j++){
                        if(i==-1 && j == -1) cout << " ";
                        else if(i==-1 && j!= -1) cout << j%10;
                        else if(i!=-1 && j==-1) cout << i%10;
                        else cout <<arr[i][j];
                }
                cout << endl;
        }
        return;
}
void Canvas::Clear(){
	for(int i=0; i<c; i++){
		for(int j=0; j<r; j++){
		arr[i][j] = '.';
		}
	}
}
Shape::Shape(int w, int h, int x_, int y_, char p){
        width = w;
        height = h;
        x = x_;
        y = y_;
        brush = p;
}

Shape::~Shape(){}
void Shape::Draw(Canvas* canvas){}
Rectangle::Rectangle(int w, int h, int x_, int y_, char p):Shape(w,h,x_,y_,p){
}
void Shape::PrintInfo(){
}
void Rectangle::Draw(Canvas* canvas){
	for(int i=y; i<y+height; i++){
		for(int j = x; j<=x+width; j++){
			canvas->DrawPixel(j,i,brush);
		}
		cout << endl;
	}
}
UpTriangle::UpTriangle(int w, int x_, int y_, char p):Shape(w,w,x_,y_,p){
}
DownTriangle::DownTriangle(int w, int x_, int y_, char p):Shape(w,w,x_,y_,p){
}
Diamond::Diamond(int w, int x_, int y_, char p):Shape(w,w,x_,y_,p){
}
void UpTriangle::Draw(Canvas* canvas){
	for(int i=y;i<y+height; i++){
		for(int j =x-(i-y); j<=x+(i-y); j++){
				canvas->DrawPixel(j,i,brush);
		}
	}
}

void DownTriangle::Draw(Canvas* canvas){
	for(int i=y;i>y-height;i--){
		for(int j=x-(y-i);j<=x+(y-i);j++){
			canvas->DrawPixel(j,i,brush);
		}
	}
}
void Diamond::Draw(Canvas* canvas){
	for(int i=y;i<y+height;i++){
		for(int j=x-(i-y);j<=x+(i-y);j++){
			 canvas->DrawPixel(j,i,brush);
		}
	}
	for(int i=y+height*2;i>=y+height*2-height;i--)
		for(int j =x-(y-height*2-i);j<=x+(y+height*2-i);j++)
			canvas->DrawPixel(j,i,brush);
}
void Rectangle::PrintInfo(){
	cout << "rect " << x << " " << y <<" " << width << " "<< height <<" ";
	cout <<char(brush) << endl;
}
void UpTriangle::PrintInfo(){
	cout << "tri_up " << x << " " << y <<" " << width <<" ";
	cout << char(brush) << endl; 
}
void DownTriangle::PrintInfo(){
	cout << "tri_down " << x << " " << y <<" " << width <<" ";
	cout <<  char(brush) << endl;
}
void Diamond::PrintInfo(){
	cout << "diamond " << x << " " << y <<" " << width << " ";
	cout << char(brush) << endl;
}
