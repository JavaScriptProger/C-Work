#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct S
{
	char s;
	int count;
};


int main ()
{
	S m[30];
	ifstream fin("Z:\in.txt", std::ios::in);
	int count = -1;

	while (!fin.eof()){
		char ch = fin.get();
		int flag = 0;
		for(int i=0; i<=count;i++)
		{
			if(ch == m[i].s)
			{
				m[i].count++;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			count++;
			m[count].s = ch;
			m[count].count = 1;
		}
	}
	for(int i=0; i<=count; i++)
		cout << m[i].s << " " << m[i].count << endl;

	for(int i = 0;i < 15;i++){
		int num = m[i].count;
		int pos = i;

		for(int j = 0;j < 15;j++){
			if(num > m[j].count){
				int pos1 = j;
				int v1 = m[j].count;

				m[j].count = num;
				m[pos].count = v1;

				break;
			}
		}
	}
	
	cout << endl;

	for(int i=0; i<=count; i++)
		cout << m[i].s << ":" << m[i].count << endl;

	system("pause");

	return 0;
}
