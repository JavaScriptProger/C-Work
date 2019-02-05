#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
	Node *next;
	Node *prev;
	int value;
	int index;

	Node(int in){
		this->next = nullptr;
		this->prev = nullptr;
		this->value = in;
		this->index = 0;
	};
};

class List
{
public:
	Node *root;
	int size;

	List(){
		root = nullptr;
		size = 0;
	};

	void Add(int in){
		if(this->root == nullptr){
			this->root = new Node(in);
			size = 1;
		} else {
			if(in > this->root->value){
				Node *temp = root;
				Node *element = root;
				
				while(temp != nullptr) {
					if(temp != nullptr) {			
						element = temp; 
					}

					temp = temp->next;
				}

				cout << "Final:" << element->value << endl;
				this->size++;
				Node *obj = new Node(in);
				obj->index = size;
				obj->prev = element;
				element->next = obj;
			} else {
				size++;
				Node *temp = root;
				Node *obj = new Node(in);
				obj->next = temp;
				obj->index = 0;

				temp->prev = obj;
				root = temp->prev;
			}
		}
	};

	void Delete(int in){
		Node *left, *right;
		Node *temp = root;

		while(temp != nullptr){
			if(in == temp->value){
				break;
			}

			temp = temp->next;
		}

		if(temp == nullptr){
			cout << "Element for deleting doesnt found! Deleting impossible! Exit!" << endl;
			return;
		}

		left = temp->prev;
		right = temp->next;

		left->next = right;
		right->prev = left;
		cout << "Delete:" << temp->value << endl;
		temp = nullptr;
		size--;
	};

	int Search(int in){
		Node *temp = root;

		while(temp != nullptr){
			if(in == temp->value){
				return in;
			}

			temp = temp->next;
		}

		return 0;
	};

	int operator[](int n) {
		if(n>(size-1)) throw -1;
		int k=0;
		Node*  current=root;
		while(k!=n)
		{
			k++;
			current=current->next;
		}
		return current->value;
	}

	void operator = (Node *n){
		this->root = n;
	}

	friend List operator + (const List &l1, const List &l2){
		List newList;

		if(l1->size > l2->size){
			int s = l1->size;
		} else {
			int s = l2->size;
		}

		for(int i = 0;i < s; i++){
			newList[i] = l1[i] + l2[i];
		}

		return newList;
	}
		 
	void Test(){
		Node *temp = root;
		while(temp != nullptr){
			cout << "Value:" << temp->value << endl;
			temp = temp->next;
		}
	}
};


int main(){
	List list;

	cout << "Add:" << endl;
	list.Add(5);
	list.Add(6);
	list.Add(4);
	list.Add(7);
	list.Add(9);
	list.Add(8);
	list.Add(1);

	cout << "\nPrint:" << endl;
	list.Test();

	cout << "\nSearch:" << endl;

	cout << list.Search(81) << endl;
	cout << list.Search(5) << endl;
	cout << list.Search(7) << endl;

	cout << "X:" << list[3] << endl;

	list.Delete(5);
	list.Delete(7);
	list.Delete(777);

	cout << "\nPrint:" << endl;
	list.Test();

	List list2 = list;

	List list3 = list + list2;
	list3.Test();

	system("pause");
	return 0;
}