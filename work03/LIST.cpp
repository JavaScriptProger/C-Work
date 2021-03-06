#include <iostream>
#include <new>
using namespace std;

class List
{
private:
	class Element
	{
	public:
		int value;
		Element* next;
		Element* prev;
		Element(int value)
		{
			this->value=value;
			next=NULL;
			prev=NULL;
		}
	};
	Element* first;
	int count;
public:
	List()
	{
		first=NULL;
		count=0;
	}
	void Add(int value)
	{
		if(count==0)
		{
			first=new Element(value);
			count++;
			return;
		}
		if(first->value>value)
		{
			Element* tmp=new Element(value);
			count++;
			tmp->next=first;
			first=tmp;
			return;
		}
		Element* tmp;
		Element*  current=first;
		while(true)
		{   
			if(current->next==NULL) break;
			if((current->value<value)&&((current->next)->value>=value))
			{
				tmp=new Element(value);
				tmp->next=current->next;
				(current->next)->prev=tmp;
				current->next=tmp;
				tmp->prev=current;
				count++;
				return;
			}
			current=current->next;
		}
		tmp=new Element(value);
		current->next=tmp;
		tmp->prev=current;
		count++;
		return;
	}
	void Print()
	{
		if(count==0)
		{
			cout<<"empty"<<endl;
			return;
		}
		Element*  current=first;
		while(current!=NULL)
		{
			cout<<current->value<<" ";
			current=current->next;
		}
	}
	bool Find(int value)
	{		
		Element*  current=first;
		while(current!=NULL)
		{
			if(current->value==value) return true;
			current=current->next;
		}
		return false;
	}
	void Del(int value)
	{
		Element*  current=first;
		while(current!=NULL)
		{
			if(current->value==value)
			{
				(current->prev)->next=current->next;
				(current->next)->prev=current->prev;
				count--;
				delete current;
				return;
			}
			current=current->next;
		}
	}
	int operator [](int n)
	{
		if(n>(count-1)) throw -1;
		int k=0;
		Element*  current=first;
		while(k!=n)
		{
			k++;
			current=current->next;
		}
		return current->value;
	}
};

int main()
{
	List x;
	x.Print();
	x.Add(3);
	x.Add(1);
	x.Add(5);
	x.Add(4);
	x.Print();
	cout<<endl;
	cout<<x.Find(4)<<endl;
	cout<<x.Find(44)<<endl;
	x.Del(4);
	x.Print();
	cout<<endl;
	try
	{
	cout<<x[0]<<endl;
	cout<<x[1]<<endl;
	cout<<x[2]<<endl;
	cout<<x[3]<<endl;
	}
	catch(...)
	{
		cout<<"error"<<endl;
	}
	return 0;
}
