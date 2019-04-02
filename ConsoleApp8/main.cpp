#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

template <class T>
class Stack {
public:
	int arr[10];
	int index;

	Stack(){
		index = 0;
		fstream f;
		int i;
		f.open("D:\\Users\\astd32\\Documents\\Visual Studio 2012\\Projects\\ConsoleApplication8\\ConsoleApplication8\\test.txt");
		while (!f.eof())
		{
			f>>i;
			arr[index] = i;
			index++;
		}
		f.close();
	};

	void add(int v){
		arr[index] = v;
		index++;
	};

	int get(){
		int i = index;
		index--;
		return arr[i-1];
	};

	friend Stack<void> operator + (Stack const &l, Stack const &r);

	Stack<void> operator = (Stack const &t)
	{
		for(int i = 0;i < 10;i++){
			arr[i] = t.arr[i];
		}
		return *this;
	};
};

Stack<void> operator + (Stack<void> &l, Stack<void> const &r) {
	Stack<void> temp;
	for(int i = 0;i < 10;i++){
		l.add(r.arr[i]);
		temp.arr[i] = l.arr[i];
	}
	return temp;
};

int main(){

	Stack<void> x;
	Stack<void> x2;
	
	cout << x.get() << endl;
	x.add(10);
	cout << x.get() << endl;

	x = x + x2;
	cout << x.get() << endl;

	system("pause");
	return 0;
}
