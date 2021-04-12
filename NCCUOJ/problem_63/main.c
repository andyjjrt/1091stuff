#include <stdio.h>
#include <string.h>

int main(){
    int counter[10] = {0};
    char query[100];
    int n = 0;
    while(gets(query) != EOF){
        printf("%s\n",query);
        /*
        if(strcmp("Royal Straight Flush",query) == 0){
            counter[0] += 1;
        }else if(strcmp("Straight Flush",query) == 0){
            counter[1] += 1;
        }else if(strcmp("Four of a kind",query) == 0){
            counter[2] += 1;
        }else if(strcmp("Full house",query) == 0){
            counter[3] += 1;
        }else if(strcmp("Flush",query) == 0){
            counter[4] += 1;
        }else if(strcmp("Straight",query) == 0){
            counter[5] += 1;
        }else if(strcmp("Three of a kind",query) == 0){
            counter[6] += 1;
        }else if(strcmp("Two pair",query) == 0){
            counter[7] += 1;
        }else if(strcmp("One pair",query) == 0){
            counter[8] += 1;
        }else if(strcmp("Zitch",query) == 0){
            counter[9] += 1;
        }
        n++;
        */
    }
    for(int i = 0; i < counter[0]; i++){
        puts("Royal Straight Flush");
    }
    for(int i = 0; i < counter[1]; i++){
        puts("Straight Flush");
    }
    for(int i = 0; i < counter[2]; i++){
        puts("Four of a kind");
    }
    for(int i = 0; i < counter[3]; i++){
        puts("Full house");
    }
    for(int i = 0; i < counter[4]; i++){
        puts("Flush");
    }
    for(int i = 0; i < counter[5]; i++){
        puts("Straight");
    }
    for(int i = 0; i < counter[6]; i++){
        puts("Three of a kind");
    }
    for(int i = 0; i < counter[7]; i++){
        puts("Two pair");
    }
    for(int i = 0; i < counter[8]; i++){
        puts("One pair");
    }
    for(int i = 0; i < counter[9]; i++){
        puts("Zitch");
    }
}