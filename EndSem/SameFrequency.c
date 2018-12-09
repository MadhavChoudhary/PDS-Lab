#include<stdio.h>
//order - n
int main(){

	int i,key,key2,count=0;
	int t,j;

	scanf("%d",&t);

	char str[t][100];

	for(j=0;j<t;j++)
		scanf("%s",str[j]);

	for(j=0;j<t;j++){

		int arr[123]={0};

		for(i=0;str[j][i]!='\0';i++)
			arr[str[j][i]]+=1;

		key=arr[str[j][i-1]];

		for(i=97;i<123;i++){

			if(arr[i]==key+1)
				count++;

			if(count>1){
				printf("0\n");return 0;
			}

		}

		if(count==1)
			printf("1\n");

	}
	
}