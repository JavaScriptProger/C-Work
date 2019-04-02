#include <iostream>
#include <stdlib.h>
using namespace std;

int m[10] = {5,2,2,4,5,6,7,7,9};

int main(){
	int count = 0;
	for(int i=0;i<9;i++){
		int e = m[i];
		count = 0;
		for(int j=0;j<9;j++){
			if(e == m[j]){
				count++;
			}
		}
		cout << m[i];
		cout << " ";
		cout << count << endl;
	}
	system("pause");
	return 0;
}	
