#include <iostream>
#include <exception>
#include <stdlib.h>
#include <string>
using namespace std;

class Element {
public:
	int key;
	string value;
};

class MagicArray {
private:
	int index;
public:
	MagicArray(){
		index = 0;
	};
	Element elements[10];

	void insert(int key, string value){
		for(int i = 0;i < 10;i++){
			if(elements[i].key == key){
				return;
			}
		}

		elements[index].value = value;
		index++;
	};

	void del(int key){
		for(int i = 0;i < 10;i++){
			if(elements[i].key == key){
				elements[i].value = "";
			}
		}
	};

	string find(int key){
		for(int i = 0;i < 10;i++){
			if(elements[i].key == key){
				cout << elements[i].value << endl;
				return elements[i].value;
			}
		}
		return NULL;
	};
};

int main(){
	MagicArray mg;
	mg.insert(1, "test");
	cout << mg.find(1)<< endl;
	system("pause");
	return 0;
}
