#include <stdio.h>
#include <string.h>
#include <ctype.h>

char table[5][6];
char table2[5][6];
int table3[5][6];

struct team {
	char name[100];
	char attr[100];
	int atk;
	int rec;
	double total;
	double recc;
};

void print_t(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			printf("%c",table[i][j]);
		}
		puts("");
	}
}

void print_1(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			printf("%c",table2[i][j]);
		}
		puts("");
	}
}

void print_2(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			printf("%d",table3[i][j]);
		}
		puts("");
	}
}

void fill(int x, int y, char stone){
	table2[x][y] = '*';
	if(tolower(table2[x][y+1]) == tolower(stone) && y+1 < 6){
		fill(x,y+1,stone);
	}
	if(tolower(table2[x][y-1]) == tolower(stone) && y-1 >=0){
		fill(x,y-1,stone);
	}
	if(tolower(table2[x+1][y]) == tolower(stone) && x+1 < 5){
		fill(x+1,y,stone);
	}
	if(tolower(table2[x-1][y]) == tolower(stone) && x-1 >= 0){
		fill(x-1,y,stone);
	}

}

int main()
{
	char sky[200][6];
	struct team teams[6];
	int input_lines = 0;
	char trash[100];
	char desolve[10000];
	int desolve_count = 0;
	for(int i = 0; i < 6; i++){
		gets(trash);
		scanf("%s %c ", trash,trash);
		gets(teams[i].name);
		scanf("%s %c ", trash,trash);
		gets(teams[i].attr);	
		scanf("%s %c", trash,trash);
		scanf(" %d\n", &teams[i].atk);
		scanf("%s %c ", trash,trash);
		scanf(" %d\n", &teams[i].rec);
		teams[i].total = 0;
		teams[i].recc = 0;
	}
	for(int i = 0; i < 6; i++){
		printf("%s,%s,%d,%d\n", teams[i].name, teams[i].attr, teams[i].atk, teams[i].rec);	
	}
	gets(trash);
	while(1){
		gets(sky[input_lines]);
		if(strcmp(sky[input_lines],"------") == 0){
			break;
		}
		input_lines ++;
	}
	for(int i = 0; i < 5; i++){
		scanf("%s",&table[i][0]);
	}
	int column[6];
	for(int i = 0; i < 6; i++){
		column[i] = input_lines-1;
	}
	print_t(table);
	puts("======");



	while(1){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 6; j++){
				memcpy(table2,table,sizeof(table));
				//print_1();
				//puts("%%%%%%");
				if(isalpha(table[i][j])){
					fill(i,j,table2[i][j]);
				}else{
					continue;
				}
				for(int k = 0; k < 5; k ++){
					for(int l = 0; l < 6; l++){
						table3[k][l] = 0;
					}
				}
				for(int k = 0; k < 5; k++){
					int row_count[4] = {0};
					int row_start[4] = {5};
					int row_tmp = 0;
					for(int l = 0; l < 6; l++){
						if(table2[k][l] == '*'){
							row_count[row_tmp]++;
						}else{
							row_tmp++;
							row_start[row_tmp] = l;
						}
					}
					for(int m = 0; m < row_tmp; m++){
						if(row_count[m] >= 3){
							for(int l = row_start[m]; l < row_start[m+1]; l++){
								if(table2[k][l] == '*'){
									table3[k][l]++;
								}
							}
						}
					}	
				}
				for(int l = 0; l < 6; l++){
					int row_count[4] = {0};
					int row_start[4] = {5};
					int row_tmp = 0;
					for(int k = 0; k < 5; k++){
						if(table2[k][l] == '*'){
							row_count[row_tmp]++;
						}else{
							row_tmp++;
							row_start[row_tmp] = l;
						}
					}
					for(int m = 0; m < row_tmp; m++){
						if(row_count[m] >= 3){
							for(int k = row_start[m]; k < row_start[m+1]; k++){
								if(table2[k][l] == '*'){
									table3[k][l]++;
								}
							}
						}
					}	
				}
				for(int k = 0; k < 5; k++){
					for(int l = 0; l < 6; l++){
						if(table3[k][l] > 0){
							desolve[desolve_count] = table[k][l];
							desolve_count++;
							table[k][l] = '&';
						}
					}
				}
			}
		}
		puts("*not fall*");
		print_t();
		puts("**********");
		desolve[desolve_count] = '\0';
		printf("%s", desolve);
		puts("======");
		int star_status = 0;
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 6; j++){
				if(table[i][j] == '&'){
					star_status = 1;
					break;
				}
			}
		}
		if(star_status == 0){
			printf("All done!\n");
			break;
		}
		// let the & to the top.
		for(int i = 0; i < 6; i++){
			for(int j = 4;j >= 0; j--){
				int j_counter = 1;
				while(table[j][i] == '&' && j_counter < 6){
					for(int k = j; k > 0; k--){
						table[k][i] = table[k-1][i];
					}
					table[0][i] = '&';
					j_counter ++;
				}
			}
			for(int j = 4; j >= 0; j--){
				if(table[j][i] == '&'){
					table[j][i] = sky[column[i]][i];
					column[i]--;
				}
			}
		}

		//start drop the stone
		print_t(table);
		puts("======");
	}
	printf("%d\n%s\n======\n",desolve_count,desolve);
	double attr_sum[6] = {0};
	double odt = 0.333333;
	for(int i = 0; i < desolve_count; i++){
		if(desolve[i] == 'h'){
			attr_sum[5] += odt;
		}else if(desolve[i] == 'H'){
			attr_sum[5] += 0.5;
		}else if(desolve[i] == 'w'){
			attr_sum[0] += odt;
		}else if(desolve[i] == 'W'){
			attr_sum[0] += 0.5;
		}else if(desolve[i] == 'f'){
			attr_sum[1] += odt;
		}else if(desolve[i] == 'F'){
			attr_sum[1] += 0.5;
		}else if(desolve[i] == 'e'){
			attr_sum[2] += odt;
		}else if(desolve[i] == 'E'){
			attr_sum[2] += 0.5;
		}else if(desolve[i] == 'l'){
			attr_sum[3] += odt;
		}else if(desolve[i] == 'L'){
			attr_sum[3] += 0.5;
		}else if(desolve[i] == 'd'){
			attr_sum[4] += odt;
		}else if(desolve[i] == 'D'){
			attr_sum[4] += 0.5;
		}
	}
	for(int i = 0; i < 6; i++){
		if(teams[i].attr[0] == 'W'){
			teams[i].total = teams[i].atk * attr_sum[0];
		}else if(teams[i].attr[0] == 'F'){
			teams[i].total = teams[i].atk * attr_sum[1];
		}else if(teams[i].attr[0] == 'E'){
			teams[i].total = teams[i].atk * attr_sum[2];
		}else if(teams[i].attr[0] == 'L'){
			teams[i].total = teams[i].atk * attr_sum[3];
		}else if(teams[i].attr[0] == 'D'){
			teams[i].total = teams[i].atk * attr_sum[4];
		}
		teams[i].recc = teams[i].rec * attr_sum[5];
		printf("%s %.0lf %.0lf\n",teams[i].name, teams[i].total, teams[i].recc);
	}
	for(int i = 0; i < 6; i++){
		printf("%lf\n", attr_sum[i]);
	}

	return 0;
}
