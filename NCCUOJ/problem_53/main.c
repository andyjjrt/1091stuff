#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct que{
    int i;
    int j;
    int step;
};
typedef struct que que;

int main(){
    while(1){
        int N;
        scanf("%d", &N);
        if(N == 0){
            break;
        }
        char table[110][110];
        for(int i = 0; i < N; ++i){
            scanf("%s", table[i]);
        }
        for(int k = 0; k < N; ++k){
            for(int j = 0; table[k][j] != '\0'; ++j){
                if(table[k][j] == 'K'){
                    que *q = malloc(sizeof(que) * 1000100);
                    q->i = k;
                    q->j = j;
                    q->step = 0;
                    int start = 0, end = 1, step = 1, ans = 0;
                    while(end - start > 0){
                        int tmp_end = end;
                        for(int i = start; i < tmp_end; ++i){
                            int index_i = (q+i)->i;
                            int index_j = (q+i)->j;
                            //printf("(%d,%d) step:%d\n", index_i, index_j, (q+i)->step);
                            if(table[index_i][index_j] == '@'){
                                //printf("break in (%d,%d)\n", index_i, index_j);
                                ans = step - 1;
                                break;
                            }
                            if(table[index_i][index_j] == '#'){
                                continue;
                            }
                            table[index_i][index_j] = '#';
                            if((table[index_i+1][index_j] == '.' || table[index_i+1][index_j] == '@')  && index_i+1 < N){
                                (q+end)->i = index_i+1;
                                (q+end)->j = index_j;
                                (q+end)->step = step;
                                //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                                end++;
                            }
                            if((table[index_i-1][index_j] == '.' || table[index_i-1][index_j] == '@')  && index_i-1 >= 0){
                                (q+end)->i = index_i-1;
                                (q+end)->j = index_j;
                                (q+end)->step = step;
                                //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                                end++;
                            }
                            if((table[index_i][index_j+1] == '.' || table[index_i][index_j+1] == '@') && index_j+1 < strlen(table[k])){
                                (q+end)->i = index_i;
                                (q+end)->j = index_j+1;
                                (q+end)->step = step;
                                //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                                end++;
                            }
                            if((table[index_i][index_j-1] == '.' || table[index_i][index_j-1] == '@')  && index_j-1 >= 0){
                                (q+end)->i = index_i;
                                (q+end)->j = index_j-1;
                                (q+end)->step = step;
                                //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                                end++;
                            }
                        }
                        if(ans != 0){
                            break;
                        }
                        start = tmp_end;
                        step++;
                    }
                    if(ans == 0){
                        printf("= =\"\n");
                    }else{
                        printf("%d\n", ans);
                    }
                    free(q);
                }
            }
        }
    }
}