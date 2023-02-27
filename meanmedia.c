#include<stdio.h>
#include<stdlib.h>
int main()
{
int arr[]={13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 35, 35, 36, 40, 45, 52, 70};
int n=sizeof(arr)/sizeof(arr[0]);
float mean=0;
int sum=0;
for(int i=0;i<n;i++)
{
    sum=sum+arr[i];
}
mean=sum/n;
printf("mean %f",mean);
int c=0;
float median;
if(n%2==0)
{
    c=n/2;
    median=(arr[c]+arr[c-1])/2;
}
else
{
    median=arr[n/2];
}
printf("\nmedian %f",median);
int fr[n],v=-1;
for(int i=0;i<n;i++)
{
    int count=1;
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]==arr[j])
        {
            count++;
            fr[j]=v;
        }
    }
    if(fr[i]!=v)
        fr[i]=count;
}
int mode=arr[0],max=1; 
for(int k=0;k<n;k++)
{
    if(fr[k]>max)
    {
        max=k;
    }
}
mode=arr[max];
printf("\n----------------------------------");
printf("\nMode %d",mode);
printf("\n----------------------------------");
int maxi=arr[0],mini=arr[0];
for(int i=1;i<n;i++)
{
    if(maxi<arr[i])
        maxi=arr[i];
    if(mini>arr[i])
        mini=arr[i];
}
printf("\nMid range %d",maxi-mini);
printf("\n----------------------------------");
int q3,q1;
q1=(n+1)/4;
q3=(n+1)*3/4;
printf("\nq1 %d",arr[q1]);
printf("\nq3 %d",arr[q3]);
printf("\n----------------------------------");
printf("\nminimum is: %d",mini);
printf("\n");
printf("first quartile is:%d",arr[q1]);
printf("\n");
printf("median is %f",median);
printf("\n");
printf("Third quartile is:%d",arr[q3]);
printf("\n");
printf("maximum is: %d",maxi);
printf("\n");
}










