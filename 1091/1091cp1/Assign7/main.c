#include <stdio.h>

int main(void){
        int N,K,counter = 0,ans = 0     ,arr[30] = {0},* const arrptr = arr;
        scanf("%d%d",&N,&K);
        for(int i = 0; i < N; i ++){
                scanf("%d",arrptr+i);
        }
        for(int i = 0; i < (1 << N);i++){
                int b = 0,binary[20] = {0}, a = i,* const bptr = binary;
                while(1){
                        int check = a % 2;
                        *(bptr+b) = check;
                        b++;
                        a /= 2;
                        if(a < 1)
                                break;
                }
                long sum = 0;
                for(int j = 0; j < N; j++){
                        //printf("%d ",*(bptr+j));
                        sum += *(arrptr + j) * *(bptr+j);
                }
                if(sum > ans && sum <= K)
                        ans = sum;
                //printf("%d\n",sum);
        }
        printf("%d\n",ans);
}
