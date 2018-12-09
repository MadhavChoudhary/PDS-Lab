#include<stdio.h>
#include<string.h>

//order - n 
//wow - started with order - n2 , went to order - nlogn and now order - n the journey is amazing 
//want ot find new methods to do this problem

int main(){

	int n,len,i;

	char str1[100],str2[100];
	int hash1[123]={0},hash2[123]={0};

	scanf("%s",str1);
	scanf("%s",str2);

	len=strlen(str1);

	if(len!=strlen(str2))
		return -1;

	for(i=0;i<len;i++){

		hash1[str1[i]]++;
		hash2[str2[i]]++;

	}

	for(i=97;i<123;i++)
		if(hash1[i]!=hash2[i])
			return -1;

	printf("They are anagrams.\n");

	return 0;
}