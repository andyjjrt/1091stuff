#include <stdio.h>
#include <stdlib.h>
int cmp_int(const void* _a , const void* _b){
    int* a = (int*)_a;
    int* b = (int*)_b;
    return *a - *b;
}

int main(){
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        int N,M,K;
        char sheet[100][1000];
        scanf("%d %d %d\n", &N, &M, &K);
        for(int j = 0; j < N; j++){
            scanf("%s", sheet[j]);
        }
        int score = 0;
        for(int j = 0; j < M; j++){
            int tmp[4] = {0};
            for(int k = 0; k < N; k++){
                if(sheet[k][j] == 'A'){
                    tmp[0]++;
                }else if(sheet[k][j] == 'B'){
                    tmp[1]++;
                }else if(sheet[k][j] == 'C'){
                    tmp[2]++;
                }else if(sheet[k][j] == 'D'){
                    tmp[3]++;
                }
            }
            if(tmp[0] != 0 && tmp[1] != 0 && tmp[2] != 0 && tmp[3] != 0){
                qsort(tmp,4,sizeof(int),cmp_int); 
                score += tmp[0] * K;
            }
        }
        printf("%d\n",score);
    }
}