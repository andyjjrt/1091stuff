#include <stdio.h>
#include <string.h>

int main() {
	char str[100010];
	scanf("%s", str);
	int str_len = strlen(str);
	int change_status = 1;
	while(change_status != 0){
		change_status = 0;
		char str_tr[100010];
		for(int i = 0; i < str_len; i++){
			if(str[i] == '.'){
				if(i == 0 && str[i+1] == 'L'){
					str_tr[i] = 'L';
					change_status++;
				}else if(i == str_len-1 && str[i-1] == 'R'){
					str_tr[i] = 'R';
					change_status++;
				}else if(str[i-1] == 'R' && str[i+1] != 'L'){
					str_tr[i] = 'R';
					change_status++;
				}else if(str[i-1] != 'R' && str[i+1] == 'L'){
					str_tr[i] = 'L';
					change_status++;
				}else{
					str_tr[i] = '.';
				}
			}else{
				str_tr[i] = str[i];
			}
		}
		str_tr[str_len] = '\0';
		memcpy(str, str_tr, sizeof(str));
	}
	printf("%s\n", str);
  	return 0;
}