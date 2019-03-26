#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void recursion(int count = 0, int max = 0) {
    int n;
	cin>>n;
    
	if(n > max){ 
		max = n;
		count = 0;
		cout << "new max:" << max << endl;
	}

	if(n == max){
		count++;
	}

	if(n == 0){
		cout << "The count of max number (" << max << ") is " << count << endl;
		return;
	}

	recursion(count, max);
}

int main() {
    recursion(); // вызов рекурсивной 

    system("pause");
    return 0;
}
