#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char table[5][6];
int table2[5][6];
char table3[5][6];
char des_array[100000];
int des_count = 0;
struct team {
        char name[100];
        char attr[100];
        int atk;
        int rec;
        double _atk;
        double _rec;
};
void desolve(char character){
        des_array[des_count] = character;
        des_count++;
}
int cmp(const void *a,const void *b){
        struct team A = *(struct team *) a;
        struct team B = *(struct team *) b;
        return B._atk - A._atk;
}
int main(){
        char fall[1000][6];
        char fall_count = 0;
        struct team team[6];
        char trash[100];
        int column[6];
        for(int i = 0; i < 6; i++){
                gets(trash);
                scanf("%s %c ",trash,trash);
                gets(team[i].name);
                scanf("%s %c ",trash,trash);
                gets(team[i].attr);
                scanf("%s %c",trash,trash);
                scanf("%d\n",&team[i].atk);
                scanf("%s %c",trash,trash);
                scanf("%d\n",&team[i].rec);
                team[i]._atk = 0;
                team[i]._rec = 0;
        }
        gets(trash);
        while(1){
                gets(fall[fall_count]);
                if(strcmp(fall[fall_count],"------") == 0)
                        break;
                fall_count++;
        }
        for(int i = 0; i < 5; i++)
                scanf("%s",table[i]);
        for(int i = 0; i < 6; i++)
                column[i] = fall_count - 1;
        while(1){
                memset(table2, 0, sizeof(table2));
                for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 6; j++){
                                if(isalpha(table[i][j])){
                                        if(tolower(table[i][j+1])== tolower(table[i][j]) && tolower(table[i][j+2]) == tolower(table[i][j]) && j <= 3){
                                                for(int k = 0; k < 3; k++)
                                                        table2[i][j+k]++;
                                        }
                                        if(tolower(table[i+1][j]) == tolower(table[i][j]) && tolower(table[i+2][j]) == tolower(table[i][j]) && i <= 2){
                                                for(int k = 0; k < 3; k++)
                                                        table2[i+k][j]++;
                                        }
                                }
                        }
                }
                int is_empty = 0;
                for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 6; j++){
                                if(table2[i][j] > 0){
                                        desolve(table[i][j]);
                                        table[i][j] = '.';
                                        is_empty = 1;
                                }
                        }
                }
                if(is_empty == 0)
                        break;
                for(int i = 0; i < 6; i++){
                        for(int j = 4; j >= 0; j--){
                                int j_counter = 1;
                                while(table[j][i] == '.' && j_counter < 6){
                                        for(int k = j; k > 0; k--)
                                                table[k][i] = table[k-1][i];
                                        table[0][i] = '.';
                                        j_counter++;
                                }
                        }
                        for(int j = 4; j >= 0; j--){
                                if(table[j][i] == '.'){
                                        table[j][i] = fall[column[i]][i];
                                        column[i]--;
                                }
                        }
                }
        }
        double attr_sum[6] = {0};
        for(int i = 0; i < des_count; i++){
                if(des_array[i] == 'h'){
                        attr_sum[5] += 1;
                }else if(des_array[i] == 'H'){
                        attr_sum[5] += 1.5;
                }else if(des_array[i] == 'w'){
                        attr_sum[0] += 1;
                }else if(des_array[i] == 'W'){
                        attr_sum[0] += 1.5;
                }else if(des_array[i] == 'f'){
                        attr_sum[1] += 1;
                }else if(des_array[i] == 'F'){
                        attr_sum[1] += 1.5;
                }else if(des_array[i] == 'e'){
                        attr_sum[2] += 1;
                }else if(des_array[i] == 'E'){
                        attr_sum[2] += 1.5;
                }else if(des_array[i] == 'l'){
                        attr_sum[3] += 1;
                }else if(des_array[i] == 'L'){
                        attr_sum[3] += 1.5;
                }else if(des_array[i] == 'd'){
                        attr_sum[4] += 1;
                }else if(des_array[i] == 'D'){
                        attr_sum[4] += 1.5;
                }
        }
        for(int i = 0; i < 6; i++){
                if(team[i].attr[0] == 'W'){
                        team[i]._atk = team[i].atk * attr_sum[0];
                }else if(team[i].attr[0] == 'F'){
                        team[i]._atk = team[i].atk * attr_sum[1];
                }else if(team[i].attr[0] == 'E'){
                        team[i]._atk = team[i].atk * attr_sum[2];
                }else if(team[i].attr[0] == 'L'){
                        team[i]._atk = team[i].atk * attr_sum[3];
                }else if(team[i].attr[0] == 'D'){
                        team[i]._atk = team[i].atk * attr_sum[4];
                }
        }
        qsort(team,6,sizeof(struct team),cmp);
        puts("-------------------------------------------");
        for(int i = 0; i < 6; i++){
                team[i]._rec = team[i].rec * attr_sum[5];
                printf("| %-40s|\n| Damage : %-10.0lf| Recovery : %-8.0lf|\n",team[i].name, team[i]._atk/3.0, team[i]._rec/3.0);
                puts("-------------------------------------------");
        }

}
