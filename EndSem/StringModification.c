#include<stdio.h>

int main(){

	int i=0,j=0,k=0;

	char str[1000];

	scanf("%s",str);

	int len=strlen(str);

	while(k<len){

		while(1)
			(str[i]==str[i+1])?((str[j]!=str[j+1])?((str[j]!=str[j-1])||j==len-1||j==0)?break:j++):j++):i++;
	}
}