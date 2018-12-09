#include<stdio.h>
#include<string.h>

int main(){

	int len,t,k,i,count;
	char str[100];

	scanf("%d",&t);

	for(i=0;i<t;i++){
		count=0;
		scanf("%s",str);
		scanf(" %d",&k);
		len=strlen(str);
		if(0==flip_cakes(str,0,len-1,k,&count))
			printf("CASE #%d  %d\n",i+1,count);
		else
			printf("CASE #%d  IMPOSSIBLE\n",i+1);
	}


}

int flip_cakes(char str[],int sta,int end,int k,int *count){

	int i;

	if(sta==end)
		return 0;

	else if(str[sta]=='-'){

		if(end-sta+1<k)
			return -1;
		str[sta]='+';
		*count=*count+1;

		for(i=sta+1;i<sta+k;i++)
			str[i]=(str[i]=='+')?'-':'+';
	}

	return flip_cakes(str,sta+1,end,k,count);
}