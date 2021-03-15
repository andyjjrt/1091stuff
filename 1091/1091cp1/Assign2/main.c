#include <math.h>
#include <stdio.h>

int main(void) {
	float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
	scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5,&x6,&y6,&x7,&y7,&x8,&y8);
	float a1 = x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - x2 * y1 - x3 * y2 -x4 * y3 - x1 * y4;
	float a2 = x5 * y6 + x6 * y7 + x7 * y8 + x8 * y5 - x6 * y5 - x7 * y6 -x8 * y7 - x5 * y8;
	a1 = fabs(a1) / 2;
	a2 = fabs(a2) / 2;
	if((int)(a1*100)%100 == 0){
	  printf("%.0f\n",a1);
	}else if((int)(a1*100)%10 == 0){
	  printf("%.1f\n",a1);
	}
	if((int)(a2*100)%100 == 0){
	  printf("%.0f\n",a2);
	}else if((int)(a2*100)%10 == 0){
	  printf("%.1f\n",a2);
	}
	if(a1>a2){
	  puts("A > B");
	}else if(a1 == a2){
	  puts("A = B");
	}else{
	  puts("A < B");
	}
}
