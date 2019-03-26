#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

void divs(int input, int number = 2){
	if(input == number) return;

	float result = input / number;

	//cout << "result:" << number << endl;

	if ((input % number) == 0){
		cout << "Num:" << number << endl;
	}

	number++;

	divs(input, number);
}

int main(){
	divs(18);
	system("pause");
	return 0;
}
