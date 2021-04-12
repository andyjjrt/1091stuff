#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main() {
	int n, m; 
	int A[1010], B[1010], c[1010][1010];
	A[0] = 0;
	B[0] = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &A[i]);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d", &B[i]);
	}
	int result = 0;
	for(int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if(i == 0 || j == 0){
				c[i][j] = 0;
			}else if(A[i] == B[j]){
				c[i][j] = c[i-1][j-1] + 1;
				result = MAX(c[i][j], result);
			}else{
				c[i][j] = 0;
			}
			//printf("%d ", c[i][j]);
		}
		//puts("");
	}	
	printf("%d\n", result);

	return 0;
}
