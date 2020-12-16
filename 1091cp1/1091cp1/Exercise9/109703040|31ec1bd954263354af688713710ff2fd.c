#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main() {
	char *dict;
	dict = malloc(1000000000 * 100 * sizeof(char));
	long long count = 0;
	char tmp[100];
	while(scanf("%s",tmp) != EOF){
		long long letter_ptr = 0;
		for(long long i = 0;; i++){
			if(isalpha(tmp[i]) != 1){
				for(long long j = letter_ptr; j < i; j++){
					long long index = count * 100 + j-letter_ptr;
					dict[index] = tolower(tmp[j]);
				}
				long long index = count * 100 + i;
				dict[index] = '\0';
				if(strcmp(dict[count],"") != 0){
					count++;
				}
				letter_ptr = i+1;
				if(tmp[i] == '\0')
					break;
			}
		}
	}
	for(long long i = 0; i < count-1; i++){
		for(long long j = i+1; j < count; j++){
			if(strcmp(dict[i],dict[j]) > 0){
				char tmp2[100];
				strcpy(tmp2,dict[i]);
				strcpy(dict[i],dict[j]);
				strcpy(dict[j],tmp2);
			}
		}
	}
	/*
	for(int i = 0; i < count; i ++){
		printf("%s\n",dict[i]);
	}
	*/
	char tmp3[100];
	strcpy(tmp3,dict[0]);
	long long every_counter = 0;
	for(long long i = 0 ;i < count; i++){
		if(strcmp(tmp3,dict[i]) == 0){
			every_counter++;
		}else{
			printf("%s %lld\n",tmp3,every_counter);
			every_counter = 1;
			strcpy(tmp3,dict[i]);
		}
	}
	printf("%s %lld\n",tmp3,every_counter);
}
