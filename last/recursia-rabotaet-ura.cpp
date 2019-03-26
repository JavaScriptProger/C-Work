#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

void AddToList(int stepCount, int maxNumber,int number){
	if(number == maxNumber + 1) return;

	stepCount++;

	//cout << "Start from:" << number << endl;

	for(int i = 0;i < number;i++){
		cout << number << endl;
	}

	number++;

	AddToList(stepCount, maxNumber, number);
}

int main(){
	int number = 0;
	cout << "Enter number:";
	cin >> number;

	AddToList(0,number, 1);

	system("pause");
	return 0;
}
