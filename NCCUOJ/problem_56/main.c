#include <stdio.h>
#include <stdlib.h>

struct que{
    int i;
    int j;
    int step;
};
typedef struct que que;

int main(){
    int M;
    char table[1010][1010];
    scanf("%d\n", &M);
    for(int i = 0; i < M; ++i){
        int n,m;
        scanf("%d %d\n", &n, &m);
        for(int j = 0; j < n; ++j){
            scanf("%s", table[j]);
        }
        que *q = malloc(sizeof(que) * 1000100);
        q->i = 0;
        q->j = 0;
        q->step = 0;
        int start = 0, end = 1, step = 0, ans = 0;
        while(end - start > 0){
            int tmp_end = end;
            for(int i = start; i < tmp_end; ++i){
                int index_i = (q+i)->i;
                int index_j = (q+i)->j;
                //printf("(%d,%d) step:%d\n", index_i, index_j, (q+i)->step);
                if(index_i == n-1 && index_j == m-1){
                    ans = step;
                    break;
                }
                if(table[index_i][index_j] == '*'){
                    continue;
                }
                table[index_i][index_j] = '*';
                if(table[index_i+1][index_j] == '.' && index_i+1 < n){
                    (q+end)->i = index_i+1;
                    (q+end)->j = index_j;
                    (q+end)->step = step;
                    //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                    end++;
                }
                if(table[index_i-1][index_j] == '.' && index_i-1 >= 0){
                    (q+end)->i = index_i-1;
                    (q+end)->j = index_j;
                    (q+end)->step = step;
                    //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                    end++;
                }
                if(table[index_i][index_j+1] == '.' && index_j+1 < m){
                    (q+end)->i = index_i;
                    (q+end)->j = index_j+1;
                    (q+end)->step = step;
                    //printf("empty: (%d,%d)\n", (q+end)->i, (q+end)->j);
                    end++;
                }
                if(table[index_i][index_j-1] == '.' && index_j-1 >= 0){
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
            puts("unbelievable");
        }else{
            printf("%d\n", ans);
        }
        free(q);
    }
}