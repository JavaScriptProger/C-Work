#include<stdio.h>
#include<stdlib.h>

//Variables
int arr[9] = { 1, 2, 3, 1, 2, 1, 1, 1, 1 };
int selected = 0;
int a = 0;
int output[9] = {};

//Functions
int xor (int x, int y)
{
    return x ^ y;
}

//Main
int main(){
	
	for(int i=0;i<9;i++){
		selected = i; // Get selected element
		printf("Selected: %i \n",selected);
		a = 0;
		for(int j=0;j<9;j++){ //Check copies of numkbers
			if(selected == arr[j]){
				a++;
			}
		}
		output[selected] = a;
		printf("Number of copies is  %i\n----------------\n", a);
	}

	int xor_result = 0;

	for(int j=0;j<9;j++){ //Get xor result
		if(j >= 9){
			break;
		}
		xor_result += xor(output[j],output[j + 1]);
	}

	printf("Xor is:%i\n-------\n", xor_result);

	printf("int - %i\n", sizeof(int));
	printf("float - %i\n", sizeof(float));
	printf("double - %i\n", sizeof(double));
	printf("char - %i\n", sizeof(char));
	printf("short - %i\n", sizeof(short));

	char *cool_var[255];

	scanf("%s", &cool_var);
	printf("%s\n", cool_var);

	system("pause");
	return 0;
}
