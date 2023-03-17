#include<stdio.h>
#define max 5
int a[max],item,top=0;

void push(int a[],int item){
if(top>=max)
    printf("Over Flow");
else {
    top++;
    a[top]=item;
}}

int pop(int a[]){
if(top<0)
    printf("Under flow");
else{
    item=a[top];
    top--;
}
return item;
}

void output(int a[]){
    int i;
for(i=top;i>=1;i--)
    printf("%d ", a[i]);
}

int main(){

push(a,4);
push(a,3);
push(a,6);
push(a,7);
output(a);
printf("\nPop: %d\n",pop(a));
output(a);

}
