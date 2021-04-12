#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
    int max = 0, min = 2000000, tmp, counter = 0, max_c = 0, min_c = 0;
    int profit = 0;
    while(scanf("%d", &tmp) != EOF){
        if(max < tmp){
            max = tmp;
            max_c = counter;
        }
        if(min > tmp){
            min = tmp;
            min_c = counter;
        }
        if(max_c > min_c){
            int tmp_profit = max - min;
            profit = MAX(profit, tmp_profit);
        }else{
            max = 0;
        }
        counter++;
    }
    printf("%d\n", profit);


    /*
    for(int i = 0; i < N_i; i++){
        printf("%d ", N[i]);
    }
    puts("");
    */
    return 0;
}
