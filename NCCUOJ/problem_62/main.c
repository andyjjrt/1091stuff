#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b){return ( *(int*)b - *(int*)a);}

int main(){
    int N, array[1000010];
    scanf("%d", &N);
    for(int i = 0; i< N; i++){
        scanf("%d", &array[i]);
    }
    qsort(array, N, sizeof(int), cmpfunc);
    int checker = array[0];
    long long ans = 0, sum = 0, choose = array[0];
    for(int i = 0; i < N; i++){
        //printf("%d %lld\n", array[i], sum);
        if(checker == array[i]){
            sum += checker;
        }else{
            if(sum > ans)
                ans = sum;
                choose = checker;
            checker = array[i];
            sum = checker;
        }
    }
    printf("%lld\n%lld", choose, ans*10000);
}