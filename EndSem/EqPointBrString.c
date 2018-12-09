#include<stdio.h>
#include<string.h>

int main(){

	char str[100];
	int i,count=0,subcount1=0,subcount2=0;
	scanf("%s",str);
	int len=strlen(str);

	for(i=0;i<len;i++)
		if(str[i]==')')
			count++;

	for(i=0;i<len;i++){

		if(str[i]=='(')
			subcount1++;
		if(str[i]==')')
			subcount2++;
		if(subcount1==count-subcount2)
			break;
	}

	printf("%d\n",i+1);
	return 0;
}