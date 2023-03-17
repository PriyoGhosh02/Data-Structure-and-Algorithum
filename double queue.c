#include<stdio.h>
#define size 5

int front=0;rear=-1;total=0,a[size],item;

void add_rear(int item){
if(size==total)
    printf("Over Flow");
rear=(rear+1)%size;
a[rear]=item;
total++;
}

void add_front(int item){
if(size==total)
    printf("Over Flow");
else{
    if(front==0)
     front=size-1;
    else
        front--;
        a[front]=item;
        total++;
}}

int delete_rear(){
if(total==0)
    printf("Under Flow");
else{
    if(rear==-1)
        rear=size-1;
    int rear_item=a[rear];
    rear--;
    total--;
return rear_item;
}
}

int delete_front(){
if(total==0)
    printf("Under Flow");
    int front_item=a[front];
    a[front]=0;
    front=(front+1)%size;
    total--;
    return front_item;
}

void output(){
printf("Display: ");
for(int i=0;i<size;i++)
    printf("%d\t", a[i]);
    printf("\n");
}

int main(){
add_front(5);
add_front(10);
output();
add_rear(25);
add_front(30);
output();
delete_rear();
output();
delete_front();
output();
delete_rear();
output();
delete_front();
output();

}
