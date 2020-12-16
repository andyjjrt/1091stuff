#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct dict {
	char name[100];
	int count;
};

int main() {
	struct dict diction[1000000];
	for(int i = 0; i < 1000000; i++){
		diction[i].count = 0;
	}
	int count = 0;
	char tmp;
	char tmp3[100];
	int tmp3_count = 0;
	while(scanf("%c",&tmp) != EOF){
		if(isalpha(tmp)){
			tmp3[tmp3_count] = tolower(tmp);
			tmp3_count++;
		}else{
			tmp3[tmp3_count] = '\0';
			tmp3_count = 0;

			int name_index = -1;
			for(int i = 0; i < count; i ++){
				if(strcmp(diction[i].name,tmp3) == 0){
					name_index = i;
				}
			}
			if(name_index == -1){
				strcpy(diction[count].name,tmp3);
				name_index = count;
				count++;
			}
			diction[name_index].count ++;
		}
	}
	for(int i = 0; i < count-1; i++){
		for(int j = i+1; j < count; j++){
			if(strcmp(diction[i].name,diction[j].name) > 0){
				char tmp2[1000];
				strcpy(tmp2,diction[i].name);
				strcpy(diction[i].name,diction[j].name);
				strcpy(diction[j].name,tmp2);
				int tmp2_count;
				tmp2_count = diction[i].count;
				diction[i].count = diction[j].count;
				diction[j].count = tmp2_count;
			}
		}
	}
	for(int i = 0 ;i < count; i++){
		if(strcmp(diction[i].name,"")!=0){
			printf("%s %d\n",diction[i].name,diction[i].count);
		}
	}
}
