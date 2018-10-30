#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Vector
{
public:
	int get(int i){
		if(i <= 0 && i >= 4) return 1;
		else return mas[i];
	};

	void set(int i, int tmp){
		if(i <= 0 && i >= 4) return;
		if(tmp < 9) mas[i] = abs(tmp);
		else mas[i] = tmp % 10;
	};

	const int *getArr() const {
		return mas;
	}
private:
	int mas[5];
};

class Matrix
{
public:
	const int *getArr() const {
		return *mas;
	}

	Vector* gets(int i){
		Vector *v = new Vector();
		if(i <= 0 && i >= 4) return NULL;
		for(int j = 0;j < 5;j++){
			v->set(j, mas[i][j]);
		}
		return v;
	};

	Vector* getr(int i){
		Vector *v = new Vector();
		if(i <= 0 && i >= 4) return NULL;
		for(int j = 0;j < 5;j++){
			v->set(j,mas[j][i]);
		}
		return v;
	};

	void set(int i, const Vector &v){
		if(i <= 0 && i >= 4) return;
		for(int j = 0;j < 5;j++) mas[i][j] = v.getArr()[j];
	};

	void print(){
		for(int i = 0;i < 5;i++){
			for(int j = 0;j < 5;j++){
				//printf("%i-",mas[j][i]);
				printf("%i-",mas[i][j]);
			}
			printf("\n");
		}
	};
private:
	int mas[5][5];
};

void set(Vector &v){
	for(int i = 0;i < 5;i++) v.set(i,i+1);
};

int main(){
	Vector va,vb,vc,ve,vd;

	set(va);
	set(vb);
	set(vc);
	set(ve);
	set(vd);

	Matrix ma;
	ma.set(0, va);
	ma.set(1, vb);
	ma.set(2, vc);
	ma.set(3, ve);
	ma.set(4, vd);
	ma.print();
	printf("\n");
	Matrix mb;
	for(int i = 0;i < 5;i++) mb.set(i, *(ma.getr(i)));
	/*mb.set(0, *(ma.getr(0)));
	mb.set(1, *(ma.getr(1)));
	mb.set(2, *(ma.getr(2)));
	mb.set(3, *(ma.getr(3)));
	mb.set(4, *(ma.getr(4)));*/
	mb.print();
	system("pause");
	return 0;
}