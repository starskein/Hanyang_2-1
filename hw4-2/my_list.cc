#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
string* split(const string& str, const string& delim){
	string* string_list = new string[10];
	
	int idx = 0;
	char* token = strtok(const_cast<char*>(str.c_str()),delim.c_str());
	while(token != NULL){
		string_list[idx] = token;
		token = strtok(NULL,delim.c_str());
		++idx;
	}
	return string_list;
}

struct item{
	string data;
	struct item *next;
	
};

struct item* create_item(){
	struct item* new_item = new struct item;
	return new_item;
};
void insert_item(struct item* prev_item,struct item* item){
	item->next = prev_item->next;
	prev_item->next = item;
}
int main(void){
	ifstream fin;
	fin.open("input.txt");
	while(!fin.eof()){
		string line;
		getline(fin,line);
		line.append("/n");
		string* list = split(line,":");
		struct item sample;
		string s;
		s.clear();
		struct item* item_list[10] = {&sample,};
		sample.data = s;
		int i = 0;
		while(1){	
			if ((*(list+1)).find("\n") != string::npos)
				item_list[i]->data = *(list+i);
                                insert_item(item_list[i-1],item_list[i]);
				break;
			if(i==0){			
				item_list[i]->next = NULL;
				item_list[i]->data = *(list+i);
			}
			else{
				item_list[i]->data = *(list+i);
				insert_item(item_list[i-1],item_list[i]);
			}
			i++;
		}
		if(item_list[2]->data.find("2013") != string::npos){
			cout << item_list[0]->data;
			cout << "(" << item_list[1]->data << ") :";
			cout << item_list[2]->data;
			delete item_list[0];
			delete item_list[1];
			for (int j=3;j<=i;j++){
				cout << "&" << item_list[j]->data;
				delete item_list[j];
			}
			cout << endl;	
				
		}
		delete[] list;
	}
	fin.close();
	return 0;
}
				
