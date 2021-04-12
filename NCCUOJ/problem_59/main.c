#include <stdio.h>

int main(){
    printf("馬德");
    char a;
    while((a = getchar()) != EOF){
        printf("%c", a);
    }
    printf("!!");
}