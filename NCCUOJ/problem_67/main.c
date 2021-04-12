#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
    int max = 0, min = 2000000, tmp, max_c = 0, min_c = 0;
    int profit = 0;
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        if(max < tmp){
            max = tmp;
            max_c = i;
        }
        if(min > tmp){
            min = tmp;
            min_c = i;
        }
        //printf("tmp:%d, max:%d, min:%d\n",tmp,  max, min);
        if(max_c < min_c){
            int tmp_profit = max - min;
            profit = MAX(profit, tmp_profit);
        }else{
            min = 2000000;
        }
        //printf("%d\n", profit);
    }
    printf("%d\n", profit);
    return 0;
}