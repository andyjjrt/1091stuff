#include <stdio.h>

int main(){
	char a[100] = {0};
	char tmp[100];
	while(scanf("%s", tmp) != EOF){
		for(int i = 0; tmp[i] != '\0'; i++){
			a[i] ^= tmp[i];
		}
	}
	/*
	for(int i = 0; a[i] != 0; i++){
		printf("%c",a[i]);
	}
	printf("\n");
	*/
	printf("%s\n",a);
  	return 0;
}
