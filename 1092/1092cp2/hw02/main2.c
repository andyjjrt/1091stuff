#include <stdio.h>

int main(){
    int n = 0;
    int array[100100];
    int relation[100100] = {-1};
    while(scanf("%d", &array[n]) != EOF){
        n++;
    }
    int start = 0, end = 1, max = array[0], sum = array[0];
    for(end = 1; end < n; end++){
        //printf("dealing: %d, max: %d\n", array[end], max);
        int tmp = array[end];
        sum += tmp;
        int repeat = relation[tmp];
        /*
        for(int j = start; j < end; j++){
            if(array[j] == array[end]){
                repeat = j;
                //printf("repeat place: %d, repeat: %d\n", j, repeat);
                break;
            }
        }
        */
        if(repeat != -1){
            //printf("repeat at: %d\n", repeat);
            for(int j = start; j <= repeat; j++){
                sum -= array[j];
            }
            start = repeat + 1;
        }
        relation[tmp] = end;
        if(sum > max){
            max = sum;
        }
    }
    printf("%d\n", max);
}
