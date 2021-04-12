#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int array[2000000];
    int sum = 0;
    scanf("%d", &n);
    array[0] = 0;
    for(int i = 1; i <= n; i++){
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
        array[i] = sum;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        printf("%d\n",array[b]-array[a-1]);
    }
}