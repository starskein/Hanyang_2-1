#include <iostream>
#include <string>
#include <vector>
#include "draw_shape.h"

using namespace std;

int main(){
	vector<Shape*> shapes;
	int row, col;
	cin >> row >> col;
	Canvas canvas(row,col);
	canvas.Print();

	while(true){
		string tok;
		cin >> tok;
 		if (tok == "add"){
			string type;
			cin >> type;
			if (type == "rect"){
				int x,y,w,h;
				char p;
				cin >> x >> y >> w >> h >> p;
				Rectangle* r = new Rectangle(w,h,x,y,p);
				shapes.push_back(r);
			}
			else if (type =="tri_up"){
				int x,y,w;
                                char p;
                                cin >> x >> y >> w >> p;
				UpTriangle* u = new UpTriangle(w,x,y,p);
				shapes.push_back(u);

			}
			else if (type == "tri_down"){
				int x,y,w;
                                char p;
                                cin >> x >> y >> w >> p;

				DownTriangle* d = new DownTriangle(w,x,y,p);
				shapes.push_back(d);
			}
			else if (type == "diamond"){
				int x,y,w;
                                char p;
                                cin >> x >> y >> w >> p;

				Diamond* di = new Diamond(w,x,y,p);
				shapes.push_back(di);
			}
			else continue;
		}
	else if (tok == "draw"){
		canvas.Clear();
		for(int i =0; i<shapes.size(); ++i) shapes[i]->Draw(&canvas);
		canvas.Print();
	}
	else if (tok == "delete"){
		int num;
		cin >> num;
		if(num>=0 && num<shapes.size()) shapes.erase(shapes.begin()+num);
	}
	else if (tok == "dump") {
		for(int i =0;i<shapes.size();++i) shapes[i]->PrintInfo();
	}
	else if (tok == "resize"){
		int row,col;
		cin >> row >> col;
		canvas.Resize(row,col);
	}
	else{
		break;
		}
	}
	for (int i=0; i<shapes.size(); ++i) delete shapes[i];
	shapes.clear();
	return 0;
}


		
				
	
