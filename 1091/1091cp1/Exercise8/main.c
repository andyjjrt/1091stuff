#include<stdio.h>
int main(void){
	char arr[10000];
	while(scanf("%s",arr) != EOF){
		int status = 0;
		int neg = 1;
		int number = 0;
		int ans = 0;
		for(int i = 0;arr[i] != '\0';i++){
			if(status == 0){
				if(arr[i] >=48 && arr[i] <= 57){
					status = 1;
					number *= 10;
					number += arr[i]-48;
				}else if(arr[i] == 45){
					status = 1;
					neg = -1;
				}
			}else if(status == 1){
				if(arr[i] < 48 || arr[i] > 57){
					status = 0;
					ans += number*neg;
					neg = 1;
					number = 0;
				}else{
					number *= 10;
					number += arr[i]-48;
				}
			}
			//printf("character:%c,number:%d,ans:%d\n",arr[i],number,ans);
		}
		printf("%d\n",ans);
	}
}
