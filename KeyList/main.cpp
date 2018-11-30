#include <iostream>
#include <string>
using namespace std;

class Element {
public:
	string value;
	int key;
	
	Element(string v,int k){
		value = v;
		key = k;
	};
};

class KeyList {
public:
	Element *elements[10];
	
	
	void insert(string v, int k){
		elements[index] = new Element(v,k);
		index++;
	};
	
	void del(int k){
		elements[k] = new Element(0,k);
	};
	
	string find(int k){
		for(int i=0;i<10;i++){
			if(elements[i]->key == k){
				return elements[i]->value;
			}
		}
	};
private:
	int index = 0;
};

int main(){
	KeyList *kl = new KeyList();
	kl->insert("test", 1);
	kl->insert("tes1t", 22);
	
	cout << kl->find(1) << endl;
	cout << kl->find(22) << endl;
	
	kl->del(22);
	
	cout << kl->find(22) << endl;
	return 0;
}
