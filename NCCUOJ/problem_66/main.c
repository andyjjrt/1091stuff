#include <stdio.h>

long long ten_pow(int power){
    long long n = 1;
    for(int i = 0; i < power; i++){
        n *= 10;
    }
    return n;
}

int get_number(long long num, int place){
    int ans[20], counter = 0;
    while(num != 0){
        ans[counter] = num % 10;
        //printf("%d ", ans[counter]);
        num = num / 10;
        counter++;
    }
    //puts("");
    counter -= 1;
    //printf("%d, %d\n", counter, place);
    return ans[counter - place];
}


int main(){
    long long N;
    while(scanf("%lld", &N) != EOF){
        N -= 1;
        long long M = 0;
        while(N - 9 * ten_pow(M)*(M+1) > 0){
            N -= 9 * ten_pow(M)*(M+1);
            //printf("%lld, %lld\n", 9 * ten_pow(M)*(M+1), N);
            M++;
        }
        M++;
        //printf("==%lld, %lld, %d\n", ten_pow(M-1) + (N / M), N % M, get_number(ten_pow(M-1) + (N / M), (N % M)));
        printf("%d\n", get_number(ten_pow(M-1) + (N / M), (N % M)));
    }
}