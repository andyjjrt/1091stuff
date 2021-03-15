#include <stdio.h>
#include <string.h>


void cut(char *comma){
	for(int i = 0; *(comma + i) != '\0'; i++){
		if(*(comma + i) == ',' || *(comma + i) == '\n')
			*(comma + i) = '\0';
	}
}

int main() {
	char trash[100];
  	gets(trash);  //eat info begin
	int n;
	char stations[15][20];
	int seat[1200][15];
	for(int i = 0; i < 1200; i ++){
		for(int j = 0; j < 15; j ++){
			seat[i][j] = -1;
		}
	}
	scanf(" %d",&n);
	for(int i = 0; i < n; i ++){
		scanf("%s,",stations[i]);
		cut(stations[i]);
	}
	//scanf("%s %s %s%s%s %s",trash,trash,trash,trash,trash,trash);
	//trash[0] = getchar();
  	gets(trash);
  	gets(trash);
  	gets(trash);
  	char command[100];
	int name_count = 0;
	char namelist[200][50];
	while(scanf("%s",command) != EOF){
		if(strcmp(command,"RESERVE") == 0){
			char name[50], start[20], end[20];
			scanf(" %s %s %s",name,start,end);
			cut(name);
			cut(start);
			cut(end);
			//determine the valid station
			int low = -1, high = -1;
			for(int i = 0; i < n; i++){
				if(strcmp(start,stations[i]) == 0){
					low = i;
				}
              	if(strcmp(end,stations[i]) == 0){
					high = i;
				}
			}
			if(low >= high || low == -1 || high == -1){
				puts("RESERVE FAILED.... (station information has something wrong)");
				continue;
			}
			int service_time;
			int service_status = 0;
			int seat_no[20] = {0};
			int service_used[10];
			scanf(" %d",&service_time);
			if(service_time > 4){
				printf("RESERVE FAILED.... (too many seats)\n");
				continue;
			}
			//determine if the user exist or not
			int name_index = -1;
			for(int i = 0; i < name_count; i++){
				if(strcmp(namelist[i],name) == 0){
					name_index = i;
				}
			}
			if(name_index == -1){
				strcpy(namelist[name_count],name);
				name_index = name_count;
				name_count++;
			}
			//start reserver service
			int act_used[10];
          	int pre_seat[1200][15];
          	memcpy(pre_seat,seat,sizeof(seat));
			for(int i = 0; i < service_time; i++){
				int carno, seatno;
				char seatchar;
              	scanf("%s",trash);
				scanf(" %d %d%c",&carno,&seatno,&seatchar);
				int seatid = (carno-1)*100 + (seatno - 1)*5 + (seatchar - 'A');
				service_used[i] = seatid;
				for(int j = low; j < high; j++){
					if(pre_seat[seatid][j] != -1){
						for(int k = 0; k < i; k++){
							pre_seat[service_used[k]][j] = -1;
						}
						service_status = 1;
						break;
					}else{
						pre_seat[seatid][j] = name_index;
					}
					if(service_status == 1)
						break;
				}
				if(service_status == 1)
					break;
				act_used[i] = seatid;
			}
			if(service_status == 0){
              	memcpy(seat,pre_seat,sizeof(seat));
				for(int i = 0; i < service_time; i++){
					int carno1 = (act_used[i] / 100) + 1;
					int seatno1 = (act_used[i]%100)/5 + 1;
					char seatchar1 = act_used[i]%5 + 'A';
					printf("RESERVE SUCCESSED!! -> %s %d %d%c (%s - %s)\n",namelist[name_index],carno1,seatno1,seatchar1,stations[low],stations[high]);
				}
			}else if(service_status == 1){
				printf("RESERVE FAILED.... (repeat seats)\n");
			}
			//printf("%s low:%d high:%d name_index:%d\n",name,low,high,name_index);
		}
      else if(strcmp(command,"CANCEL") == 0){
			char cancel_name[50], cancel_start[20], cancel_end[20];
			int cancel_no, cancel_seat;
			char cancel_seatchar;
			scanf(" %s %s %s %d %d%c",cancel_name, cancel_start, cancel_end, &cancel_no, &cancel_seat, &cancel_seatchar);
			cut(cancel_name);
			cut(cancel_start);
			cut(cancel_end);
			int seatid = (cancel_no-1)*100 + (cancel_seat - 1)*5 + (cancel_seatchar - 'A');
			int name_index = -1;
			for(int i = 0; i < name_count; i++){
				if(strcmp(namelist[i],cancel_name) == 0){
					name_index = i;
				}
			}
			int low = -1, high = -1;
			for(int i = 0; i < n; i++){
				if(strcmp(cancel_start,stations[i]) == 0){
					low = i;
				}else if(strcmp(cancel_end,stations[i]) == 0){
					high = i;
				}
			}
			if(low >= high || low == -1 || high == -1){
				printf("CANCELLATION FAILED.... (cannot find the stations information)\n");
				continue;
			}
          	if(name_index == -1){
				printf("CANCELLATION FAILED.... (cannot find the seat information)\n");
				continue;
			}
			int cancel_verify[20];
			int is_check = 0;
			for(int i = 0; i < n; i++){
				if(seat[seatid][i] == name_index && low <= i && i < high){
					is_check++;
				}
			}
			if(is_check == (high-low)){
				for(int i = low; i < high; i++){
					seat[seatid][i] = -1;
				}
				printf("CANCELLATION SUCCESSED!! %d %d%c (%s - %s)\n",cancel_no, cancel_seat, cancel_seatchar, cancel_start, cancel_end);
			}else{
				printf("CANCELLATION FAILED.... (cannot find the seat information)\n");
			}
		}
      else if(strcmp(command,"CHECK") == 0){
			char check_name[50];
			int check_no,check_seat;
			char check_seatchar;
			scanf(" %s %d %d%c",check_name, &check_no, &check_seat, &check_seatchar);
			cut(check_name);
			int name_index = -1;
			for(int i = 0; i < name_count; i++){
				if(strcmp(namelist[i],check_name) == 0){
					name_index = i;
				}
			}
			if(name_index == -1){
				printf("CHECK FAILED.... (cannot find the reservation data)\n");
				continue;
			}
			int seatid = (check_no-1)*100 + (check_seat - 1)*5 + (check_seatchar - 'A');
			int check_stat[15] = {0};
			int is_check = 0;
			for(int i = 0; i < n; i++){
				if(seat[seatid][i] == name_index){
					check_stat[i] = 1;
					is_check++;
				}
			}
			if(is_check == 0){
				printf("CHECK FAILED.... (cannot find the reservation data)\n");
				continue;
			}
			int check_station = 0;
			printf("CHECK %s %d %d%c ->", namelist[name_index], check_no, check_seat, check_seatchar);
			for(int i = 0; i < n; i ++){
				if(check_station == 0){
					if(check_stat[i] == 1){
						printf(" (%s - ",stations[i]);
						check_station = 1;
					}
				}else{
					if(check_stat[i] == 0){
						printf("%s)",stations[i]);
						check_station = 0;
					}
				}
			}
			printf("\n");

		}
	}
  	return 0;
}
