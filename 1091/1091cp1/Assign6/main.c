#include <stdio.h>

int detect(int *tableptr,int para){
        int counter = 1;
        int pos = 0;
        while(*tableptr == *(tableptr+(1+pos)*para)){
                pos++;
        }
        counter += pos;
        pos = 0;
        while(*tableptr == *(tableptr-(1+pos)*para)){
                pos ++;
        }
        counter += pos;
        return counter;
}
int main() {
        int table[17][17] = {0};
        int com[4] = {1,16,17,18};
        char col;
        int row;
        int player = 1;
        int error = 0;
        int winner = 0;
        int counter = 1;
        while(scanf("%c %d\n",&col,&row) != EOF){
                //printf("W%d %d\n",col-64,row);
                if(error == 0&&winner == 0){
                        if(table[col-64][row] != 0){
                                error = counter;
                        }if(col-64>15 || col-64 < 1 || row > 15 || row < 1){
                                error = counter;
                        }else{
                                table[col-64][row] = player;
                                for(int i = 0; i < 4; i ++){
                                        if(detect(&table[col-64][row],com[i]) >= 5){
                                                winner = player;
                                                break;
                                        }
                                }               
                        }
                }
                player = counter % 2;
                player++;
                //printf("counter:%d,error:%d\n",counter,error);
                counter++;
        }
        if(error != 0){
                printf("Invalid move at step %d.\n",error);
        }else if(winner == 2){
                printf("The winner is white.\n");
        }else if(winner == 1){
                printf("The winner is black.\n");
        }else if(winner == 0){
                printf("The game is tie.\n");
        }
        return 0;
}
