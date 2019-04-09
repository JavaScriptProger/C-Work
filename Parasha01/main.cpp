#include <iostream>
#include <stdlib.h>
using namespace std;

#define TARGET 2

void calc(int in){
	int e = in;

	if((e % 2 == 1)){
		cout << "NO" << endl;
		return;
	} else {
		e = e / 2;
		if(e == TARGET){
			cout << "YES" << endl;
			return;
		}
	}

	calc(e);
}

int main(){
	int input = 0;

	cin >> input;

	calc(input);

	system("pause");
	return 0;
}
