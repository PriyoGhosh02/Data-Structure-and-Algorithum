#include<stdio.h>
int main(){
int n,i,j,a[100],temp,min;
printf("Enter the array limit: ");
scanf("%d", &n);
printf("Enter the array element: ");
for(i=0;i<n;i++)
    scanf("%d", &a[i]);

//sort
for(i=0;i<n;i++){
    min=i;
    for(j=i+1;j<n;j++){
        if(a[j]<a[min]){
        min=j;
        }
    }
    temp=a[i];
        a[i]=a[min];
        a[min]=temp;
}
printf("After sorting: ");
for(i=0;i<n;i++)
    printf("%d", a[i]);
}
