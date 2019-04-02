#include <iostream>
#include <algorithm>    
#include <stdlib.h>
#include <string>
using namespace std;
	
#define COL 2
#define ROW 2

int arr[COL][ROW];

int main() 
{ 
	for(int i = 0;i < COL;i++){
		for(int j = 0;j < ROW;j++){

		}
	}

	cout << "================" << endl;

	for(int i = 0;i < COL;i++){
		for(int j = 0;j < ROW;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}

	cout << "- - - - - - -" << endl;

	for(int i = 0;i < COL;i++){
		for(int j = 0;j < ROW;j++){
			if(arr[i][j] == 1) arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	for(int i = 0;i < COL;i++){
		for(int j = 0;j < ROW;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}