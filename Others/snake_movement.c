#include<stdio.h>
#include<stdlib.h>

move_right(int right,int *x,int *y);
move_left(int left,int *x,int *y);
move_up(int up,int *x,int *y);
move_down(int down,int *x,int *y);


int main(){

int x=0,y=0;
char ch;
int dir;

move_right(10,&x,&y);
move_down(15,&x,&y);
move_left(10,&x,&y);
move_up(9,&x,&y);


}

move_right(int right,int *x,int *y){

int i=0,j=0,a=0,b=0,d=0;

while(a<right){

system("clear");
for(j=0;j<*y;j++)
printf("\n");                          //right
for(i=*x;i<a+*x;i++)
printf(" ");
printf("0\n");
a++;
for(d=0;d<10000000;d++)
{};

}

*x+=right;

}

move_left(int left,int *x,int *y){

int i=0,j=0,a=0,b=0,d=0;

while(a<left){
system("clear");
for(j=0;j<*y;j++)
printf("\n");                         //left
for(i=0;i<*x-a;i++)
printf(" ");
printf("0\n");
a++;
for(d=0;d<10000000;d++)
{};

}

*x-=left;
}

move_up(int up,int *x,int *y){

int i=0,j=0,a=0,b=0,d=0;

while(b<up){
system("clear");
for(j=0;j<*y-b;j++)
printf("\n");                         //up
for(i=0;i<*x;i++)
printf(" ");
printf("0\n");
b++;
for(d=0;d<10000000;d++)
{};

}

*y-=up;
}

move_down(int down,int *x,int *y){

int i=0,j=0,a=0,b=0,d=0;

while(b<down){
system("clear");
for(j=0;j<*y+b;j++)
printf("\n");                         
for(i=0;i<*x;i++)                      //down
printf(" ");
printf("0\n");
b++;
for(d=0;d<10000000;d++)
{};
}

*y+=down;

}


