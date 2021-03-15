#include <stdio.h>

int main(void){
	int n;
	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}else{
			int row[100] = {0};
			int column[100] = {0};
			int data[100][100];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					scanf("%d",&data[i][j]);
					row[i] += data[i][j];
					column[j] += data[i][j];
				}
			}
			int check_column = -1,check_row = -1,status_row = 0,status_column = 0;
			for(int i = 0; i < n; i++){
				if(row[i] % 2 == 1){
					if(status_row == 0){                                            
						check_row = i;
					}
					status_row ++;
				}
				if(column[i] % 2 == 1){
					if(status_column == 0){                                         
						check_column = i;
					}
					status_column ++;
				}
			}
			if(status_row == 0 && status_column == 0){
				puts("OK");
			}else if(status_row == 1 && status_column == 1){
				printf("Change bit (%d,%d)\n", check_row+1,check_column+1);
			}else{
				puts("Corrupt");
			}
		}
	}
}
