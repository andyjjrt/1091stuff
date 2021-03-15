#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char dict[1000000][100];
	int count = 0;
	char tmp;
	char tmp3[100];
	int tmp3_count = 0;
	int dict_count[1000000] = {0};
	while(scanf("%c",&tmp) != EOF){
		if(isalpha(tmp)){
			tmp3[tmp3_count] = tolower(tmp);
			tmp3_count++;
		}else{
			tmp3[tmp3_count] = '\0';
			tmp3_count = 0;

			int name_index = -1;
			for(int i = 0; i < count; i ++){
				if(strcmp(dict[i],tmp3) == 0){
					name_index = i;
				}
			}
			if(name_index == -1){
				strcpy(dict[count],tmp3);
				name_index = count;
				count++;
			}
			dict_count[name_index] ++;
		}
	}
	for(int i = 0; i < count-1; i++){
		for(int j = i+1; j < count; j++){
			if(strcmp(dict[i],dict[j]) > 0){
				char tmp2[1000];
				strcpy(tmp2,dict[i]);
				strcpy(dict[i],dict[j]);
				strcpy(dict[j],tmp2);
				int tmp2_count;
				tmp2_count = dict_count[i];
				dict_count[i] = dict_count[j];
				dict_count[j] = tmp2_count;
			}
		}
	}
	for(int i = 0 ;i < count; i++){
		if(strcmp(dict[i],"")!=0){
			printf("%s %d\n",dict[i],dict_count[i]);
		}
	}
}
