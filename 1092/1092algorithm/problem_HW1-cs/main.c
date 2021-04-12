#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main(){
    int N[200010], n=0;
    while(scanf("%d", &N[n]) != EOF){
        n++;
    }
    for(int i = 0; i < n; i++){
        N[i+n] = N[i];
    }
    int new_n = n + n;
    int ans = 0, suffix = 0, counter = 0;
    for(int i = 0; i < new_n; i++){
        if(suffix > 0 && counter < n){
            suffix += N[i];
            counter++;
        }else{
            suffix = N[i];
            counter = 0;
        }
        ans = MAX(suffix, ans);
        //printf("%d, %d, %d, %d\n", N[i], suffix, ans, counter);
    }
    printf("%d\n", ans);
}