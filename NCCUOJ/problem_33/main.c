#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct que{
    int x;
    int y;
    int step;
};
typedef struct que que;

int main(){
    int table[8][8];
    que *q = malloc(sizeof(que) * 100);
    memset(q,0,sizeof(que));
    scanf("%d %d\n", q->x, q->y);
    int ans_x, ans_y;
    scanf("%d %d", ans_x, ans_y);
    int start = 0, end = 1, step = 0, ans = 0;
    while(end - start > 0){
        int tmp_end = end;
        for(int i = start; i < tmp_end; ++i){
            int x = (q+i)->x;
            int y = (q+i)->y;
            if(x == ans_x && y == ans_y){
                ans = step;
                break;
            }
            if(table[x][y] == 1){
                continue;
            }
            table[x][y] = 1;
            if(table[x+2][y+1] == 0 && x+2 < 8 && y+1 < 8){
                (q+end)->x = x+2;
                (q+end)->y = y+1;
                (q+end)->step = step;
                end++;
            }
            if(table[x-2][y+1] == 0 && x-2 >= 0 && y+1 < 8){
                (q+end)->x = x-2;
                (q+end)->y = y+1;
                (q+end)->step = step;
                end++;
            }
        }
        if(ans != 0){
            break;
        }
        step++;
        start = tmp_end;
    }
    printf("%d\n", ans);
}