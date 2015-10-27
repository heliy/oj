#include<stdio.h>
#include<string.h>

using namespace std;

char ZONE[32][5] = {"UTC", "GMT", "BST", "IST", "WET", "WEST", "CET", "CEST", "EET", "EEST", "MSK", "MSD", "AST", "ADT", "NST", "NDT", "EST", "EDT", "CST", "CDT", "MST", "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST", "AEDT", "ACST", "ACDT", "AWST"};

float TIME[32] = {0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};

int difference(char* zone1, char* zone2){
  int i,j;
  for(i = 0; strcmp(ZONE[i], zone1); i++)
    ;
  for(j = 0; strcmp(ZONE[j], zone2); j++)
    ;
  return (int)((TIME[i] - TIME[j])*60);
}

int main(){
  int n, i, hours, minutes;
  char time[9];
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s", time);
    switch(time[0]){
    case 'n': 
      hours = 12;
      minutes = 0;
      break;
    case 'm':
      hours = 0;
      minutes = 0;
      break;
    default:
      sscanf(time, "%d:%d", &hours, &minutes);
      hours %= 12;
      scanf("%s", time);
      if(time[0] == 'p')
	hours += 12;
    }
    char timezone1[5], timezone2[5];
    scanf("%s %s", timezone1, timezone2);
    int nt = hours*60+minutes+difference(timezone2, timezone1);
    if(nt < 0){
      nt += 1440;
    }
    nt %= 1440;
    switch(nt){
    case 0:
      printf("midnight\n");
      break;
    case 720:
      printf("noon\n");
      break;
    default:
      hours = nt/60;
      minutes = nt%60;
    }
    if(hours == 0){
      printf("12:%02d a.m.\n", minutes);
    }else if(hours < 12){
      printf("%d:%02d a.m.\n", hours, minutes);
    }else if(hours == 12){
      printf("12:%02d p.m.\n", minutes);      
    }else{
      printf("%d:%02d p.m.\n", hours%12, minutes);      
    }
  }
  return 0;
}
