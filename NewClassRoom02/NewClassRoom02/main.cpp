#include <iostream>
#include <stdlib.h>
#include <string>
#include <new>
using namespace std;

//CodeHanning

int getCountOfSymbol(string text, int index){
	int count = 0;
	int len = text.length();

	//cout << len << endl;

	count = 0;
	char symb = text[index];
		
	for(int j = 0;j < len;j++){
		if(symb == text[j]){
			count++;
		}
	}
	
	return count;
}

class HTree
{
public:
	class List
	{
	public:
		char value;
		List* r;
		List* l;
		List(char value)
		{
			this->value=value;
			r=NULL;
			l=NULL;
		}
	};
};

class HList
{
public:
	class Element
	{
	public:
		HTree::List* value;
		int rank;
		Element* next;
		Element* prev;
		Element(char value)
		{
			next=NULL;
			prev=NULL;
			this->value=new HTree::List(value);
		}
	};

	int count;
	Element* root;

	HList()
	{
		root=NULL;
		count=0;
	}

	void HList::Add(char value, int rank)
	{
		if(count==0)
		{
			root = new Element(value);
			count++;
			return;
		}
		if(root->rank > rank)
		{
			Element* tmp=new Element(value);
			count++;
			tmp->next = root;
			root = tmp;
			return;
		}
		Element* tmp;
		Element*  current = root;
		while(true)
		{   
			if(current->next==NULL) break;
			if((current->rank < rank)&&((current->next)->rank >= rank))
			{
				tmp=new Element(value);
				tmp->next = current->next;
				(current->next)->prev = tmp;
				current->next = tmp;
				tmp->prev = current;
				count++;
				return;
			}
			current = current->next;
		}
		tmp = new Element(value);
		current->next = tmp;
		tmp->prev = current;
		count++;
		return;
	}

	void Print()
	{
		if(count == 0)
		{
			cout << "empty" << endl;
			return;
		}
		Element*  current = root;
		while(current != NULL)
		{
			char a = current->value->value;
			std::string str(1, a);
			cout << str << " ";
			current = current->next;
		}
	}
};

int main()
{
	string text = "LOL KEK CHEBUREK";

	HList list;

	list.Add((char) "L", getCountOfSymbol(text, 0));
	list.Add((char) "O", getCountOfSymbol(text, 1));
	list.Add((char) "L", getCountOfSymbol(text, 2));
	list.Add((char) " ", getCountOfSymbol(text, 3));
	list.Add((char) "K", getCountOfSymbol(text, 4));
	list.Print();

	system("pause");
	return 0;
}