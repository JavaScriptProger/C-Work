#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUM_COUNT 5

#pragma warning(disable : 4996)

char str[NUM_COUNT];
char str2[NUM_COUNT];
const char s[] = "+ -";
const char s2[] = "";

int main(){
	printf("Enter a string:");
	gets(str);

	int num[NUM_COUNT];
	strcpy(str2,str);
	char* tokenNum = strtok(str, s);

	for(int i = 0; i < NUM_COUNT;i++){
		if(tokenNum == NULL) {
			break;
		} else {
			printf("Num:%s\n", tokenNum);
			num[i] = atoi(tokenNum);
			tokenNum = strtok(NULL, s);
		}
	}

	int result = 0;
	char *sym[NUM_COUNT];
	int i = 0;

	for(int i = 0;i < NUM_COUNT;i++){
		sym[i] = (char*)str2[i];

		if(strcmp((char*)sym[i], "+") == 0){
			int a = i;
			a++;
			result += (num[i] + num[a]);
		}

		if(strcmp((char*)sym[i], "-") == 0){
			int a = i;
			a++;
			result += (num[i] - num[a]);
		}

		i++;
	}

	printf("%i\n", result);
	system("pause");
	return 0;
}
