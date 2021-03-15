#include <stdio.h>

int main(void) {
  long long x,y,s=0;
  scanf("%lld %lld",&x,&y);
  char command;
  while((command = getchar()) != EOF){
    if(command == 'U'){
      long long para;
      scanf("%lld",&para);
      if(s == 0){
        y += para;
      }else{
        s --;
      }
    }else if(command == 'D'){
      long long para;
      scanf("%lld",&para);
      if(s == 0){
        y -= para;
      }else{
        s --;
      }
    }else if(command == 'R'){
      long long para;
      scanf("%lld",&para);
      if(s == 0){
        x += para;
      }else{
        s --;
      }
    }else if(command == 'L'){
      long long para;
      scanf("%lld",&para);
      if(s == 0){
        x -= para;
      }else{
        s --;
      }
    }else if(command == 'T'){
      long long para1,para2;
      scanf("%lld %lld",&para1,&para2);
      if(s == 0){
        x = para1;
        y = para2;
      }else{
        s --;
      }
    }else if(command == 'S'){
      long long para;
      scanf("%lld",&para);
      if(s == 0){
        s = para;
      }else{
        s --;
      }
    }
  }
  printf("(%lld , %lld)\n",x,y);
  return 0;
}
