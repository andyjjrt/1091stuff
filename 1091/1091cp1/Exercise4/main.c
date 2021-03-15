#include <stdio.h>
int GCD(int t,int v)
{
  if(t%v==0){ 
    return v;
  }else{
    return GCD(v,t%v);
  }
}
int main(void) {
  int a,b=1,tes = 0;
  while((scanf("%d",&a)) != EOF){
    if(a != 0 && tes == 0){
      //輾轉相除
      if(a<b){
        int tmp = b;
        b = a;
        a = tmp;
      }
      int gcd = GCD(a,b);
      b = a*b/gcd;
    }else{
      tes = 1;
      b = 0;
    }
  }
  printf("%d\n",b);
}
