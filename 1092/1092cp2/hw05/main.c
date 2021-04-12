#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main(){
    int N, array[110][110];
    scanf("%d", &N);
    for(int i = N-1; i >=0; --i){
        scanf("%d", &array[N-1][i]);
    }
    for(int i = N-2; i >= 0; --i){
        for(int j = 0; j <= i; ++j){
            array[i][j] = MAX(array[N-1][j] - array[i+1][j+1], array[N-1][j+N-i-1] - array[i+1][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%3d ", array[i][j]);
        }
        puts("");
    }
    if(array[0][0] >= 0){
        puts("True");
    }else{
        puts("False");
    }
}