#include<stdio.h>
int main(){
int i,a[100],n,val,pos=-1;
printf("enter array limit: ");
scanf("%d ", &n);
for(i=0;i<n;i++)
        scanf("%d", &a[i]);

printf("Enter the value: ");
scanf("%d", &val);
for(i=0;i<n;i++){
    if(val==a[i]){
        pos=i+1;
        break;
    }
}
if(pos==-1)
    printf("Value not found!");
else
    printf("%d found in %d position.", val,pos);


}
