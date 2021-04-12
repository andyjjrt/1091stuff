#include <stdio.h>

int main(void) {
    char a[10000];
    while(scanf("%s",a) != EOF){
        int n = 0;
        for(int i = 0; a[i] != '\0'; i++){
            n += a[i];
            n %= 3;
        }
        if(n % 3 == 0){
            puts("yes");
        }else{
            puts("no");
        }
    }
}