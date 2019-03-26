#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

int matrix[4][4] = {
	{ 1, 1, 0, 0},
	{ 1, 1, 0, 0},
	{ 0, 0, 0, 0},
	{ 0, 0, 0, 0}
};

int main(){
	for(int i = 0;i < 4;i++){
		int row = i;
		int finalSum = 0;
		int v = 0;

		for(int j = 0;j < 4;j++){
			finalSum = 0;

			if(row == 0){
				for(int k = 0;k < j+1;k++){
					finalSum += matrix[row][k];
				}

				if(matrix[row][j] == 0){
					matrix[row][j] = finalSum;
				} 
			} else {
				for(int k = 0;k < row;k++){
					for(int z = 0; z < j+1;z++){
						finalSum += matrix[k][z];
					}
				}

				for(int k = 0;k < j+1;k++){
					finalSum += matrix[row][k];
				}

				if(matrix[row][j] == 0){
					matrix[row][j] = finalSum;
				} 
			}
		}

		//cout << endl;
	}

	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	system("pause");
	return 0;
}
