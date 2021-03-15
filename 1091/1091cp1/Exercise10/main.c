#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct monster Monster;

struct monster {
	int id;
	char name[10];
	int atk;
	int def;
	int hp;
};

int cmp1(const void *a, const void *b){
	Monster A = *(Monster *)a;
	Monster B = *(Monster *)b;
	if(B.atk == A.atk){
		if(B.def == A.def){
			if(strlen(B.name) == strlen(A.name)){
				return strcmp(A.name,B.name);
			}
			return strlen(B.name) - strlen(A.name);
		}
		return B.def - A.def;
	}
	return B.atk - A.atk;
}

int main()
{
	Monster pokemon[500];
	int i = 0;
	while(scanf("%d %s %d %d %d\n", &pokemon[i].id, pokemon[i].name, &pokemon[i].atk, &pokemon[i].def, &pokemon[i].hp) != EOF){
		i++;
	}
	qsort(pokemon,i,sizeof(struct monster),cmp1);
	for(int j = 0; j < i; j++){
		if(pokemon[j].id < 10){
			printf("00%d %-10s %-3d %-3d %d\n", pokemon[j].id, pokemon[j].name, pokemon[j].atk, pokemon[j].def, pokemon[j].hp);
		}else if(pokemon[j].id <= 99 && pokemon[j].id >= 10){
			printf("0%d %-10s %-3d %-3d %d\n", pokemon[j].id, pokemon[j].name, pokemon[j].atk, pokemon[j].def, pokemon[j].hp);
		}else{
			printf("%d %-10s %-3d %-3d %d\n", pokemon[j].id, pokemon[j].name, pokemon[j].atk, pokemon[j].def, pokemon[j].hp);
		}
	}
	return 0;
}
