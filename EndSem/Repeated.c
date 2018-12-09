#include<stdio.h>
//order - n
int main(){

	int arr[123]={0};
	char str[100];
	int i=0;

	scanf("%s",str);

	while(str[i]!='\0'){
		arr[str[i]]+=1;

		if(arr[str[i]]>1){
			printf("%c\n",str[i]);
			return 0;}

		i++;
	}

	printf("No repeatedcharacter\n");
	return 0;
}