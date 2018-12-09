#include<stdio.h>

int main(){

    int t,i,j,count;
    
    scanf("%d",&t);
	char username[t][1000];

    for(i=0;i<t;i++)
    	scanf("%s",username[i]);

    for(i=0;i<t;i++){

    	j=-1;count=0;
    	int arr[123]={0};

    	while(username[i][++j]!='\0'){

    		if(username[i][j]=='a' || username[i][j]=='e' || username[i][j]=='i' ||
    			username[i][j]=='o' || username[i][j]=='u')
    			continue;
    		else
    			arr[username[i][j]]++;
    	}

    	for(j=97;j<123;j++){
    		
    		if(arr[j]==1)
    			count++;
    		else if(arr[j]!=0)
    			count++;
    	}

    	for(i=97;i<123;i++)
    		printf("%d ",arr[i]);

    	if(count%2==0)
    		printf("SHE!\n");
    	else
    		printf("HE!\n");
    }

	return 0;
}