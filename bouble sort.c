#include<stdio.h>
int main(){
int i,n,a[10],j,temp;
printf("Enter the array limit ");
scanf("%d", &n);
printf("Enter the element: ");
for(i=0;i<n;i++)
    scanf("%d", &a[i]);

    printf("Before sorting: ");
    for(i=0;i<n;i++)
    printf("%d\t", a[i]);

    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
                if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }}
    }

    printf("After soorting: ");
    for(i=0;i<n;i++)
printf("%d\t", a[i]);
}
