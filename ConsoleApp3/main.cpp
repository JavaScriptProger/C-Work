#include <stdio.h>
#include <math.h>
#include <stdlib.h>

class ArrayController {
public:
	int arr[10];
	int tempArr[10];

	ArrayController(){
		for(int i = 0;i < 10;i++){
			arr[i] = 0;
		}
	};

	void sort(){
		//No my method........
		for(int i = 0; i < 10 - 1; i++){
			int currentMin = arr[i];
			int currentMinIndex = i;

			for(int j = i + 1; j < 10; j++){
				if(currentMin > arr[j]){
					currentMin = arr[j];
					currentMinIndex = j;
				}
			}
           
			if(currentMinIndex != i){
				arr[currentMinIndex] = arr[i];
				arr[i] = currentMin;

			}
		}
	};

	int getMaxValue(){
		int selected = 0;
		int hits = 0;
		for(int i = 0;i < 10;i++){
			selected = arr[i];
			hits = 0;
			for(int j = 0;j < 10;j++){
				if(selected < arr[j]){
					hits++;
				}
			}

			if(hits == 0){
				return selected;
			}
		}
	};

	void printElements(){
		for(int i = 0;i < 10;i++){
			printf("%i\n", arr[i]);
		}
	};

	void sumArrays(ArrayController *array){
		for(int i = 0;i < 10;i++){
			arr[i] += array->arr[i];
		}
	};
	
	int* addOneToEveryElement(){
		for(int i = 0;i < 10;i++){
			tempArr[i] = arr[i];
		}

		for(int i = 0;i < 10;i++){
			tempArr[i]++;
		}
		return tempArr;
	};

	int getMinValue(){
		int selected = 0;
		int hits = 0;
		for(int i = 0;i < 10;i++){
			selected = arr[i];
			hits = 0;
			for(int j = 0;j < 10;j++){
				if(selected > arr[j]){
					hits++;
				}
			}

			if(hits == 0){
				return selected;
			}
		}
	};
};

int main(){
	ArrayController *array = new ArrayController();
	array->arr[0] = 10;
	array->arr[1] = 1333;
	array->arr[2] = 21;
	array->arr[3] = 75;
	array->arr[4] = 67;
	array->arr[5] = 123;
	array->arr[6] = 666;
	array->arr[7] = 321;
	array->arr[8] = 432;
	array->arr[9] = 234;

	ArrayController *array2 = new ArrayController();
	array2->arr[0] = 10;
	array2->arr[1] = 1333;
	array2->arr[2] = 21;
	array2->arr[3] = 75;
	array2->arr[4] = 67;
	array2->arr[5] = 123;
	array2->arr[6] = 666;
	array2->arr[7] = 321;
	array2->arr[8] = 432;
	array2->arr[9] = 234;

	//array->sort();
	array->addOneToEveryElement();
	array->printElements();
	printf("The max number is %i\n", array->getMaxValue());
	printf("The min number is %i\n", array->getMinValue());
	for(int i = 0;i < 10;i++){
		printf("Array++ %i\n", array->addOneToEveryElement()[i]);
	}
	printf("Array no one i\n");
	array->printElements();

	system("pause");
	return 0;
}
