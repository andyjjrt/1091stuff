#include <stdio.h>

int main() {
	int array[30];
	int number = 0;
	while(scanf("%d", &array[number]) != EOF){
		number++;
	}
	array[number] = array[number-1];
	number++;

	int checker[2] = {array[0],array[0]};
	for(int i = 1; i < number; ++i){
		int minus = array[i] - checker[1];
		if(minus == 1){
			checker[1] = array[i];
		}else{
			if(checker[0] == checker[1]){
				printf("%d\n", checker[0]);
			}else{
				printf("%d->%d\n", checker[0], checker[1]);
			}
			checker[0] = array[i];
			checker[1] = array[i];
		}
	}
	return 0;
}
