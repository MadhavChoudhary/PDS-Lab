#include<stdio.h>

int main(){

int count=0,y,temp,year1=1900,year2,i;
int date1=101,date2,d;
int span[]={31,28,31,30,31,30,31,31,30,31,30,31};

printf("Enter the year\n");
scanf("%d",&year2);
printf("Enter date in month.date format\n");
scanf("%d",&date2);

for(y=year1;y<year2;y++){

temp=y;

	if(temp%100==0)
		temp/=100;

	if(temp%4==0)
		count+=2;
	else
		count++;

}

count=count%7;

	if(y%100==0)
		y/=100;

	if(y%4==0)
		span[1]=29;

d=date1;

while(d!=date2){

if(d%100==span[(d/100)-1])
	d=d+100-(d%100);
d++;
count++;

}

temp=count%7;

switch(temp){

	case 0:printf("It is Monday\n");break;
	case 1:printf("It is Tuesday\n");break;
	case 2:printf("It is Wednesday\n");break;
	case 3:printf("It is Thursday\n");break;
	case 4:printf("It is Friday\n");break;
  	case 5:printf("It is Saturday\n");break;
	case 6:printf("It is Sunday\n");break;
}

return 0;

}
