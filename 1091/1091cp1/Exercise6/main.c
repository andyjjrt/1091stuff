#include <stdio.h>

int main(){
        int a,b;
        while(scanf("%d%d",&a,&b) != EOF){
                int rec1[a][b];
                for(int i = 0; i < a; i++){
                        for(int j = 0; j < b; j ++){
                                scanf("%d",&rec1[i][j]);
                        }
                }
                int c,d;
                scanf("%d%d",&c,&d);
                int rec2[c][d];
                for(int i = 0; i < c; i++){
                        for(int j = 0; j < d; j ++){
                                scanf("%d",&rec2[i][j]);
                        }
                }
                if(b != c){
                        puts("Invalid calculation!!");
                        continue;
                }
                int ans[a][d];
                for(int i = 0; i < a; i++){
                        for(int j = 0; j < d; j ++){
                                int ind = 0;
                                for(int k = 0; k < b; k ++){
                                        ind += rec1[i][k] * rec2[k][j];
                                }
                                if(j == 0){
                                        printf("%d",ind);
                                }else{
                                        printf(" %d",ind);
                                }
                        }
                        puts("");
                }
        }

}
