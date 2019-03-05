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
	R->b=m[1].b;
	R->flag=m[1].flag;
	R->L=m[1].L;
	R->R=m[1].R;

	int sum=m[0].k+m[1].k;

	for(int i=0;i<=(count-2);i++)
		m[i]=m[i+2];
}

int main ()
{
	S m[30];
 ifstream fin("Z:\in.txt", std::ios::in);
 int count=-1;
while (!fin.eof())
 {
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

for(int i=0;i<count;i++)
	for(int j=0;j<count;j++)
		if(m[j].k>m[j+1].k)
		{
			S tmp;
			tmp=m[j];
			m[j]=m[j+1];
			m[j+1]=tmp;
		}
for(int i=0; i<=count; i++)
	cout<<m[i].b<<" "<<m[i].k<<endl;



}
