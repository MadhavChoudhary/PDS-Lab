#include<stdio.h>

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();
int expo(int ,int );
int binomial(int ,int );
void towers(int ,char ,char ,char );
int catalana(int );
int catalanb(int ,int []);

int main(){

int x;

while(1){

printf("Enter the question you want:");
scanf("%d",&x);

switch (x){

case 1:Q1();break;
case 2:Q2();break;
case 3:Q3();break;
case 4:Q4();break;
case 5:Q5();break;
default:printf("Enter a proper question no.\n");break;

}

}
return 0;
}


void Q1(){

int a,b,exp;

printf("Enter a and b:");
scanf("%d %d",&a,&b);

exp=expo(a,b);
printf("%d\n",exp);

}

void Q2(){

int n,r,bin;

printf("Enter n and r:");
scanf("%d %d",&n,&r);

bin=binomial(n,r);
printf("%d\n",bin);

}

void Q3(){

int n;
char pos1,pos2,pos3;

printf("Enter n:");
scanf("%d",&n);
printf("Enter the initial,inter and final position of disks:");
scanf(" %c %c %c",&pos1,&pos2,&pos3);
towers(n,pos1,pos2,pos3);

}

void Q4(){

int n,cat,k;

printf("Enter n:");
scanf("%d",&n);

cat=catalana(n);
printf("Cn=%d\n",cat);


}

void Q5(){

int n,cat,k;

printf("Enter n:");
scanf("%d",&n);

int cata[n+1];

for(k=0;k<=n;k++)
cata[k]=0;

cat=catalanb(n,cata);
printf("Cn=%d\n",cat);


}

int catalanb(int n,int cata[]){

int k,cat=0;

if(n==0 || n==1)
return 1;

else if(cata[n]!=0)
return cata[n];                                                                //storing values to avoid recalculation

else                                                                            //memoisation
for(k=0;k<n;k++)
cat=cat+catalanb(n-k-1,cata)*catalanb(k,cata);
cata[n]=cat;
return cata[n];

}

int catalana(int n){

int k,cat=0;

if(n==0)
return 1;

else if(n==1)
return 1;

else
for(k=0;k<n;k++)
cat=cat+catalana(n-k-1)*catalana(k);

return cat;

}

void towers(int n,char pos1,char pos2,char pos3){

if(n==1)
printf("Move disk from %c to %c\n",pos1,pos3);

else{
towers(n-1,pos1,pos3,pos2);
printf("Move disk from %c to %c\n",pos1,pos3);
towers(n-1,pos2,pos1,pos3);
}

}

int binomial(int n,int r){

if(r==0)
return 1;

else if(n==r)
return 1;

else
return(binomial(n-1,r)+binomial(n-1,r-1));

}

int expo(int a,int b){

if(b==0)
return 1;

else
return(a*expo(a,b-1));

}
