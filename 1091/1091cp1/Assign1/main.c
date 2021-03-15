#include <stdio.h>

int main(void) {
  int b;
  float a;
  scanf("%f %d",&a,&b);
  float c = a/100;
  c = b/(c*c);
  printf("%.2f\n",c);
}
