#include <stdio.h>

int Letter2int(char c){
	int list[26] = {1, 0, 9, 8, 7, 6, 5, 4, 9, 3, 2, 2, 1, 0, 8, 9, 8, 7, 6, 5, 4, 3, 1, 3, 2, 0};
	return(list[c-'A']);
}


int main(void) {
  int m;
  scanf("%d",&m);
  for(int i= 0;i<m;i++){
    char a[10];
    scanf("%s",a);
    int verify = Letter2int(a[0])+(a[1]-48)*8+(a[2]-48)*7+(a[3]-48)*6+(a[4]-48)*5+(a[5]-48)*4+(a[6]-48)*3+(a[7]-48)*2+(a[8]-48)+(a[9]-48);
    verify = verify % 10;
    if(verify != 0){
      puts("Invalid");
    }else{
      
      if(a[1]-48 >= 3){
        puts("Invalid");
      }else{
      
          puts("Valid");
      }
    }
  }
}
