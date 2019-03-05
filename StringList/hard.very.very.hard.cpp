#include <iostream>
#include "fstream"
using namespace std;

struct S
{
	char b;
	int k;
	S* R;
	S* L;
	int flag;
};

void ferststep(S *m, int &count)
{
	S* L=new S();
	L->b=m[0].b;
	L->flag=m[0].flag;
	L->L=m[0].L;
	L->R=m[0].R;

	S* R=new S();

}

int main ()
{
	S m[30];
	ifstream fin("Z:\in.txt", std::ios::in);
	int count=-1;
	while (!fin.eof()) {
		 char ch = fin.get();
		 int flag=0;
		 for(int i=0; i<=count;i++)
		 {
			 if(ch==m[i].b)
			 {
				 m[i].k++;
				 flag=1;
				 break;
			 }
		 }
		 if(flag==0)
		 {
			 count++;
			 m[count].b=ch;
			 m[count].k=1;
		 }
	}
	count--;
	for(int i=0; i<=count; i++)
	{
		cout<<m[i].b<<" "<<m[i].k<<endl;
		m[i].flag=1;
		m[i].L=NULL;
		m[i].R=NULL;
	}
	cout<<"-------------"<<endl;

	for(int i = 0;i < 15;i++){
		int num = m[i].k;
		int pos = i;

		for(int j = 0;j < 15;j++){
			if(num > m[j].k){
				int pos1 = j;
				int v1 = m[j].k;

				m[j].k = num;
				m[pos].k = v1;

				break;
			}
		}
	}

	for(int i=0; i<=count; i++){
		cout<<m[i].b<<" "<<m[i].k<<endl;
	}

	system("pause");

	return 0;
}
