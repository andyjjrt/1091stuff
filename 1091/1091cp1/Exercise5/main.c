#include <stdio.h>

int main(void){
	int data[10000];
	int count = 0;
	while((scanf("%d",&data[count])) != EOF){
		count++;
	}
	int sum = 0;
	int ans = 0;
	for(int i = 0; i <= count; i++){
		sum = 0;
		for(int j = i;j <= count; j++){
			sum += data[j];
			if(ans < sum){
				ans = sum;
			}
			//printf("%d.%d.",i,j);
		}
	}
	printf("Maximum contiguous sum is %d\n",ans);
	return 0;
}
