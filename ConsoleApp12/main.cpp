#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class pizza
{
private:
	string name;
	int size;
	pizza(string name, int size)
	{
		this->name=name;
		this->size=size;
	};
public:
	class builder
	{
	private:
		string name;
		int size;
	public:
		builder(string name)
		{
			this->name=name;
			if(name=="Margherita") size=30; else size=25;
		}
		void setname(string name)
		{
			this->name=name;
			if(name=="Margherita") size=30; else size=25;
		}
		pizza build()
		{
			return pizza(name,size);
		}
	};
	void show()
	{
		cout<<"Name->"<<name<<" size->"<<size<<endl;
	}
};

class pizzaset
{
private:
	pizza *m;
	int count;
	pizzaset(pizza *m, int count)
	{
		this->count=count;
		m=(pizza*)malloc(count*sizeof(pizza));
		for(int i=0;i<=count;i++)
			this->m[i]=m[i];
	}
public:
class builder
{
private:
	pizza *m;
	int count;
public:
	builder()
	{
		m=(pizza*)malloc(10*sizeof(pizza));
		count=-1;
	};
	void add(pizza tmp)
	{
		count++;
		m[count]=tmp;
	};
	pizzaset build()
	{
		return pizzaset(m,count);
	}
	};
	void show()
	{
		for(int i=0;i<=count;i++)
			m[i].show();
	}
};

int main()
{
	pizzaset::builder setb;
	pizza::builder b("Margherita");
	pizza y=b.build();
	setb.add(y);
	b.setname("Napolitana");
	pizza z=b.build();
	setb.add(z);
	b.setname("Alla marinara");
	pizza x=b.build();
	setb.add(x);
	pizzaset setp=setb.build();
	setp.show();
	system("pause");
	return 0;
}
