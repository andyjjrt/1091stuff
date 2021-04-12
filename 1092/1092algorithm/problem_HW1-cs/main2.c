#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
    int N[100010], n=0, sum = 0;
    while(scanf("%d", &N[n]) != EOF){
        sum += N[n];
        n++;
    }
    int max = 0, suffix = 0, min = 0, suffix_m = 0;
    for(int i = 0; i < n; i++){
        if(N[i] + suffix > 0){
            suffix += N[i];
            max = MAX(suffix, max);
        }else{
            suffix = 0;
        }
        if(N[i] + suffix_m < 0){
            suffix_m += N[i];
            min = MIN(suffix_m, min);
        }else{
            suffix_m = 0;
        }
        //printf("%3d, %3d, %3d, %3d, %3d\n", N[i], suffix, max, suffix_m, min);
    }
    printf("%d\n", MAX(max, sum-min));
}