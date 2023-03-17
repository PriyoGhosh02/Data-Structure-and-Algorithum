#include<stdio.h>
int main(){
int i,a[100],n,value,gap;
printf("Enter the array limit: ");
scanf("%d", &n);
printf("Enter the array value: ");
for(i=0;i<n;i++)
    scanf("%d", &a[i]);

    //sort
    for(i=1;i<n;i++){
        value=a[i];
        gap=i;
        while(gap>0 && a[gap-1]>value){
            a[gap]=a[gap-1];
            gap--;
        }
        a[gap]=value;
    }
    printf("After sorting: ");
    for(i=0;i<n;i++)
printf("%d\t", a[i]);
}
