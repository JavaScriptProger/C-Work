#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#define LEN 8
#define TARGET 100

int numbers[LEN] = {2,5,1,5,0,2,5,9};
string str = "";
string strNum[LEN];

int main(){
	for(int i = 0;i < LEN;i++){
		for(int j = 1;j < LEN;j++){
			//cout << numbers[i] << numbers[j] << endl; 
			if(numbers[j] == 5){
				str = "";
				str.append(to_string(numbers[i]));
				str.append(to_string(numbers[j]));
				//cout << str << endl;
				strNum[i].append(str);
				strNum[i].append(" ");
			}
		}
	}
	for(int i = 0;i < LEN;i++){
		cout << strNum[i][0];
		cout << strNum[i][1] << endl;
		string v1;
		v1+=strNum[i][0];
		v1+= strNum[i][1];
		cout << "v1:" << v1 << endl;
	}
	system("pause");
	return 0;
}