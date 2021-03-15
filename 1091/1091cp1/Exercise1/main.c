#include <stdio.h>
#include <math.h>

int main(void) {
  long long a,b,c,d,ans;
  scanf("%lld %lld\n%lld %lld",&a,&b,&c,&d);
  ans = llabs(a-c)*llabs(b-d);
  printf("%lld\n",ans);
  return 0;
}
