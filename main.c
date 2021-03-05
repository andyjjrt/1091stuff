#include <stdio.h>
#include <stdlib.h>

void BFS(char table[1000][1000], int* q_i, int* q_j, int start, int end, int n, int m, int step, int* min){
    int index_i = *(q_i+start);
    int index_j = *(q_j+start);
    if(index_i == n-1 && index_j == m-1){
        *min = step+1;
        return;
    }
    if(table[index_i][index_j] == '*'){
        return;
    }
    table[index_i][index_j] = '*';
    if(table[index_i+1][index_j] == '.' && index_i+1 < n){
        *(q_i+end) = index_i+1;
        *(q_j+end) = index_j;
        end++;
    }
    if(table[index_i-1][index_j] == '.' && index_i-1 >= 0){
        *(q_i+end) = index_i-1;
        *(q_j+end) = index_j;
        end++;
    }
    if(table[index_i][index_j+1] == '.' && index_j+1 < m){
        *(q_i+end) = index_i;
        *(q_j+end) = index_j+1;
        end++;
    }
    if(table[index_i][index_j-1] == '.' && index_j-1 >= 0){
        *(q_i+end) = index_i;
        *(q_j+end) = index_j-1;
        end++;
    }
    if(start != end){
        printf("(%d,%d),step:%d\n",index_i, index_j, step);
        BFS(table, q_i, q_j, start+1, end, n, m, step+1, min);
    }
    
}

int main(){
    int M = 0;
    scanf("%d\n", &M);
    for(int i = 0; i < M; ++i){
        int n,m;
        scanf("%d %d\n", &n, &m);
        char table[1000][1000];
        for(int j = 0; j < n; ++j){
            scanf("%s", table[j]);
        }
        int *q_i = malloc(sizeof(int) * 1000000);
        int *q_j = malloc(sizeof(int) * 1000000);
        *q_i = 0;
        *q_j = 0;
        int start = 0, end = 1;
        int min = 0;
        BFS(table, q_i, q_j, start, end, n, m, 0, &min);
        if(min == 0){
            puts("unbelievable");
        }else{
            printf("%d\n", min);
        }
    }
    return 0;
    
}