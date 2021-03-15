#include <stdio.h>
int arr[22][22] = {0};
void rec(int x,int y){
        arr[x][y] = 0;
        if((arr[x+1][y]) == 1){
                arr[x+1][y] = 0;
                rec(x+1,y);
        }
        if((arr[x-1][y]) == 1){
                arr[x-1][y] = 0;
                rec(x-1,y);
        }
        if((arr[x][y+1]) == 1){
                arr[x][y+1] = 0;
                rec(x,y+1);
        }
        if((arr[x][y-1]) == 1){
                arr[x][y-1] = 0;
                rec(x,y-1);
        }
}

int main(){
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i ++){
                int m;
                int counter = 0;
                scanf("%d",&m);
                for(int j = 1; j <= m; j ++){
                        for(int k = 1; k <= m; k ++){
                                char tmp;
                                scanf(" %c",&tmp);
                                if(tmp == '.'){
                                        arr[j][k] = 0;
                                }else{
                                        arr[j][k] = 1;
                                }
                        }
                }
                for(int j = 0; j < 22; j ++){
                        for(int k = 0; k < 22; k ++){
                                if(arr[j][k] == 1){
                                        rec(j,k);
                                        counter++;
                                }

                                //printf("%d ",table[j][k]);
                        }
                        //puts("");
                }
                printf("%d\n",counter);
        }
}
