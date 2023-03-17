#include<stdio.h>
int main(){
int i,a[100],n,val,mid,l=0;
printf("Enter the array limit: ");
scanf("%d", &n);
printf("enter the array element: ");
for(i=0;i<n;i++)
scanf("%d", &a[i]);

printf("Enter the value: ");
scanf("%d", &val);
int h=n-1;

while(l<=h)
{
    mid=(l+h)/2;
    if(a[mid]==val){
        printf("%d found in %d position.", val,mid+1);
         break;}
    else if(a[mid]>val)
    h=mid-1;
    else
        l=mid+1;

}
if(l>h)
printf("Item not found");

}
