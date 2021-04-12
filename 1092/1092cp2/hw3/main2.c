#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
	int n;
	scanf("%d", &n);
	int solutions[1000010];
	for(int u = 0; u < 1000010; u++){
		solutions[u] = 1000010;
	}
	solutions[0] = 0;
	int perfect = 1;
	for(int i = 1; perfect <= n; i++){
		perfect = i*i;
		for(int j = perfect; j <= n; j++){
			solutions[j] = MIN(solutions[j], solutions[j - perfect] + 1);
		}
	}
	printf("%d\n", solutions[n]);
}