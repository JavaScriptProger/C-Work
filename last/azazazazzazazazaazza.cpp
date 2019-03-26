#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void recursion(int count = 0, int last = -1) {
    int n;
	cin>>n;

	if(n == 1) count++;
    
	if(n == 0 && last == 0){
		cout << "Count of 1 is " << count << endl;
		return;
	}

	last = n;

	recursion(count, last);
}

int main() {
    recursion();

	system("pause");
	return 0;
}
