#include <stdio.h>
int main()
{
int arr[]={2,3,1,5,6};
int size=5;
for(int i=1;i<size-1;i++)
{ int temp=arr[i];
int j=i-1;
for(;j>=0;j--)
{
if(temp<arr[j])
{
arr[j+1]=arr[j];
}
else
{
break;
}
}
arr[j+1]=temp;
}
for( int k=0;k<size;k++)
{
printf("%d ",arr[k]);
}
return 0;
}