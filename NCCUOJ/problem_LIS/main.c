#include <stdio.h>

int main(){
    int N;
    int lis = 1;
    int last;
    scanf("%d", &N);
    scanf("%d", &last)
    for(int i = 1; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp > last){
            lis++;
        }
    }
}