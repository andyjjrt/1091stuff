#include <stdio.h>
#include <string.h>

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        int canvas[100][100];
        memset(canvas,0,sizeof(canvas));
        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; ++j){
            int x1,y1,x2,y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for(int k = y1; k < y2; ++k){
                for(int l = x1; l < x2; l++){
                    canvas[k][l] ++;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 100; k++){
                if(canvas[j][k] > 0){
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}