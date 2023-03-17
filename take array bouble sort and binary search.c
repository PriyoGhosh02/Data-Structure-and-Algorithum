#include<stdio.h>
void binary_search(int a[],int n,int val) {
 int mid,l=0,h,pos=-1;
 h=n-1;
 while(l<=h){
    mid=(l+h)/2;
    if(a[mid]==val){
        pos=mid+1;
        printf("%d founded in %d position", val,pos);
 break;
 }

    else if(a[mid]<val)
        l=mid+1;

    else
        h=mid-1;
 }
 if(l>h)
        printf("Item not found!");
 }

void bouble_sort(int a[],int n){
int temp,i,j;
for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }}}}



int main(){
int a[10],i,n,val,pos;
printf("Enter the array limit: ");
scanf("%d", &n);
printf("Enter array element: ");
for(i=0;i<n;i++)
    scanf("%d", &a[i]);
bouble_sort(a,n);
for(i=0;i<n;i++)
    printf("%d\t", a[i]);

    printf("Enter searching value: ");
    scanf("%d", &val);
    binary_search(a,n,val);


}
