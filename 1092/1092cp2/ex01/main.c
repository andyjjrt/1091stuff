#include <stdio.h>
#include <string.h>

int main() {
	char strings[1000];
	int num;
	scanf("%s", strings);
	scanf(" %d", &num);
	if(num == 1){
		printf("%s\n", strings);
		return 0;
	}
	int step = 2 * (num - 1);
	for(int i = 0; i < strlen(strings); i += step){
		printf("%c", strings[i]);
	}
	for(int j = 1; j <= num-2; ++j){
		for(int i = 0; i <= strlen(strings); i += step){
			if((i+j) < strlen(strings))
				printf("%c", strings[i+j]);
			if((i+step-j) < strlen(strings))
				printf("%c", strings[i+step-j]);
		}
	}
	for(int i = num-1; i < strlen(strings); i += step){
		printf("%c", strings[i]);
	}
	puts("");
	return 0;
}
