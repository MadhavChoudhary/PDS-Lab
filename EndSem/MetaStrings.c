#include<stdio.h>
#include<string.h>

int main(){

	int t,count,len,i,j;
	char letter;
	scanf("%d",&t);
	char str1[t][1000],str2[t][1000];

	for(i=0;i<t;i++){

		scanf("%s",str1[i]);
		scanf("%s",str2[i]);

	}

	for(i=0;i<t;i++){

		if(strlen(str1[i])!=strlen(str2[i])){
			printf("0\n");
			return 0;}
		count=0;letter='\0';
		len=strlen(str1[i]);

		for(j=0;j<len;j++){

			if(str1[i][j]!=str2[i][j] && (str2[i][j]==letter || letter=='\0')){
				count++;
				letter=str1[i][j];
			}

			else if(str1[i][j]!=str2[i][j])
				break;

			if(count>2)
				break;
		}

			if(count==2)
				printf("1\n");
			else
				printf("0\n");
	}

	return 0;
}