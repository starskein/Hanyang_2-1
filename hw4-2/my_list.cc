#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

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
	string name;
	int age;
	int id;
	string* subjects = new string[10];
	struct item *next;
	
};

struct item* create_item(){
	struct item* node = new item;
	return node;
};
void insert_item(struct item* prev_item,struct item* item){
	prev_item->next = item;
	item -> next = NULL;
	return;
}
int main(void){
	struct item* node = new item[100];
	int i = 0;
	ifstream fin;
	fin.open("input.txt");
	string line;
	string* sline = new string[10];
	while(!fin.eof()){
		i++;
		getline(fin,line);
		sline = split(line,":");
		node[i].name = sline[0];
		node[i].age = atoi(sline[1].c_str());
		node[i].id = atoi(sline[2].c_str());
		node[i].subjects = split(sline[3],",");
		insert_item(&node[i-1],&node[i]);
	}
	struct item* curr = node[0].next;
	while(curr->next != NULL){
		if(curr->id/10000 == 2013){
			cout<< curr->name << "(" << curr->id << ")" << curr->subjects[0];
			for(int i = 1;curr->subjects[i] != "";i++){
				cout << "&" << curr->subjects[i];
			}
			cout << endl;
		}
		curr = curr->next;
	}
	delete[] node-> subjects;
	delete[] node;
	fin.close();
	return 0;
}
			
