#include <string.h>
#include <stdio.h>

int main()
{
	char tmp[1000000];
	char comma[2] = ",";
	char dictionary[10000][5000];
	int dic = 0;
	char *token;
	scanf("%s",tmp);

	/* get the first token */
	token = strtok(tmp, comma);

	/* walk through other tokens */
	while( token != NULL ) 
	{
		strcpy(dictionary[dic],token);
		dic++;
		token = strtok(NULL,comma);
	}
	for(int i = 0; i < dic; i ++){
		for(int j = i+1; j <dic; j ++){
			if(strcmp(dictionary[i],dictionary[j]) > 0){
				char t[5000];
				strcpy(t, dictionary[i]);
				strcpy(dictionary[i], dictionary[j]);
				strcpy(dictionary[j], t);
			}
		}
	}
	
	int cha[5000],num[5000],ch = 97,nu = 1;
	for(int i = 0; i < dic; i ++){
		//printf("%c",dictionary[i][0]);
		while((int)dictionary[i][0] != ch){
			ch++;
			nu = 1;
		}
		cha[i] = ch-32;
		num[i] = nu;
		//printf("%d %d\n",ch,nu);
		nu++;
	}
	char tmp1[5000];
	while(scanf(" %s",tmp1) != EOF){
		int found = 0;
		for(int i = 0; i < dic; i ++){
			if(strcmp(dictionary[i],tmp1) == 0){
				printf("%c %d\n",cha[i],num[i]);
				found = 1;
				break;
			}
		}
		if(found==0){
			puts("NOT FOUND");
		}
	}

	return(0);
}
