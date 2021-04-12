#include <stdio.h>
#include <limits.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
	int n;
	scanf("%d", &n);
	int solutions[1000010];
	solutions[0] = 0;
	solutions[1] = 1;
	for(int i = 2; i <= n; ++i){
		solutions[i] = i;
		for(int j = 2; j*j <= i; ++j){
			solutions[i] = MIN(solutions[i], solutions[i - j*j] + 1);
		}
	}
	printf("%d\n", solutions[n]);
}